//#include <highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int g_nMedianBlurValue = 2;
Mat element = getStructuringElement(MORPH_RECT, Size(3, 3));
vector<Point> point_seq;

int main()
{
    Mat selectChannel(Mat src, int channel);
    bool objectDetection(Mat src, int threshold_value, int areasize, int channel);
    Mat Threshold(Mat src, int iLowH, int iHighH, int iLowS, int iHighS, int iLowV, int iHighV);
    
    //HSV阈值
    int iLowH = 0;
    int iHighH = 10;
    int iLowS = 43;
    int iHighS = 255;
    int iLowV = 46;
    int iHighV = 255;
    
    string path = "timg.jpeg";
    
    Mat imgSrc = imread(path);
    Mat imgThresholded = Threshold(imgSrc, iLowH, iHighH, iLowS, iHighS, iLowV, iHighV);
    objectDetection(imgThresholded, 100, 100, 1);
    
    imshow("Oringinal Picture", imgSrc);
    imshow("Thresholded Picture", imgThresholded);
    
    waitKey(0);
}

//HSV阈值分割
Mat Threshold(Mat src, int iLowH, int iHighH, int iLowS, int iHighS, int iLowV, int iHighV)
{
    Mat imgHsv;
    Mat imgThresholded;
    
    vector<Mat> hsvSplit;
    
    cvtColor(src, imgHsv, COLOR_BGR2HSV);
    
    //通道分离处理
    split(imgHsv, hsvSplit);
    equalizeHist(hsvSplit[2], hsvSplit[2]);
    merge(hsvSplit, imgHsv);
    
    //HSV分离
    inRange(imgHsv, Scalar(iLowH, iLowS, iLowV), Scalar(iHighH, iHighS, iHighV), imgThresholded);
    
    //开操作去除噪点
    Mat element = getStructuringElement(MORPH_RECT, Size(5, 5));
    morphologyEx(imgThresholded, imgThresholded, MORPH_OPEN, element);
    
    //闭操作连接连通域
    morphologyEx(imgThresholded, imgThresholded, MORPH_CLOSE, element);
    
    //图像膨胀
    for (int i = 0; i < 3; i++)
    {
        dilate(imgThresholded, imgThresholded, element);
    }
    
    return imgThresholded;
}

//通道选择
Mat selectChannel(Mat src, int channel)
{
    Mat image, gray, hsv;
    image = src.clone();
    
    //下面两个cvtColor函数内存出错
    cvtColor(image, gray, CV_BGR2GRAY);
    cvtColor(image, hsv, CV_BGR2HSV);
    vector<Mat> imageRGBORHSV;
    Mat imageSC;
    //cvSplit(image,imageSC,0,0,0);
    split(image, imageRGBORHSV);
    imageSC = imageRGBORHSV[0];
    
    return imageSC;
}

//根据阈值分割图像找出物体
bool objectDetection(Mat src, int threshold_value, int areasize, int channel)
{
    int i;
    Mat displayImage = src.clone();
    
    Mat imageSC = selectChannel(src, channel);
    //图像中值滤波
    medianBlur(imageSC, imageSC, g_nMedianBlurValue * 2 + 1);//中值滤波
    threshold(imageSC, imageSC, threshold_value, 255, CV_THRESH_BINARY);
    threshold(imageSC, imageSC, threshold_value, 255, CV_THRESH_BINARY_INV);          //把元素的每一位取反
    
    
    dilate(imageSC, imageSC, element);
    Scalar color = Scalar(155, 155, 155);
    vector<vector<Point>> Contours;
    vector<Vec4i> Hierarchy;
    
    findContours(imageSC, Contours, Hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));
    vector<Moments> mu(Contours.size());
    vector<Point2f> mc(Contours.size());
    Mat drawing = Mat::zeros(src.size(), CV_8UC3);
    for (int i = 0; i< Contours.size(); i++) {
        mu[i] = moments(Contours[i], false);
    }
    for (int i = 0; i< Contours.size(); i++) {
        mc[i] = Point2d(mu[i].m10 / mu[i].m00, mu[i].m01 / mu[i].m00);
    }
    
    for (int i = 0; i< Contours.size(); i++) {
        double tmparea = fabs(contourArea(Contours[i]));
        if (tmparea>areasize) {
            drawContours(displayImage, Contours, i, color, 2, 8, Hierarchy, 0, Point());
            
            rectangle(drawing, boundingRect(Contours.at(i)), cvScalar(0, 255, 0));
                
            char tam[10000];
            sprintf(tam, "(%0.0f,%0.0f,%0.0d,%0.0d)", mc[i].x, mc[i].y, boundingRect(Contours.at(i)).height, boundingRect(Contours.at(i)).width);
            //tam[0]=mc[i].x;
            
            cout << "x " << mc[i].x << "y  " << mc[i].y << " height " << boundingRect(Contours.at(i)).height << " width " << boundingRect(Contours.at(i)).width << endl;
            circle(drawing, mc[i], 5, cvScalar(255, 0, 0));
            putText(drawing, tam, Point(mc[i].x, mc[i].y), FONT_HERSHEY_SIMPLEX, 0.4, Scalar(255, 0, 255), 1);
            
        }
    }
    
    imshow("pic", drawing);
    imshow("imageSC", imageSC);
    imshow("src", src);
    waitKey(0);
    return false;
}
