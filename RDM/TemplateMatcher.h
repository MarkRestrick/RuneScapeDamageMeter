#ifndef TEMPLATEMATCHER_H
#define TEMPLATEMATCHER_H


#include<opencv2\opencv.hpp>
#include <Windows.h>
#include<stdint.h>


using namespace cv;
using namespace std;

//The purpose of this class is to grab a screenshot of the desktop and return it as a Mat file

class TemplateMatcher
{
public:
	TemplateMatcher();
	~TemplateMatcher();

	bool GetMatch(Mat1b& Source, Mat1b& Template, float Thresh); //This function captures a screenshot, converts it to a mat file and returns it.
	

	Point GetPoint() { return m_MatchPoint; };


private:

	Rect m_DamageArea;

	Point m_MatchPoint; //If a template match is found, the location of the match will be stored in this variable

	Mat1f m_MatchResult;
	


};


#endif