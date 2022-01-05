#include "ros/ros.h"
#include <vector>
#include <string>

int main(int argc, char **argv){

    ros::init(argc, argv, "show_param");

    ros::NodeHandle nh;

    double noise;
    std::string string_var;
    std::vector<int> a_list;


    nh.getParam("noise", noise);
    nh.getParam("string_var", string_var);
    nh.getParam("a_list", a_list);//读取数组或者向量

    ROS_INFO("noise parameter is................... %f", noise);
    ROS_INFO("noise parameter is................... %s", string_var);
    // ROS_INFO("noise parameter is................... %s", string_var);
};