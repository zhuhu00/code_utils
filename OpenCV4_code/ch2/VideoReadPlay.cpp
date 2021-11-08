/*
 * @Description Video play and use
 * @LastEditTime 2021-09-13 17:20:46
 */
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    cv::Mat frame;
    cv::VideoCapture video(argv[1]);
    if (video.isOpened())
    {
        video >> frame;
        cout << "The size(width*height) of video are:" << video.get(cv::CAP_PROP_FRAME_WIDTH) << "*" << video.get(cv::CAP_PROP_FRAME_HEIGHT) << endl;
        cout << "The frame rate in video is: " << video.get(cv::CAP_PROP_FPS);
        cout << "Total frames in video is: " << video.get(cv::CAP_PROP_FRAME_COUNT);
//        cout << "frame dim is: " << video.get(cv::CAP_FR)
    }
    else
    {
        cout << "Usage: ./VideoCapture xx.mp4" << endl;
    }
    while (1)
    { //play video
        cv::Mat frame;
        video >> frame;
        if (frame.empty())
            break;
        cv::imshow("video", frame);
        cv::waitKey(1000 / video.get(cv::CAP_PROP_FPS));
    }
    cv::waitKey();
    return 0;
}