add_library(scenes game_scene.cpp game_over_scene.cpp  puase_scene.cpp title_scene.cpp)

target_include_directories(scenes PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(scenes PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../player")
target_include_directories(scenes PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../asset_manager")
target_include_directories(scenes PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../utils")