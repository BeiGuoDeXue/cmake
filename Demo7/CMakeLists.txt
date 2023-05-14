# 多个目录，多个源文件

# 设置CMake最低版本
cmake_minimum_required(VERSION 3.10)

# 工程名称
project(Demo7)
set (Demo_VERSION_MAJOR 1)
set (Demo_VERSION_MINOR 0)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)

# 检查系统是否支持 pow 函数
include (${CMAKE_ROOT}/Modules/CheckFunctionExists.cmake)
check_function_exists (pow HAVE_POW)

# 加入一个配置头文件，用于处理CMake对源码的设置
configure_file (
    "${PROJECT_SOURCE_DIR}/config.h.in"
    "${PROJECT_BINARY_DIR}/config.h"
)

# 是否使用自己的 MathFunctions 库
option (USE_MYMATH "Use provided math implementation" ON)

# 是否加入 MathFunctions 库
if (NOT HAVE_POW)
    include_directories ("${PROJECT_SOURCE_DIR}/math")
    add_subdirectory (math)
    set (EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
  endif (NOT HAVE_POW)


# 查找当前目录下的所有源文件，并且保存到变量DIR_SRCS中
aux_source_directory(. DIR_SRCS)

# 编译源码生成目标
add_executable(Demo ${DIR_SRCS})

# 添加链接库
target_link_libraries(Demo ${EXTRA_LIBS})

# gdb debug
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
set(CMAKE_CXX_FLAGS_RELESE "ENV{CXXFLAGS} -O3 -Wall")

# 指定安装路径
install (TARGETS Demo DESTINATION bin)
install (FILES "${PROJECT_BINARY_DIR}/config.h"
         DESTINATION include)

# 启用测试
enable_testing()

# 测试程序是否成功运行
add_test (test_run Demo)

# 测试帮助信息是否可以正常提示
add_test (test_usage Demo)
set_tests_properties (test_usage
# 其中 PASS_REGULAR_EXPRESSION 用来测试输出是否包含后面跟着的字符串
  PROPERTIES PASS_REGULAR_EXPRESSION "Hello, World!")

