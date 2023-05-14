# 单个源文件
## 写一个.cpp文件
```
#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
```
## 编写 CMakeLists.txt
    CMakeLists.txt放在工程的顶层目录
```
# 设置CMake最低版本
cmake_minimum_required(VERSION 3.10)
# 工程名称
project(Demo1)
# 设置C++标准
set(CMAKE_CXX_STANDARD 11)
# 编译源码生成目标
add_executable(Demo main.cc)
```
## 编译、执行
新建一个build文件用于放编译结果
```
mkdir build
cmake ..
make -j8
./Demo
```
