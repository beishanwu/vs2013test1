#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/imgproc.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>

using namespace cv;
using namespace std;


void rot90(Mat &matImage, Mat &dstimg, int flag)
{
	transpose(matImage, dstimg);
	flip(dstimg, dstimg, flag); //transpose+flip(1)=CW
}

int main()
{
	
	Mat image = imread("1.jpg");
	Mat destimg(image.size(), image.type());
	namedWindow("Original Image");
	imshow("Original Image", image);

	Mat map_x, map_y;
	map_x.create(image.size(),CV_32FC1);
	map_y.create(image.size(), CV_32FC1);

	image.copyTo(destimg);
	//transpose(destimg, destimg);
	//flip(destimg, destimg, 1); //transpose+flip(1)=CW

	rot90(image, destimg,1);
	rot90(destimg, destimg, 0);
	imshow("result Image", destimg);
	cout << "image" << image.rows <<"   "<< image.cols << endl;
	cout << "destimg" << destimg.rows <<"    "<< destimg.cols << endl;
	waitKey(0);
	return 1;

}

