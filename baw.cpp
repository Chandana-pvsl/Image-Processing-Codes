#include<stdio.h>
#include"opencv2/highgui.hpp"
#include"opencv2/imgproc.hpp"
#include"opencv2/core.hpp"
//#include<iostream	>
 
using namespace cv;
using namespace std;

int main()
{
	Mat img = imread("/home/chandana/OpenCV/ip/images.jpeg",1);
	Mat temp(img.rows,img.cols,CV_8UC1,Scalar(0));
    int i,j;
    float t;
    for(i = 0 ; i<img.rows;i++)
    {
    	for(j = 0 ; j<img.cols;j++)
    	{
    		t = 0.114*img.at<Vec3b>(i,j)[0]+0.527*img.at<Vec3b>(i,j)[1]+0.299*img.at<Vec3b>(i,j)[2];
    		temp.at<uchar>(i,j)=(int)t;
    	}
    } 
    namedWindow("win",WINDOW_NORMAL);
    imshow("win",temp);
    waitKey(0);
    return 0;
}