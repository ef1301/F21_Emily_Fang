include_directories(include)
if(UNIX)
add_definitions(-fpic)
endif()
add_library(glad STATIC src/glad.c include/glad/glad.h)

