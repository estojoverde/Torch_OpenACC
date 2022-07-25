from ctypes import *
import ctypes
import numpy as np
import cupy as cp
#import torch


so_file = "mylib.so"

cp.cuda.set_allocator(cp.cuda.MemoryPool(cp.cuda.malloc_managed).malloc)
print(cp.cuda.get_allocator())

n = 10
a = cp.ones(n, dtype=cp.float32)
a_ctypes = cast(a.data.ptr, ctypes.c_void_p)

b = cp.ones(n, dtype=cp.float32)
b_ctypes = cast(b.data.ptr, ctypes.c_void_p)

c = cp.zeros(n, dtype=cp.float32)
c_ctypes = cast(c.data.ptr, ctypes.c_void_p)


my_functions = ctypes.CDLL(so_file)


my_functions.addvector_cab.argtypes = [ctypes.c_void_p, ctypes.c_void_p, ctypes.c_void_p, ctypes.c_int]
my_functions.addvector_cab.restype = ctypes.c_int


print(my_functions.addvector_cab(a_ctypes, b_ctypes, c_ctypes, n))

print(f"Valor de c: {c}")
print(f"Valor de b: {b}")
print(f"Valor de a: {a}")

