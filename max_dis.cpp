#include<stdio.h>
#include"opencv2/highgui.hpp"
#include"opencv2/imgproc.hpp"
#include"opencv2/core.hpp"
#include<iostream>
#include<stack>
 
using namespace cv;
using namespace std;

Mat img = imread("/home/chandana/OpenCV/ip/dfs_path.jpg",0);
Mat vis(img.rows,img.cols,CV_8UC1,Scalar(0));
int flag=0;

typedef struct shape
{
	int id;
	int x;
	int y;
	struct shape* next;
}shape;

shape *head = NULL;

void dfs(int x , int y)
{
	int i,j;
	int a=0,b=0,c=0;
	shape *temp = malloc(sizeof(shape));
	pair<int,int> p ;
	p.first = x;
	p.second = y;
	pair<int,int> p1;
	stack<pair<int,int> > s;
	s.push(p);
	vis.at<uchar>(x,y) = 255;
	while(!s.empty())
	{
		p = s.top();
		s.pop();
		for(i = p.first-1 ; i <= p.first+1 ;i++)
		{
			for( j=p.second-1 ; j <=p.second+1 ; j++)
			{
				if( i < 0 || j < 0 || i>=img.rows || j>=img.cols)
				{
					continue;
				}
				
				if(vis.at<uchar>(i,j)==0 && img.at<uchar>(i,j)==0)
				{
					p1.first = i;
				    p1.second = j;
				    a+=i;
				    b+=j;
				    c++;
					vis.at<uchar>(i,j) =255;
					s.push(p1);
				}
			}
		}
	}
	a = a/c;
	b = b/c;
	temp->id = flag;
	temp->x = a;
	temp->y = b;
	temp->next = head;
	head = temp;
}

int main()
{
	int i,j;
	
	for( i = 0 ; i<img.rows ; i++)
	{
		for( j = 0 ; j<img.cols ; j++)
		{
			if(vis.at<uchar>(i,j)==0 && img.at<uchar>(i,j)==0)
			{
				dfs(i,j);
				flag++;
			}
		}
	}
	for( i =0;i<flag;i++)
	{
		for( j = i;j<flag;j++)
		{
			
		}
	}
	cout<<flag;
	return 0;
}