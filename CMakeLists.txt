# declare cmake version
cmake_minimum_required (VERSION 3.15)

# set main project infomation
project (architect VERSION 0.0.1 LANGUAGES CXX)

# add module search path
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/tools/cmake)

# import utilities
include(utilities)

# set global cxx standard as C++14
set_global_cxx_standard(14)

# set global windows export all symbols
set_global_windows_export_all_symbols()

# set global build output name same as install
set_global_build_output_name_same_as_install()

# set global rpath
set_global_rpath()

# set global tools
include_directories(${CMAKE_SOURCE_DIR}/tools)

#----------------------------------------------------------------------------
# Find googletest
#----------------------------------------------------------------------------
find_googletest()

#----------------------------------------------------------------------------
# Find OpenMP
#----------------------------------------------------------------------------
find_package(OpenMP)

#----------------------------------------------------------------------------
# Find Eigen3
#----------------------------------------------------------------------------
find_package(Eigen3)


#----------------------------------------------------------------------------
# set debug mode 
#----------------------------------------------------------------------------
if(${CMAKE_BUILD_TYPE} MATCHES "Debug")
    add_definitions(-D_DEBUG)
endif()

#----------------------------------------------------------------------------
# add source
#----------------------------------------------------------------------------
add_subdirectory(src)

#----------------------------------------------------------------------------
# add tests
# ----------------------------------------------------------------------------
add_subdirectory(tests)

#----------------------------------------------------------------------------
# Build examples
#----------------------------------------------------------------------------
add_subdirectory(examples)
