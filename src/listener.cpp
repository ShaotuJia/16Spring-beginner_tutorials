/**
 *@Author: Shaotu Jia 
 *@Copyright [2017] <wiki ROS> 
 * This the subscriber node listener
 */

#include "ros/ros.h"
#include "std_msgs/String.h"

/**
 *  A call back function to recieve messages from topic chatter
 */
void chatterCallback(const std_msgs::String::ConstPtr& msg) {
     ROS_INFO("I heard: [%s]", msg->data.c_str());
}


int main(int argc, char **argv) {
	/**
	 * Initilaize a ros node
	 */
  	ros::init(argc, argv, "listener");
	/**
	 * Define node varible
	 */
	ros::NodeHandle n;

	/**
	 * Define a Subscriber that subscribe topic chatter
	 */
        ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);
	/**
	 * Single thread application
	 */
	ros::spin();

        return 0;
}
