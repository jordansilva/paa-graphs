# Adds a library called util from the source files

file(GLOB domain_SRC
    "*.h"
    "*.hpp"
    "*.cpp"
)

ADD_LIBRARY(domain ${domain_SRC})
target_link_libraries(domain)