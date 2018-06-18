
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv/cvaux.hpp>
#include <fstream>
using namespace std;
using namespace cv;

#define BYTE unsigned char


int main(int argc, const char * argv[])
{
#if 1
    IplImage* img = cvLoadImage("//Users//firmiana//1.jpg");
    cvNamedWindow("picture", 1);
    cvShowImage("picture", img);
    cvWaitKey(0);
    cvReleaseImage(&img);
    cvDestroyWindow("picture");
#endif
    return 0;
}
