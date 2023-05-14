## 添加环境检查
### 检查系统是否支持 pow 函数
未测试成功
```
include (${CMAKE_ROOT}/Modules/CheckFunctionExists.cmake)
check_function_exists (pow HAVE_POW)
```