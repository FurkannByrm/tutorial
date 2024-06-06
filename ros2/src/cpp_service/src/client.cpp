#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/srv/add_two_ints.hpp"

int main(int argc,char ** args){

    rclcpp::init(argc,args);
    auto node   = std::make_shared<rclcpp::Node>("cpp_client_node");
    auto client = node->create_client<example_interfaces::srv::AddTwoInts>("server_test");
    while (!client->wait_for_service(std::chrono::seconds(1))){
        RCLCPP_WARN(node->get_logger(),"wait for the server to be up ...");
    }
    auto request = std::make_shared<example_interfaces::srv::AddTwoInts::Request>();
    request->a = 20;
    request->b = 30;
    auto future = client->async_send_request(request);
    if(rclcpp::spin_until_future_complete(node,future) == rclcpp::FutureReturnCode::SUCCESS)
    {
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Sum = %ld",future.get()->sum);
    }
    else{
        RCLCPP_ERROR(rclcpp::get_logger("rclcpp"),"Failed to call servide add_two_ints");
    }
    rclcpp::shutdown();
    return 0;
    }
