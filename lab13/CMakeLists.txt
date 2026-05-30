cmake_minimum_required(VERSION 3.10)

project(first_cmake)

option(BUILD_SHARED_LIBS "Build shared libraries" ON)
option(BUILD_STATIC_LIBS "Build static libraries" OFF)

set(APP_DIR ${CMAKE_CURRENT_SOURCE_DIR}/app)
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(SOURCES ${SOURCE_DIR}/function.c)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(main ${APP_DIR}/main.c ${SOURCES})

if(BUILD_SHARED_LIBS AND NOT BUILD_STATIC_LIBS)
    add_library(UTIL_LIB SHARED ${SOURCES})
    target_link_libraries(main UTIL_LIB)
    message(STATUS "Building shared library: libUTIL_LIB.so")
elseif(BUILD_STATIC_LIBS AND NOT BUILD_SHARED_LIBS)
    add_library(UTIL_LIB STATIC ${SOURCES})
    target_link_libraries(main UTIL_LIB)
    message(STATUS "Building static library: libUTIL_LIB.a")
endif()