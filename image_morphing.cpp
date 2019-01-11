#include<stdio.h>
#include"opencv2/highgui.hpp"
#include"opencv2/imgproc.hpp"
#include"opencv2/core.hpp"
#include<iostream>
 
using namespace cv;
using namespace std;
Mat img = imread("/home/chandana/OpenCV/ip/c.jpeg",1);
Mat img1 = imread("/home/chandana/OpenCV/ip/b.jpeg",1);
int r;

void callback(int ,void*)
{
	int i,j,a,t;
	float k;
	Mat img2(img.rows,img.cols,CV_8UC3,Scalar(0,0,0));
	k = r/100.0;
	for(i = 0 ; i< img.rows; i++)
	{
		for(j = 0 ; j<img.cols;j++)
		{
			img2.at<Vec3b>(i,j)[0]= k*img.at<Vec3b>(i,j)[0] + (1-k)*img1.at<Vec3b>(i,j)[0];
			img2.at<Vec3b>(i,j)[1]= k*img.at<Vec3b>(i,j)[1] + (1-k)*img1.at<Vec3b>(i,j)[1];
			img2.at<Vec3b>(i,j)[2]= k*img.at<Vec3b>(i,j)[2] + (1-k)*img1.at<Vec3b>(i,j)[2];
		}
	}
	imshow("win",img2);
}

int main()
{
	r = 0;
	namedWindow("win",WINDOW_NORMAL);
	createTrackbar("degree_of_morphing","win",&r,100,callback);
	waitKey(0);
	return 0;
}