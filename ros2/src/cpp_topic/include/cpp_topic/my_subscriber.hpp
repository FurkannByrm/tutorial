#ifndef MY_SUBSCRIBER_HPP_
#define MY_SUBSCRIBER_HPP_
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int16.hpp"
#include "std_msgs/msg/string.hpp"

class SubNode: public rclcpp::Node{

    public:
    SubNode();
    ~SubNode();

    void subCallbackInt(const std_msgs::msg::Int16 msg);
    void subCallbackString(const std_msgs::msg::String msg);

    private:
    int count_;
    rclcpp::Subscription<std_msgs::msg::Int16>::SharedPtr sub_int;
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr sub_string;

};


#endif 