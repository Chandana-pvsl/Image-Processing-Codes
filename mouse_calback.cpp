#include<stdio.h>
#include"opencv2/highgui.hpp"
#include"opencv2/imgproc.hpp"
#include"opencv2/core.hpp"
#include<iostream>
#include<stack>
 
using namespace cv;
using namespace std;

Mat img = imread("/home/chandana/OpenCV/ip/rubik.jpg",1);

void callback(int event,int x,int y,int d,void *)
{
	
	if(event ==EVENT_LBUTTONDOWN)
		printf("%d        %d",x,y);
}

int main()
{
	namedWindow("win",WINDOW_NORMAL);
	imshow("win",img);
	setMouseCallback("win",callback);
	
	waitKey(0);
	return 0;
}