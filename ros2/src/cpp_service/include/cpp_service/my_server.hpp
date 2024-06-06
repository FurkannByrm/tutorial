#ifndef MY_SERVER_HPP_
#define MY_SERVER_HPP_
#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/srv/add_two_ints.hpp"

class Server: public rclcpp::Node{

    public: 

    Server();
    void serverCallback(const example_interfaces::srv::AddTwoInts::Request::SharedPtr request,
                        const example_interfaces::srv::AddTwoInts::Response::SharedPtr response);

    private:

    rclcpp::Service<example_interfaces::srv::AddTwoInts>::SharedPtr server_;

};


#endif