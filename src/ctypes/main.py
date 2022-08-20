import ctypes

lib1 = ctypes.CDLL("./lib.so")

lib1.start_thread()
