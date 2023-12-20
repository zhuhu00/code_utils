cmake_minimum_required(VERSION 3.0)

# 创建工程
project(ch8)

#C++版本为 11
set(CMAKE_CXX_FLAGS "-std=c++11")

find_package(OpenCV 4 REQUIRED)#找 OpenCV 4.0 安装路径

include_directories(${OpenCV_INCLUDE_DIRS})#加载 OpenCV 4.0 的头文件


add_executable(ImgDct ImgDct.cpp)#将程序生成可执行文件
target_link_libraries(ImgDct ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgDft ImgDft.cpp)#将程序生成可执行文件
target_link_libraries(ImgDft ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgFloodfill ImgFloodfill.cpp)#将程序生成可执行文件
target_link_libraries(ImgFloodfill ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgGrabCut ImgGrabCut.cpp)#将程序生成可执行文件
target_link_libraries(ImgGrabCut ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgInpaint ImgInpaint.cpp)#将程序生成可执行文件
target_link_libraries(ImgInpaint ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgInteger ImgInteger.cpp)#将程序生成可执行文件
target_link_libraries(ImgInteger ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgMulSpectrums ImgMulSpectrums.cpp)#将程序生成可执行文件
target_link_libraries(ImgMulSpectrums ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgPyrMeanShiftFiltering ImgPyrMeanShiftFiltering.cpp)#将程序生成可执行文件
target_link_libraries(ImgPyrMeanShiftFiltering ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgWatershed ImgWatershed.cpp)#将程序生成可执行文件
target_link_libraries(ImgWatershed ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgWatershedself ImgWatershedself.cpp)#将程序生成可执行文件
target_link_libraries(ImgWatershedself ${OpenCV_LIBS})#链接 lib 文件到可执行文件中