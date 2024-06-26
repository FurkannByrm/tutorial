#include "rclcpp/rclcpp.hpp"
#include "variable/srv/add_three_ints.hpp"

class Mynode: public rclcpp::Node{

public:
    Mynode(): Node("cpp_client_node"){
        clientCallback(10,12,20);

    }

private:
    void clientCallback(int a, int b, int c){
        client_ = this->create_client<variable::srv::AddThreeInts>("add");
        while(!client_->wait_for_service(std::chrono::seconds(1))){
            RCLCPP_WARN(this->get_logger(), "wait for the server to be up...");
        }
        auto request = std::make_shared<variable::srv::AddThreeInts::Request>();
        request->a = a;
        request->b = b;
        request->c = c;
        auto future = client_->async_send_request(request);
        // try
        // {
        // auto response = future.get();
        // RCLCPP_INFO(this->get_logger("rclcpp"),"Sum: %ld", future.get()->sum);
        // }
        // catch(const std::exception& e)
        // {
        //     RCLCPP_ERROR(this->get_logger(), "failed to call service add_two_ints");
        // }
        
    }
    rclcpp::Client<variable::srv::AddThreeInts>::SharedPtr client_;
};
int main(int argc, char ** args){

    rclcpp::init(argc, args);
    rclcpp::spin(std::make_shared<Mynode>());
    rclcpp::shutdown();
}
