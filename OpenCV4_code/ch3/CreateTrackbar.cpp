/*
 * @Description: 
 * @Version: 0.0
 * @Author: Huge
 * @Date: 2021-09-14 11:04:50
 */
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

//为了能在被调函数中使用，所以设置成全局的
int value;
void CallBack(int, void *); //滑动条回调函数
cv::Mat img1, img2;


int main(int argc, char** argv)
{
    img1 = cv::imread("../../data/lena.png");
    if (!img1.data)
    {
        cout << "请确认是否输入正确的图像文件" << endl;
        return -1;
    }
    cv::namedWindow("滑动条改变图像亮度");
    cv::imshow("滑动条改变图像亮度", img1);
    value = 100; //滑动条创建时的初值
                 //创建滑动条
    cv::createTrackbar("亮度值百分比", "滑动条改变图像亮度", &value, 600, CallBack, 0);
    cv::waitKey();
}


void CallBack(int, void*){
    float a=value/100.0;
    img2 = img1*a;
    cv::imshow("滑动改变图像亮度",img2);
}