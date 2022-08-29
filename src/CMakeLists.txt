# define library
add_library(${PROJECT_NAME} INTERFACE)

# add mplite
set(header_file BT_Traversal.hpp definitions.hpp architect.hpp dependency_inversion_principle.hpp
    factory.hpp fight_strategy.hpp expression_templates.hpp builder.hpp
    decorator.hpp)
add_subdirectory(${PROJECT_NAME})