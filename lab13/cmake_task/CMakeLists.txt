cmake_minimum_required(VERSION 3.10)

project(second_cmake)



add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/pipes)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/background)

add_executable(main src/main.c)

target_link_libraries(main PRIVATE background_lib pipes_lib)

