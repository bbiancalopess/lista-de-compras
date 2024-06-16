cmake_minimum_required(VERSION 3.10)

# Define the project name
project(shopping_list)

# Include directories
include_directories(includes)

# Add the sources
set(SOURCES
    src/Item.cpp
    src/PerishableItem.cpp
    src/ShoppingList.cpp
    src/System.cpp
    src/main.cpp
)

# Add the executable
add_executable(shopping_list ${SOURCES})