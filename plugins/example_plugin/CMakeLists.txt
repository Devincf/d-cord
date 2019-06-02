cmake_minimum_required(VERSION 3.9)

project(example_plugin VERSION 1.0.0 DESCRIPTION "First Plugin")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")


set(CMAKE_BUILD_TYPE Debug)


add_library(example_plugin SHARED
plugin.cpp
)

set_target_properties(example_plugin PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(example_plugin PROPERTIES SOVERSION 1)


target_include_directories(example_plugin PRIVATE "../../include/" )



export(PACKAGE example_plugin)

include(GNUInstallDirs)

install(TARGETS example_plugin 
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}/bin/
        PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/include/)

