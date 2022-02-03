#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
using namespace cv;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // VideoCapture class for playing video for which faces to be detected
    VideoCapture capture;
    Mat frame, image;
    // Start Video..1) 0 for WebCam 2) "Path to Video" for a Local Video
        capture.open(0);
        if( capture.isOpened() )
        {
            // Capture frames from video and detect faces
            std::cout << "Face Detection Started...." << std::endl;
            while(1)
            {
                capture >> frame;
                if( frame.empty() )
                    break;
                Mat frame1 = frame.clone();
                imshow("Face Detection",frame1);
                char c = (char)waitKey(10);

                // Press q to exit from window
                if( c == 27 || c == 'q' || c == 'Q' )
                    break;
            }
        }
        else
            std::cout<<"Could not Open Camera";
}

MainWindow::~MainWindow()
{
    delete ui;
}
