project(Stack_lib)
#set(HEADER_FILE Stack.h)
#set(SOURCE_FILE Stack.cpp)

add_library(stack_src INTERFACE)
target_include_directories(stack_src INTERFACE include/Stack.h)