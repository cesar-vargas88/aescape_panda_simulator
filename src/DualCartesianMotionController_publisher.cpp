#include "ros/ros.h"
#include "geometry_msgs/PoseStamped.h"
 
int main(int argc, char **argv)
{
    geometry_msgs::PoseStamped LeftArm_msg;
    geometry_msgs::PoseStamped RightArm_msg;

    ros::init(argc, argv, "CartesianMotionController_publisher");
    ros::NodeHandle n;

    ros::Publisher LeftArm_cartesian_motion_controller  = n.advertise<geometry_msgs::PoseStamped>("/left/robot_goal", 1000);
    ros::Publisher RightArm_cartesian_motion_controller = n.advertise<geometry_msgs::PoseStamped>("/right/robot_goal", 1000);
    ros::Rate loop_rate(50);
  
    int index = 0;
    
    ros::Duration(2).sleep();

    // Left arm Pose
    LeftArm_msg.header.frame_id = "left_link0";
    LeftArm_msg.pose.position.x = 0.350;
    LeftArm_msg.pose.position.y = 0;
    LeftArm_msg.pose.position.z = 0.600;
    LeftArm_msg.pose.orientation.x =-0.707; 
    LeftArm_msg.pose.orientation.y = 0.000; 
    LeftArm_msg.pose.orientation.z = 0.000; 
    LeftArm_msg.pose.orientation.w = 0.707;

    // Right arm Pose
    RightArm_msg.header.frame_id = "right_link0";
    RightArm_msg.pose.position.x = 0.350;
    RightArm_msg.pose.position.y = 0;
    RightArm_msg.pose.position.z = 0.600;
    RightArm_msg.pose.orientation.x =-0.707; 
    RightArm_msg.pose.orientation.y = 0.000; 
    RightArm_msg.pose.orientation.z = 0.000; 
    RightArm_msg.pose.orientation.w = 0.707;

    bool LeftArm_MoveLeft = true;
    bool RightArm_MoveLeft = true;

    while (ros::ok())
    {   
        // Left arm: Move front
        if (LeftArm_msg.pose.position.x <= 0.250)
        { 
            LeftArm_msg.pose.position.x += 0.004;
            LeftArm_msg.pose.position.z -= 0.001;      
        }
        // Left arm: Move down
        else if (LeftArm_msg.pose.position.z >= 0.250)
            LeftArm_msg.pose.position.z -= 0.010;      
        // Left arm: Move left
        else if (LeftArm_MoveLeft)
            LeftArm_msg.pose.position.y -= 0.010;  
        // Left arm: Move right 
        else
            LeftArm_msg.pose.position.y += 0.010;  
        
        // Left arm: Change direction
        if (LeftArm_msg.pose.position.y >= 0.300)
            LeftArm_MoveLeft = true;
        if (LeftArm_msg.pose.position.y <= -0.300)
            LeftArm_MoveLeft = false;

        
        // Right arm: Move front
        if (RightArm_msg.pose.position.x <= 0.250)
        { 
            RightArm_msg.pose.position.x += 0.004;
            RightArm_msg.pose.position.z -= 0.001;      
        }
        // Right arm: Move down
        else if (RightArm_msg.pose.position.z >= 0.250)
            RightArm_msg.pose.position.z -= 0.010;      
        // Right arm: Move left
        else if (RightArm_MoveLeft)
            RightArm_msg.pose.position.y -= 0.010;  
        // Right arm: Move right 
        else
            RightArm_msg.pose.position.y += 0.010;  
        
        // Right arm: Change direction
        if (RightArm_msg.pose.position.y >= 0.300)
            RightArm_MoveLeft = true;
        if (RightArm_msg.pose.position.y <= -0.300)
            RightArm_MoveLeft = false;

        // Publish message               
        LeftArm_cartesian_motion_controller.publish(LeftArm_msg);
        RightArm_cartesian_motion_controller.publish(RightArm_msg);
                
        ros::spinOnce();
 
        loop_rate.sleep();
    }

    return 0;
}