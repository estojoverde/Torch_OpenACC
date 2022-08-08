
import ctypes
import torch
import traceback
import sys



def crashing_function(so_file = "./mylib.so"):
     my_functions = ctypes.CDLL(so_file)

     my_functions.wrapper_add.restype = ctypes.c_int

     if( my_functions.wrapper_add() == 0):
          print("Returned OKAY!")



try:
    crashing_function()
except Exception:
    print(traceback.format_exc())
    # or
    print(sys.exc_info()[2])






