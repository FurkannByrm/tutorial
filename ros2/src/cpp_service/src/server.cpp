#include "my_server.hpp"


Server::Server(): Node("cpp_server_node"){
    RCLCPP_INFO(this->get_logger(),"server has been started.");
    server_ = this->create_service<example_interfaces::srv::AddTwoInts>("server_test", 
    std::bind(&Server::serverCallback, this,std::placeholders::_1,std::placeholders::_2));
}

void Server::serverCallback(const example_interfaces::srv::AddTwoInts::Request::SharedPtr request,
                            const example_interfaces::srv::AddTwoInts::Response::SharedPtr response){
                                response->sum =request->a + request->b;
                                RCLCPP_INFO(this->get_logger(),"%ld + %ld = %ld", request->a, request->b,response->sum);
                            }

int main(int argc, char ** args){
    rclcpp::init(argc, args);
    rclcpp::spin(std::make_shared<Server>());
    rclcpp::shutdown();
}