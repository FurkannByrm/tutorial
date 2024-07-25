cmake_minimum_required(VERSION 3.8)
project(cpp_parameters)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

add_executable(mini_param_node src/cpp_parameters.cpp)
# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(ament_lint_auto REQUIRED)

ament_target_dependencies(mini_param_node rclcpp)
install(TARGETS
    mini_param_node
  DESTINATION lib/${PROJECT_NAME}
)
install(
  DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}
)

ament_package()
