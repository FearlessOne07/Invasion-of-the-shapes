add_library(enemy_manager enemy_manager.cpp)

target_include_directories(enemy_manager PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(enemy_manager PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../spawner")
target_include_directories(enemy_manager PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../enemy")
target_include_directories(enemy_manager PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../utils")
target_include_directories(enemy_manager PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../player")
target_include_directories(enemy_manager PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../bullet_manager/")