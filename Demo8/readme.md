## cpack的使用方法：
### 首先需要在CMakeLists.txt里面添加以下内容
```
# 构建一个 CPack 安装包
include (InstallRequiredSystemLibraries)
set (CPACK_RESOURCE_FILE_LICENSE
  "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set (CPACK_PACKAGE_VERSION_MAJOR "${Demo_VERSION_MAJOR}")
set (CPACK_PACKAGE_VERSION_MINOR "${Demo_VERSION_MINOR}")
include (CPack)
# 导入 InstallRequiredSystemLibraries 模块，以便之后导入 CPack 模块；
# 设置一些 CPack 相关变量，包括版权信息和版本信息，其中版本信息用了上一节定义的版本号；
# 导入 CPack 模块。
```
### 开始构建、编译、打包
```
cmake ..
make -j8
# 生成二进制安装包：
sudo cpack -C CPackConfig.cmake
# 生成源码安装包
sudo cpack -C CPackSourceConfig.cmake
# 解压cpack包，路径要为默认值，不然会打包失败
sudo sh Demo8-1.0.1-Linux.sh
# 执行
./Demo8-1.0.1-Linux/bin/Demo
```