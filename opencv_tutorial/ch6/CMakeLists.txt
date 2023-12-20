cmake_minimum_required(VERSION 3.0)

# 创建工程
project(ch6)

#C++版本为 11
set(CMAKE_CXX_FLAGS "-std=c++11")

find_package(OpenCV 4 REQUIRED)#找 OpenCV 4.0 安装路径

include_directories(${OpenCV_INCLUDE_DIRS})#加载 OpenCV 4.0 的头文件

add_executable(ImgConnectCom ImgConnectCom.cpp)#将程序生成可执行文件
target_link_libraries(ImgConnectCom ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgConnectCompWithStats ImgConnectCompWithStats.cpp)#将程序生成可执行文件
target_link_libraries(ImgConnectCompWithStats ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgDilate ImgDilate.cpp)#将程序生成可执行文件
target_link_libraries(ImgDilate ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgDistanceTransform ImgDistanceTransform.cpp)#将程序生成可执行文件
target_link_libraries(ImgDistanceTransform ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgErode ImgErode.cpp)#将程序生成可执行文件
target_link_libraries(ImgErode ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgMorphologyAPP ImgMorphologyAPP.cpp)#将程序生成可执行文件
target_link_libraries(ImgMorphologyAPP ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgThinning ImgThinning.cpp)#将程序生成可执行文件
target_link_libraries(ImgThinning ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

# add_executable(ImgGetDerivKernels ImgGetDerivKernels.cpp)#将程序生成可执行文件
# target_link_libraries(ImgGetDerivKernels ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

# add_executable(ImgLaplacian ImgLaplacian.cpp)#将程序生成可执行文件
# target_link_libraries(ImgLaplacian ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

# add_executable(ImgMedianBlur ImgMedianBlur.cpp)#将程序生成可执行文件
# target_link_libraries(ImgMedianBlur ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

# add_executable(ImgSaltAndPrpper ImgSaltAndPrpper.cpp)#将程序生成可执行文件
# target_link_libraries(ImgSaltAndPrpper ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

# add_executable(ImgScharr ImgScharr.cpp)#将程序生成可执行文件
# target_link_libraries(ImgScharr ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

# add_executable(ImgSelfFilter ImgSelfFilter.cpp)#将程序生成可执行文件
# target_link_libraries(ImgSelfFilter ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

# add_executable(ImgSobel ImgSobel.cpp)#将程序生成可执行文件
# target_link_libraries(ImgSobel ${OpenCV_LIBS})#链接 lib 文件到可执行文件中
