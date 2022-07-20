import ctypes
from ctypes import  cdll

import os 
import subprocess

import numpy as np

p = subprocess.Popen(['pwd'], stdout=subprocess.PIPE, 
                              stderr=subprocess.PIPE)
out, err = p.communicate()


# c_lib = cdll.LoadLibrary(os.path.join(os.path.split(__file__)[0], "mylib.so") )

c_lib = cdll.LoadLibrary("/home/marcelo.silva/repos/python_bindings/openacc/myLib/mylib.so")

c_lib.Foo_sum.restype = ctypes.c_float
c_lib.Foo_sum.argtypes = [ ctypes.c_void_p, ctypes.c_float , ctypes.c_float ]

c_lib.Foo_mean.restype = ctypes.c_float
c_lib.Foo_mean.argtypes  = [ctypes.c_void_p, ctypes.c_void_p, ctypes.c_int]


c_lib.Foo_step.argtypes  = [ctypes.c_void_p, ctypes.c_void_p, ctypes.c_int, ctypes.c_float, ctypes.c_uint8]

c_lib.Foo_step_openacc.argtypes  = [ctypes.c_void_p, ctypes.c_void_p, ctypes.c_int, ctypes.c_float, ctypes.c_uint8]

c_lib.Foo_step_openacc2.argtypes  = [ctypes.c_void_p]


# c_lib.step_openacc2.argtypes  = [ctypes.c_void_p]



def stepacc2( ):
    c_lib.step_openacc2( )


class Foo(object):
    def __init__(self):
        self.obj = c_lib.Foo_new()

    def bar(self):
        c_lib.Foo_bar(self.obj)

    def sum(self, a, b):
        return(c_lib.Foo_sum(self.obj, a , b ))

    def mean(self, vec, n):
        return(c_lib.Foo_mean(self.obj, vec , n ))

    def step(self, vec, n, step= 1.0, verbose = True ):
        if( verbose ):
            cpp_verbose = int(1)
        else :
            cpp_verbose = int(0)
        
        step = float(step)
        n = int(n)
        #vec = vec.astype(np.float32)

        c_lib.Foo_step(self.obj, vec , n, step, cpp_verbose )

    def step_acc(self, vec, n, step= 1.0, verbose = True ):
        if( verbose ):
            cpp_verbose = int(1)
        else :
            cpp_verbose = int(0)
        
        step = float(step)
        n = int(n)
        #vec = vec.astype(np.float32)

        c_lib.Foo_step_openacc(self.obj, vec , n, step, cpp_verbose )


    def step_acc2(self ):
        c_lib.Foo_step_openacc2(self.obj )
