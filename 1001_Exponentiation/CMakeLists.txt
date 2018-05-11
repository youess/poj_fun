cmake_minimum_required(VERSION 3.10)
project(1001_Exponentiation)

set(CMAKE_CXX_STANDARD 11)


# 源文件目录
AUX_SOURCE_DIRECTORY(src DIR_SRCS)

# 添加要编译的可执行文件
ADD_EXECUTABLE(${PROJECT_NAME} ${DIR_SRCS})

# add_executable(1001_Exponentiation main.cpp)