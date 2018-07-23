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

	//Chat message image used to locate where the chat window is on the player's screen
	m_ChatTag = imread("Images/ChatLocate.png");
	cvtColor(m_ChatTag, m_ChatTagGray, COLOR_BGR2GRAY);

	//"Solak" images in the instance creation menu that are used to establish the solak fight is about to begin
	m_SolakTagA = imread("Images/BossImages/Solak_A.png");
	cvtColor(m_SolakTagA, m_SolakTagAGray, COLOR_BGR2GRAY);
	m_SolakTagB = imread("Images/BossImages/Solak_B.png");
	cvtColor(m_SolakTagB, m_SolakTagBGray, COLOR_BGR2GRAY);

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

	for (int i = 0; i <= 9; i++)
	{
		cvtColor(m_DmgVal[i], m_DmgValGray[i], COLOR_BGR2GRAY);
	}
	
}

void ImageSetup::SolakSetup()
{
	m_SolakBar = imread("Images/SolakImages/SolakBar.png");
	cvtColor(m_SolakBar, m_SolakBarGray, COLOR_BGR2GRAY);

	m_SolakCore = imread("Images/SolakImages/SolakCore.png");
	cvtColor(m_SolakCore, m_SolakCoreGray, COLOR_BGR2GRAY);

	m_SolakCoreEnd = imread("Images/SolakImages/SolakCoreFinish.png");
	cvtColor(m_SolakCoreEnd, m_SolakCoreEndGray, COLOR_BGR2GRAY);

	m_SolakStart = imread("Images/SolakImages/SolakFightStart.png");
	cvtColor(m_SolakStart, m_SolakStartGray, COLOR_BGR2GRAY);

	m_SolakLeftArm = imread("Images/SolakImages/SolakLeftArm.png");
	cvtColor(m_SolakLeftArm, m_SolakLeftArmGray, COLOR_BGR2GRAY);

	m_SolakRightArm = imread("Images/SolakImages/SolakRightArm.png");
	cvtColor(m_SolakRightArm, m_SolakRightArmGray, COLOR_BGR2GRAY);

	m_SolakLeftLeg = imread("Images/SolakImages/SolakLeftLeg.png");
	cvtColor(m_SolakLeftLeg, m_SolakLeftLegGray, COLOR_BGR2GRAY);

	m_SolakRightLeg = imread("Images/SolakImages/SolakRightLeg.png");
	cvtColor(m_SolakRightLeg, m_SolakRightLegGray, COLOR_BGR2GRAY);

	m_SolakP2Start = imread("Images/SolakImages/SolakP2Start.png");
	cvtColor(m_SolakP2Start, m_SolakP2StartGray, COLOR_BGR2GRAY);

	m_SolakP3Start = imread("Images/SolakImages/SolakP3Start.png");
	cvtColor(m_SolakP3Start, m_SolakP3StartGray, COLOR_BGR2GRAY);

	m_SolakP4Start = imread("Images/SolakImages/SolakP4Start.png");
	cvtColor(m_SolakP4Start, m_SolakP4StartGray, COLOR_BGR2GRAY);

	m_SolakEnd = imread("Images/SolakImages/SolakP4End.png");
	cvtColor(m_SolakEnd, m_SolakEndGray, COLOR_BGR2GRAY);

	m_SolakMindDebuff = imread("Images/SolakImages/SolakDebuff.png");
	cvtColor(m_SolakMindDebuff, m_SolakMindDebuffGray, COLOR_BGR2GRAY);

}
