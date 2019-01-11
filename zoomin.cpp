#include<stdio.h>
#include"opencv2/highgui.hpp"
#include"opencv2/imgproc.hpp"
#include"opencv2/core.hpp"
//#include<iostream	>
 
using namespace cv;
using namespace std;

int main()
{
	Mat img = imread("/home/chandana/OpenCV/ip/a.png",1);
	Mat temp(img.rows/2,img.cols/2,CV_8UC3,Scalar(0,0,0));
	int i,j;
	for( i = 0 ; i<img.rows/2 ; i=i+2)
	{
		for(j = 0 ; j<img.cols/2 ; j = j+2)
		{
         	temp.at<Vec3b>(i,j)[0] = (img.at<Vec3b>(2*i,2*j)[0] + img.at<Vec3b>(2*i,2*j+1)[0] + img.at<Vec3b>(2*i+1,2*j)[0] +img.at<Vec3b>(2*i+1,2*j+1)[0])/4;
			temp.at<Vec3b>(i,j)[1] = (img.at<Vec3b>(2*i,2*j)[1] + img.at<Vec3b>(2*i,2*j+1)[1] + img.at<Vec3b>(2*i+1,2*j)[1] +img.at<Vec3b>(2*i+1,2*j+1)[1])/4;
			temp.at<Vec3b>(i,j)[2] = (img.at<Vec3b>(2*i,2*j)[2] + img.at<Vec3b>(2*i,2*j+1)[2] + img.at<Vec3b>(2*i+1,2*j)[2] +img.at<Vec3b>(2*i+1,2*j+1)[2])/4;
		}		
	}
	namedWindow("win",WINDOW_AUTOSIZE);
	namedWindow("img",WINDOW_AUTOSIZE);
	imshow("win",temp);
	imshow("img",img);
	waitKey(0);
	return 0;
}