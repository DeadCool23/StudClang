import ctypes
import libnames as ld

lib = ctypes.CDLL(ld.libname)

# int uniqcpy(const int *src, size_t src_size, int *dst, size_t *dst_size);
_uniqcpy = lib.uniqcpy
_uniqcpy.argtypes = (ctypes.POINTER(ctypes.c_int), ctypes.c_size_t,
                     ctypes.POINTER(ctypes.c_int), ctypes.POINTER(ctypes.c_size_t))
_uniqcpy.restype = ctypes.c_int


def _uniqcpy_with_size_find(src_arr: [int]) -> [int]:
    src_len = len(src_arr)
    src = (ctypes.c_int * src_len)(*src_arr)
    dst_len = ctypes.c_size_t(0)

    err = _uniqcpy(src, src_len, None, dst_len)
    if err:
        dst = (ctypes.c_int * dst_len.value)()
        err = _uniqcpy(src, src_len, dst, dst_len)

        return list(dst)
    else:
        return list()


def _uniqcpy_with_supposed_size(src_arr: [int]) -> [int]:
    src_len = len(src_arr)
    src = (ctypes.c_int * src_len)(*src_arr)

    dst = (ctypes.c_int * src_len)()
    dst_len = ctypes.c_size_t(src_len)

    err = _uniqcpy(src, src_len, dst, dst_len)
    if err:
        return None
    else:
        return list(dst)[:dst_len.value]


def uniqcpy(src_arr: [int], find_size: bool) -> [int]:
    if find_size:
        return _uniqcpy_with_size_find(src_arr)
    else:
        return _uniqcpy_with_supposed_size(src_arr)
