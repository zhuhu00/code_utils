# CMake 最低版本号要求
cmake_minimum_required( VERSION 2.8 )

# 项目名称
project( threadDemo )

# 设置编译方式
set( CMAKE_BUILD_TYPE Release )

#支持C++11
set( CMAKE_CXX_FLAGS "-std=c++11" )

find_package(Threads)

# 用指定的源文件为工程添加可执行文件
add_executable( hello_thread ${PROJECT_SOURCE_DIR}/src/test1.cpp )

add_executable( data_share ${PROJECT_SOURCE_DIR}/src/test2.cpp )

add_executable( mutex ${PROJECT_SOURCE_DIR}/src/test3.cpp )

add_executable( deadlock ${PROJECT_SOURCE_DIR}/src/test4.cpp )
target_link_libraries(hello_thread ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(data_share ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(mutex ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(deadlock ${CMAKE_THREAD_LIBS_INIT})


