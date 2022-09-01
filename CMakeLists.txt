###############################################################
# copyright 2016-2016, Jiang GUO, Yimin ZHOU, UESTC           #
###############################################################

project(rd)
cmake_minimum_required(VERSION 2.8.12)

include_directories(lcommon)
subdirs(lcommon ldecod)

set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Build type")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -fcommon -fsanitize=address")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fsanitize=address")
set(CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -fsanitize=address")
