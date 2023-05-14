# 编译多文件
## 把MathFunctions放到math文件夹下，然后单独编译为库文件
### 在math文件夹下创建CMakeLists.txt ：
```
# 查找当前目录下的所有源文件，并且保存到变量DIR_SRCS中
aux_source_directory(. DIR_LIB_SRCS)

# 生成连接库，add_library 将 src 目录中的源文件编译为静态链接库。
add_library(MathFunctions ${DIR_LIB_SRCS})

```
### 在顶层CMakeLists.txt中添加MathFunctions链接库
```
# 添加math子目录，这样 math 目录下的 CMakeLists.txt 文件和源代码也会被处理
add_subdirectory(math)

# 添加链接库到Demo
target_link_libraries(Demo MathFunctions)
```
