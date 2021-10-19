cmake_minimum_required(VERSION 3.0)

# 创建工程
project(ch5)

#C++版本为 11
set(CMAKE_CXX_FLAGS "-std=c++11")

find_package(OpenCV 4 REQUIRED)#找 OpenCV 4.0 安装路径

include_directories(${OpenCV_INCLUDE_DIRS})#加载 OpenCV 4.0 的头文件

add_executable(ImgBilateraFilter ImgBilateraFilter.cpp)#将程序生成可执行文件
target_link_libraries(ImgBilateraFilter ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgBlur ImgBlur.cpp)#将程序生成可执行文件
target_link_libraries(ImgBlur ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgBoxFilter ImgBoxFilter.cpp)#将程序生成可执行文件
target_link_libraries(ImgBoxFilter ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgCanny ImgCanny.cpp)#将程序生成可执行文件
target_link_libraries(ImgCanny ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgEdge ImgEdge.cpp)#将程序生成可执行文件
target_link_libraries(ImgEdge ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgGaussianBlur ImgGaussianBlur.cpp)#将程序生成可执行文件
target_link_libraries(ImgGaussianBlur ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgGaussianNoise ImgGaussianNoise.cpp)#将程序生成可执行文件
target_link_libraries(ImgGaussianNoise ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgGetDerivKernels ImgGetDerivKernels.cpp)#将程序生成可执行文件
target_link_libraries(ImgGetDerivKernels ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgLaplacian ImgLaplacian.cpp)#将程序生成可执行文件
target_link_libraries(ImgLaplacian ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgMedianBlur ImgMedianBlur.cpp)#将程序生成可执行文件
target_link_libraries(ImgMedianBlur ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgSaltAndPrpper ImgSaltAndPrpper.cpp)#将程序生成可执行文件
target_link_libraries(ImgSaltAndPrpper ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgScharr ImgScharr.cpp)#将程序生成可执行文件
target_link_libraries(ImgScharr ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgSelfFilter ImgSelfFilter.cpp)#将程序生成可执行文件
target_link_libraries(ImgSelfFilter ${OpenCV_LIBS})#链接 lib 文件到可执行文件中

add_executable(ImgSobel ImgSobel.cpp)#将程序生成可执行文件
target_link_libraries(ImgSobel ${OpenCV_LIBS})#链接 lib 文件到可执行文件中
