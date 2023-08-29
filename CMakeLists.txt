cmake_minimum_required(VERSION 3.12)
project(SFML-Graph-Plotter VERSION 0.0.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(SFML-Graph-Plotter ${SOURCES} main.cpp)

if (UNIX)
    target_link_libraries(SFML-Graph-Plotter 
        X11 Xrandr Xcursor
        sfml-graphics sfml-window sfml-system
    )
elseif (WIN32)
    target_link_libraries(SFML-Graph-Plotter sfml-all)
endif ()

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

target_include_directories(SFML-Graph-Plotter PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )