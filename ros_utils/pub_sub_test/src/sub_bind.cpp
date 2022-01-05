#include "ros/ros.h"
#include "std_msgs/Int8.h"

/**
 * This tutorial demonstrates simple receipt of messages over the ROS system.
 */
void chatterCallback(const std_msgs::Int8::ConstPtr& msg)
{
  ROS_INFO("I heard: [%d]", msg->data);
}

void chatterCallback(const std_msgs::Int8::ConstPtr& msg, int &x, int &y, int &z)
{
    // ROS_INFO("TEST bind x: %d, y: %d", x,y);
    ROS_INFO("TEST bind x: %d, y: %d, z: %d", x,y,z);
    ROS_INFO("I heard: [%d]", msg->data);
}


int xidx = 1;
int yidx=2;
int zidx=3;

int main(int argc, char **argv)
{
  ros::init(argc, argv, "listener");

  ros::NodeHandle n;

//   ros::Subscriber sub = n.subscribe("/chatter", 1000, chatterCallback);
  ros::Subscriber sub = n.subscribe<std_msgs::Int8>("/chatter", 1000, boost::bind(&chatterCallback,_1, xidx, yidx,zidx));

  ros::spin();

  return 0;
}