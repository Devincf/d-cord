cmake_minimum_required(VERSION 3.9)

project(dppmoney VERSION 1.0.0 DESCRIPTION "System for virtual money management within d++cord")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")


set(CMAKE_BUILD_TYPE Debug)


add_library(dppmoney SHARED
plugin.cpp
)

set_target_properties(dppmoney PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(dppmoney PROPERTIES SOVERSION 1)


target_include_directories(dppmoney PRIVATE "../../include/" "../../submodules/nlohmannjson/single_include")

export(PACKAGE dppmoney)

include(GNUInstallDirs)

install(TARGETS dppmoney 
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}/bin/
        PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/include/)

