

# 隐藏警告信息
set(CMAKE_LEGACY_CYGWIN_WIN32 0)

# 指定cmake版本
cmake_minimum_required(VERSION 2.8)

# 项目名称
PROJECT(test_beginer)

# 添加头文件目录
INCLUDE_DIRECTORIES(include)

# 源文件目录
AUX_SOURCE_DIRECTORY(src DIR_SRCS)

# 设置环境变量
SET(
        TEST_MATH ${DIR_SRCS}
)

# 添加要编译的可执行文件
ADD_EXECUTABLE(${PROJECT_NAME} ${TEST_MATH})

# 添加链接目录
TARGET_LINK_LIBRARIES(${PROJECT_NAME} m)