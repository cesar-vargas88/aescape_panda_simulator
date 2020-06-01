#include "ros/ros.h"
#include "geometry_msgs/PoseStamped.h"
 
int main(int argc, char **argv)
{
    std::vector<std::vector<double>> pose{  {0.1000, 0.000, 0.9500}, 
                                            {0.1500, 0.000, 0.9500},
                                            {0.2000, 0.000, 0.9500}, 
                                            {0.2500, 0.000, 0.9500},
                                            {0.2500, 0.000, 0.9000},  
                                            {0.2500, 0.000, 0.8500},
                                            {0.3000, 0.000, 0.8500}, 
                                            {0.3500, 0.000, 0.8500}, 
                                            {0.4000, 0.000, 0.8500},
                                            {0.4000, 0.000, 0.8000},
                                            {0.4000, 0.000, 0.7500},
                                            {0.4000, 0.000, 0.7000},
                                            {0.4000, 0.000, 0.6500},
                                            {0.4000, 0.000, 0.6000},
                                            {0.4000, 0.000, 0.5500},
                                            {0.4000, 0.000, 0.5000},
                                            {0.4000, 0.000, 0.5500},
                                            {0.4000, 0.000, 0.6000},
                                            {0.4000, 0.000, 0.6500},
                                            {0.4000, 0.000, 0.7000},
                                            {0.4000, 0.000, 0.7500},
                                            {0.4000, 0.000, 0.8000},
                                            {0.4000, 0.000, 0.8500},
                                            {0.3500, 0.000, 0.8500},
                                            {0.3000, 0.000, 0.8500},
                                            {0.2500, 0.000, 0.8500},
                                            {0.2500, 0.000, 0.9000},
                                            {0.2500, 0.000, 0.9500},
                                            {0.2000, 0.000, 0.9500}, 
                                            {0.1500, 0.000, 0.9500}};

    geometry_msgs::PoseStamped msg;

    ros::init(argc, argv, "CartesianMotionController_publisher");
    ros::NodeHandle n;

    ros::Publisher cartesian_motion_controller = n.advertise<geometry_msgs::PoseStamped>("/panda/cartesian_motion_controller/target_frame", 1000);
    ros::Rate loop_rate(3);
  
    int index = 0;
    
    ros::Duration(4).sleep();

    while (ros::ok())
    {   
        index < pose.size()-1 ? index++ : index = 0;

        // Pose
        msg.header.frame_id = "link0";
        msg.pose.position.x = pose[index][0];
        msg.pose.position.y = pose[index][1];
        msg.pose.position.z = pose[index][2];
        msg.pose.orientation.x = 1; 
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