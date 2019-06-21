#include <iostream>
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/core/utility.hpp"
#include "opencv2/imgcodecs.hpp"

cv::Mat& ScanImageAndReduceC(cv::Mat& I, const uchar* const table)
{
    // accept only char type matrices
    CV_Assert(I.depth() == CV_8U);
    int channels = I.channels();
    int nRows = I.rows;
    int nCols = I.cols * channels;

    if (I.isContinuous())
    {
        nCols *= nRows;
        nRows = 1;
    }

    int i, j;
    uchar* p;
    for (i = 0; i < nRows; ++i)
    {
        p = I.ptr<uchar>(i);
        for (j = 0; j < nCols; ++j)
        {
            p[j] = table[p[j]];
        }
    }
}
cv::Mat& ScanImageAndReduceIterator(cv::Mat& I, const uchar* const table)
{
    // accept only char type matrices
    CV_Assert(I.depth() == CV_8U);
    const int channels = I.channels();
    switch (channels)
    {
        case 1:
        {
            cv::MatIterator_<uchar> it, end;
            for (it = I.begin<uchar>(), end = I.end<uchar>(); it != end; ++it)
                * it = table[*it];
            break;
        }
        case 3:
        {
            cv::MatIterator_<cv::Vec3b> it, end;
            for (it = I.begin<cv::Vec3b>(), end = I.end<cv::Vec3b>(); it != end; ++it)
            {
                (*it)[0] = table[(*it)[0]];
                (*it)[1] = table[(*it)[1]];
                (*it)[2] = table[(*it)[2]];
            }
        }
    }
}
cv::Mat& ScanImageAndReduceRandomAccess(cv::Mat& I, const uchar* const table)
{
    // accept only char type matrices
    CV_Assert(I.depth() == CV_8U);
    const int channels = I.channels();
    switch (channels)
    {
        case 1:
        {
            for (int i = 0; i < I.rows; ++i)
                for (int j = 0; j < I.cols; ++j)
                    I.at<uchar>(i, j) = table[I.at<uchar>(i, j)];
            break;
        }
        case 3:
        {
            cv::Mat_<cv::Vec3b> _I = I;
            for (int i = 0; i < I.rows; ++i)
                for (int j = 0; j < I.cols; ++j)
                {
                    _I(i, j)[0] = table[_I(i, j)[0]];
                    _I(i, j)[1] = table[_I(i, j)[1]];
                    _I(i, j)[2] = table[_I(i, j)[2]];
                }
            I = _I;
            break;
        }
    }
    return I;
}


int main()
{
    int divideWith = 30;

    cv::Mat image = cv::imread("C:\\Users\\zbora\\Downloads\\rainbow_lollipop.jpg");
    cv::Mat result = image.clone();

    //LookUpTable as uchar array
    unsigned char table[256];
    for (int i = 0; i < 256; ++i)
        table[i] = (unsigned char)(divideWith * (i / divideWith));

    //LookUpTable as Mat object
    cv::Mat lookUpTable(1, 256, CV_8U);
    uchar* p = lookUpTable.ptr();
    for (int i = 0; i < 256; ++i)
        p[i] = table[i];

    double t;

    //Processing image efficient way
    t = (double)cv::getTickCount();
    ScanImageAndReduceC(image, table);

    t = ((double)cv::getTickCount() - t) / cv::getTickFrequency();
    std::cout << "Times passed in seconds(efficient): " << t << std::endl;

    //Processing image iterator way
    t = (double)cv::getTickCount();
    ScanImageAndReduceIterator(image, table);

    t = ((double)cv::getTickCount() - t) / cv::getTickFrequency();
    std::cout << "Times passed in seconds(iterator): " << t << std::endl;

    //Processing image random access way
    t = (double)cv::getTickCount();
    ScanImageAndReduceRandomAccess(image, table);

    t = ((double)cv::getTickCount() - t) / cv::getTickFrequency();
    std::cout << "Times passed in seconds(random access): " << t << std::endl;

    //Processing image cv::LUT() way
    t = (double)cv::getTickCount();
    cv::LUT(image, lookUpTable, result);

    t = ((double)cv::getTickCount() - t) / cv::getTickFrequency();
    std::cout << "Times passed in seconds(cv::LUT()): " << t << std::endl;


    cv::imshow("Reduced", result);
    cv::imshow("Original", image);

    cv::waitKey(0);

    return 0;
}