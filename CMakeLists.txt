cmake_minimum_required(VERSION 3.12)


project(Invasion-of-the-Shapes)

include_directories(
    "${CMAKE_CURRENT_SOURCE_DIR}/vendor/jsoncpp/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/vendor/raylib/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
)


set(BUILD_TYPE "R" CACHE STRING "Build type (Debug or Release)")

if(BUILD_TYPE STREQUAL "D")
  message("Building Debug")
  set(CMAKE_BUILD_TYPE "Debug")
else()
  set(CMAKE_BUILD_TYPE "Release")
  message("Building Release")
endif()

set(CMAKE_CXX_COMPILER_ID "Clang")
set(CMAKE_GENERATOR_TOOLSET "Makefile")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/src")



