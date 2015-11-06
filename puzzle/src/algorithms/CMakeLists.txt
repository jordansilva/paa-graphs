# Adds a library called common from the source files
file(GLOB algorithms_SRC
    "*.h"
    "*.cpp"
)


ADD_LIBRARY( algorithms ${algorithms_SRC})
target_link_libraries(algorithms domain helper)