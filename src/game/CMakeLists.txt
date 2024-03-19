add_library(game game.cpp)

target_include_directories(game PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(game PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../scenes")
target_include_directories(game PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../config")
target_include_directories(game PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../utils")