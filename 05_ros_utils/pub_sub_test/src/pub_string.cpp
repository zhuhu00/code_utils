#include "ros/ros.h"
#include "std_msgs/String.h"

#include <sstream>

/**
 * This tutorial demonstrates simple sending of messages over the ROS system.
 */
int main(int argc, char **argv)
{
  ros::init(argc, argv, "talker");//这里的talker是node的名字

  ros::NodeHandle n;

    // publish的信息和信息的名字，pub的是标准信息的String，名字（topic）是`chatter`，而1000是缓冲的信息量，因为消息传递有延时，不能及时传的就是放在缓冲区。
  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("/chatter", 1000);

    // 表示发布信息的快慢，这里表示是10hz，需要和loop_rate.sleep()配合使用。才有效果。
  ros::Rate loop_rate(10);

  int count = 0;
  while (ros::ok())
  {
    std_msgs::String msg;

    std::stringstream ss;
    ss << "hello world " << count;
    msg.data = ss.str();

    ROS_INFO("%s", msg.data.c_str());

    chatter_pub.publish(msg);

    // 和ros::spin()，一般是用于订阅部分的，必须要有这两个函数之一，检测是否接收到信息。
    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }

  return 0;
}
