#include<stdio.h>
#include"opencv2/highgui.hpp"
#include"opencv2/imgproc.hpp"
#include"opencv2/core.hpp"
#include<iostream>
#include<cmath>
 
using namespace cv;
using namespace std;

Mat img = imread("/home/chandana/OpenCV/ip/pentagon.png",0);
int a = sqrt(img.rows*img.rows + img.cols*img.cols);
Mat img1(a,360,CV_8UC1,Scalar(0));
Mat temp(img.rows,img.cols,CV_8UC1,Scalar(0));
int r=0;

void hough()
{
	int i,j,k,x;
	for(i = 0 ; i < img.rows ;i++)
	{
		for( j = 0 ; j < img.cols ; j++)
		{
			if(img.at<uchar>(i,j)>150)
			{
				for ( k = 0 ; k < 180 ;k++)
				{
					x = (double(j))*cos(k*3.14/180) + (double(i))*sin(k*3.14/180);
					//cout<<x <<endl;
					/*if(x<0)
						x=-x;*/
					if( img1.at<uchar>(x,k)>250)
					{
						
						img1.at<uchar>(x,k) =255;
					}
					else
					{
						img1.at<uchar>(x,k)+=15;
					}
				}
			}
		}
	}
	/*namedWindow("win1",WINDOW_NORMAL);
	imshow("win1",img1);
	waitKey(0);*/
}

void callback(int ,void*)
{
	int i,j,x,y;
	for(i = 0 ; i <img1.rows;i++)
	{
		for(j = 0 ; j < img1.cols ; j++)
		{
			if(img1.at<uchar>(i,j) >r)
			{
				x = i*cos(j*3.14/180);
				y = i*sin(j*3.14/180);
				temp.at<uchar>(y,x) = 255;
			}
		}
	}
	imshow("win",temp);
}


int main()
{
	hough();
	r = 0;
	namedWindow("win",WINDOW_NORMAL);
	createTrackbar("bright","win",&r,255,callback);
	waitKey(0);
	return 0;
}