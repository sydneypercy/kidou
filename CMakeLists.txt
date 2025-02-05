cmake_minimum_required(VERSION 3.14) # FetchContent is available in 3.11+
project(kidouki)

find_package(raylib 4.0.0 QUIET)
if (NOT raylib_FOUND)
  include(FetchContent)
  FetchContent_Declare(
    raylib
    URL https://github.com/raysan5/raylib/archive/refs/tags/4.0.0.tar.gz
  )
  FetchContent_MakeAvailable(raylib)
endif()

add_executable(${PROJECT_NAME} main.cpp)
#set(raylib_VERBOSE 1)
add_dependencies(${PROJECT_NAME} raylib)
# Uncomment to include extra libraries
#target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/_deps/raylib-src/src/extras)
target_link_libraries(${PROJECT_NAME} raylib)
if (NOT WIN32) # libm doesn't exist on Windows land :(
    target_link_libraries(${PROJECT_NAME} m)
endif()

if (APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif()
