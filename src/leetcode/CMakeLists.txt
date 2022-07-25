message("subdirrectory ${CMAKE_CURRENT_SOURCE_DIR}")

message("add executable sorting")
FILE(GLOB cppfiles ./*.cpp)
FILE(GLOB hppfiles ./*.hpp)
include_directories(./solutions)
message("compile files ${cppfiles}")

add_executable(leetcode main.cpp ${cppfiles} ${hppfiles})