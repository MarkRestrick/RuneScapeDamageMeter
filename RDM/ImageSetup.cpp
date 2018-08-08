#include "ImageSetup.h"
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

ImageSetup::ImageSetup()
{



	
}

ImageSetup::~ImageSetup()
{
}

void ImageSetup::GeneralSetup()
{

	//"Damage" text used to locate the damage value
	m_DamageTag = imread("Images/DamageImages/DamageTag.png");
	cvtColor(m_DamageTag, m_DamageTagGray, COLOR_BGR2GRAY);
	m_DamageTag.release();

	//Chat message image used to locate where the chat window is on the player's screen
	m_ChatTag = imread("Images/ChatLocate.png");
	cvtColor(m_ChatTag, m_ChatTagGray, COLOR_BGR2GRAY);
	m_ChatTag.release();

	//"Solak" images in the instance creation menu that are used to establish the solak fight is about to begin
	m_SolakTagA = imread("Images/BossImages/Solak_A.png");
	cvtColor(m_SolakTagA, m_SolakTagAGray, COLOR_BGR2GRAY);
	m_SolakTagB = imread("Images/BossImages/Solak_B.png");
	cvtColor(m_SolakTagB, m_SolakTagBGray, COLOR_BGR2GRAY);
	m_SolakTagA.release();
	m_SolakTagB.release();

	//Telos menu tag
	m_TelosTag = imread("Images/BossImages/Telos.png");
	cvtColor(m_TelosTag, m_TelosTagGray, COLOR_BGR2GRAY);
	m_TelosTag.release();

	//User Interface Images
	m_DamageFound = imread("Images/UI/DamageFound.png");
	m_DamageNotFound = imread("Images/UI/DamageNotFound.png");
	m_ChatFound = imread("Images/UI/ChatFound.png");
	m_ChatNotFound = imread("Images/UI/ChatNotFound.png");
	m_Header = imread("Images/UI/Head.png");
	m_SolakLayout = imread("Images/UI/DamageFound.png");
	m_DamageFound.release();
	m_DamageNotFound.release();
	m_ChatFound.release();
	m_ChatNotFound.release();
	m_Header.release();
	m_SolakLayout.release();

}

void ImageSetup::DmgSetup()
{

	//Background of the damage value used to detect no characters present, and the values 0 through 9
	m_DmgValNull = imread("Images/DamageImages/DMG_VALUE_NULL.png");
	cvtColor(m_DmgValNull, m_DmgValNullGray, COLOR_BGR2GRAY);
	m_DmgVal[0] = imread("Images/DamageImages/DMG_VALUE_0.png");
	m_DmgVal[1] = imread("Images/DamageImages/DMG_VALUE_1.png");
	m_DmgVal[2] = imread("Images/DamageImages/DMG_VALUE_2.png");
	m_DmgVal[3] = imread("Images/DamageImages/DMG_VALUE_3.png");
	m_DmgVal[4] = imread("Images/DamageImages/DMG_VALUE_4.png");
	m_DmgVal[5] = imread("Images/DamageImages/DMG_VALUE_5.png");
	m_DmgVal[6] = imread("Images/DamageImages/DMG_VALUE_6.png");
	m_DmgVal[7] = imread("Images/DamageImages/DMG_VALUE_7.png");
	m_DmgVal[8] = imread("Images/DamageImages/DMG_VALUE_8.png");
	m_DmgVal[9] = imread("Images/DamageImages/DMG_VALUE_9.png");
	m_DmgValNull.release();

	for (int i = 0; i <= 9; i++)
	{
		cvtColor(m_DmgVal[i], m_DmgValGray[i], COLOR_BGR2GRAY);
		//m_DmgVal[i].release();
	}
	
}

void ImageSetup::SolakSetup()
{
	m_SolakBar = imread("Images/SolakImages/SolakBar.png");
	cvtColor(m_SolakBar, m_SolakBarGray, COLOR_BGR2GRAY);
	m_SolakBar.release();

	m_SolakCore = imread("Images/SolakImages/SolakCore.png");
	cvtColor(m_SolakCore, m_SolakCoreGray, COLOR_BGR2GRAY);
	m_SolakCore.release();

	m_SolakCoreEnd = imread("Images/SolakImages/SolakCoreFinish.png");
	cvtColor(m_SolakCoreEnd, m_SolakCoreEndGray, COLOR_BGR2GRAY);
	m_SolakCoreEnd.release();

	m_SolakStart = imread("Images/SolakImages/SolakFightStart.png");
	cvtColor(m_SolakStart, m_SolakStartGray, COLOR_BGR2GRAY);
	m_SolakStart.release();

	m_SolakLeftArm = imread("Images/SolakImages/SolakLeftArm.png");
	cvtColor(m_SolakLeftArm, m_SolakLeftArmGray, COLOR_BGR2GRAY);
	m_SolakLeftArm.release();

	m_SolakRightArm = imread("Images/SolakImages/SolakRightArm.png");
	cvtColor(m_SolakRightArm, m_SolakRightArmGray, COLOR_BGR2GRAY);
	m_SolakRightArm.release();

	m_SolakLeftLeg = imread("Images/SolakImages/SolakLeftLeg.png");
	cvtColor(m_SolakLeftLeg, m_SolakLeftLegGray, COLOR_BGR2GRAY);
	m_SolakLeftLeg.release();

	m_SolakRightLeg = imread("Images/SolakImages/SolakRightLeg.png");
	cvtColor(m_SolakRightLeg, m_SolakRightLegGray, COLOR_BGR2GRAY);
	m_SolakRightLeg.release();

	m_SolakP2Start = imread("Images/SolakImages/SolakP2Start.png");
	cvtColor(m_SolakP2Start, m_SolakP2StartGray, COLOR_BGR2GRAY);
	m_SolakP2Start.release();

	m_SolakP3Start = imread("Images/SolakImages/SolakP3Start.png");
	cvtColor(m_SolakP3Start, m_SolakP3StartGray, COLOR_BGR2GRAY);
	m_SolakP3Start.release();

	m_SolakP4Start = imread("Images/SolakImages/SolakP4Start.png");
	cvtColor(m_SolakP4Start, m_SolakP4StartGray, COLOR_BGR2GRAY);
	m_SolakP4Start.release();

	m_SolakEnd = imread("Images/SolakImages/SolakP4End.png");
	cvtColor(m_SolakEnd, m_SolakEndGray, COLOR_BGR2GRAY);
	m_SolakEnd.release();

	m_SolakMindDebuff = imread("Images/SolakImages/SolakDebuff.png");
	cvtColor(m_SolakMindDebuff, m_SolakMindDebuffGray, COLOR_BGR2GRAY);
	m_SolakMindDebuff.release();

	m_SolakBomb = imread("Images/SolakImages/SolakBomb.png");
	cvtColor(m_SolakBomb, m_SolakBombGray, COLOR_BGR2GRAY);
	m_SolakBomb.release();

	m_PlayerDeath = imread("Images/Death.png");
	cvtColor(m_PlayerDeath, m_PlayerDeathGray, COLOR_BGR2GRAY);
	m_PlayerDeath.release();

}

void ImageSetup::TelosSetup()
{
	m_TelosTarget = imread("Images/TelosImages/TelosTarget.png");
	cvtColor(m_TelosTarget, m_TelosTargetGray, COLOR_BGR2GRAY);
	m_TelosTarget.release();

	m_TelosPhase1 = imread("Images/TelosImages/Phase1.png");
	cvtColor(m_TelosPhase1, m_TelosPhase1Gray, COLOR_BGR2GRAY);
	m_TelosPhase1.release();

	m_TelosPhase2 = imread("Images/TelosImages/Phase2.png");
	cvtColor(m_TelosPhase2, m_TelosPhase2Gray, COLOR_BGR2GRAY);
	m_TelosPhase2.release();

	m_TelosPhase3 = imread("Images/TelosImages/Phase3.png");
	cvtColor(m_TelosPhase3, m_TelosPhase3Gray, COLOR_BGR2GRAY);
	m_TelosPhase3.release();

	m_TelosPhase4 = imread("Images/TelosImages/Phase4.png");
	cvtColor(m_TelosPhase4, m_TelosPhase4Gray, COLOR_BGR2GRAY);
	m_TelosPhase4.release();

	m_TelosPhase5 = imread("Images/TelosImages/Phase5.png");
	cvtColor(m_TelosPhase5, m_TelosPhase5Gray, COLOR_BGR2GRAY);
	m_TelosPhase5.release();

	m_TelosFightEnd = imread("Images/TelosImages/FightEnd.png");
	cvtColor(m_TelosFightEnd, m_TelosFightEndGray, COLOR_BGR2GRAY);
	m_TelosFightEnd.release();

	m_PlayerDeath = imread("Images/Death.png");
	cvtColor(m_PlayerDeath, m_PlayerDeathGray, COLOR_BGR2GRAY);
	m_PlayerDeath.release();
}

void ImageSetup::SetDamageArea(Rect & DamageArea)
{

	m_DamageArea = cv::Rect(DamageArea.x, DamageArea.y, DamageArea.width, DamageArea.height);

}

void ImageSetup::SetChatArea(Rect& ChatArea)
{
	m_ChatArea = ChatArea;
	
}
