#include<stdio.h>
#include"opencv2/highgui.hpp"
#include"opencv2/imgproc.hpp"
#include"opencv2/core.hpp"
//#include<iostream	>
 
using namespace cv;
using namespace std;
Mat img = imread("/home/chandana/OpenCV/ip/images.jpeg",0);
int t;


void callback(int ,void*)
{
	int i,j;
	Mat temp(img.rows,img.cols,CV_8UC1,Scalar(0));
	for(i = 0 ; i<img.rows ; i++)
	{
		for(j = 0 ; j< img.cols;j++)
		{
			if(img.at<uchar>(i,j)<t)
				temp.at<uchar>(i,j)=0;
			else
				temp.at<uchar>(i,j)=255;
		}
	}
    imshow("win",temp);
}



int main()
{
	t = 0;
	namedWindow("win",WINDOW_NORMAL);
	createTrackbar("thresh","win",&t,255,callback);
    callback(t,0);
	
	waitKey(0);
	return 0;
}