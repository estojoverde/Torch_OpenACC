#!/opt/conda/bin/python


import ctypes
from ctypes import CDLL

import cupy as cp
import torch

import math
import time

import numpy as np

#from myLib import Foo
from myLib import Foo, stepacc2
#from mylib import stepacc2


f = Foo()
f.bar() #and you will see "Hello" on the screen

print(f.sum(2,4))

arr = np.arange(0, 5, dtype=np.float32)

arr2 = np.copy(arr)

stepacc2()

#f.step_acc(vec = arr.ctypes.data, n = arr.size, step=1.357, verbose= False)




