/*
 * @Description OpenCV 4的test
 * @LastEditTime 2021-09-13 13:49:00
 */

#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char ** argv){
    cv::Mat img;//声明一个保存图像的类
    img = cv::imread(argv[1]);
    if(img.empty()){
        std::cout <<"Error in open image, Please using ./testOpenCV xx.png"<<std::endl;
        return -1;
    }
    cv::imshow("test",img);
    cv::waitKey(0);//等待键盘输入
    return 0;
}