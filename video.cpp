#include<stdio.h>
#include"opencv2/highgui.hpp"
#include"opencv2/imgproc.hpp"
#include"opencv2/core.hpp"
#include<iostream>
 
using namespace cv;
using namespace std;

int main()
{
	Mat img;
	VideoCapture vid(0);
	while(vid.read(img))
	{
		imshow("win",img);
		waitKey(10);
	}
	return 0;
}