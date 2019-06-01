cmake_minimum_required(VERSION 3.9)

project(Example)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")

set(CMAKE_BUILD_TYPE Debug)

add_executable(Example 
                bot.cpp)

add_library(dppcord SHARED IMPORTED)

set_target_properties(dppcord PROPERTIES
IMPORTED_LOCATION "/home/lumi/code/cpp/d++cord/bin/libdppcord.so" 
INTERFACE_INCLUDE_DIRECTORIES "/home/lumi/code/cpp/d++cord/include/")
#find_package(dppcord REQUIRED)
#add_library(dppcord SHARED IMPORTED)


target_include_directories(Example PRIVATE "../include/" "../submodules/nlohmannjson/single_include/" "../submodules/websocketpp/websocketpp/" "../submodules/curlpp/include/")

target_link_libraries(Example PRIVATE dppcord crypto pthread)