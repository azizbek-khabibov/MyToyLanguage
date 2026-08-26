cmake_minimum_required(VERSION 3.15)
project(MyToyLanguage CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create a library target for your Lexer
add_library(Lexer Lexer/Lexer.cpp)

# Make headers in the Lexer directory accessible to the library and dependents
target_include_directories(Lexer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Create the main executable and link the lexer library
add_executable(my_toy_language main.cpp)
target_link_libraries(my_toy_language PRIVATE Lexer)