#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/String.h"

int main(int argc, char **argv)
{
    std_msgs::String LeftArm_status;
    std_msgs::String RightArm_status;

    ros::init(argc, argv, "RobotStatus_publisher");
    ros::NodeHandle n;

    ros::Publisher LeftArm_RobotStatus  = n.advertise<std_msgs::String>("/left/aescape/mode/status", 1000);
    ros::Publisher RightArm_RobotStatus = n.advertise<std_msgs::String>("/right/aescape/mode/status", 1000);
    ros::Rate loop_rate(50);
    
    LeftArm_status.data = "execution";
    RightArm_status.data = "execution";

    while (ros::ok())
    {              
        LeftArm_RobotStatus.publish(LeftArm_status);
        RightArm_RobotStatus.publish(RightArm_status);
                
        ros::spinOnce();
 
        loop_rate.sleep();
    }

    return 0;
}