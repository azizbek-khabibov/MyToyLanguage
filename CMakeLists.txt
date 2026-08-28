cmake_minimum_required(VERSION 3.15)
project(MyToyLanguage C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. Find the LLVM package installed on your system
find_package(LLVM REQUIRED CONFIG)

include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

# 2. Create a library target for your Parser module
add_library(Parser Parser/Parser.cpp)

# 3. Make the current source directory accessible for headers
target_include_directories(Parser PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# 4. Create the main executable using root-level main.cpp
add_executable(my_toy_language main.cpp)

# 5. Map the necessary LLVM components for code generation and JIT execution
llvm_map_components_to_libnames(llvm_libs core native orcjit support)

# 6. Link BOTH your Parser library AND the LLVM libraries to your executable
target_link_libraries(my_toy_language PRIVATE Parser ${llvm_libs})