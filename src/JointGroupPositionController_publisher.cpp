#include "ros/ros.h"
#include "std_msgs/Float64.h"
#include "std_msgs/Float64MultiArray.h"
 
#include <vector>

int main(int argc, char **argv)
{
    std::vector<std::vector<double>> joint_position{{-0.40, 0.00, 0.00,-2.70, 0.00, 3.50, 0.00},  
                                                    {-0.40, 0.00, 0.00,-2.70, 0.00, 2.40, 0.00},
                                                    { 0.40, 0.00, 0.00,-2.70, 0.00, 2.40, 0.00},
                                                    { 0.40, 0.00, 0.00,-2.70, 0.00, 3.50, 0.00}};

    std_msgs::Float64MultiArray msg;

    ros::init(argc, argv, "JointGroupPositionController_publisher");
    ros::NodeHandle n;

    ros::Publisher joint_goup_position_controller = n.advertise<std_msgs::Float64MultiArray>("/panda/joint_group_position_controller/command", 1000);
    ros::Rate loop_rate(0.5);
  
    int index = 0;
  
    while (ros::ok())
    {   
        index < joint_position.size()-1 ? index++ : index = 0;

        // copy in the data
        msg.data.clear();
        msg.data.insert(msg.data.end(), joint_position[index].begin(), joint_position[index].end());

        joint_goup_position_controller.publish(msg);
             
        ROS_INFO("JointGroupPositionController: %f, %f, %f, %f, %f, %f, %f", msg.data[0], msg.data[1], msg.data[2], msg.data[3], msg.data[4], msg.data[5], msg.data[6]);
 
        ros::spinOnce();
 
        loop_rate.sleep();
    }

    return 0;
}