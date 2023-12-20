/*
 * @Description: 画鼠标的轨迹
 * @Version: 
 * @Author: Huge
 * @Date: 2021-09-14 12:58:24
 */
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
// using namespace cv;

cv::Mat img, imgPoint; //全局的图像
cv::Point prePoint;    //前一时刻鼠标的坐标，用于绘制直线
void mouse(int event, int x, int y, int flags, void *);

int main(int argc, char **argv)
{
    img = cv::imread("../../data/lena.png");
    if (!img.data)
    {
        cout << "请确认输入图像名称是否正确！ " << endl;
        return -1;
    }
    img.copyTo(imgPoint); //深拷贝
    imshow("1", img);
    imshow("2", imgPoint);
    cv::setMouseCallback("1", mouse, 0); //鼠标影响
    cv::waitKey(0);
    return 0;
}

void mouse(int event, int x, int y, int flags, void *)
{   
    //鼠标左键
    if (event == cv::EVENT_RBUTTONDOWN)
        cout << "点击鼠标左键才可以绘制轨迹" << endl;
    if (event == cv::EVENT_LBUTTONDOWN)
    {
        prePoint = cv::Point(x, y);
        cout << "轨迹起始坐标为" << prePoint << endl;
    }
    if (event == cv::EVENT_MOUSEMOVE && (flags & cv::EVENT_LBUTTONDOWN)) //按住左键开始画
    {
        // cout << "开始绘制"  << endl;

        //通过改变图像像素来显示移动的轨迹
        imgPoint.at<cv::Vec3b>(y, x) = cv::Vec3b(0, 0, 255);
        imgPoint.at<cv::Vec3b>(y, x - 1) = cv::Vec3b(0, 0, 255);
        imgPoint.at<cv::Vec3b>(y, x + 1) = cv::Vec3b(0, 0, 255);
        imgPoint.at<cv::Vec3b>(y - 1, x) = cv::Vec3b(0, 0, 255);
        imgPoint.at<cv::Vec3b>(y + 1, x) = cv::Vec3b(0, 0, 255);
        imshow("2", imgPoint);

        //通过绘制直线显示鼠标的移动轨迹
        cv::Point pt(x, y);
        cv::line(img, prePoint, pt, cv::Scalar(0, 0, 255), 2, 5, 0);
        prePoint = pt;
        cv::imshow("1", img);
    }
}