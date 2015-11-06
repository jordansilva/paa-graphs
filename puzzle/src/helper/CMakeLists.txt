# Adds a library called util from the source files

file(GLOB helper_SRC
    "*.h"
    "*.hpp"
    "*.cpp"
)

ADD_LIBRARY(helper ${helper_SRC})
target_link_libraries(helper)