#include<stdio.h>
#include"opencv2/highgui.hpp"
#include"opencv2/imgproc.hpp"
#include"opencv2/core.hpp"
#include<iostream>
 
using namespace cv;
using namespace std;

Mat img = imread("/home/chandana/OpenCV/ip/rubik.jpg",0);
int r;

void callback(int,void*)
{
	Mat img1(img.rows,img.cols,CV_8UC1,Scalar(0));
	Canny( img, img1, r, r*3, 3 );
	imshow("win",img1);

}

int main()
{
	r=0;
	namedWindow("win",WINDOW_NORMAL);
	createTrackbar("threshold","win",&r,85,callback);
	waitKey(0);
	return 0;
}