#include "ros/ros.h"
#include "std_msgs/String.h"
#include "sensor_msgs/JointState.h"

void joint_states_Callback(const sensor_msgs::JointState::ConstPtr& msg)
{
    //ROS_INFO("Name:     %s  ", msg->name);//, msg->name[1].c_str(), msg->name[2].c_str(), msg->name[3].c_str(), msg->name[4].c_str(), msg->name[5].c_str(), msg->name[6].c_str());
    ROS_INFO("Position: %f  %f  %f  %f  %f  %f  %f", msg->position[0], msg->position[1], msg->position[2], msg->position[3], msg->position[4], msg->position[5], msg->position[6]);
    ROS_INFO("Velocity: %f  %f  %f  %f  %f  %f  %f", msg->velocity[0], msg->velocity[1], msg->velocity[2], msg->velocity[3], msg->velocity[4], msg->velocity[5], msg->velocity[6]);
    ROS_INFO("Effort:   %f  %f  %f  %f  %f  %f  %f", msg->effort[0], msg->effort[1], msg->effort[2], msg->effort[3], msg->effort[4], msg->effort[5], msg->effort[6]);
}

int main(int argc, char **argv)
 {
    ros::init(argc, argv, "JointStateController_subscriber");
    ros::NodeHandle n;

    ros::Subscriber sub = n.subscribe("/panda/joint_states", 1000, joint_states_Callback);

    ros::spin();

    return 0;
}