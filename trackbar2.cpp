#include<stdio.h>
#include"opencv2/highgui.hpp"
#include"opencv2/imgproc.hpp"
#include"opencv2/core.hpp"
//#include<iostream	>
 
using namespace cv;
using namespace std;

Mat img = imread("/home/chandana/OpenCV/ip/a.png",1);
int r,R,g,G,b,B;


void callback(int ,void*)
{
	int i,j;
	Mat temp(img.rows,img.cols,CV_8UC3,Scalar(0,0,0));
	/*while(waitKey(1)!='q')
	{*/
		for(i = 0 ; i<img.rows;i++)
		{
			for(j = 0 ; j< img.cols;j++)
			{
				if(img.at<Vec3b>(i,j)[2]>r && img.at<Vec3b>(i,j)[2]<R && img.at<Vec3b>(i,j)[1]>g && img.at<Vec3b>(i,j)[1]<G && img.at<Vec3b>(i,j)[0]>b && img.at<Vec3b>(i,j)[0]<B )				
				{
					temp.at<Vec3b>(i,j)[0] = img.at<Vec3b>(i,j)[0];
					temp.at<Vec3b>(i,j)[1] = img.at<Vec3b>(i,j)[1];
					temp.at<Vec3b>(i,j)[2] = img.at<Vec3b>(i,j)[2];
            	}
            	else
            	{
            		temp.at<Vec3b>(i,j)[0] = 0;
					temp.at<Vec3b>(i,j)[1] = 0;
					temp.at<Vec3b>(i,j)[2] = 0;
            	}
        	}
    	}
	//}
    imshow("win",temp);
}

int main()
{
	
	namedWindow("win",WINDOW_NORMAL);
	r = 0;
	b = 0;
	g = 0;
	R = 0;
	B = 0;
	G = 0;
	createTrackbar("low_r","win",&r,255,callback);
	createTrackbar("high_r","win",&R,255,callback);
	createTrackbar("low_g","win",&g,255,callback);
	createTrackbar("high_g","win",&G,255,callback);
	createTrackbar("low_b","win",&b,255,callback);
	createTrackbar("high_b","win",&B,255,callback);
	//callback()
	
	waitKey(0);
	//waitkey(0);

	return 0;
}