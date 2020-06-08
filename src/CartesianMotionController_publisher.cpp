#include "ros/ros.h"
#include "geometry_msgs/PoseStamped.h"
 
int main(int argc, char **argv)
{
    geometry_msgs::PoseStamped msg;

    ros::init(argc, argv, "CartesianMotionController_publisher");
    ros::NodeHandle n;

    ros::Publisher cartesian_motion_controller = n.advertise<geometry_msgs::PoseStamped>("/panda/cartesian_motion_controller/target_frame", 1000);
    ros::Rate loop_rate(20);
  
    int index = 0;
    
    ros::Duration(2).sleep();

    // Pose
    msg.header.frame_id = "link0";
    msg.pose.position.x = 0.350;
    msg.pose.position.y = 0;
    msg.pose.position.z = 0.600;
    msg.pose.orientation.x =-0.707; 
    msg.pose.orientation.y = 0.000; 
    msg.pose.orientation.z = 0.000; 
    msg.pose.orientation.w = 0.707;

    bool left = true;

    while (ros::ok())
    {   
        // Move front
        if (msg.pose.position.x <= 0.500)
        { 
            msg.pose.position.x += 0.004;
            msg.pose.position.z -= 0.001;      
        }
        // Move down
        else if (msg.pose.position.z >= 0.250)
            msg.pose.position.z -= 0.010;      
        // Move left
        else if (left)
            msg.pose.position.y -= 0.010;  
        // Move right 
        else
            msg.pose.position.y += 0.010;  
        
        // Change direction
        if (msg.pose.position.y >= 0.300)
            left = true;
        if (msg.pose.position.y <= -0.300)
            left = false;
                            
        cartesian_motion_controller.publish(msg);
                
        /*ROS_INFO("CartesianMotionController: position %f, %f, %f, orientation: %f, %f, %f, %f ",msg.pose.position.x, 
                                                                                                msg.pose.position.y, 
                                                                                                msg.pose.position.z, 
                                                                                                msg.pose.orientation.x, 
                                                                                                msg.pose.orientation.x, 
                                                                                                msg.pose.orientation.x, 
                                                                                                msg.pose.orientation.w);*/
         
        ros::spinOnce();
 
        loop_rate.sleep();
    }

    return 0;
}