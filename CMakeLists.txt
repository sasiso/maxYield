cmake_minimum_required(VERSION 3.10)
project(FLTK_OpenCV_Project)

find_package(OpenCV REQUIRED)
find_package(FLTK REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS} ${FLTK_INCLUDE_DIRS})

add_executable(fltk_opencv main.cpp)
target_link_libraries(fltk_opencv ${OpenCV_LIBS} ${FLTK_LIBRARIES})
