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
	void TelosSetup();

	Mat1b& GetDamageTag() { return m_DamageTagGray; };
	Mat1b& GetChatTag() { return m_ChatTagGray; };
	Mat1b& GetSolakTagA() { return m_SolakTagAGray; };
	Mat1b& GetSolakTagB() { return m_SolakTagBGray; };
	Mat1b& GetTelosTag() { return m_TelosTagGray; };
	Mat1b& GetDamageNull() { return m_DmgValNullGray; };
	Mat1b& GetDamage(int Value) { return m_DmgValGray[Value]; };

	Mat1b& GetSolakBar() { return m_SolakBarGray; };
	Mat1b& GetSolakCore() { return m_SolakCoreGray; };
	Mat1b& GetSolakCoreEnd() { return m_SolakCoreEndGray; };
	Mat1b& GetSolakStart() { return m_SolakStartGray; };
	Mat1b& GetSolakLeftArm() { return m_SolakLeftArmGray; };
	Mat1b& GetSolakRightArm() { return m_SolakRightArmGray; };
	Mat1b& GetSolakLeftLeg() { return m_SolakLeftLegGray; };
	Mat1b& GetSolakRightLeg() { return m_SolakRightLegGray; };
	Mat1b& GetSolakP2Start() { return m_SolakP2StartGray; };
	Mat1b& GetSolakP3Start() { return m_SolakP3StartGray; };
	Mat1b& GetSolakP4Start() { return m_SolakP4StartGray; };
	Mat1b& GetSolakMindDebuff() { return m_SolakMindDebuffGray; };
	Mat1b& GetSolakEnd() { return m_SolakEndGray; };
	Mat1b& GetSolakBomb() { return m_SolakBombGray; };
	Mat1b& GetPlayerDeath() { return m_PlayerDeathGray; };

	Mat1b& GetTelosTarget() { return m_TelosTargetGray; };
	Mat1b& GetTelosPhase1() { return m_TelosPhase1Gray; };
	Mat1b& GetTelosPhase2() { return m_TelosPhase2Gray; };
	Mat1b& GetTelosPhase3() { return m_TelosPhase3Gray; };
	Mat1b& GetTelosPhase4() { return m_TelosPhase4Gray; };
	Mat1b& GetTelosPhase5() { return m_TelosPhase5Gray; };
	Mat1b& GetTelosFightEnd() { return m_TelosFightEndGray; };

	Mat3b& GetChatFound() { return m_ChatFound; };
	Mat3b& GetChatNotFound() { return m_ChatNotFound; };
	Mat3b& GetDamageFound() { return m_DamageFound; };
	Mat3b& GetDamageNotFound() { return m_DamageNotFound; };
	Mat3b& GetHeader() { return m_Header; };
	Mat3b& GetSolakLayout() { return m_SolakLayout; };

	Rect GetDamageArea() { return m_DamageArea; };
	Rect GetChatArea() { return m_ChatArea; };
	void SetDamageArea(Rect& DamageArea);
	void SetChatArea(Rect& ChatArea);


private:

	Rect m_DamageArea;
	Rect m_ChatArea;

	Mat3b m_DamageFound;
	Mat3b m_DamageNotFound;
	Mat3b m_ChatFound;
	Mat3b m_ChatNotFound;
	Mat3b m_Header;
	Mat3b m_SolakLayout;

	Mat3b m_SolakTagA;
	Mat3b m_SolakTagB;
	Mat1b m_SolakTagAGray;
	Mat1b m_SolakTagBGray;
	Mat3b m_TelosTag;
	Mat1b m_TelosTagGray;

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
	Mat3b m_SolakBomb;
	Mat1b m_SolakBombGray;

	Mat3b m_TelosTarget;
	Mat1b m_TelosTargetGray;
	Mat3b m_TelosPhase1;
	Mat1b m_TelosPhase1Gray;
	Mat3b m_TelosPhase2;
	Mat1b m_TelosPhase2Gray;
	Mat3b m_TelosPhase3;
	Mat1b m_TelosPhase3Gray;
	Mat3b m_TelosPhase4;
	Mat1b m_TelosPhase4Gray;
	Mat3b m_TelosPhase5;
	Mat1b m_TelosPhase5Gray;
	Mat3b m_TelosFightEnd;
	Mat1b m_TelosFightEndGray;
	

	Mat3b m_PlayerDeath;
	Mat1b m_PlayerDeathGray;
	




};


#endif