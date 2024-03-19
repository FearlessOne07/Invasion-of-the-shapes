add_library(enemy shooter/shooter.cpp runner/runner.cpp)

target_include_directories(enemy PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(enemy PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/shooter")
target_include_directories(enemy PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/runner")
target_include_directories(enemy PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../player")
target_include_directories(enemy PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../utils")