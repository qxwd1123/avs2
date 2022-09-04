# ##############################################################
# copyright 2016-2016, Jiang GUO, Yimin ZHOU, UESTC           #
# ##############################################################

project(rd)
cmake_minimum_required(VERSION 2.8.12)

set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Build type")
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -fcommon")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -fcommon -fsanitize=address")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fsanitize=address")
set(CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -fsanitize=address")

set(CONFIG_HW ON CACHE BOOL "Enable Haraware")
set(CONFIG_HW_DEQUANT ON CACHE BOOL "Enable Haraware Dequant")

include_directories(lcommon)

if(CONFIG_HW)
    subdirs(lcommon lhardware ldecod)
else()
    subdirs(lcommon ldecod)
endif()
