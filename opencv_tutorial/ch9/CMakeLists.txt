cmake_minimum_required(VERSION 3.0)

# 创建工程
project(ch9)

#C++版本为 11
set(CMAKE_CXX_FLAGS "-std=c++11")

find_package(OpenCV 4 REQUIRED)#找 OpenCV 4.0 安装路径

include_directories(${OpenCV_INCLUDE_DIRS})#加载 OpenCV 4.0 的头文件


add_executable(ImgCornerHarris ImgCornerHarris.cpp)#将程序生成可执行文件
target_link_libraries(ImgCornerHarris ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgCornerSubPix ImgCornerSubPix.cpp)#将程序生成可执行文件
target_link_libraries(ImgCornerSubPix ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgDrawKeypoint ImgDrawKeypoint.cpp)#将程序生成可执行文件
target_link_libraries(ImgDrawKeypoint ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgGoodFeaturesToTrack ImgGoodFeaturesToTrack.cpp)#将程序生成可执行文件
target_link_libraries(ImgGoodFeaturesToTrack ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgORB ImgORB.cpp)#将程序生成可执行文件
target_link_libraries(ImgORB ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgORBMatch ImgORBMatch.cpp)#将程序生成可执行文件
target_link_libraries(ImgORBMatch ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgORBMatchRansac ImgORBMatchRansac.cpp)#将程序生成可执行文件
target_link_libraries(ImgORBMatchRansac ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

# add_executable(ImgPyrMeanShiftFiltering ImgPyrMeanShiftFiltering.cpp)#将程序生成可执行文件
# target_link_libraries(ImgPyrMeanShiftFiltering ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

# add_executable(ImgWatershed ImgWatershed.cpp)#将程序生成可执行文件
# target_link_libraries(ImgWatershed ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

# add_executable(ImgWatershedself ImgWatershedself.cpp)#将程序生成可执行文件
# target_link_libraries(ImgWatershedself ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

# add_executable(ImgMatchShapes ImgMatchShapes.cpp)#将程序生成可执行文件
# target_link_libraries(ImgMatchShapes ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

# add_executable(ImgMoments ImgMoments.cpp)#将程序生成可执行文件
# target_link_libraries(ImgMoments ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

# add_executable(ImgPointPolygonTest ImgPointPolygonTest.cpp)#将程序生成可执行文件
# target_link_libraries(ImgPointPolygonTest ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

# add_executable(ImgQRcode ImgQRcode.cpp)#将程序生成可执行文件
# target_link_libraries(ImgQRcode ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

# add_executable(ImgRect ImgRect.cpp)#将程序生成可执行文件
# target_link_libraries(ImgRect ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

# add_executable(ImgTriangleAndCircle ImgTriangleAndCircle.cpp)#将程序生成可执行文件
# target_link_libraries(ImgTriangleAndCircle ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

# add_executable(QRcodeDetect QRcodeDetect.cpp)#将程序生成可执行文件
# target_link_libraries(QRcodeDetect ${OpenCV_LIBS})#链接 lib 文件到可执行文件中