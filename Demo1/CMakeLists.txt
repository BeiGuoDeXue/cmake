# 设置CMake最低版本
cmake_minimum_required(VERSION 3.10)
# 工程名称
project(Demo1)
# 设置C++标准
set(CMAKE_CXX_STANDARD 11)
# 编译源码生成目标
add_executable(Demo main.cc)