set(SOURCE_FILES SuzuApp.cpp)

set(HEADER_FILES Suzu.h SuzuApp.h SuzuUtils.h)

add_library(suzu_lib SHARED ${SOURCE_FILES} ${HEADER_FILES})

target_precompile_headers(suzu_lib PRIVATE pch.h)

add_definitions(-DSUZU_LIB)

target_link_libraries(suzu_lib glfw)

include_directories(../glfw/include)