#include "ros/ros.h"
#include "geometry_msgs/PoseStamped.h"
 
int main(int argc, char **argv)
{
    std::vector<std::vector<double>> pose{  {-0.5, 0.5, 0.4},  
                                            {-0.5, 0.5, 0.5},
                                            {-0.5, 0.5, 0.6},
                                            {-0.5, 0.5, 0.5}};

    geometry_msgs::PoseStamped msg;

    ros::init(argc, argv, "CartesianMotionController_publisher");
    ros::NodeHandle n;

    ros::Publisher cartesian_motion_controller = n.advertise<geometry_msgs::PoseStamped>("/panda/cartesian_motion_controller/target_frame", 1000);
    ros::Rate loop_rate(1);
  
    int index = 0;
  
    while (ros::ok())
    {   
        index < pose.size()-1 ? index++ : index = 0;

        // Pose
        msg.header.frame_id = "link0";
        msg.pose.position.x = pose[index][0];
        msg.pose.position.y = pose[index][1];
        msg.pose.position.z = pose[index][2];
        msg.pose.orientation.x = 0; 
        msg.pose.orientation.y = 0; 
        msg.pose.orientation.z = 0; 
        msg.pose.orientation.w = 0; 
        
        cartesian_motion_controller.publish(msg);
             
        ROS_INFO("CartesianMotionController: position %f, %f, %f, orientation: %f, %f, %f, %f ",msg.pose.position.x, 
                                                                                                msg.pose.position.y, 
                                                                                                msg.pose.position.z, 
                                                                                                msg.pose.orientation.x, 
                                                                                                msg.pose.orientation.x, 
                                                                                                msg.pose.orientation.x, 
                                                                                                msg.pose.orientation.w);
 
        ros::spinOnce();
 
        loop_rate.sleep();
    }

    return 0;
}