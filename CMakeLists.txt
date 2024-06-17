cmake_minimum_required(VERSION 3.10)

# Define the project name
project(shopping_list)

# Include directories
include_directories(includes)

file(GLOB SRC "src/*.cpp")

# Add the sources
set(SOURCES
    ${SRC}
    principal/main.cpp
)

# Add the executable
add_executable(lista_de_compra ${SOURCES})