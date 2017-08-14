cmake_minimum_required(VERSION 2.8)

project(infraredimage-processing)

set(CMAKE_BUILD_TYPE "${CMAKE_BUILD_TYPE} -std=Release")

include(CheckCXXCompilerFlag)

CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)

if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
    message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()

FILE(GLOB sourcefiles "*.cpp" "*.c")

add_executable(infraredimage-processing ${sourcefiles})

# library
IF(WIN32)
# Windows平台执行
INCLUDE($ENV{OPENCV_2413_PREBUILD_DIR}/OpenCVConfig.cmake)
message( STATUS "OpenCV library status:" )              # 输出一下得到的变量
message( STATUS "version: ${OpenCV_VERSION}" )
message( STATUS "libraries: ${OpenCV_LIBS}" )
message( STATUS "include path: ${OpenCV_INCLUDE_DIRS}" )

INCLUDE_DIRECTORIES(${OpenCV_INCLUDE_DIRS})

ELSEIF(UNIX)
# Linux平台执行

FIND_PACKAGE(OpenCV 2 REQUIRED)
# INCLUDE(/usr/local/share/OpenCV/OpenCVConfig.cmake)

message( STATUS "OpenCV library status:" )              # 输出一下得到的变量
message( STATUS "version: ${OpenCV_VERSION}" )
message( STATUS "libraries: ${OpenCV_LIBS}" )
message( STATUS "include path: ${OpenCV_INCLUDE_DIRS}")

INCLUDE_DIRECTORIES(${OpenCV_INCLUDE_DIRS})
ENDIF(WIN32)

target_link_libraries(infraredimage-processing ${OpenCV_LIBS})