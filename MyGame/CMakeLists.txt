add_executable(my_game main.cpp MyGameApp.h MyGameApp.cpp Unit.h Unit.cpp Monster.cpp Monster.h)

target_link_libraries(my_game suzu_lib)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/.. PROPERTY VS_STARTUP_PROJECT my_game)

include_directories(../Suzu)

if(WIN32)
file(COPY Assets DESTINATION .)
file(COPY Assets DESTINATION ${CMAKE_BINARY_DIR}/Debug/)
file(COPY Assets DESTINATION ${CMAKE_BINARY_DIR}/Release/)
else()
file(COPY Assets DESTINATION ${CMAKE_BINARY_DIR})
endif()
