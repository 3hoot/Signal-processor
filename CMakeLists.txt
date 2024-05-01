cmake_minimum_required(VERSION 3.14)
project(Signal_processor)

# For pybind11
add_subdirectory(extern/pybind11)

# For matplot++
add_subdirectory(extern/matplotplusplus)

# Add the signal processor module
pybind11_add_module(Signal_processor source/signal_processor.cpp)

# Link against Matplot++
target_link_libraries(Signal_processor PRIVATE Matplot++::matplot)
