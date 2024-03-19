add_library(player player.cpp)

target_include_directories(player PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(player PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../asset_manager")
target_include_directories(player PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../config")