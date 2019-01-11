#include<stdio.h>
#include"opencv2/highgui.hpp"
#include"opencv2/imgproc.hpp"
#include"opencv2/core.hpp"
#include<iostream>
#include<cmath>
 
using namespace cv;
using namespace std;

Mat img = imread("/home/chandana/OpenCV/ip/x.png",1);
Mat temp(img.rows,img.cols,CV_8UC1,Scalar(0));
Mat img1(img.rows,img.cols,CV_8UC1,Scalar(0));
int r;
RNG rng(12345);

void callback(int,void*)
{
	vector<vector<Point> > contours;
	vector<Vec4i> hierarchy;

	Canny(img1,temp,r,r*2,3);
	findContours(temp,contours,hierarchy,RETR_TREE,CHAIN_APPROX_SIMPLE,Point(0,0));
	Mat img2(temp.rows,temp.cols,CV_8UC3,Scalar(0,0,0));

	for(size_t i = 0 ; i < contours.size();i++)
	{
		 Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
       	drawContours( img2, contours, (int)i, color, 2, 8, hierarchy, 0, Point() );
	}
	namedWindow("contours",	WINDOW_NORMAL);
	imshow("contours",img2);

}

int main()
{
	r=0;
	cvtColor(img, img1, COLOR_BGR2GRAY);
  	blur(img1, img1, Size(3,3));
  	namedWindow("win",WINDOW_NORMAL);
  	imshow("win",img1);

  	createTrackbar("thresh","win",&r,255,callback);
  	waitKey(0);
    return 0;
}