#ifndef MY_PUBLISHER_CPP
#define MYL_PUBLISHER__CPP
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int16.hpp"
#include "std_msgs/msg/string.hpp"

class PubNode: public rclcpp::Node{

    public:
    PubNode();
    ~PubNode();
    
    void pubCallbackInt();
    void pubCallbackString();

    private:
    int count_;
    rclcpp::Publisher<std_msgs::msg::Int16>::SharedPtr pub_int;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr pub_string;
    rclcpp::TimerBase::SharedPtr timer_;

};


#endif