#include<stdio.h>
#include"opencv2/highgui.hpp"
#include"opencv2/imgproc.hpp"
#include"opencv2/core.hpp"
#include<iostream>
 
using namespace cv;
using namespace std;

int main()
{
	Mat img = imread("/home/chandana/OpenCV/ip/filter4.png",0);
	Mat img1 =imread("/home/chandana/OpenCV/ip/filter4.png",0) ;
	int i,j;
	int a[9];
	for(i = 0 ; i<img.rows-2 ; i++)
	{
		for(j = 0 ; j < img.cols-2 ; j++)
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
			sort(a,a+9);
			img1.at<uchar>(i,j)=img1.at<uchar>(i+1,j)=img1.at<uchar>(i+2,j)=img1.at<uchar>(i,j+1)=img1.at<uchar>(i+1,j+1)=img1.at<uchar>(i+2,j+1)=img1.at<uchar>(i,j+2)
			=img1.at<uchar>(i+1,j+2)=img1.at<uchar>(i+2,j+2) = a[8];

		} 
	}
	Mat img2 = img1.clone();
	for(i = 0 ; i<img.rows-2 ; i++)
	{
		for(j = 0 ; j < img.cols-2 ; j++)
		{
			a[0]=img1.at<uchar>(i,j);
			a[1]=img1.at<uchar>(i+1,j);
			a[2]=img1.at<uchar>(i+2,j);
			a[3]=img1.at<uchar>(i,j+1);
			a[4]=img1.at<uchar>(i+1,j+1);
			a[5]=img1.at<uchar>(i+2,j+1);
			a[6]=img1.at<uchar>(i,j+2);
			a[7]=img1.at<uchar>(i+1,j+2);
			a[8]=img1.at<uchar>(i+2,j+2);
			sort(a,a+9);
			
			img2.at<uchar>(i,j)=img2.at<uchar>(i+1,j)=img2.at<uchar>(i+2,j)=img2.at<uchar>(i,j+1)=img2.at<uchar>(i+1,j+1)=img2.at<uchar>(i+2,j+1)=img2.at<uchar>(i,j+2)
			=img2.at<uchar>(i+1,j+2)=img2.at<uchar>(i+2,j+2) = a[0];

		} 
	}
	Mat img3 = img2.clone();
	for(i = 0 ; i<img.rows-2 ; i++)
	{
		for(j = 0 ; j < img.cols-2 ; j++)
		{
			a[0]=img2.at<uchar>(i,j);
			a[1]=img2.at<uchar>(i+1,j);
			a[2]=img2.at<uchar>(i+2,j);
			a[3]=img2.at<uchar>(i,j+1);
			a[4]=img2.at<uchar>(i+1,j+1);
			a[5]=img2.at<uchar>(i+2,j+1);
			a[6]=img2.at<uchar>(i,j+2);
			a[7]=img2.at<uchar>(i+1,j+2);
			a[8]=img2.at<uchar>(i+2,j+2);
			sort(a,a+9);
			
			img3.at<uchar>(i,j)=img3.at<uchar>(i+1,j)=img3.at<uchar>(i+2,j)=img3.at<uchar>(i,j+1)=img3.at<uchar>(i+1,j+1)=img3.at<uchar>(i+2,j+1)=img3.at<uchar>(i,j+2)
			=img3.at<uchar>(i+1,j+2)=img3.at<uchar>(i+2,j+2) = a[0];

		} 
	}

	namedWindow("win",WINDOW_NORMAL);
	imshow("win",img1);
	namedWindow("img",WINDOW_NORMAL);
	imshow("img",img3);
	namedWindow("win2",WINDOW_NORMAL);
	imshow("win2",img2);
	waitKey(0);
	return 0;
}