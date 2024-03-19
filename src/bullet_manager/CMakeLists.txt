add_library(bullet_manager bullet_manager.cpp)
target_include_directories(bullet_manager PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(bullet_manager PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../utils")
target_include_directories(bullet_manager PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../asset_manager")