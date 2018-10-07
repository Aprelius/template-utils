cmake_minimum_required(VERSION 3.2)

# Project directories
set(PROJECT_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Define the project name
project(TemplateUtils
    LANGUAGES CXX
    VERSION 0.1.0)

# Declare the Library
add_library(TemplateUtils INTERFACE)

# Set the target include path
target_include_directories(TemplateUtils
    INTERFACE ${PROJECT_INCLUDE_DIR})
