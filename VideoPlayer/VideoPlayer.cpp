// VideoPlayer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main( int argc, char** argv )
{
	VideoCapture cap;
	//cap.open("tcp://192.168.1.1:5555/video?h264");
	//cap.open("tcp://192.168.0.3:80/cgi-bin/fwstream.cgi?FwModId=0&PortId=0&PauseTime=0&FwCgiVer=0x0001");
	cap.open("rtsp://192.168.0.3/cam0_1");
	//cap.open("Drone.mov");

	// Print build information.
	std::cout << "Using OpenCV version " << CV_VERSION << std::endl ;
	std::cout << getBuildInformation();


	if (!cap.isOpened()) 
	{
		cout << "Cant find the file." << endl;
		return 0;
	}

	Mat edges;
	namedWindow("edges",1);
	for(;;)
	{
		Mat frame;
		cap >> frame;
		//frame = imread("e.1.l.1.c.9.tif", IMREAD_COLOR); // Read the file
		imshow("edges", frame);
		if (waitKey(30) >= 0) break;
	}

	return 0;
}



int mdain( int argc, char** argv )
{
    if( argc != 2)
    {
     cout <<" Usage: display_image ImageToLoadAndDisplay" << endl;
     return -1;
    }
    Mat image;
    image = imread(argv[1], IMREAD_COLOR); // Read the file
    if( image.empty() ) // Check for invalid input
    {
        cout << "Could not open or find the image" << std::endl ;
        return -1;
    }
    namedWindow( "Display window", WINDOW_AUTOSIZE ); // Create a window for display.
    imshow( "Display window", image ); // Show our image inside it.
    waitKey(0); // Wait for a keystroke in the window
    return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

