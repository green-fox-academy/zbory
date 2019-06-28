#include <iostream>
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/core/utility.hpp"
#include "opencv2/imgcodecs.hpp"

cv::Mat image;
cv::Mat blurred;
int parameter;


void blurTrackbarCallback(int pos, void *userData)
{
    switch (parameter) {
        case 0:
            cv::blur(image, blurred, cv::Size(pos + 1, pos + 1));
            break;
        case 1:
            cv::GaussianBlur(image, blurred, cv::Size(2 * pos + 1, 2 * pos + 1), 0, 0);
            break;
        case 2:
            cv::medianBlur(image, blurred, 2 * pos + 1);
            break;
        case 3:
            cv::bilateralFilter(image, blurred, 2 * pos + 1, 50, 50);
            break;
        default:
            break;
    }
    cv::imshow("Blurred", blurred);
}


int main(int argc, char **argv)
{
    parameter = std::atoi(argv[1]);
    image = cv::imread("tiles.jpg");
    cv::imshow("Original", image);

    int startValue = 1;

    blurred = image.clone();

    cv::namedWindow("Blurred");
    cv::imshow("Blurred", blurred);

    cv::createTrackbar("Ksize", "Blurred", &startValue, 50, blurTrackbarCallback);

    cv::waitKey(0);

    cv::imwrite("blurred" + std::to_string(parameter) + ".jpg", blurred);
    return 0;
}