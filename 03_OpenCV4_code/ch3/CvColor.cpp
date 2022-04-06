/*
 * @Description: 图片的各个通道显示
 * @Version: 
 * @Author: Huge
 * @Date: 2021-09-14 11:12:42
 */
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

int main(int argc, char** argv){
    cv::Mat img = cv::imread("../../data/face1.png");
    if(img.empty()){
        cout<<"Error!!! Check the image file path"<<endl;
        return -1;
    }
    cv::Mat gray, HSV, YUV, Lab, img32;
    img.convertTo(img32,CV_32F, 1.0/255);

    cv::cvtColor(img32,HSV,cv::COLOR_BGR2HSV);
    cv::cvtColor(img32,YUV,cv::COLOR_BGR2YUV);
    cv::cvtColor(img32,Lab,cv::COLOR_BGR2Lab);
    cv::cvtColor(img32,gray,cv::COLOR_BGR2GRAY);

    cv::imshow("Origin",img32);
    cv::imshow("HSV",HSV);
    cv::imshow("YUV",YUV);
    cv::imshow("Lab",Lab);
    cv::imshow("gray",gray);
    cv::waitKey(0);
    return 0;

    
}