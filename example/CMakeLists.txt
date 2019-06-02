cmake_minimum_required(VERSION 3.9)

project(Example)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")

set(CMAKE_BUILD_TYPE Debug)

add_executable(Example 
                bot.cpp)

find_package(dppcord REQUIRED)
find_package(example_plugin REQUIRED)


target_include_directories(Example PRIVATE "../" "../include/" "../submodules/nlohmannjson/single_include/" "../submodules/websocketpp/websocketpp/" "../submodules/curlpp/include/")

target_link_libraries(Example PRIVATE dppcord example_plugin crypto pthread)