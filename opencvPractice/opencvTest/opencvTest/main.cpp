//#include "pch.h"
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "../opencvTest/opencvTestHelper.h"

cv::Mat UncleSam;

cv::Scalar colorTemperature(int x, int y)
{
	int red, blue;

	red = 255 - 255.0 * std::max(std::abs(x - samX) / 600.0, std::abs(y - samY) / 600.0);
	blue = 255.0 * std::max(std::abs(x - samX) / 600.0, std::abs(y - samY) / 600.0);

	return CV_RGB(red, 0, blue);
}

void myMouseCallback(int event, int x, int y, int flags, void* userdata)
{
	cv::Mat img = *((cv::Mat*)userdata);


	if (flags & cv::MouseEventFlags::EVENT_FLAG_LBUTTON) {
		if (std::abs(x - samX) < samRadius && std::abs(y - samY) < samRadius) {
			img = UncleSam;
		}
		else {
			img = cv::Scalar(255, 255, 255);
			cv::circle(img, { img.cols / 2, img.rows / 2 }, 5, CV_RGB(0, 0, 0));

			cv::circle(img, { x, y }, 5, CV_RGB(37, 226, 0));
			//Horizontal line
			cv::line(img, { img.cols / 2, img.rows / 2 }, { img.cols , img.rows / 2 }, CV_RGB(226, 45, 0), 2);
			//Angled line
			cv::line(img, { img.cols / 2, img.rows / 2 }, { x , y }, colorTemperature(x, y), 2);

			cv::putText(img, std::to_string(getDegree(img.cols / 2, img.rows / 2, x, y)), { img.cols / 2 + 20, img.rows / 2 - 20 }, cv::FONT_HERSHEY_SIMPLEX, 0.5, CV_RGB(0, 0, 0), 2);
			//cv::putText(img, std::to_string(x) + " " + std::to_string(y),
			//	{ img.cols / 2 + 20, img.rows / 2 + 20 }, cv::FONT_HERSHEY_SIMPLEX, 0.5, CV_RGB(0, 0, 0), 2);
		}
	}

	cv::imshow("Ablak", img);
}


int main()
{
	cv::Mat image = cv::Mat(600, 600, CV_8UC3);
	UncleSam = cv::imread("C:\\Users\\zbora\\Downloads\\uncle_sam.jpg");
	image = cv::Scalar(255, 255, 255);

	cv::circle(image, { image.cols / 2, image.rows / 2 }, 5, CV_RGB(0, 0, 0));

	cv::imshow("Ablak", image);
	cv::setMouseCallback("Ablak", myMouseCallback, &image);

	cv::waitKey(0);
}