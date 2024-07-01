#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/string.hpp"

constexpr auto FREQ = 10;
class MyNode: public rclcpp::Node{
    
public:
    MyNode():Node("cpp_talker_node"){
        this->declare_parameter("cpp_class_name",2);
        this->declare_parameter("freq_pub",FREQ);
        frequency = this->get_parameter("freq_pub").as_int();
        rclcpp::Parameter number_ = this->get_parameter("cpp_class_name");
        RCLCPP_INFO(this->get_logger()," %ld) Talker started.. ", number_.as_int());
        publisher_ = this->create_publisher<example_interfaces::msg::String>("cpp_test_counter",10);
        timer_= this->create_wall_timer(std::chrono::microseconds((int)(10000.0/frequency)),std::bind(&MyNode::publisherCallback,this));

    }
private:

    void publisherCallback(){
        RCLCPP_INFO(this->get_logger(), "hello");
        example_interfaces::msg::String msg;
        msg.data = std::string("HEllo");
        publisher_->publish(msg);
    }
    int frequency;
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<example_interfaces::msg::String>::SharedPtr publisher_;
};
int main(int argc, char ** args){
    rclcpp::init(argc, args);
    rclcpp::spin(std::make_shared<MyNode>());
    rclcpp::shutdown();
}