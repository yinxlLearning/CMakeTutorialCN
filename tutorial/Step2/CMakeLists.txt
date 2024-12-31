cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(Tutorial VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 为什么option需要放置在configure_file前边
# configure_file命令通常会使用CMake变量来生成配置文件。如果这些变量是由option命令定义的，
# 那么在调用configure_file之前必须先定义这些变量，否则configure_file命令将无法正确替换这些变量的值
option(USE_MYMATH "Use tutorial provided math implementation" ON)

# 将版本号传递到源码中
# 在构建目录中生成了TutorialConfig.h文件，这个文件包含了TutorialConfig.h.in中的内容，并且替换了@后面的内容
configure_file(TutorialConfig.h.in TutorialConfig.h)

if(USE_MYMATH)
    # 用于添加一个子项目，他有两个参数
    # 第一个参数是子项目的路径
    # 第二个参数是子项目的二进制目录,即构建输出目录。如果未指定，CMake 将使用 source_dir 作为构建输出目录。
    add_subdirectory(MathFunctions)

    # list用来设置列表参数
    list(APPEND EXTRA_LIBS MathFunctions)

    list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/MathFunctions")
endif(USE_MYMATH)

# add the executable
add_executable(Tutorial tutorial.cxx)

# 打印内容为构建目录
# PROJECT_BINARY_DIR: D:/codes/cxx/CMakeTutorialCN/tutorial/Step2/build
message(STATUS "PROJECT_BINARY_DIR: ${PROJECT_BINARY_DIR}")

message(STATUS "EXTRA_LIBS: ${EXTRA_LIBS}")

message(STATUS "EXTRA_INCLUDES: ${EXTRA_INCLUDES}")

# 用于指定目标程序需要链接的库。这里指定了Tutorial需要链接MathFunctions库
target_link_libraries(Tutorial PUBLIC ${EXTRA_LIBS})

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
# 将二进制树添加到搜索路径中，以便我们找到TutorialConfig.h
# PROJECT_BINARY_DIR 指定了构建目录的路径，这个目录是cmake用来存放生成的构建文件以及编译输出文件的地方。
target_include_directories(Tutorial PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           "${EXTRA_INCLUDES}"
                           )
