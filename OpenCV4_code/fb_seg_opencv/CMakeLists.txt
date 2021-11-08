cmake_minimum_required(VERSION 3.0)
project(fbsegtest)

find_package(OpenCV 4)
if(NOT OpenCV_FOUND)
    message(FATAL_ERROR "OpenCV 4 not found")
endif()

#target_link_libraries(${PROJECT_NAME}
#        ${OpenCV_LIBS})

add_executable(fbsegtest Source.cpp)
target_link_libraries(fbsegtest ${OpenCV_LIBS})