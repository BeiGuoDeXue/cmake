set(CMAKE_INSTALL_PREFIX ~/zhao/test_code/cmake/cmake_zhao/)

# 查找当前目录下的所有源文件，并且保存到变量DIR_SRCS中
aux_source_directory(. DIR_LIB_SRCS)

# 生成连接库
add_library(MathFunctions ${DIR_LIB_SRCS})

# 指定 MathFunctions 库安装路径
install (TARGETS MathFunctions DESTINATION lib)
install (FILES MathFunctions.h DESTINATION include)