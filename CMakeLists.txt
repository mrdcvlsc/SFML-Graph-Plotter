# cmake_minimum_required(VERSION 3.12)
# project(SFML-Graph-Plotter VERSION 1.0)

# set(CMAKE_CXX_STANDARD 20)
# # set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

# include_directories(include)
# include_directories(SFML-2.6.0/include)

# file(GLOB SOURCES "src/*.cpp")

# add_executable(SFML-Graph-Plotter ${SOURCES} main.cpp)

# if (UNIX)
#     target_link_libraries(SFML-Graph-Plotter 
#         X11 Xrandr Xcursor
#         sfml-graphics sfml-window sfml-system
#     )
# elseif (WIN32)
#     target_link_libraries(SFML-Graph-Plotter sfml-main)
# endif ()

# set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

# target_include_directories(SFML-Graph-Plotter PUBLIC
#                            "${PROJECT_BINARY_DIR}"
#                            )

cmake_minimum_required(VERSION 3.21)
project(SFML-Graph-Plotter LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

include_directories(include)
include_directories(SFML-2.6.0/include)

file(GLOB SOURCES "src/*.cpp")

add_executable(SFML-Graph-Plotter ${SOURCES} main.cpp)

target_link_libraries(SFML-Graph-Plotter PRIVATE sfml-graphics sfml-window)

target_compile_features(SFML-Graph-Plotter PRIVATE cxx_std_17)

if (WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(TARGET SFML-Graph-Plotter POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:SFML-Graph-Plotter> $<TARGET_FILE_DIR:SFML-Graph-Plotter> COMMAND_EXPAND_LISTS)
endif()

# install(TARGETS SFML-Graph-Plotter)