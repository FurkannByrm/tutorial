#include "rclcpp/rclcpp.hpp"
#include "variable/msg/info.hpp"

class MyNode: public rclcpp::Node{
public:
    MyNode():Node("cpp_topic_node"){
    publisher_ = this->create_publisher<variable::msg::Info>("info_msg_cpp",10);
    timer_     =this->create_wall_timer(std::chrono::seconds(1), std::bind(&MyNode::publisherCallback,this));
    }

private:
    inline void publisherCallback(){
    variable::msg::Info msg;
    msg.name = "ROS";
    msg.age = 10;
    publisher_->publish(msg);
    }
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<variable::msg::Info>::SharedPtr publisher_;
};
int main(int argc, char ** args){
    rclcpp::init(argc,args);
    rclcpp::spin(std::make_shared<MyNode>());
    rclcpp::shutdown();
}