#ifndef IMAGESETUP_H
#define IMAGESETUP_H

#include<opencv2\opencv.hpp>
#include <Windows.h>
#include<stdint.h>
#include "opencv2\imgproc.hpp"
#include <iostream>
#include "opencv2\opencv_modules.hpp"
#include <stdio.h>
#include <opencv2\xfeatures2d.hpp>
#include "opencv2/imgcodecs.hpp"
#include "opencv2/features2d.hpp"
#include "opencv/highgui.h"


using namespace cv;
using namespace std;

//The purpose of this class is to grab a screenshot of the desktop and return it as a Mat file

class ImageSetup
{
public:
	ImageSetup();
	~ImageSetup();

	void GeneralSetup();
	void DmgSetup();
	void SolakSetup();

	Mat1b GetDamageTag() { return m_DamageTagGray; };
	Mat1b GetChatTag() { return m_ChatTagGray; };
	Mat1b GetSolakTagA() { return m_SolakTagAGray; };
	Mat1b GetSolakTagB() { return m_SolakTagBGray; };
	Mat1b GetDamageNull() { return m_DmgValNullGray; };
	Mat1b GetDamage(int Value) { return m_DmgValGray[Value]; };

	Mat1b GetSolakBar() { return m_SolakBarGray; };
	Mat1b GetSolakCore() { return m_SolakCoreGray; };
	Mat1b GetSolakCoreEnd() { return m_SolakCoreEndGray; };
	Mat1b GetSolakStart() { return m_SolakStartGray; };
	Mat1b GetSolakLeftArm() { return m_SolakLeftArmGray; };
	Mat1b GetSolakRightArm() { return m_SolakRightArmGray; };
	Mat1b GetSolakLeftLeg() { return m_SolakLeftLegGray; };
	Mat1b GetSolakRightLeg() { return m_SolakRightLegGray; };
	Mat1b GetSolakP2Start() { return m_SolakP2StartGray; };
	Mat1b GetSolakP3Start() { return m_SolakP3StartGray; };
	Mat1b GetSolakP4Start() { return m_SolakP4StartGray; };
	Mat1b GetSolakMindDebuff() { return m_SolakMindDebuffGray; };
	Mat1b GetSolakEnd() { return m_SolakEndGray; };


	Rect GetDamageArea() { return m_DamageArea; };
	Rect GetChatArea() { return m_ChatArea; };
	void SetDamageArea(Rect DamageArea) { m_DamageArea = DamageArea; };
	void SetChatArea(Rect ChatArea) { m_ChatArea = ChatArea; };


private:

	Rect m_DamageArea;
	Rect m_ChatArea;

	Mat3b m_SolakTagA;
	Mat3b m_SolakTagB;
	Mat1b m_SolakTagAGray;
	Mat1b m_SolakTagBGray;

	Mat3b m_DamageTag;
	Mat1b m_DamageTagGray;

	Mat3b m_ChatTag;
	Mat1b m_ChatTagGray;

	Mat3b m_DmgValNull;
	Mat1b m_DmgValNullGray;
	Mat3b m_DmgVal[10];
	Mat1b m_DmgValGray[10];

	Mat3b m_SolakBar;
	Mat1b m_SolakBarGray;
	Mat3b m_SolakCore;
	Mat1b m_SolakCoreGray;
	Mat3b m_SolakCoreEnd;
	Mat1b m_SolakCoreEndGray;
	Mat3b m_SolakStart;
	Mat1b m_SolakStartGray;
	Mat3b m_SolakLeftArm;
	Mat1b m_SolakLeftArmGray;
	Mat3b m_SolakRightArm;
	Mat1b m_SolakRightArmGray;
	Mat3b m_SolakLeftLeg;
	Mat1b m_SolakLeftLegGray;
	Mat3b m_SolakRightLeg;
	Mat1b m_SolakRightLegGray;
	Mat3b m_SolakP2Start;
	Mat1b m_SolakP2StartGray;
	Mat3b m_SolakP3Start;
	Mat1b m_SolakP3StartGray;
	Mat3b m_SolakP4Start;
	Mat1b m_SolakP4StartGray;
	Mat3b m_SolakEnd;
	Mat1b m_SolakEndGray;
	Mat3b m_SolakMindDebuff;
	Mat1b m_SolakMindDebuffGray;

	




};


#endif