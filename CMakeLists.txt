cmake_minimum_required(VERSION 3.18)

project(my_game)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

if(WIN32)
	add_definitions(-DSUZU_WINDOWS)
elseif(APPLE)
	add_definitions(-DSUZU_MAC)
elseif(UNIX)
	add_definitions(-DSUZU_LINUX)
endif()

add_definitions(-DSUZU_OPENGL)

add_subdirectory(MyGame)
add_subdirectory(Suzu)
add_subdirectory(glfw)
add_subdirectory(glad)
add_subdirectory(stbi)