project(Stack_lib)
set(HEADER_FILE include/Stack.h)

add_library(stack_src INTERFACE)
target_include_directories(stack_src INTERFACE ${HEADER_FILE})

add_subdirectory(test/googletest)

add_executable(stack_test test/test.cpp)

target_link_libraries(stack_test stack_src)
target_link_libraries(stack_test gtest gtest_main)