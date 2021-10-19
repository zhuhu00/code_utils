// ORB 提取特征点

#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>

using namespace std;
using namespace cv;

int main(int argc, char **argv)
{
    Mat img = imread("../../data/lena.png");
    if (!img.data)
    {
        cout << "请确认图像文件名称是否正确" << endl;
        return -1;
    }

    //创建 ORB 特征点类 变量
    Ptr<ORB> orb = ORB::create(500,               //特征点数目
                               1.2f,              //金字塔层级间的缩放比例
                               8,                 //金字塔图像层数系数
                               31,                //边缘阈值
                               0,                 //原图在金字塔中的层数
                               2,                 //生成描述子时需要用的像素数目
                               ORB::HARRIS_SCORE, //使用 Harris 方法评价特征点
                               31,                //生成描述子时关键点周围邻域的尺寸
                               20                 //计算FAST角点时像素值差值的阈值
    );

    //计算 ORB 关键点
    vector<KeyPoint> KeyPoints;
    orb->detect(img, KeyPoints);//角点检测

    //计算描述子
    Mat descriptors;

    orb->compute(img, KeyPoints, descriptors);//计算描述子
    Mat ImgAngle;

    img.copyTo(ImgAngle);
    //不含角度和大小的结果
    drawKeypoints(img, KeyPoints, img, Scalar(255,255,255));
    //包含角度和大小的结果
	drawKeypoints(img, KeyPoints, ImgAngle, Scalar(255, 255, 255), DrawMatchesFlags::DRAW_RICH_KEYPOINTS);

    imshow("不含角度和大小的结果" , img);
    imshow("含角度和大小的结果",ImgAngle);
    waitKey(0);
    return 0;

}
