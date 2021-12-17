set(SOURCE_FILES 
	SuzuApp.cpp 
	SuzuWindow.cpp 
	GLFWimpl/GlfwImplementation.cpp
	Renderer.cpp
	Shader.cpp
	Sprite.cpp
	Events.cpp
	OpenGLimpl/OpenGLRenderer.cpp
	OpenGLimpl/OpenGLShader.cpp
	OpenGLimpl/OpenGLSprite.cpp
)

set(HEADER_FILES 
	Suzu.h 
	SuzuApp.h 
	SuzuUtils.h 
	WindowImplementation.h 
	SuzuWindow.h 
	GLFWimpl/GlfwImplementation.h
	Renderer.h
	RendererImplementation.h
	Shader.h
	ShaderImplementation.h
	Sprite.h
	SpriteImplementation.h
	Events.h
	OpenGLimpl/OpenGLRenderer.h
	OpenGLimpl/OpenGLShader.h
	OpenGLimpl/OpenGLSprite.h
)

add_library(suzu_lib SHARED ${SOURCE_FILES} ${HEADER_FILES})

target_precompile_headers(suzu_lib PRIVATE pch.h)

add_definitions(-DSUZU_LIB)

target_link_libraries(suzu_lib glfw glad stbi)

include_directories(../glfw/include)
include_directories(../Suzu)
include_directoried(../glad/include)
include_directories(../stbi)