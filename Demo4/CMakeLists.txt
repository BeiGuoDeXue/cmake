# 多个目录，多个源文件

# 设置CMake最低版本
cmake_minimum_required(VERSION 3.10)

# 工程名称
project(Demo4)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)

# 加入一个配置头文件，用于处理CMake对源码的设置
configure_file (
    "${PROJECT_SOURCE_DIR}/config.h.in"
    "${PROJECT_BINARY_DIR}/config.h"
)

# 是否使用自己的 MathFunctions 库
option (USE_MYMATH "Use provided math implementation" ON)

if (USE_MYMATH)
    include_directories ("${PROJECT_SOURCE_DIR}/math")
    # 添加math子目录
    add_subdirectory(math)
    set (EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
endif (USE_MYMATH)


# 查找当前目录下的所有源文件，并且保存到变量DIR_SRCS中
aux_source_directory(. DIR_SRCS)

# 编译源码生成目标
add_executable(Demo ${DIR_SRCS})

# 添加链接库
target_link_libraries(Demo ${EXTRA_LIBS})

