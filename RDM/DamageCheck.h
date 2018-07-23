#ifndef DAMAGECHECK_H
#define DAMAGECHECK_H

#include<opencv2\opencv.hpp>
#include <Windows.h>
#include<stdint.h>
#include "TemplateMatcher.h"
#include "ImageSetup.h"


using namespace cv;
using namespace std;

//The purpose of this class is to take in a picture of the damage screen and return the value that is being displayed as an unsigned integer

class DamageCheck
{
public:
	DamageCheck();
	~DamageCheck();

	unsigned int GetDamage(Mat1b Source); //This function takes in a grayscale image of the damage meter and works out what the damage being displayed is

private:
	Rect m_DmgRect = Rect(0, 0, 6, 9);
	ImageSetup m_DmgImgStore;
	TemplateMatcher m_DmgTemplate;

	Mat1b m_DmgCrops[14];

	int m_DamageValsCount;

	int m_DamageFramesCounter = 0;
	int m_DamageFramesLimit = 5;

	unsigned int m_TotalDamage;

	void Units(Mat1b Source);
	void Tens(Mat1b Source);
	void Hundreds(Mat1b Source);
	void Thousands(Mat1b Source);
	void TenThousands(Mat1b Source);
	void HundredThousands(Mat1b Source);
	void Millions(Mat1b Source);
	void TenMillions(Mat1b Source);
	void HundredMillions(Mat1b Source);
	void Billions(Mat1b Source);

	int IdentifyNumber(Mat1b NumberImg);

};


#endif