
cmake_minimum_required(VERSION 3.4.1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#include_directories(${CMAKE_SOURCE_DIR}/include)
#link_directories(${CMAKE_SOURCE_DIR}/libs/armeabi-v7a)

add_library(hello-cpp SHARED
            ndkvideoplayer.cpp
            #emp.cpp
            VideoPlayer.cpp
            VideoPlayer.h
            helpers/EnvHolder.cpp
            helpers/EnvHolder.h
            )

#target_include_directories(hello-cpp PRIVATE
#                            ${CMAKE_SOURCE_DIR}/include)


#set(ffmpeg_DIR ${CMAKE_SOURCE_DIR})
#add_library(avutil-56 SHARED IMPORTED)
#set_target_properties(avutil-56 PROPERTIES IMPORTED_LOCATION ${ffmpeg_DIR}/libs/${ANDROID_ABI}/libavutil-56.so)

#add_library(avcodec-58 SHARED IMPORTED)
#set_target_properties(avcodec-58 PROPERTIES IMPORTED_LOCATION ${ffmpeg_DIR}/libs/${ANDROID_ABI}/libavcodec-58.so)

#add_library(avformat-58 SHARED IMPORTED)
#set_target_properties(avformat-58 PROPERTIES IMPORTED_LOCATION ${ffmpeg_DIR}/libs/${ANDROID_ABI}/libavformat-58.so)

target_link_libraries(hello-cpp
                      android
                      #avutil-56
                      #avformat-58
                      #avcodec-58
                      log)