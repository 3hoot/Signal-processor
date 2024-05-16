cmake_minimum_required(VERSION 3.14)
project(Signals)

set (PYTHON_LIB_NAME signal_processing)

set (SOURCES
    source/signal.cpp
)

# Dependencies
add_subdirectory(extern/pybind11)   # For pybind11
add_subdirectory(extern/matplotplusplus)    # For matplot++
include_directories(${CMAKE_SOURCE_DIR}/headers)    # For headers

# Add the signal processor module
pybind11_add_module(${PYTHON_LIB_NAME} ${SOURCES})

# Link against Matplot++
target_link_libraries(${PYTHON_LIB_NAME} PRIVATE Matplot++::matplot)
