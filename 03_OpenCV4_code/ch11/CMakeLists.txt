cmake_minimum_required(VERSION 3.0)

# 创建工程
project(ch11)

#C++版本为 11
set(CMAKE_CXX_FLAGS "-std=c++11")

find_package(OpenCV 4 REQUIRED)#找 OpenCV 4.0 安装路径

include_directories(${OpenCV_INCLUDE_DIRS})#加载 OpenCV 4.0 的头文件


add_executable(Imgabsdiff Imgabsdiff.cpp)#将程序生成可执行文件
target_link_libraries(Imgabsdiff ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgCalcOpticalFlowFarneback ImgCalcOpticalFlowFarneback.cpp)#将程序生成可执行文件
target_link_libraries(ImgCalcOpticalFlowFarneback ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgCalcOpticalFlowPyrLK ImgCalcOpticalFlowPyrLK.cpp)#将程序生成可执行文件
target_link_libraries(ImgCalcOpticalFlowPyrLK ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgCanShift ImgCanShift.cpp)#将程序生成可执行文件
target_link_libraries(ImgCanShift ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgMeanShift ImgMeanShift.cpp)#将程序生成可执行文件
target_link_libraries(ImgMeanShift ${OpenCV_LIBS})#链接 lib 文件到可执行文件中