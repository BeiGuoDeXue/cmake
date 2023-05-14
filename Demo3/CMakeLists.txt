# 多个目录，多个源文件

# 设置CMake最低版本
cmake_minimum_required(VERSION 3.10)

# 工程名称
project(Demo3)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)

# 查找当前目录下的所有源文件，并且保存到变量DIR_SRCS中
aux_source_directory(. DIR_SRCS)

# 添加math子目录
add_subdirectory(math)

# 编译源码生成目标
add_executable(Demo ${DIR_SRCS})

# 添加链接库
target_link_libraries(Demo MathFunctions)

