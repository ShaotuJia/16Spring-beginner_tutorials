/**
 * @Copyright [2017] <wiki ROS>
 * @Author: Shaotu Jia
 * This node to send string message to topic
 */
#include <stdlib.h>
#include <sstream>

#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_srvs/Empty.h"




int count = 0; /**< a integer global variable to count number of message published */
std_msgs::String msg; /**< a message string global varible*/
std::stringstream ss; /**< a string global variable*/

/*
 * A call back funciton.
 * This call back function is to publish 5 level messages on Server
 * @param req an argument of Service Request
 * @param resp an argument of Service Response
 * @return true
 */
bool SeverityInfo(std_srvs::Empty::Request &req, std_srvs::Empty::Response &resp) {

	ROS_DEBUG_STREAM("Count is " << count << "\n");

	// empty the stringstream
	ss.str("");

	if (count % 3 == 0) {
		ss <<" count " << count << " is divisible by 3; \n";
		msg.data = ss.str();
		ROS_INFO_STREAM(msg.data);
	}

	if (count % 5 == 0) {
		ss <<" count " << count << " is divisible by 5; \n";
		msg.data = ss.str();
		ROS_WARN_STREAM(msg.data);
	}

	if (count % 7 == 0) {
		ss <<" count " << count << " is divisible by 7; \n";
		msg.data = ss.str();
		ROS_ERROR_STREAM(msg.data);
	}

	if (count % 9 == 0) {
		ss <<" count " << count << " is divisible by 9; \n";
		msg.data = ss.str();
		ROS_FATAL_STREAM(msg.data);
	}
	return true;
}

int main(int argc , char **argv) {

	/**
	 * initialize node with name talker in ROS system
 	 */
	ros::init(argc, argv, "talker");
	/**
	 * initialize node object n
	 */
	ros::NodeHandle n;

	/**
	 *Register service on master
	 */
	ros::ServiceServer server = n.advertiseService("Severity_Info", &SeverityInfo);

	/**	
	 *set up publisher to publish message to chatter
	 */
	ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);

	/**
	 * Get the frequency parameter for publish rate
 	 */
	const std::string PARAM_NAME = "~frequency";
	double freq;
	bool ok = ros::param::get(PARAM_NAME,freq);
	if(!ok) {
	ROS_FATAL_STREAM("Could not get parameter " << PARAM_NAME);
	freq = 10;
	}

	/**
	 * set up rate
	 */
	ros::Rate loop_rate(freq);

	while (ros::ok()) {

		/**
		 * Publish message msg to topic chatter
		 */
		chatter_pub.publish(msg);

		/**
		 * clear message container for next round
		 */
		msg.data = "";
		ros::spinOnce();
		loop_rate.sleep();
		++count;
	}

	return 0;

}
