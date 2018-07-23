#ifndef SCREENCAPTURE_H
#define SCREENCAPTURE_H

#include<opencv2\opencv.hpp>
#include <Windows.h>
#include<stdint.h>


using namespace cv;
using namespace std;

//The purpose of this class is to grab a screenshot of the desktop and return it as a Mat file

class ScreenCapture
{
public:
	ScreenCapture();
	~ScreenCapture();

	Mat1b GetScreen(); //This function captures a screenshot, converts it to a mat file and returns it.

private:

	Mat hwnd2mat(HWND hwnd);

	Mat src;

	Mat1b m_SrcGray;

	HWND desktop;

};


#endif