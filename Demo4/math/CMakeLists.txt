# 查找当前目录下的所有源文件，并且保存到变量DIR_SRCS中
aux_source_directory(. DIR_LIB_SRCS)

# 生成连接库
add_library(MathFunctions ${DIR_LIB_SRCS})
