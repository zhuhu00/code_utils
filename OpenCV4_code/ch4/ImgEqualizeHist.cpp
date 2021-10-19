/*
 * @Description: 图片的直方图均衡化
 * @Version: 
 * @Author: Huge
 * @Date: 2021-09-15 10:50:45
 */
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void drawHist(Mat &hist, int type, string name) //归一化并绘制直方图函数
{
    int hist_w = 512;
    int hist_h = 400;
    int width = 2;
    Mat histImage = Mat::zeros(hist_h, hist_w, CV_8UC3);
    normalize(hist, hist, 255, 0, type, -1, Mat());
    for (int i = 0; i <= hist.rows; i++)
    {
        rectangle(histImage, Point(width * (i - 1), hist_h - 1), Point(width * i - 1, hist_h - cvRound(hist_h * hist.at<float>(i - 1)) - 1), Scalar(255, 255, 255), -1);
    }
    namedWindow(name, WINDOW_NORMAL);
    imshow(name, histImage);
}

//主函数
int main(int argc, char ** argv)
{
    Mat img = imread("../../data/apple.jpg");
    if (img.empty())
    {
        cout << "请确认图像文件名称是否正确" << endl;
        return -1;
    }
    Mat gray, hist, hist2;
    cvtColor(img, gray, COLOR_BGR2GRAY);
    Mat equalImg;
    equalizeHist(gray, equalImg);

    const int channels[1] = {0};
    float inRanges[2] = {0, 255};
    const float *ranges[1] = {inRanges};
    const int bins[1] = {256};

    calcHist(&gray, 1, channels, Mat(), hist, 1, bins, ranges);
    calcHist(&equalImg, 1, channels, Mat(), hist2, 1, bins, ranges);
    drawHist(hist, NORM_INF, "hist");
    drawHist(hist2, NORM_INF, "hist2");

    imshow("Origin", gray);
    imshow("HistEqualized",equalImg);
    waitKey(0);
    return 0;
}