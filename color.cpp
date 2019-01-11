#include<stdio.h>
#include"opencv2/highgui.hpp"
#include"opencv2/imgproc.hpp"
#include"opencv2/core.hpp"
#include<iostream>
#include<stack>
 
using namespace cv;
using namespace std;

Mat img = imread("/home/chandana/OpenCV/ip/shapes.jpg",0);
Mat temp = imread("/home/chandana/OpenCV/ip/shapes.jpg",1);

void callback1(int event,int x,int y,int d,void *)
{
	if(event==EVENT_LBUTTONDOWN)
	{
		Point p = Point(x,y);
		circle(temp,p,1,Scalar(255,0,0),10,4,0);
	}
	imshow("win",temp);
	waitKey(1);
}

void callback(int event,int x,int y,int d,void *)
{
	if(event==EVENT_MOUSEMOVE)
	{
		setMouseCallback("win",callback1);
		
	}
	imshow("win",temp);
	waitKey(1);
}

int main()
{
	namedWindow("win",WINDOW_NORMAL);
	imshow("win",temp);
	setMouseCallback("win",callback);
	waitKey(0);
	return 0;
}