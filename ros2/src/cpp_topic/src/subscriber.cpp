#include "cpp_topic/my_subscriber.hpp"


SubNode::SubNode(): Node("subscriber_node"){

    using namespace std::placeholders;
    RCLCPP_DEBUG(this->get_logger(),"subscription has been started");
    sub_int    = this->create_subscription<std_msgs::msg::Int16>("cpp_topic_int", 10, std::bind(&SubNode::subCallbackInt, this,_1));
    sub_string = this->create_subscription<std_msgs::msg::String>("cpp_topic_string",10, std::bind(&SubNode::subCallbackString, this, _1));

}
SubNode::~SubNode(){
    RCLCPP_DEBUG(this->get_logger(),"Subscriber terminated");
}
void SubNode::subCallbackInt(const std_msgs::msg::Int16 msg){
    RCLCPP_INFO(this->get_logger(),"int: %d", msg.data);
}
void SubNode::subCallbackString(const std_msgs::msg::String msg){
    RCLCPP_INFO(this->get_logger(),"string: %s",msg.data.c_str());
}
int main(int argc, char ** args){

    rclcpp::init(argc,args);
    rclcpp::spin(std::make_shared<SubNode>());
    rclcpp::shutdown();
}
