# define library
add_library(${PROJECT_NAME} INTERFACE)

# add mplite
set(header_file architect.hpp)
add_subdirectory(${PROJECT_NAME})