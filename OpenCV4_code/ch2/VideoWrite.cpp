/*
 * @Description Video Write
 * @LastEditTime 2021-09-13 17:50:01
 */
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    cv::VideoCapture video(0); //using camera
    if (video.isOpened())
    {
        cout << "The size(width*height) of video are:" << video.get(cv::CAP_PROP_FRAME_WIDTH) << "*" << video.get(cv::CAP_PROP_FRAME_HEIGHT) << endl;
        cout << "The frame rate in video is: " << video.get(cv::CAP_PROP_FPS) << endl;
        // cout << "Total frames in video is: " << video.get(cv::CAP_PROP_FRAME_COUNT)<<endl;
    }
    else
    {
        cout << "Usage: ./VideoWrite" << endl;
    }
    // while (1)
    // { //play video
    cv::Mat frame;
    video >> frame;
    if (frame.empty())
    {
        cout << "error, check the code" << endl;
        // break;
    }
    // cv::imshow("video", frame);
    // cv::waitKey(1000 / video.get(cv::CAP_PROP_FPS));
    // }

    bool isColor = (frame.type() == CV_8UC3); //check 彩色?

    cv::VideoWriter writer;
    int codec = cv::VideoWriter::fourcc('M', 'J', 'P', 'G'); //选择编码格式
    //for OpenCV 4
    //int codec = CV_FOURCC('M', 'J', 'P', 'G');

    double fps = 25.0;
    string filename = "ch2.avi";
    writer.open(filename, codec, fps, frame.size(), isColor); //创建保存视频文件的视频流

    if (!writer.isOpened())
    { //check 视频流是否创建成功
        cout << "Error!! Check the filename!" << endl;
        return -1;
    }

    while (1)
    {
        /* code */
        //检测是否执行完毕
        if (!video.read(frame))
        { //判断是否能从摄像头或者文件读出图像
            cout << "camera disconnect or video read end (from file)" << endl;
            break;
        }
        writer.write(frame);       //图像写入视频流
        cv::imshow("Live", frame); //显示
        char c = cv::waitKey(50);
        if (c == 27)
        { //Esc
            break;
        }
    }
    // 退出程序时刻自动关闭视频流
    //video.release();
    //writer.release();
    return 0;
}