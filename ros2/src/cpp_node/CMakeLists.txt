cmake_minimum_required(VERSION 3.8)
project(cpp_node)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(rclcpp_lifecycle REQUIRED)
find_package(rmw_implementation_cmake REQUIRED)

include_directories(
  ${rclcpp_INCLUDE_DIRS}
  ${rclcpp_lifecycle_INCLUDE_DIRS}
  ${std_msgs_INCLUDE_DIRS}
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_executable(my_node src/my_node.cpp)
add_executable(simple_lifecycle_node src/simple_lifecycle_node.cpp)
add_executable(my_oop_node src/my_oop_node.cpp)

ament_target_dependencies(my_node rclcpp)
ament_target_dependencies(simple_lifecycle_node rclcpp std_msgs rclcpp_lifecycle)
ament_target_dependencies(my_oop_node rclcpp)

install(TARGETS
  my_node
  simple_lifecycle_node
  my_oop_node
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
