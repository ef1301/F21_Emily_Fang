if(UNIX)
add_definitions(-fpic)
endif()
add_library(stbi STATIC stb_image.cpp stb_image.h)

