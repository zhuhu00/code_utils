/*
 * @Description: 图片的concat connect
 * @Version: 
 * @Author: Huge
 * @Date: 2021-09-14 09:24:21
 */
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    //矩阵or图像横竖连接
    cv::Mat matArray[] = {cv::Mat(1, 2, CV_32FC1, cv::Scalar(1)), cv::Mat(1, 2, CV_32FC1, cv::Scalar(2))};//数组内部
    cv::Mat vout1, hout1;
    cv::vconcat(matArray, 2, vout1);
    cout << "图像数组竖向连接：" << vout1 << endl;
    hconcat(matArray, 2, hout1);
    cout << "图像数组横向连接：" << hout1 << endl;

    cv::Mat A = (cv::Mat_<float>(2,2) << 1,2,3,4);
    cv::Mat B = (cv::Mat_<float>(2,2)<<5,6,7,8);
    cv::Mat vout2, hout2;
    cv::vconcat(A,B,vout2);
    cv::hconcat(A,B,hout2);
    cout << "图像数组竖向连接：" << vout2 << endl;
    cout << "图像数组横向连接：" << hout2 << endl;

    cv::Mat img00 = cv::imread("../../data/face1.png");
    cv::Mat img01 = cv::imread("../../data/face1.png");
    cv::Mat img10 = cv::imread("../../data/face1.png");
    cv::Mat img11 = cv::imread("../../data/face1.png");

    if(img00.empty()||img01.empty()||img10.empty()||img11.empty()){
        cout<<"Error, Please check the image path."<<endl;
        return -1;
    }
    cv::imshow("image00",img00);
    cv::imshow("image01",img01);
    cv::imshow("image02",img10);
    cv::imshow("image03",img11);

    cv::Mat img0,img1,img2;

    cv::hconcat(img00,img01,img0);
    cv::hconcat(img10,img11,img1);
    cv::vconcat(img0,img1,img2);

    cv::imshow("img0",img0);
    cv::imshow("img1",img1);
    cv::imshow("img2",img2);
    cv::waitKey(0);

    return 0;
}