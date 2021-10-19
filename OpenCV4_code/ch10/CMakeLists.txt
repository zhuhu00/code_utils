cmake_minimum_required(VERSION 3.0)

# 创建工程
project(ch10)

#C++版本为 11
set(CMAKE_CXX_FLAGS "-std=c++11")

find_package(OpenCV 4 REQUIRED)#找 OpenCV 4.0 安装路径

include_directories(${OpenCV_INCLUDE_DIRS})#加载 OpenCV 4.0 的头文件


add_executable(ImgHomogenous ImgHomogenous.cpp)#将程序生成可执行文件
target_link_libraries(ImgHomogenous ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgCalibrateCamera ImgCalibrateCamera.cpp)#将程序生成可执行文件
target_link_libraries(ImgCalibrateCamera ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgChessboard ImgChessboard.cpp)#将程序生成可执行文件
target_link_libraries(ImgChessboard ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgConcat ImgConcat.cpp)#将程序生成可执行文件
target_link_libraries(ImgConcat ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgPnPAndRansac ImgPnPAndRansac.cpp)#将程序生成可执行文件
target_link_libraries(ImgPnPAndRansac ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgProjectPoints ImgProjectPoints.cpp)#将程序生成可执行文件
target_link_libraries(ImgProjectPoints ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(StereoCalib StereoCalib.cpp)#将程序生成可执行文件
target_link_libraries(StereoCalib ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(StereoRectify StereoRectify.cpp)#将程序生成可执行文件
target_link_libraries(StereoRectify ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

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