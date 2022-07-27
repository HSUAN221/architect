# define library
add_library(${PROJECT_NAME} INTERFACE)

# add mplite
set(header_file binary_tree.hpp definitions.hpp architect.hpp)
add_subdirectory(${PROJECT_NAME})