
import ctypes
import torch

so_file = "./mylib.so"

my_functions = ctypes.CDLL(so_file)

my_functions.addvector_cab.restype = ctypes.c_int

if( my_functions.addvector_cab() == 0):
     print("Returned OKAY!")


