cmake_minimum_required(VERSION 3.0)
project(rotate_image_opencv)

# 设置 OpenCV 路径（根据你的安装路径进行修改）
set(OpenCV_DIR /home/zqm/opencv)

# 查找 OpenCV 库
find_package(OpenCV REQUIRED)

# 添加可执行文件
add_executable(rotate_image main.cpp)

# 链接 OpenCV 库
target_link_libraries(rotate_image ${OpenCV_LIBS})
