/**
 * Copyright [2017] <wiki ROS>
 * This node to send string message to topic
 */

#include <sstream>

#include "ros/ros.h"
#include "std_msgs/String.h"

int main(int argc , char **argv) {

	// initialize node with name talker in ROS system
	ros::init(argc, argv, "talker");
	// initialize node object n
	ros::NodeHandle n;
	// set up publisher
	ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);
	// set up rate, 10Hz
	ros::Rate loop_rate(10);

	// count how many message have sent
	int count = 0;

	while (ros::ok()) {

		std_msgs::String msg;

		std::stringstream ss;

		ss << "hello world " << count;
		msg.data = ss.str();

		ROS_INFO("%s", msg.data.c_str());

		chatter_pub.publish(msg);

		ros::spinOnce();

		loop_rate.sleep();
		++count;
}

	return 0;

}
