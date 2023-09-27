cmake_minimum_required(VERSION 3.5)

project(Fibonacci LANGUAGES C)

add_executable(Fibonacci main.c)

install(TARGETS Fibonacci
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
