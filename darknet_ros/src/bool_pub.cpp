#include <ros/ros.h>
#include <std_msgs/Bool.h>
#include <iostream>
#include <fstream>
// #include "../../darknet/src/image.h"

int person_check;

int main(int argc, char **argv) {
    ros::init(argc, argv, "bool_pub");
    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<std_msgs::Bool>("check_person", 10);
    
    std_msgs::Bool msg;
    ros::Rate rate(10);

    while(ros::ok()){
        // std::cout << "person_check: " << person_check << std::endl;
        ROS_INFO("started reading person_check");
        std::ifstream file("/home/cgvlab/a.txt");
        if(!file.is_open()){
            ROS_INFO("Error opening file!");
            continue;
        }
        file >> person_check;
        file.close();
        msg.data = person_check;

        pub.publish(msg);

        ROS_INFO("Published boolean value: %s", (msg.data ? "true" : "false"));

        // std::cout << "Published boolean value: " << (msg.data ? "true" : "false") << std::endl;

        rate.sleep();
    }
    
    // ros::spin();
}