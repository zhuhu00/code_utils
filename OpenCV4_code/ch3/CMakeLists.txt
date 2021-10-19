cmake_minimum_required(VERSION 3.0)

# 创建工程
project(ch3)

#C++版本为 11
set(CMAKE_CXX_FLAGS "-std=c++11")

find_package(OpenCV 4 REQUIRED)#找 OpenCV 4.0 安装路径

include_directories(${OpenCV_INCLUDE_DIRS})#加载 OpenCV 4.0 的头文件

add_executable(ImgConcat ImgConcat.cpp)#将程序生成可执行文件
target_link_libraries(ImgConcat ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(CreateTrackbar CreateTrackbar.cpp)#将程序生成可执行文件
target_link_libraries(CreateTrackbar ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(CvColor CvColor.cpp)#将程序生成可执行文件
target_link_libraries(CvColor ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(DeepShallowcopy DeepShallowcopy.cpp)#将程序生成可执行文件
target_link_libraries(DeepShallowcopy ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgFlip ImgFlip.cpp)#将程序生成可执行文件
target_link_libraries(ImgFlip ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgLUT ImgLUT.cpp)#将程序生成可执行文件
target_link_libraries(ImgLUT ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgLogicOper ImgLogicOper.cpp)#将程序生成可执行文件
target_link_libraries(ImgLogicOper ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgMaxandMin ImgMaxandMin.cpp)#将程序生成可执行文件
target_link_libraries(ImgMaxandMin ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgMeanAndmearstdDev ImgMeanAndmearstdDev.cpp)#将程序生成可执行文件
target_link_libraries(ImgMeanAndmearstdDev ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(Mouse_traj Mouse_traj.cpp)#将程序生成可执行文件
target_link_libraries(Mouse_traj ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgPlot ImgPlot.cpp)#将程序生成可执行文件
target_link_libraries(ImgPlot ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgPyramid ImgPyramid.cpp)#将程序生成可执行文件
target_link_libraries(ImgPyramid ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgResize ImgResize.cpp)#将程序生成可执行文件
target_link_libraries(ImgResize ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgSplitMerge ImgSplitMerge.cpp)#将程序生成可执行文件
target_link_libraries(ImgSplitMerge ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgThreshold ImgThreshold.cpp)#将程序生成可执行文件
target_link_libraries(ImgThreshold ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgWarpAffine ImgWarpAffine.cpp)#将程序生成可执行文件
target_link_libraries(ImgWarpAffine ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgWarpPerspective ImgWarpPerspective.cpp)#将程序生成可执行文件
target_link_libraries(ImgWarpPerspective ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgFindminmax ImgFindminmax.cpp)#将程序生成可执行文件
target_link_libraries(ImgFindminmax ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgWarpPolar ImgWarpPolar.cpp)#将程序生成可执行文件
target_link_libraries(ImgWarpPolar ${OpenCV_LIBS})#链接 lib 文件到可执行文件中