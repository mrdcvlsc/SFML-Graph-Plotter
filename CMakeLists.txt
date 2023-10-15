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