import os

print(os.environ['LD_LIBRARY_PATH'])


from ctypes import *
import ctypes
import numpy as np
#import cupy as cp
import torch

print(os.environ['LD_LIBRARY_PATH'])



so_file = "/home/marcelo.silva/repos/python_bindings/pytorch_openacc/myLib/mylib.so"

# cp.cuda.set_allocator(cp.cuda.MemoryPool(cp.cuda.malloc_managed).malloc)
# print(cp.cuda.get_allocator())

# n = 10
# a = cp.ones(n, dtype=cp.float32)
# a_ctypes = cast(a.data.ptr, ctypes.c_void_p)

# b = cp.ones(n, dtype=cp.float32)
# b_ctypes = cast(b.data.ptr, ctypes.c_void_p)


# print("OK")

# # c_torch = torch.rand(n, device='cuda')
# # c = cp.asarray(c_torch)
# c = cp.zeros(n, dtype=cp.float32)
# c_ctypes = cast(c.data.ptr, ctypes.c_void_p)


n = 10
a = np.ones(n, dtype=np.float32)
a_ctypes = cast(a.ctypes.data, ctypes.c_void_p)

b = np.ones(n, dtype=np.float32)
b_ctypes = cast(b.ctypes.data, ctypes.c_void_p)


print("OK")

c = np.ones(n, dtype=np.float32)
c_ctypes = cast(c.ctypes.data, ctypes.c_void_p)



print("OK2")

my_functions = ctypes.CDLL(so_file)
#my_functions.plusone.argtypes = [ctypes.c_void_p, ctypes.c_void_p, ctypes.c_int]

print("OK3")

my_functions.addvector_cab.argtypes = [ctypes.c_void_p, ctypes.c_void_p, ctypes.c_void_p, ctypes.c_int]
my_functions.addvector_cab.restype = ctypes.c_int

print("OK4")

# my_functions.plusone(a_ctypes, b_ctypes, n)
# print(f"Valor de b: {b}")
# print(f"Valor de a: {a}")

print("OK5")

print(my_functions.addvector_cab(a_ctypes, b_ctypes, c_ctypes, n))

print("OK6")


print(f"Valor de c: {c}")
print(f"Valor de b: {b}")
print(f"Valor de a: {a}")

