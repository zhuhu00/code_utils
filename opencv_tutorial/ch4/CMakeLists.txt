cmake_minimum_required(VERSION 3.0)

# 创建工程
project(ch4)

#C++版本为 11
set(CMAKE_CXX_FLAGS "-std=c++11")

find_package(OpenCV 4 REQUIRED)#找 OpenCV 4.0 安装路径

include_directories(${OpenCV_INCLUDE_DIRS})#加载 OpenCV 4.0 的头文件

add_executable(ImgCalHist ImgCalHist.cpp)#将程序生成可执行文件
target_link_libraries(ImgCalHist ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgHistBackProj ImgHistBackProj.cpp)#将程序生成可执行文件
target_link_libraries(ImgHistBackProj ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgHistComp ImgHistComp.cpp)#将程序生成可执行文件
target_link_libraries(ImgHistComp ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgEqualizeHist ImgEqualizeHist.cpp)#将程序生成可执行文件
target_link_libraries(ImgEqualizeHist ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgHistMatch ImgHistMatch.cpp)#将程序生成可执行文件
target_link_libraries(ImgHistMatch ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgMatchTemp ImgMatchTemp.cpp)#将程序生成可执行文件
target_link_libraries(ImgMatchTemp ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgNormalize ImgNormalize.cpp)#将程序生成可执行文件
target_link_libraries(ImgNormalize ${OpenCV_LIBS})#链接 lib 文件到可执行文件中



# add_executable(ImgMeanAndmearstdDev ImgMeanAndmearstdDev.cpp)#将程序生成可执行文件
# target_link_libraries(ImgMeanAndmearstdDev ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

# add_executable(Mouse_traj Mouse_traj.cpp)#将程序生成可执行文件
# target_link_libraries(Mouse_traj ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

# add_executable(ImgPlot ImgPlot.cpp)#将程序生成可执行文件
# target_link_libraries(ImgPlot ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

# add_executable(ImgPyramid ImgPyramid.cpp)#将程序生成可执行文件
# target_link_libraries(ImgPyramid ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

# add_executable(ImgResize ImgResize.cpp)#将程序生成可执行文件
# target_link_libraries(ImgResize ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

# add_executable(ImgSplitMerge ImgSplitMerge.cpp)#将程序生成可执行文件
# target_link_libraries(ImgSplitMerge ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

# add_executable(ImgThreshold ImgThreshold.cpp)#将程序生成可执行文件
# target_link_libraries(ImgThreshold ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

# add_executable(ImgWarpAffine ImgWarpAffine.cpp)#将程序生成可执行文件
# target_link_libraries(ImgWarpAffine ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

# add_executable(ImgWarpPerspective ImgWarpPerspective.cpp)#将程序生成可执行文件
# target_link_libraries(ImgWarpPerspective ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

# add_executable(ImgFindminmax ImgFindminmax.cpp)#将程序生成可执行文件
# target_link_libraries(ImgFindminmax ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

# add_executable(ImgWarpPolar ImgWarpPolar.cpp)#将程序生成可执行文件
# target_link_libraries(ImgWarpPolar ${OpenCV_LIBS})#链接 lib 文件到可执行文件中