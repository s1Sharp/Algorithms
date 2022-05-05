message("subdirrectory ${CMAKE_CURRENT_SOURCE_DIR}")

message("add executable sorting")
FILE(GLOB cppfiles *.cpp)
add_executable(sorting main.cpp ${cppfiles})