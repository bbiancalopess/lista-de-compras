cmake_minimum_required(VERSION 3.10)

# Define the project name
project(shopping_list_tests)

# Include directories
include_directories(../includes)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

file(GLOB SRC "../src/*.cpp")

# Add the sources
set(SOURCES
    ${SRC}
    test.cpp
    Item.test.cpp
    ShoppingList.test.cpp
    csv.test.cpp
)

# Add the executable
add_executable(shopping_list_tests ${SOURCES})