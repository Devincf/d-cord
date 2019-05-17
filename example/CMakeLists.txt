cmake_minimum_required(VERSION 3.9)

project(Example)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")

set(CMAKE_BUILD_TYPE Debug)


find_package(Boost 1.55.0 REQUIRED COMPONENTS thread system filesystem)
include_directories(... ${Boost_INCLUDE_DIRS})
link_directories(... ${Boost_LIBRARY_DIRS})

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)


add_executable(Example 
                bot.cpp)


add_library(dppcord SHARED IMPORTED)
set_target_properties(dppcord PROPERTIES
IMPORTED_LOCATION "/home/lumi/code/cpp/d++cord/bin/libdppcord.so" 
INTERFACE_INCLUDE_DIRECTORIES "/home/lumi/code/cpp/d++cord/include/")



target_include_directories(Example PRIVATE "../include/" "../submodules/nlohmannjson/single_include/" "../submodules/websocketpp/websocketpp/" "../submodules/curlpp/include/")

target_link_libraries(Example dppcord Threads::Threads crypto ssl curl curlpp sqlite3 stdc++fs Boost::thread)