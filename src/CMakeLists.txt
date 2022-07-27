# define library
add_library(${PROJECT_NAME} INTERFACE)

# add mplite
set(header_file BT_Traversal.hpp definitions.hpp architect.hpp)
add_subdirectory(${PROJECT_NAME})