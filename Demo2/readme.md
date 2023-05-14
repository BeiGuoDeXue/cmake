# 多个源文件
### 新建一个MathFunctions.cc文件，cmake统一编译
```
# 查找当前目录下的所有源文件，并且保存到变量DIR_SRCS中
aux_source_directory(. DIR_SRCS)

# 编译源码生成目标
add_executable(Demo ${DIR_SRCS})
```
### 编译
```
mkdir build
cmake ..
make -j8
./Demo
```
