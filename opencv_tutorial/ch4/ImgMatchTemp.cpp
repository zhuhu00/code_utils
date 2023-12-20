/*
 * @Description: 直方图模板匹配
 * @Version: 
 * @Author: Huge
 * @Date: 2021-09-15 11:26:20
 */
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char **argv)
{
    Mat img = imread("../../data/lena.png");
    Mat temp = imread("../../data/lena_face.png");
    if (img.empty() || temp.empty())
    {
        cout << "请确认图像文件名称是否正确" << endl;
        return -1;
    }
    Mat result;
    matchTemplate(img, temp, result, TM_CCOEFF_NORMED);
    double maxVal, minVal;
    Point minLoc, maxLoc;
    //寻找匹配结果中的最大值和最小值以及坐标位置
    minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc);

    //绘制最佳匹配区域
    rectangle(img, cv::Rect(maxLoc.x, maxLoc.y, temp.cols, temp.rows), Scalar(0, 0, 255), 2);
    imshow("Origin", img);
    imshow("temp image", temp);
    imshow("result", result);
    waitKey(0);
    return 0;
}