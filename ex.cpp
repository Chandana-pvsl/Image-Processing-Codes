#include<stdio.h>
#include"opencv2/highgui.hpp"
#include"opencv2/imgproc.hpp"
#include"opencv2/core.hpp"
#include<iostream>
 
using namespace cv;
using namespace std;

int main()
{
	int i,j,t;
	int a[9];
	Mat img = imread("/home/chandana/OpenCV/ip/veg.jpg",0);
	Mat temp =imread("/home/chandana/OpenCV/ip/veg.jpg",0);

	for(i = 0 ; i < img.rows-2 ;i++)
	{
		for(j = 0 ; j < img.cols-2 ;j++)
		{
			a[0]=img.at<uchar>(i,j);
			a[1]=img.at<uchar>(i+1,j);
			a[2]=img.at<uchar>(i+2,j);
			a[3]=img.at<uchar>(i,j+1);
			a[4]=img.at<uchar>(i+1,j+1);
			a[5]=img.at<uchar>(i+2,j+1);
			a[6]=img.at<uchar>(i,j+2);
			a[7]=img.at<uchar>(i+1,j+2);
			a[8]=img.at<uchar>(i+2,j+2);
			sort(a,a+8);
			t = (int)((a[4]+a[5])/2);
			temp.at<uchar>(i+1,j+1) = t;
		}
	}
	namedWindow("win",WINDOW_NORMAL);
	namedWindow("img",WINDOW_NORMAL);
	 imshow("win",temp);
	 imshow("img",img);
	 waitKey(0);
	 return 0;
}