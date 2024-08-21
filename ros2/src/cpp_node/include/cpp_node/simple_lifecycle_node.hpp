#ifndef SIMPLE_LIFE_CYCLE_NODE_
#define SIMPLE_LIFE_CYCLE_NODE_


#include <chrono>
#include <string>
#include <thread>

#include "rclcpp/rclcpp.hpp"
#include "rclcpp_lifecycle/lifecycle_node.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;
using std::placeholders::_1;


class SimpleLifecycleNode : public rclcpp_lifecycle::LifecycleNode
{
    public:
    explicit SimpleLifecycleNode(const std::string & node_name, bool intra_process_comms = false) 
    : rclcpp_lifecycle::LifecycleNode(node_name, 
    rclcpp::NodeOptions().use_intra_process_comms(intra_process_comms)) {}

    rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn on_configure(const rclcpp_lifecycle::State&);
    rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn on_activate(const rclcpp_lifecycle::State&);
    rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn on_deactivate(const rclcpp_lifecycle::State&);
    rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn on_cleanup(const rclcpp_lifecycle::State&);
    rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn on_shutdown(const rclcpp_lifecycle::State&);
    void msgCallback(const std_msgs::msg::String &msg);

    private:
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr sub_;
};




#endif //SIMPLE_LIFE_CYCLE_NODE_ 