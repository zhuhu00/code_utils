cmake_minimum_required(VERSION 3.0)

# 创建工程
project(ch7)

#C++版本为 11
set(CMAKE_CXX_FLAGS "-std=c++11")

find_package(OpenCV 4 REQUIRED)#找 OpenCV 4.0 安装路径

include_directories(${OpenCV_INCLUDE_DIRS})#加载 OpenCV 4.0 的头文件

add_executable(ImgApproxPolyDP ImgApproxPolyDP.cpp)#将程序生成可执行文件
target_link_libraries(ImgApproxPolyDP ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgContourArea ImgContourArea.cpp)#将程序生成可执行文件
target_link_libraries(ImgContourArea ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgContours ImgContours.cpp)#将程序生成可执行文件
target_link_libraries(ImgContours ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgConvexHull ImgConvexHull.cpp)#将程序生成可执行文件
target_link_libraries(ImgConvexHull ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgFitLine ImgFitLine.cpp)#将程序生成可执行文件
target_link_libraries(ImgFitLine ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgHoughCircles ImgHoughCircles.cpp)#将程序生成可执行文件
target_link_libraries(ImgHoughCircles ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgHoughLines ImgHoughLines.cpp)#将程序生成可执行文件
target_link_libraries(ImgHoughLines ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgHoughLinesP ImgHoughLinesP.cpp)#将程序生成可执行文件
target_link_libraries(ImgHoughLinesP ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgHoughLinesPointSet ImgHoughLinesPointSet.cpp)#将程序生成可执行文件
target_link_libraries(ImgHoughLinesPointSet ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgHuMoments ImgHuMoments.cpp)#将程序生成可执行文件
target_link_libraries(ImgHuMoments ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgMatchShapes ImgMatchShapes.cpp)#将程序生成可执行文件
target_link_libraries(ImgMatchShapes ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgMoments ImgMoments.cpp)#将程序生成可执行文件
target_link_libraries(ImgMoments ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgPointPolygonTest ImgPointPolygonTest.cpp)#将程序生成可执行文件
target_link_libraries(ImgPointPolygonTest ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgQRcode ImgQRcode.cpp)#将程序生成可执行文件
target_link_libraries(ImgQRcode ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgRect ImgRect.cpp)#将程序生成可执行文件
target_link_libraries(ImgRect ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgTriangleAndCircle ImgTriangleAndCircle.cpp)#将程序生成可执行文件
target_link_libraries(ImgTriangleAndCircle ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(QRcodeDetect QRcodeDetect.cpp)#将程序生成可执行文件
target_link_libraries(QRcodeDetect ${OpenCV_LIBS})#链接 lib 文件到可执行文件中