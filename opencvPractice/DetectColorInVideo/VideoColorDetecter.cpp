#include <iostream>
#include "opencv2/opencv.hpp"

int low_H = 0, low_S = 0, low_V = 0;
int high_H = 180, high_S = 255, high_V = 255;
int recolor_H = 50;

void recolor_trackbar(int pos, void *)
{
    recolor_H = pos;
}

void on_low_H_thresh_trackbar(int pos, void *)
{
    low_H = pos;
}
void on_low_S_thresh_trackbar(int pos, void *)
{
    low_S = pos;
}
void on_low_V_thresh_trackbar(int pos, void *)
{
    low_V = pos;
}
void on_high_H_thresh_trackbar(int pos, void *)
{
    high_H = pos;
}
void on_high_S_thresh_trackbar(int pos, void *)
{
    high_S = pos;
}
void on_high_V_thresh_trackbar(int pos, void *)
{
    high_V = pos;
}

void myMouseCallback(int event, int x, int y, int flags, void *userdata)
{
    bool *state = ((bool *)userdata);
    if (flags & cv::MouseEventFlags::EVENT_FLAG_LBUTTON) {
        if (*state)
            *state = false;
        else
            *state = true;
    }
}

int main(int argc, char **argv)
{
    cv::VideoCapture webcam(0);

    bool modeFlag = false;
    cv::Mat frame;
    cv::Mat frame_greyscale;
    cv::Mat frame_greyscale3;
    cv::Mat hsv, object_hsv;
    cv::Mat object_mask;
    cv::Mat background_mask;
    cv::Mat color_object;
    cv::Mat color_background;
    cv::Mat temp;
    cv::Mat result;

    // Normalizing HSV values obtained from GIMP
    //cv::Scalar lowValue(240.0 / 2, 42.0 / 100 * 255, 46.0 / 100 * 255);
    //cv::Scalar lowValue(0, 0, 0);
    //cv::Scalar highValue(180, 255, 255);

    cv::namedWindow("Control");
    cv::namedWindow("Output");
    // Add mouse callback
    cv::setMouseCallback("Output", myMouseCallback, &modeFlag);
    cv::createTrackbar("Recolor", "Output", &recolor_H, 180, recolor_trackbar);


    // Add low threshold bars 
    cv::createTrackbar("Low H", "Control", &low_H, 180, on_low_H_thresh_trackbar);
    cv::createTrackbar("Low S", "Control", &low_S, 255, on_low_S_thresh_trackbar);
    cv::createTrackbar("Low V", "Control", &low_V, 255, on_low_V_thresh_trackbar);

    //Add high treshold bars
    cv::createTrackbar("High H", "Control", &high_H, 180, on_high_H_thresh_trackbar);
    cv::createTrackbar("High S", "Control", &high_S, 255, on_high_S_thresh_trackbar);
    cv::createTrackbar("High V", "Control", &high_V, 255, on_high_V_thresh_trackbar);

    while (1) {
        webcam >> frame;
        cv::imshow("Control", frame);
            cv::cvtColor(frame, hsv, cv::COLOR_RGB2HSV);
            // Detect the object based on HSV Range Values
            cv::inRange(hsv, cv::Scalar(low_H, low_S, low_V), cv::Scalar(high_H, high_S, high_V), object_mask);


            // Convert single channel mask to 3 channel for bitwise operator
            cv::cvtColor(object_mask, temp, cv::COLOR_GRAY2RGB);
            // Get object in color
            cv::bitwise_and(frame, temp, color_object);

            // Getting mask for background (invert object mask)
            background_mask = ~temp;

            // Getting color background
            cv::bitwise_and(frame, background_mask, color_background);

            // Making frame greyscale
            cv::cvtColor(color_background, frame_greyscale, cv::COLOR_RGB2GRAY);
            cv::cvtColor(frame_greyscale, frame_greyscale3, cv::COLOR_GRAY2RGB);

            // Addi grey background and colored object
            result = frame_greyscale3 + color_object;

        if (modeFlag) {
            cv::imshow("Output", result);
        }
        else {
            uchar h;
            cv::cvtColor(color_object, object_hsv, cv::COLOR_RGB2HSV);
            for (int i = 0; i < object_hsv.rows; i++){
                for (int j = 0; j < object_hsv.cols; j++){
                    h = object_hsv.at<cv::Vec3b>(i, j)[0] = recolor_H;
                }
            }
            cv::cvtColor(object_hsv, color_object, cv::COLOR_HSV2RGB);
            result = color_background + color_object;
            cv::imshow("Output", result);
        }

        cv::waitKey(16);
    }

    return 0;
}