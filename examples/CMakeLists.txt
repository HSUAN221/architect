set(example_name beginner_example)
add_gtest_with_libraries(${PROJECT_NAME}_${example_name} ${example_name}.cpp ${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME}_${example_name} PUBLIC ${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME}_${example_name} PUBLIC Eigen3::Eigen)
if(OpenMP_CXX_FOUND)
    target_link_libraries(${PROJECT_NAME}_${example_name} PUBLIC OpenMP::OpenMP_CXX)
endif()

unset(test_name)