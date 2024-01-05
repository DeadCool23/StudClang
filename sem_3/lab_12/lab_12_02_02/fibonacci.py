import ctypes
import libnames as ld

lib = ctypes.CDLL(ld.libname)

# void fill_fibonacci(int*, size_t)
_fill_fibonacci = lib.fill_fibonacci
_fill_fibonacci.argtypes = (ctypes.POINTER(ctypes.c_int), ctypes.c_size_t)
_fill_fibonacci.restype = None


def fill_fibonacci(size: int) -> [int]:
    fib_nums = (ctypes.c_int * size)()
    _fill_fibonacci(fib_nums, size)

    return list(fib_nums)
