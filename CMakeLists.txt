cmake_minimum_required(VERSION 3.14)
project(Signal_Processor)

# For matoplotlib
add_subdirectory(matplotplusplus)

set(SOURCES
    source/main.cpp
)

set(HEADERS
   
)

set(LIBRARIES
   matplot
)

# Set the executable
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Include the headers directory
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/headers)

# Link any libraries
target_link_libraries(${PROJECT_NAME} ${LIBRARIES})
