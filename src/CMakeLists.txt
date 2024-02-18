project(Stack_lib)
set(HEADER_FILE include/Stack.h)
set(SOURCE_FILE Stack.cpp)

add_library(stack_src ${HEADER_FILE} ${SOURCE_FILE})