import ctypes

lib1 = ctypes.CDLL("./lib.so")

counter = 10
c_counter = ctypes.c_int(counter)

lib1.start_thread(ctypes.byref(c_counter))

counter = c_counter.value
print(counter)