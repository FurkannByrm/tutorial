#include <chrono>
#include <functional>
#include <string>
#include <vector>

#include <rclcpp/rclcpp.hpp>


using namespace std::chrono_literals;

class MiniParam : public rclcpp::Node{

    public:
    MiniParam() : Node("minimal_param_node")
    {
        this->declare_parameter("my_parameter", "Worls");
        timer_ = this->create_wall_timer(
            1000ms,std::bind(&MiniParam::timer_callback, this));
    }
    void timer_callback(){
        std::string my_param = this->get_parameter("my_parameter").as_string();
        RCLCPP_INFO(this->get_logger(), "Hello %s!", my_param.c_str());
        std::vector<rclcpp::Parameter> all_new_parameters{rclcpp::Parameter("my_parameter", "world")};
        this->set_parameters(all_new_parameters);

    }
    private:
    rclcpp::TimerBase::ConstSharedPtr timer_;


};

int main(int argc, char ** argv){

    rclcpp::init(argc,argv);
    rclcpp::spin(std::make_shared<MiniParam>());
    rclcpp::shutdown();
    return 0;


}