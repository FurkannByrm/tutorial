#include "cpp_node/simple_lifecycle_node.hpp"


rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn SimpleLifecycleNode::on_configure(
    const rclcpp_lifecycle::State&){
        sub_ = create_subscription<std_msgs::msg::String>("chatter", 10, std::bind(&SimpleLifecycleNode::msgCallback, this, _1));
        RCLCPP_INFO(this->get_logger(),"Lifecycle node on_configure() called.");
        return rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn::SUCCESS;
    }

rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn SimpleLifecycleNode::on_activate(
    const rclcpp_lifecycle::State& state){
    LifecycleNode::on_activate(state);
    RCLCPP_INFO(this->get_logger(),"Lifecycle node on_activate() called.");
    std::this_thread::sleep_for(2s);
    return rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn::SUCCESS;
    }

rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn SimpleLifecycleNode::on_deactivate(
    const rclcpp_lifecycle::State& state){
     LifecycleNode::on_deactivate(state);
     RCLCPP_INFO(this->get_logger(),"Lifecycle node on_deactive() called.");
     return rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn::SUCCESS;
    }

rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn SimpleLifecycleNode::on_cleanup(
    const rclcpp_lifecycle::State&){
    sub_.reset();
    RCLCPP_INFO(this->get_logger(),"Lifecycle node on_cleanup() called.");
    return rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn::SUCCESS;
    }

rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn SimpleLifecycleNode::on_shutdown(
    const rclcpp_lifecycle::State&){
    sub_.reset();
    RCLCPP_INFO(this->get_logger(),"Lifecycle node on_shutdown() called.");
    return rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn::SUCCESS;
    }

void SimpleLifecycleNode::msgCallback(const std_msgs::msg::String &msg)
{
    auto state = get_current_state();
    if(state.label() == "active")
    {
        RCLCPP_INFO_STREAM(this->get_logger(), "Lifecycle node heard: "<< msg.data.c_str());
    }
}

int main(int argc, char * argv[])
{
    rclcpp::init(argc,argv);

    rclcpp::executors::SingleThreadedExecutor ste;
    std::shared_ptr<SimpleLifecycleNode> simple_lifecycle_node =
    std::make_shared<SimpleLifecycleNode>("simple_lifecycle_node");
    ste.add_node(simple_lifecycle_node->get_node_base_interface());
    ste.spin();
    rclcpp::shutdown();
}