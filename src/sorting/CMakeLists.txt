message("subdirrectory ${CMAKE_CURRENT_SOURCE_DIR}")

message("add executable sorting")
FILE(GLOB cppfiles ./*.cpp)
FILE(GLOB hppfiles ./*.hpp)
include_directories(./utils)
include_directories(./sotring_algorithms)
message("compile files ${cppfiles}")

add_executable(sorting main.cpp ${cppfiles} ${hppfiles})