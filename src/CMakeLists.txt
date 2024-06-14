file(GLOB_RECURSE SRC_FILES "${CMAKE_SOURCE_DIR}/src/*.cpp")
add_executable("${PROJECT_NAME}" main.cpp ${SRC_FILES})


target_link_directories("${PROJECT_NAME}" PRIVATE "${CMAKE_SOURCE_DIR}/vendor/raylib/lib")
target_link_directories("${PROJECT_NAME}" PRIVATE "${CMAKE_SOURCE_DIR}/vendor/jsoncpp/lib")
target_link_libraries(${PROJECT_NAME} PUBLIC raylib jsoncpp)
