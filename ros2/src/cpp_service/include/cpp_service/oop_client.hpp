#ifndef OOP_CLIENT_HPP_
#define OOP_CLIENT_HPP_

#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/srv/add_two_ints.hpp"


class Client: public rclcpp::Node{

    private:
    rclcpp::Client<example_interfaces::srv::AddTwoInts>::SharedPtr client_;
    std::vector<std::thread> threads;
    public:
    Client();
    ~Client();
    void clientCallback(int a, int b);
};

#endif