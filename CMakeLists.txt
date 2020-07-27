cmake_minimum_required(VERSION 3.16)
project(TrueConf)

set(CMAKE_CXX_STANDARD 17)

add_executable(TrueConf main.cpp)
target_link_libraries(TrueConf -O3 -L/usr/X11R6/lib -lm -lpthread -lX11 -ljpeg)
