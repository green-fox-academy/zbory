#include <iostream>
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/core/utility.hpp"
#include "opencv2/imgcodecs.hpp"

void Sharpen(const cv::Mat& myImage, cv::Mat& Result)
{
    CV_Assert(myImage.depth() == CV_8U);  // accept only uchar images
    const int nChannels = myImage.channels();
    Result.create(myImage.size(), myImage.type());
    for (int j = 1; j < myImage.rows - 1; ++j)
    {
        const uchar* previous = myImage.ptr<uchar>(j - 1);
        const uchar* current = myImage.ptr<uchar>(j);
        const uchar* next = myImage.ptr<uchar>(j + 1);
        uchar* output = Result.ptr<uchar>(j);
        for (int i = nChannels; i < nChannels * (myImage.cols - 1); ++i)
        {
            *output++ = cv::saturate_cast<uchar>(5 * current[i]
                - current[i - nChannels] - current[i + nChannels] - previous[i] - next[i]);
        }
    }
    Result.row(0).setTo(cv::Scalar(0));
    Result.row(Result.rows - 1).setTo(cv::Scalar(0));
    Result.col(0).setTo(cv::Scalar(0));
    Result.col(Result.cols - 1).setTo(cv::Scalar(0));
}

void Blur(const cv::Mat& myImage, cv::Mat& Result)
{
    CV_Assert(myImage.depth() == CV_8U);  // accept only uchar images
    const int nChannels = myImage.channels();
    Result.create(myImage.size(), myImage.type());
    for (int j = 1; j < myImage.rows - 1; ++j)
    {
        const uchar* previous = myImage.ptr<uchar>(j - 1);
        const uchar* current = myImage.ptr<uchar>(j);
        const uchar* next = myImage.ptr<uchar>(j + 1);
        uchar* output = Result.ptr<uchar>(j);
        for (int i = nChannels; i < nChannels * (myImage.cols - 1); ++i)
        {
            *output++ = cv::saturate_cast<uchar>((current[i - nChannels] + current[i + nChannels] + previous[i] + next[i]) / 4);
        }
    }
    Result.row(0).setTo(cv::Scalar(0));
    Result.row(Result.rows - 1).setTo(cv::Scalar(0));
    Result.col(0).setTo(cv::Scalar(0));
    Result.col(Result.cols - 1).setTo(cv::Scalar(0));
}

int main()
{
    int divideWith = 30;

    cv::Mat image = cv::imread("C:\\Users\\zbora\\Downloads\\rainbow_lollipop.jpg");
    cv::Mat result;
    cv::Mat result2;

    Sharpen(image, result);
    Blur(image, result2);

    cv::imshow("Sharpened", result);
    cv::imshow("Original", image);
    cv::imshow("Blured", result2);

    cv::waitKey(0);

    return 0;
}