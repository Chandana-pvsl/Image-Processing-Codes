#include<stdio.h>
#include"opencv2/highgui.hpp"
#include"opencv2/imgproc.hpp"
#include"opencv2/core.hpp"
//#include<iostream	>
 
using namespace cv;
using namespace std;

int main()
{
	int i,j,t;
	Mat img = imread("/home/chandana/OpenCV/ip/a.png",0);
	Mat temp = imread("/home/chandana/OpenCV/ip/a.png",0);

	for(i = 0 ; i < img.rows-2 ;i++)
	{
		for(j = 0 ; j < img.cols-2 ;j++)
		{
			t =(img.at<uchar>(i,j)+img.at<uchar>(i,j+1)+img.at<uchar>(i,j+2)+
			img.at<uchar>(i+1,j)+img.at<uchar>(i+1,j+1)+img.at<uchar>(i+1,j+2)+img.at<uchar>(i+2,j)+
			img.at<uchar>(i+2,j+1)+img.at<uchar>(i+2,j+2))/9;
			temp.at<uchar>(i+1,j+1) = t;
		}
	}
	namedWindow("win",WINDOW_NORMAL);
	namedWindow("img",WINDOW_NORMAL);
	 imshow("win",img);
	 imshow("img",img);
	 waitKey(0);
	 //imshow("win",temp);
	 //waitKey(0);
	 return 0;
}
