cmake_minimum_required(VERSION 3.10)

project(myproject)

set(CMAKE_CXX_STANDARD 20)

include_directories(${PROJECT_SOURCE_DIR}/include/${PROJECT_NAME})

# 添加地址消毒选项
# 需要注意的是，使用 ASan 工具会增加程序的运行时间和内存消耗，
# 因此应该谨慎使用，并在测试环境下进行测试。
# 此外，如果使用了其他的编译选项或调试器，
# 可能会与 ASan 工具产生冲突，导致程序无法正常运行
# TODO: 判断是测试环境还是生产环境
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")

# 动态添加源文件
# 需要注意的是，使用 file(GLOB ...) 命令可以方便地添加文件，
# 但也存在一些潜在的问题。例如，如果在添加文件之后，
# 修改了文件的名称或删除了文件，可能会导致编译错误或运行时错误。
# 因此，建议在添加文件时，尽量避免使用通配符，而是明确指定要添加的文件。
# 如果必须使用通配符，也应该在修改或删除文件时，及时更新 CMake 文件的设置。
aux_source_directory(${CMAKE_SOURCE_DIR}/src SOURCES)
set(MAIN_FILE ${PROJECT_SOURCE_DIR}/src/cli/main.cpp)

add_executable(${PROJECT_NAME} ${MAIN_FILE} ${SOURCES})

# 最好使用下面的方案，但是上面的方案加文件不不需要
# add_executable(${PROJECT_NAME} 
#     src/main.cpp 
#     src/MyClass.cpp
# )