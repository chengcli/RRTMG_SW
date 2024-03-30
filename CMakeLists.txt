# Installs RRTMG_SW library
#   
#   library: librrtmg_sw_debug.a
#   library: librrtmg_sw_release.a
#
# Define the following variables
#
#   RRTMG_SW_INCLUDE_DIR
#   RRTMG_SW_LIBRARY_DEBUG
#   RRTMG_SW_LIBRARY_RELEASE
#
# Normal usage would be
#
#   include_directories( ${RRTMG_SW_INCLUDE_DIR})
#   target_link_libraries( ${RRTMG_SW_LIBRARY_DEBUG})
#
cmake_minimum_required(VERSION 3.20)

project(
  RRTMG_SW
  LANGUAGES CXX Fortran
  )

if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
  message(STATUS "Default Build Type = Release")
  message(STATUS "")
else()
  message(STATUS "Build Type = ${CMAKE_BUILD_TYPE}")
  message(STATUS "")
endif()

LIST(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules/)

## 1. set up compiler flags ##
message(STATUS "1. Set up project compiler flags ...")
message(STATUS "Include ${CMAKE_SOURCE_DIR}/cmake/compilers.cmake")
include(${CMAKE_SOURCE_DIR}/cmake/compilers.cmake)

## 2. set up project specific configuration ##
message(STATUS "2. Set up project specific configuration ...")
set(NETCDF_F90 "YES")
find_package(NetCDF REQUIRED COMPONENTS F90)

message(STATUS "Set up rrtmg_sw source codes")
add_subdirectory(modules)
add_subdirectory(src)
add_subdirectory(interface)

set(RRTMG_SW_INCLUDE_DIR
  "${CMAKE_CURRENT_SOURCE_DIR}"
  CACHE INTERNAL "rrtmg_sw include directory")

add_subdirectory(tests)

