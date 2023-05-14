# 安装、测试、调试
## 安装
### 指定 MathFunctions 库的安装路径
```
首先先在 math/CMakeLists.txt 文件里添加下面两行：
install (TARGETS MathFunctions DESTINATION lib)
install (FILES MathFunctions.h DESTINATION include)
```
### 指定可执行文件安装路径
```
之后同样修改根目录的 CMakeLists 文件，在末尾添加下面几行：
install (TARGETS Demo DESTINATION bin)
install (FILES "${PROJECT_BINARY_DIR}/config.h"
         DESTINATION include)

# 执行安装命令
sudo make install
```
### 生成的 Demo 文件安装到/usr/local/bin，MathFunctions 函数库 libMathFunctions.o 文件将会被复制到 /usr/local/lib
    安装路径也是可以改变的

## 测试
### CTest测试工具，在CMakeLists添加add_test命令
```
# 启用测试
enable_testing()

# 测试程序是否成功运行
add_test (test_run Demo)

# 测试帮助信息是否可以正常提示
add_test (test_usage Demo)
set_tests_properties (test_usage
# 其中 PASS_REGULAR_EXPRESSION 用来测试输出是否包含后面跟着的字符串
  PROPERTIES PASS_REGULAR_EXPRESSION "Hello, World!")

# 执行测试命令：
make test
```

## gbd调试
指定 Debug 模式下开启 -g 选项
```
# gdb debug
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
set(CMAKE_CXX_FLAGS_RELESE "ENV{CXXFLAGS} -O3 -Wall")
```