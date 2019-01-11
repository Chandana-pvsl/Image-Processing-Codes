#include<stdio.h>
#include"opencv2/highgui.hpp"
#include"opencv2/imgproc.hpp"
#include"opencv2/core.hpp"
//#include<iostream	>
 
using namespace cv;
using namespace std;
Mat img = imread("/home/chandana/OpenCV/ip/a.png",0);
int t,k;

void callback(int ,void*)
{
	int i,j;
	float a;
	Mat temp(img.rows,img.cols,CV_8UC1,Scalar(0));
	for(i = 0 ; i<img.rows ; i++)
	{
		for(j = 0 ; j< img.cols;j++)
		{
			a = 1+(float)(k)/255;
			if((int)(a*img.at<uchar>(i,j))+t<=255)
				temp.at<uchar>(i,j)=(int)(a*img.at<uchar>(i,j))+t;
			else
				temp.at<uchar>(i,j)=255;
		}
	}
    imshow("win",temp);
    //waitKey(0);
}



int main()
{
	t = 0;
	k = 0;
	namedWindow("win",WINDOW_NORMAL);
	createTrackbar("brightness","win",&t,255,callback);
	createTrackbar("intensity","win",&k,255,callback);	
	waitKey(0);
	return 0;
}