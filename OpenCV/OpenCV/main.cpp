//
//  main.cpp
//  OpenCV
//
//  Created by zpf on 15-4-11.
//  Copyright (c) 2015年 zpf. All rights reserved.
//
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv/cv.h>
#include <iostream>





using namespace cv;
using namespace std;

int main(int argc, char** argv){
    if (argc != 2) {
        cout << "Usage: display_image ImageToLoadAndDisplay"<< endl;
        return -1;
    }
    
    char* imageName = argv[1];
    
    Mat image;
    image = imread(imageName, CV_LOAD_IMAGE_COLOR);
    
    if (!image.data) {
        cout << "Could not open or find the image" << std::endl;
        return -1;
    }
    
    Mat M(100,100,CV_8UC3,Scalar(0,0,255));
    cout << "M = "<< endl << " " << M << endl << endl;
    
    Mat gray_image;
    cvtColor(image, gray_image, CV_BGR2GRAY);
    imwrite("./images/Gray_image.jpg", gray_image);
    namedWindow("Display window", CV_WINDOW_AUTOSIZE);
    namedWindow("Gray Image", CV_WINDOW_AUTOSIZE);
    imshow("Display window", image);
    imshow("Gray image", gray_image);
    imshow("Mat",M);
    
    waitKey(0);
    
    return 0;
}

