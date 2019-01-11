#include<stdio.h>
#include"opencv2/highgui.hpp"
#include"opencv2/imgproc.hpp"
#include"opencv2/core.hpp"
#include<iostream>
 
using namespace cv;
using namespace std;
Mat img = imread("/home/chandana/OpenCV/ip/rubik.jpg",0);
int r;

void callback(int ,void*)
{
	int i,j,a,t;
	Mat img1(img.rows,img.cols,CV_8UC1,Scalar(0));
	for(i = 0 ; i< img.rows-2 ; i++)
	{
		for(j = 0 ; j<img.cols-2;j++)
		{
			t = 0;
			for(a=0;a<3;a++)
			{
				
				t+=img.at<uchar>(i,j+a);
				t-=img.at<uchar>(i+2,j+a);
				if(a==1)
					t-=img.at<uchar>(i+2,j+a);
			}
			if(t<0)
				t=-t;
			for(a=0;a<3;a++)
			{
				
				t-=img.at<uchar>(i+a,j);
				t+=img.at<uchar>(i+a,j+2);
				if(a==1)
					t-=img.at<uchar>(i+2,j+a);
			}
			if(t<0)
				t=-t;
			if(t>r)
			{
				img1.at<uchar>(i+1,j+1) = 255;
			}
			else
				img1.at<uchar>(i+1,j+1) = 0;
		}
	}
	imshow("win",img1);
}

int main()
{
	r = 0;
	namedWindow("win",WINDOW_NORMAL);
	createTrackbar("edges","win",&r,255,callback);
	namedWindow("win1",WINDOW_NORMAL);
	imshow("win1",img);
	waitKey(0);
	return 0;
}