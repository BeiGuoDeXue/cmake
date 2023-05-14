# 自定义编译选项
## 第一步是在顶层的 CMakeLists.txt 文件中添加该选项：
```
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


configure_file 命令用于加入一个配置头文件 config.h ，这个文件由 CMake 从 config.h.in 生成，通过这样的机制，将可以通过预定义一些参数和变量来控制代码的生成。
option 命令添加了一个 USE_MYMATH 选项，并且默认值为 ON 。
USE_MYMATH 变量的值来决定是否使用我们自己编写的 MathFunctions 库。
```
## 修改代码，使用自定义编译选项
```
#include "config.h"

#ifdef USE_MYMATH
    #include "math/MathFunctions.h"
#else
    #include <math.h>
#endif


#ifdef USE_MYMATH
    double ret = power(1, 2);
    std::cout << "USE MYMATH " << ret << std::endl;
#else
    double ret = pow(1, 2);
    std::cout << "NOT USE MYMATH " << ret << std::endl;
#endif
```

## 编写 config.h.in 文件
config.h.in为了生成config.h，可以界面化配置config.h，也可以自己定义config.h，config.h.in内容：
```
#cmakedefine USE_MYMATH
```
### 然后使用ccmake编译config.h.in
```
ccmake .
# 回车键可以改变USE_MYMATH变量的值
# 修改完成后可以按下 c 选项完成配置，之后再按 g 键确认生Makefile
# 默认生成到build下面，之后重新编译，执行观察效果
```
