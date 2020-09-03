import os
import collections
import ctypes
import sys
import math


# Convert octets
def convert_size(size_bytes):
    if size_bytes == 0:
        return "0B"
    size_name = ("B", "KB", "MB", "GB", "TB", "PB", "EB", "ZB", "YB")
    i = int(math.floor(math.log(size_bytes, 1024)))
    p = math.pow(1024, i)
    s = round(size_bytes / p, 2)
    return "%s %s" % (s, size_name[i])


# Get disk size with API GetDiskFreeSpaceExW
def disk_size(path):
    PULARGE_INTEGER = ctypes.POINTER(ctypes.c_ulonglong)
    kernel32 = ctypes.WinDLL('kernel32', use_last_error=True)
    kernel32.GetDiskFreeSpaceExW.argtypes = (ctypes.c_wchar_p,) + (PULARGE_INTEGER,) * 3

    _, total, free = ctypes.c_ulonglong(), ctypes.c_ulonglong(), ctypes.c_ulonglong()
    success = kernel32.GetDiskFreeSpaceExW(path, ctypes.byref(_), ctypes.byref(total), ctypes.byref(free))
    size = convert_size(total.value)
    print "The size of the disk is: ", size


if __name__ == '__main__':
    disk_size("C:/")