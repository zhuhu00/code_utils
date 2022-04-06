/*
 * @Description: 图像金字塔,进行上采样和下采样时,图像必须是2的倍数
    cv::pyrDown: 先对图像进行高斯平滑，然后再进行降采样（将图像尺寸行和列方向缩减一半）
    cv::pyrUP: 先对图像进行升采样（将图像尺寸行和列方向增大一倍），然后再进行高斯平滑
 * @Version: 
 * @Author: Huge
 * @Date: 2021-09-14 13:48:11
 */
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char **argv)
{
    Mat img = imread("../../data/lena.png");
    if (img.empty())
    {
        cout << "请确认图像文件名称是否正确" << endl;
        return -1;
    }
    vector<Mat> Gauss, Lap; //高斯金字塔和拉普拉斯金字塔
    int level =3;//高斯金字塔下采样次数

    Gauss.push_back(img);//将原图作为高斯金字塔的第0层

//构建高斯金字塔
    for(int i=0;i<level;i++){
        cv::Mat gauss;
        pyrDown(Gauss[i],gauss);
        Gauss.push_back(gauss);
    }

    //构建拉普拉斯金字塔
    for(int i=Gauss.size()-1;i>0;i--){
        cv::Mat lap,upGauss;
        if(i==Gauss.size()-1)//如果图像是高斯金字塔中最上层图像
        {
            cv::Mat down;
            pyrDown(Gauss[i],down);//上采样
            pyrUp(down,upGauss);
            lap = Gauss[i] - upGauss;
            Lap.push_back(lap);
        }
        pyrUp(Gauss[i],upGauss);
        lap = Gauss[i-1] - upGauss;
        Lap.push_back(lap);
    }

    //查看金字塔中的图像
    for(int i=0;i<Gauss.size();i++){
        string name = to_string(i);
        cv::imshow("G"+name,Gauss[i]);
        cv::imshow("L"+name,Lap[i]);
    }
    cv::waitKey(0);
    return 0;
}