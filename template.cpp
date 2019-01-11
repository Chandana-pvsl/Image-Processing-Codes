#include<stdio.h>
#include"opencv2/highgui.hpp"
#include"opencv2/imgproc.hpp"
#include"opencv2/core.hpp"
#include<iostream>
#include<cmath>
 
using namespace cv;
using namespace std;

Mat img = imread("/home/chandana/OpenCV/ip/coins.jpg",1);
Mat temp = imread("/home/chandana/OpenCV/ip/coins1.jpg",1);
int r;

void method_callback(int , void*)
{
	Mat img_display = imread("/home/chandana/OpenCV/ip/coins.jpg",1);
	Mat result(img.rows-temp.rows+1,img.cols-temp.cols+1,CV_32FC1,Scalar(0));

	matchTemplate(img,temp,result,r);
	normalize(result,result,0,1,NORM_MINMAX,-1,Mat());

	double min,max;
	Point minloc,maxloc,matchloc;
	minMaxLoc(result, &min,&max,&minloc,&maxloc,Mat());

	if(r == CV_TM_SQDIFF || r == CV_TM_SQDIFF_NORMED )
	{
		matchloc = minloc;
	}
	else
    { matchloc = maxloc; }

  rectangle( img_display, matchloc, Point( matchloc.x + temp.cols , matchloc.y + temp.rows ), Scalar::all(0), 2, 8, 0 );
  rectangle( result, matchloc, Point( matchloc.x + temp.cols , matchloc.y + temp.rows ), Scalar::all(0), 2, 8, 0 );

  imshow( "win", img_display );
  imshow( "win1", result );

  return;
}


int main()
{
	r = 0;
	namedWindow("win",WINDOW_NORMAL);
	namedWindow("win1",WINDOW_NORMAL);
	createTrackbar("methods","win",&r,5,method_callback);
	waitKey(0);
	return 0;
}