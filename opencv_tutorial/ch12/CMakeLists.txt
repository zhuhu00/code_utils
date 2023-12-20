cmake_minimum_required(VERSION 3.0)

# 创建工程
project(ch12)

#C++版本为 11
set(CMAKE_CXX_FLAGS "-std=c++11")

find_package(OpenCV 4 REQUIRED)#找 OpenCV 4.0 安装路径

include_directories(${OpenCV_INCLUDE_DIRS})#加载 OpenCV 4.0 的头文件


add_executable(ImgDTrees ImgDTrees.cpp)#将程序生成可执行文件
target_link_libraries(ImgDTrees ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgGenderDetect ImgGenderDetect.cpp)#将程序生成可执行文件
target_link_libraries(ImgGenderDetect ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgImagePattern ImgImagePattern.cpp)#将程序生成可执行文件
target_link_libraries(ImgImagePattern ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgKMeanImage ImgKMeanImage.cpp)#将程序生成可执行文件
target_link_libraries(ImgKMeanImage ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgKMeanPoints ImgKMeanPoints.cpp)#将程序生成可执行文件
target_link_libraries(ImgKMeanPoints ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgKNearestTest ImgKNearestTest.cpp)#将程序生成可执行文件
target_link_libraries(ImgKNearestTest ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgKNearestTrain ImgKNearestTrain.cpp)#将程序生成可执行文件
target_link_libraries(ImgKNearestTrain ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgNeuralStyle ImgNeuralStyle.cpp)#将程序生成可执行文件
target_link_libraries(ImgNeuralStyle ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgReadNet ImgReadNet.cpp)#将程序生成可执行文件
target_link_libraries(ImgReadNet ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgRTrees ImgRTrees.cpp)#将程序生成可执行文件
target_link_libraries(ImgRTrees ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgSVM ImgSVM.cpp)#将程序生成可执行文件
target_link_libraries(ImgSVM ${OpenCV_LIBS})#链接 lib 文件到可执行文件中