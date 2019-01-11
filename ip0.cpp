#include"opencv2/highgui.hpp"
#include"opencv2/imgproc.hpp"
#include"opencv2/core.hpp"
 
using namespace cv;
using namespace std;

int main()
{
  Mat img(50,50,CV_8UC3,Scalar(0,255,255));
  namedWindow("win",WINDOW_NORMAL);
  imshow("win",img);
  waitKey(0);
  return 0;
}
