#include "my_publisher.hpp"

PubNode::PubNode(): Node("publisher_node"), count_(0){
RCLCPP_DEBUG(this->get_logger(),"Publisher has been started.");
pub_int    = this->create_publisher<std_msgs::msg::Int16>("cpp _topic_int",10);
pub_string = this->create_publisher<std_msgs::msg::String>("cpp_tpic_string",10);
timer_     = this->create_wall_timer(std::chrono::seconds(1), std::bind(&PubNode::pubCallbackInt, this));


} 
PubNode::~PubNode(){
    RCLCPP_DEBUG(this->get_logger(), "subscriber terminated...");
}
