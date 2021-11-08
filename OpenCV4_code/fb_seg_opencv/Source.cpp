#include<opencv2/opencv.hpp>
#include <iostream>
#include <sstream>
//#include <opencv2/imgcodecs.hpp>
//#include <opencv2/imgproc.hpp>
//#include <opencv2/videoio.hpp>
//#include <opencv2/highgui.hpp>
//#include <opencv2/video.hpp>
//#include <opencv2/core.hpp>
//#include <opencv2/imgproc/imgproc.hpp>
//#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/video/background_segm.hpp>
#include <string>
#include <fstream>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

using namespace std;
using namespace cv;


inline bool exists_test(const string& name) {
    struct stat buffer;
    return (stat(name.c_str(), &buffer) == 0);
}

// /////////////////////////////////////////////////////
// Procedure to save videofiles from images
// inputs:
//      filename = output video filename
//      videoOutputPath = path to save output videofile
//      frameSize = width and height of images
//      fps = frmaes per second on output video file
//      dirPath = path to dir with images

void videoWriter(string filename, string videoOutputPath,
    Size frameSize, double fps,
    string dirPath)
{
    VideoCapture inputVideo(dirPath);
    Mat frame;

    VideoWriter outputVideo;
    int codec = VideoWriter::fourcc('M', 'P', 'E', 'G');
    outputVideo.open(videoOutputPath + filename, codec, fps, frameSize, true);

    if (!outputVideo.isOpened())
    {
        cout << "[ERROR] Could not open the output video for write: " << filename << endl;
        return;
    }

    vector<String> fn;
    glob(dirPath, fn, false);

    size_t imgCount = fn.size();
    for (size_t iCount = 0; iCount < imgCount; iCount++) {
        cout << "Frame " + to_string(iCount) + " out of " + to_string(imgCount) << endl;
        frame = imread(fn[iCount]);
        Mat xframe;
        resize(frame, xframe, frameSize);
        outputVideo.write(xframe);

    }
    outputVideo.release();
    return;
}

int main(int argc, char* argv[])
{
    bool showFrames = true;
    bool saveImages = true;
    bool saveVideo = false;

//    string filename = "/home/roma-zh/Documents/data/cup.mp4";
    string filename = "/home/roma-zh/Documents/data/kitti.mp4";
    string savedir = "/home/roma-zh/test_code/fb_seg_opencv";
    string foregroundPath = "/home/roma-zh/test_code/fb_seg_opencv";
    string backgroundPath = "/home/roma-zh/test_code/fb_seg_opencv";

    VideoCapture cap;

    // Make simple frame and MOG2 mask
    Mat frame, MOGMask, foregroundImg, backgroundImage, backgroundImg;

    double learning_rate = 0.5;

    if (exists_test(filename)) {
        cap.open(filename);
    }

    // Init MOG2 BackgroundSubstractor
    Ptr<BackgroundSubtractor> BackgroundSubstractor;
    BackgroundSubstractor = createBackgroundSubtractorMOG2(false);

    int iCount = 0;

    while (true) {
        iCount++;

        cap >> frame;
        if (frame.empty())
            break;

        // Update the background model
        BackgroundSubstractor->apply(frame, MOGMask);

        // Some works with noises on frame //
        // Blur the foreground mask to reduce the effect of noise and false positives

        // Remove the shadow parts and the noise
        // To remove the shadow just threshold the foreground image with value 127 as minimum. 128? 254?
        blur(MOGMask, MOGMask, Size(5, 5), Point(-1, -1));
        threshold(MOGMask, MOGMask, 128, 255, 0);

        // Get the frame number and write it on the current frame
        rectangle(frame, Point(10, 2), Point(100, 20),
            Scalar(255, 255, 255), -1);

        stringstream ss;
        ss << cap.get(CAP_PROP_POS_FRAMES);
        string frameNumberString = ss.str();

        putText(frame, frameNumberString.c_str(), Point(15, 15),
            FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 0, 0));

        // Zeros images
        foregroundImg = Scalar::all(0);
        backgroundImg = Scalar::all(0);

        // Using mask to cut foreground
        frame.copyTo(foregroundImg, MOGMask);

        // Invert mask and cut background
        backgroundImage = 255 - MOGMask;
        frame.copyTo(backgroundImg, backgroundImage);

        // Show input frame, mask, bg and fg frames
        if (showFrames){
            imshow("Frame", frame);
            imshow("BackGround", backgroundImg);
            imshow("ForeGround", foregroundImg);
            imshow("MOG2 Mask", MOGMask);
        }

        // Save images
        if (saveImages) {
            if (iCount != 1) {
                string counter = to_string(iCount);

                bool res1 = imwrite(savedir + "/original/Frames" + counter + ".jpg", frame);
                bool res2 = imwrite(savedir + "/background/Frames" + counter + ".jpg", backgroundImg);
                bool res3 = imwrite(savedir + "/foreground/Frames" + counter + ".jpg", foregroundImg);
//                if (!res1||!res2||!res3)
//                {
//                    cout << "Save image error!!" << endl;
//                    return -1;
//                }
//                cout << "Save image successfully!!" << endl;
//                cout<<"save to "<<savedir + "/foreground/Frames" + counter + ".jpg"<<endl;

            }
        }


        int keyboard = waitKey(30);
        if (keyboard == 'q' || keyboard == 27)
            break;
    }

    // Save videofiles from Images. U need to save frames first
    if (saveVideo) {
        Size frameSize = Size((int)cap.get(CAP_PROP_FRAME_WIDTH), (int)cap.get(CAP_PROP_FRAME_HEIGHT));
        int fps = (double)cap.get(CAP_PROP_FRAME_COUNT);

        videoWriter("outputVideoForeground.mpg4", foregroundPath, frameSize, fps, savedir + "/foreground/");
        videoWriter("outputVideoBackground.mp4", backgroundPath, frameSize, fps, savedir + "/background/");
    }

    return 0;
}