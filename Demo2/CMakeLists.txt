# 设置CMake最低版本
cmake_minimum_required(VERSION 3.10)

# 工程名称
project(Demo2)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)

# 查找当前目录下的所有源文件，并且保存到变量DIR_SRCS中
aux_source_directory(. DIR_SRCS)

# 编译源码生成目标
add_executable(Demo ${DIR_SRCS})

