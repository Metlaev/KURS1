# Задание: Создать библиотеку из background.c и слинковать ее с библиотекой pipes
include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/../pipes)
set(SOURCES background.c)
add_library(background_lib STATIC ${SOURCES})

target_include_directories(background_lib PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(background_lib PRIVATE pipes_lib)