cmake_minimum_required(VERSION 3.8)
project(Stack_project)
set(CMAKE_CXX_STANDARD 20)
set(SOURCE_FILES main.cpp emulator.cpp preprocessor.cpp emulator.h preprocessor.h commands.h parser.h parser.cpp enum_commands.h)

add_executable(stack_run ${SOURCE_FILES})

include_directories(stack_lib)
add_subdirectory(stack_lib)
target_link_libraries(stack_run PRIVATE stack_src)