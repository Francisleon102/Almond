cmake_minimum_required(VERSION 3.10)
project(test_opencv VERSION 1.0 LANGUAGES CXX)

# Set C++ standard and compiler warnings
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options(-Wall)

# Find OpenCV
find_package(OpenCV REQUIRED)

# Include OpenCV headers
include_directories(${OpenCV_INCLUDE_DIRS})

# Define source files
set(SRC_FILES
    main.cpp
    # Add other source files here if needed, e.g., edges.cpp
)

# Create executable
add_executable(${PROJECT_NAME} ${SRC_FILES})

# Link OpenCV libraries
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})

# Ensure RPATH points to the system lib directory so it picks up the correct libpthread
set_target_properties(${PROJECT_NAME} PROPERTIES
    INSTALL_RPATH "/lib/x86_64-linux-gnu"
    BUILD_RPATH   "/lib/x86_64-linux-gnu"
)

# Add a convenient 'run' target
# Add a convenient 'run' target
add_custom_target(run
    COMMAND ${CMAKE_COMMAND} -E echo "Running ${PROJECT_NAME} with LD_PRELOAD..."
    COMMAND env LD_PRELOAD=/lib/x86_64-linux-gnu/libpthread.so.0 ./test_opencv
    DEPENDS ${PROJECT_NAME}
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)