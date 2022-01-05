#include <ros/ros.h>
#include <cv_bridge/cv_bridge.h>
#include <opencv2/highgui/highgui.hpp>

void subscriber(const sensor_msgs::ImageConstPtr& msg)
{
    cv::Mat img;
    cv_bridge::CvImageConstPtr cv_ptr;
    try
    {
        cv_ptr = cv_bridge::toCvShare(msg);
    }
    catch (cv_bridge::Exception& e)
    {
        ROS_ERROR("cv_bridge exception: %s", e.what());
        return;
    }
    cv_ptr->image.copyTo(img);
    cv::imshow("image",img);
    if(27==cv::waitKey(10))ros::shutdown();
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "image_subscriber");
    ros::NodeHandle nh;
    if(!nh.ok())return 0;
    ros::Subscriber imgSub = nh.subscribe("camera/image_raw", 10, subscriber);
    ROS_INFO("I am subscribing an image...");
    while (ros::ok())ros::spin();
    cv::destroyAllWindows();
    return 0;
}