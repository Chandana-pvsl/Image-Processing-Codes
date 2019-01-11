#include<stdio.h>
#include"opencv2/highgui.hpp"
#include"opencv2/imgproc.hpp"
#include"opencv2/core.hpp"
 
using namespace cv;
using namespace std;

int main()
{
	Mat img(50,50,CV_8UC3,Scalar(0,0,0));
	int i,j;
	for(i = 0 ; i < 50 ; i++)
	{
		for( j = 0 ; j < 50 ; j++)
		{
			if(i<j)
				img.at<uchar>(i,j)=150;
			else
				img.at<uchar>(i,j)=0;
		}
	}
	namedWindow("win",WINDOW_NORMAL);
	imshow("win",img);
	waitKey(0);
	return 0;
}
	