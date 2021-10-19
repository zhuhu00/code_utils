/*
 * @Description: 图像的极坐标变换
void cv::warpPolar(InputArray  src,
                         OutputArray  dst,
                         Size  dsize,
                         Point2f  center, 极坐标变换时极坐标的原点坐标。
                         double  maxRadius, 变换时边界圆的半径，它也决定了逆变换时的比例参数
                         int  flags  插值方法与极坐标映射方法标志
                         )

 * @Version: 
 * @Author: Huge
 * @Date: 2021-09-14 15:02:32
 */
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char **argv)
{
    Mat img = imread("../../data/dial.png");
    if (img.empty())
    {
        cout << "Error!!! Check the image file path." << endl;
        return -1;
    }
    Mat img1, img2;

    Point2f center = Point2f(img.cols / 2, img.rows / 2); //极坐标在图像中的原点
    //正极坐标变换
    warpPolar(img, img1, Size(300, 600), center, center.x, INTER_LINEAR + WARP_POLAR_LINEAR);
    //逆极坐标变换
    warpPolar(img1, img2, Size(img.cols, img.rows), center, center.x, INTER_LINEAR + WARP_POLAR_LINEAR+WARP_INVERSE_MAP);

    imshow("原表盘图", img);
    imshow("表盘极坐标变换结果", img1);
    imshow("逆变换结果", img2);
    waitKey(0);
    return 0;
}