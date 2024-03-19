cmake_minimum_required(VERSION 3.12)
project(Invasion-of-the-Shapes)

include_directories(
    "${CMAKE_CURRENT_SOURCE_DIR}/vendor/jsoncpp/include",
    "${CMAKE_CURRENT_SOURCE_DIR}/vendor/raylib/include",
)

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/src")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/out")



