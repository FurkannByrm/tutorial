#include "rclcpp/rclcpp.hpp"
#include "variable/srv/add_three_ints.hpp"


using namespace std::placeholders;
class MyNode: public rclcpp::Node{
    public:
    MyNode(): Node("cpp_server"){
        RCLCPP_INFO(this->get_logger(), "server has been started.");
        server_ = this->create_service<variable::srv::AddThreeInts>("add", std::bind(&MyNode::serverCallback, this, _1,_2));
}
    private:
    void serverCallback(const variable::srv::AddThreeInts::Request::SharedPtr request, const variable::srv::AddThreeInts::Response::SharedPtr response){
        response->sum = request->a + request->b + request->c;
        RCLCPP_INFO(this->get_logger(), "%ld + %ld + %ld = %ld", request->a, request->b, request->c, response->sum);
    }
    rclcpp::Service<variable::srv::AddThreeInts>::SharedPtr server_;
};
int main(int argc, char ** args){
    rclcpp::init(argc, args);
    rclcpp::spin(std::make_shared<MyNode>());
    rclcpp::shutdown();
}