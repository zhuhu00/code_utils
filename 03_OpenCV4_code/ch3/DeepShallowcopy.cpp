/*
 * @Description: 深拷贝和浅拷贝
    浅拷贝: 会共享同一块内存空间，改变其中一个变量的值，另一个变量的值也会随之改变
    深拷贝: 不会共享空间,是分开的变量
 * @Version: 
 * @Author: Huge
 * @Date: 2021-09-14 11:22:40
 */
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    Mat img = imread("../../data/lena.png");
    Mat noobcv = imread("../../data/noobcv.jpg");
    if (img.empty() || noobcv.empty())
    {
        cout << "请确认图像文件名称是否正确" << endl;
        return -1;
    }
    Mat ROI1, ROI2, ROI2_copy, mask, img2, img_copy, img_copy2;
    resize(noobcv, mask, Size(200, 200));
    img2 = img; //浅拷贝
    imshow("浅拷贝的img2", img2);


        //深拷贝的两种方式
    img.copyTo(img_copy2);
    imshow("深拷贝的img_copy2", img_copy2);

    copyTo(img, img_copy, img);
    imshow("深拷贝的img_copy", img_copy);


    //两种在图中截取ROI区域的方式
    Rect rect(206, 206, 200, 200);                           //定义ROI区域
    ROI1 = img(rect);                                        //截图
    ROI2 = img(Range(300, 500), Range(300, 500));            //第二种截图方式
    img(Range(300, 500), Range(300, 500)).copyTo(ROI2_copy); //深拷贝
    mask.copyTo(ROI1);                                       //在图像中加入部分图像
    imshow("加入noobcv后图像", img);
    imshow("ROI对ROI2的影响", ROI2);
    imshow("深拷贝的ROI2_copy", ROI2_copy);
    circle(img, Point(300, 300), 20, Scalar(0, 0, 255), -1); //绘制一个圆形
    imshow("画圆对ROI1的影响", ROI1);
    waitKey(0);
    return 0;
}