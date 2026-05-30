# Задание: Создать библиотеку pipes из read_pipe.c write_pipe.c
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
set(SOURCES read_pipe.c write_pipe.c)

add_library(pipes_lib STATIC ${SOURCES})