#include<stdio.h>
#include"opencv2/highgui.hpp"
#include"opencv2/imgproc.hpp"
#include"opencv2/core.hpp"
#include<math.h>
#include<algorithm>
//#include<iostream	>
 
using namespace cv;
using namespace std;

Mat img = imread("/home/chandana/OpenCV/ip/a.png",0);
int r;


void angle(int , void*)
{
	Mat temp(2*max(img.rows,img.cols),2*max(img.rows,img.cols),CV_8UC1,Scalar(0));
	int a,b,c,d;
	a = img.rows/2;
	b = img.cols/2;
    int i,j;
    float t;
    t = (r/360.0)*2*3.14;
    for( i = 0 ; i < img.rows ; i++)
    {
    	for(j = 0 ; j < img.cols ; j++)
    	{
    		c = (i-a)*cos(t) - (j-b)*sin(t);
    		d = (i-a)*sin(t) + (j-b)*cos(t);
    		c = c+max(img.rows,img.cols);
    		d =d+max(img.rows,img.cols);
        	temp.at<uchar>(c,d) = img.at<uchar>(i,j);
    	}
    }
    imshow("win",temp);
}

int main()
{
	r = 0;
	namedWindow("win",WINDOW_NORMAL);
	createTrackbar("rotate","win",&r,360,angle);
	waitKey(0);
	return 0;
}
