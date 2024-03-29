set(example_name BT_Traversal_example)
add_gtest_with_libraries(${PROJECT_NAME}_${example_name} ${example_name}.cpp ${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME}_${example_name} PUBLIC ${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME}_${example_name} PUBLIC Eigen3::Eigen)
if(OpenMP_CXX_FOUND)
    target_link_libraries(${PROJECT_NAME}_${example_name} PUBLIC OpenMP::OpenMP_CXX)
endif()


set(example_name dependency_inversion_principle_example)
add_gtest_with_libraries(${PROJECT_NAME}_${example_name} ${example_name}.cpp ${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME}_${example_name} PUBLIC ${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME}_${example_name} PUBLIC Eigen3::Eigen)
if(OpenMP_CXX_FOUND)
    target_link_libraries(${PROJECT_NAME}_${example_name} PUBLIC OpenMP::OpenMP_CXX)
endif()

set(example_name factory_example)
add_gtest_with_libraries(${PROJECT_NAME}_${example_name} ${example_name}.cpp ${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME}_${example_name} PUBLIC ${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME}_${example_name} PUBLIC Eigen3::Eigen)
if(OpenMP_CXX_FOUND)
    target_link_libraries(${PROJECT_NAME}_${example_name} PUBLIC OpenMP::OpenMP_CXX)
endif()

set(example_name expression_templates_example)
add_gtest_with_libraries(${PROJECT_NAME}_${example_name} ${example_name}.cpp ${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME}_${example_name} PUBLIC ${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME}_${example_name} PUBLIC Eigen3::Eigen)
if(OpenMP_CXX_FOUND)
    target_link_libraries(${PROJECT_NAME}_${example_name} PUBLIC OpenMP::OpenMP_CXX)
endif()

set(example_name builder_example)
add_gtest_with_libraries(${PROJECT_NAME}_${example_name} ${example_name}.cpp ${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME}_${example_name} PUBLIC ${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME}_${example_name} PUBLIC Eigen3::Eigen)
if(OpenMP_CXX_FOUND)
    target_link_libraries(${PROJECT_NAME}_${example_name} PUBLIC OpenMP::OpenMP_CXX)
endif()

set(example_name decorator_example)
add_gtest_with_libraries(${PROJECT_NAME}_${example_name} ${example_name}.cpp ${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME}_${example_name} PUBLIC ${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME}_${example_name} PUBLIC Eigen3::Eigen)
if(OpenMP_CXX_FOUND)
    target_link_libraries(${PROJECT_NAME}_${example_name} PUBLIC OpenMP::OpenMP_CXX)
endif()

set(example_name adapter_example)
add_gtest_with_libraries(${PROJECT_NAME}_${example_name} ${example_name}.cpp ${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME}_${example_name} PUBLIC ${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME}_${example_name} PUBLIC Eigen3::Eigen)
if(OpenMP_CXX_FOUND)
    target_link_libraries(${PROJECT_NAME}_${example_name} PUBLIC OpenMP::OpenMP_CXX)
endif()

# set(example_name disjoint_set_example)
# add_gtest_with_libraries(${PROJECT_NAME}_${example_name} ${example_name}.cpp ${PROJECT_NAME})
# target_link_libraries(${PROJECT_NAME}_${example_name} PUBLIC ${PROJECT_NAME})
# target_link_libraries(${PROJECT_NAME}_${example_name} PUBLIC Eigen3::Eigen)
# target_link_libraries(${PROJECT_NAME}_${example_name} PUBLIC vtkio::vtkio)
# if(OpenMP_CXX_FOUND)
#     target_link_libraries(${PROJECT_NAME}_${example_name} PUBLIC OpenMP::OpenMP_CXX)
# endif()

set(example_name visitor_example)
add_gtest_with_libraries(${PROJECT_NAME}_${example_name} ${example_name}.cpp ${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME}_${example_name} PUBLIC ${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME}_${example_name} PUBLIC Eigen3::Eigen)
if(OpenMP_CXX_FOUND)
    target_link_libraries(${PROJECT_NAME}_${example_name} PUBLIC OpenMP::OpenMP_CXX)
endif()

set(example_name singletion_example)
add_gtest_with_libraries(${PROJECT_NAME}_${example_name} ${example_name}.cpp ${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME}_${example_name} PUBLIC ${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME}_${example_name} PUBLIC Eigen3::Eigen)
if(OpenMP_CXX_FOUND)
    target_link_libraries(${PROJECT_NAME}_${example_name} PUBLIC OpenMP::OpenMP_CXX)
endif()

set(example_name prototype_example)
add_gtest_with_libraries(${PROJECT_NAME}_${example_name} ${example_name}.cpp ${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME}_${example_name} PUBLIC ${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME}_${example_name} PUBLIC Eigen3::Eigen)
if(OpenMP_CXX_FOUND)
    target_link_libraries(${PROJECT_NAME}_${example_name} PUBLIC OpenMP::OpenMP_CXX)
endif()

set(example_name mediator_example)
add_gtest_with_libraries(${PROJECT_NAME}_${example_name} ${example_name}.cpp ${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME}_${example_name} PUBLIC ${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME}_${example_name} PUBLIC Eigen3::Eigen)
if(OpenMP_CXX_FOUND)
    target_link_libraries(${PROJECT_NAME}_${example_name} PUBLIC OpenMP::OpenMP_CXX)
endif()

set(example_name state_example)
add_gtest_with_libraries(${PROJECT_NAME}_${example_name} ${example_name}.cpp ${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME}_${example_name} PUBLIC ${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME}_${example_name} PUBLIC Eigen3::Eigen)
if(OpenMP_CXX_FOUND)
    target_link_libraries(${PROJECT_NAME}_${example_name} PUBLIC OpenMP::OpenMP_CXX)
endif()

set(example_name feature_control_example)
add_gtest_with_libraries(${PROJECT_NAME}_${example_name} ${example_name}.cpp ${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME}_${example_name} PUBLIC ${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME}_${example_name} PUBLIC Eigen3::Eigen)
if(OpenMP_CXX_FOUND)
    target_link_libraries(${PROJECT_NAME}_${example_name} PUBLIC OpenMP::OpenMP_CXX)
endif()

set(example_name linklist_example)
add_gtest_with_libraries(${PROJECT_NAME}_${example_name} ${example_name}.cpp ${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME}_${example_name} PUBLIC ${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME}_${example_name} PUBLIC Eigen3::Eigen)
if(OpenMP_CXX_FOUND)
    target_link_libraries(${PROJECT_NAME}_${example_name} PUBLIC OpenMP::OpenMP_CXX)
endif()

set(example_name sort_example)
add_gtest_with_libraries(${PROJECT_NAME}_${example_name} ${example_name}.cpp ${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME}_${example_name} PUBLIC ${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME}_${example_name} PUBLIC Eigen3::Eigen)
if(OpenMP_CXX_FOUND)
    target_link_libraries(${PROJECT_NAME}_${example_name} PUBLIC OpenMP::OpenMP_CXX)
endif()

set(example_name locator_example)
add_gtest_with_libraries(${PROJECT_NAME}_${example_name} ${example_name}.cpp ${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME}_${example_name} PUBLIC ${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME}_${example_name} PUBLIC Eigen3::Eigen)
if(OpenMP_CXX_FOUND)
    target_link_libraries(${PROJECT_NAME}_${example_name} PUBLIC OpenMP::OpenMP_CXX)
endif()

set(example_name solver_builder_example)
add_gtest_with_libraries(${PROJECT_NAME}_${example_name} ${example_name}.cpp ${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME}_${example_name} PUBLIC ${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME}_${example_name} PUBLIC Eigen3::Eigen)
if(OpenMP_CXX_FOUND)
    target_link_libraries(${PROJECT_NAME}_${example_name} PUBLIC OpenMP::OpenMP_CXX)
endif()

set(example_name aspect_oriented_programming)
add_gtest_with_libraries(${PROJECT_NAME}_${example_name} ${example_name}.cpp ${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME}_${example_name} PUBLIC ${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME}_${example_name} PUBLIC Eigen3::Eigen)
if(OpenMP_CXX_FOUND)
    target_link_libraries(${PROJECT_NAME}_${example_name} PUBLIC OpenMP::OpenMP_CXX)
endif()

unset(test_name)