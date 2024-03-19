add_library(spawner spawner.cpp)

target_include_directories(spawner PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(spawner PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/../enemy_manager")
target_include_directories(spawner PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/../enemy")