import os
from ctypes import *

# os.chdir("D:\PYTEST")

dll = cdll.LoadLibrary("./CATDLL.dll")

ret = dll.sum(3, 4)

print(ret)
