# include directories
target_include_directories(${PROJECT_NAME}
    INTERFACE 
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/src>
)

# install headers
install(DIRECTORY ${CMAKE_SOURCE_DIR}/src/${solver_name}/${feature_folder} DESTINATION "include"
    FILES_MATCHING 
        PATTERN "*.hpp"
        PATTERN "*.hh"
        PATTERN "*.h"
        PATTERN "test" EXCLUDE
)

# add sources
target_sources(${PROJECT_NAME} 
    INTERFACE
        ${header_file}
)


unset(header_file)