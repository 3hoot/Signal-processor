cmake_minimum_required(VERSION 3.14)
project(Signals)

set (SOURCES
    source/signal.cpp
    source/plot.cpp
    source/noise.cpp
)

# Dependencies
add_subdirectory(extern/pybind11)   # For pybind11
add_subdirectory(extern/matplotplusplus)    # For matplot++
include_directories(${CMAKE_SOURCE_DIR}/headers)    # For headers

# Add the signal processor module
pybind11_add_module(signal ${SOURCES})

# Link against Matplot++
target_link_libraries(signal PRIVATE Matplot++::matplot)
