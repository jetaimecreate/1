cmake_minimum_required(VERSION 3.0)
project(VideoPlayer)

# Find OpenCV package
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

# Add executable target
add_executable(video_player main.cpp)

# Link OpenCV libraries to the executable
target_link_libraries(video_player ${OpenCV_LIBS})
