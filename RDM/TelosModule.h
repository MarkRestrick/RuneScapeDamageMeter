#ifndef TELOSMODULE_H
#define TELOSMODULE_H


#include<opencv2\opencv.hpp>
#include <Windows.h>
#include<stdint.h>
#include "TemplateMatcher.h"
#include "ImageSetup.h"
#include "WindowRect.h"
#include "WindowText.h"
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include "Timer.h"
#include "DataHandler.h"


using namespace cv;
using namespace std;

//The purpose of this class is to grab a screenshot of the desktop and return it as a Mat file

class TelosModule
{
public:
	TelosModule();
	~TelosModule();
	void SaveFight();
	void Update(Mat1b& Screenshot, unsigned int Damage, Mat1b& ChatScreen);
	void Reset(); //Resets all values to default
	void SetBaseDamage(unsigned int Damage) { m_BaseDamage = Damage; };
	void ReportDamage(); //Reports the damage from the encounter
	void SetActive(bool status) { m_Active = status; };
	bool GetFightEnded() { return m_FightEnded; };
	bool GetFightStarted() { return m_FightStarted; };



private:

	TemplateMatcher TelosMatch;
	ImageSetup TelosImages;
	//WindowText TextTelosDuoActive;


	bool m_FirstTime = true;

	//Overal integers
	unsigned int m_BaseDamage; //The damage value before the encounter has begun
	unsigned int m_TotalDamage; //Total damage dealt throughout the encounter
	unsigned int m_TempDamage; //Used to store values temporarily
	unsigned int m_BestCompareDamage; //Damage value used to compare best log, ignores P4 Damage to mitigat Tank/DPS role damage differences
	unsigned int m_DamageLastCheckpoint;
	
	//Fight damage integers
	unsigned int m_P1Damage; 				 
	unsigned int m_P2Damage;
	unsigned int m_P3Damage;
	unsigned int m_P4Damage;
	unsigned int m_P5Damage;

	unsigned int m_P1DPS;
	unsigned int m_P2DPS;
	unsigned int m_P3DPS;
	unsigned int m_P4DPS;
	unsigned int m_P5DPS;

	int m_P1Time;
	int m_P2Time;
	int m_P3Time;
	int m_P4Time;
	int m_P5Time;

	//Report Strings
	string m_StrTotalDamage;
	string m_StrP1Damage;
	string m_StrP2Damage;
	string m_StrP3Damage;
	string m_StrP4Damage;
	string m_StrP5Damage;
	string m_StrP1DamageTotal;

	string m_StrP1Time;
	string m_StrP2Time;
	string m_StrP3Time;
	string m_StrP4Time;
	string m_StrP5Time;
	string m_TotalTime;

	string m_StrP1DPS;
	string m_StrP2DPS;
	string m_StrP3DPS;
	string m_StrP4DPS;
	string m_StrP5DPS;

	//Booleans used to track fight progress
	bool m_FightStarted = false;
	bool m_Phase1Active = false;
	bool m_Phase2Active = false;
	bool m_Phase3Active = false;
	bool m_Phase4Active = false;
	bool m_Phase5Active = false;
	bool m_FightEnded = false;

	bool m_ReportDamage = true;
	bool m_DamageWasUpdated = false; //Used to track if we should update the total damage label
									 //Text textures

	WindowText TextTelosPhase1Total;

	WindowText TextTelosReportHeader;//Just here to fail on initialisation, doesn't do much other than that


	WindowText TextTelosP1Dmg;
	WindowText TextTelosP2Dmg;
	WindowText TextTelosP3Dmg;
	WindowText TextTelosP4Dmg;
	WindowText TextTelosP5Dmg;

	WindowText TextTelosP1Time;
	WindowText TextTelosP2Time;
	WindowText TextTelosP3Time;
	WindowText TextTelosP4Time;
	WindowText TextTelosP5Time;

	WindowText TextTelosDmg;

	//Ally variables
	WindowText TextAllyP1Dmg;
	WindowText TextAllyP2Dmg;
	WindowText TextAllyP3Dmg;
	WindowText TextAllyP4Dmg;
	WindowText TextAllyP5Dmg;
	WindowText TextAllyDmgTotal;

	WindowText TextAllyP1Time;
	WindowText TextAllyP2Time;
	WindowText TextAllyP3Time;
	WindowText TextAllyP4Time;
	WindowText TextAllyP5Time;


	string m_StrAllyP1Dmg;
	string m_StrAllyP2Dmg;
	string m_StrAllyP3Dmg;
	string m_StrAllyP4Dmg;
	string m_StrAllyP5Dmg;
	string m_StrAllyDmgTotal;
	string m_StrBestDmg;

	string m_StrAllyP1DPS;
	string m_StrAllyP2DPS;
	string m_StrAllyP3DPS;
	string m_StrAllyP4DPS;
	string m_StrAllyP5DPS;

	string m_StrAllyP1Time;
	string m_StrAllyP2Time;
	string m_StrAllyP3Time;
	string m_StrAllyP4Time;
	string m_StrAllyP5Time;
	

	int m_AllyP1Dmg;
	int m_AllyP2Dmg;
	int m_AllyP3Dmg;
	int m_AllyP4Dmg;
	int m_AllyP5Dmg;
	int m_AllyDmgTotal;
	int m_AllyBestDmg;

	int m_AllyP1DPS;
	int m_AllyP2DPS;
	int m_AllyP3DPS;
	int m_AllyP4DPS;
	int m_AllyP5DPS;

	int m_AllyP1Bar;
	int m_AllyP2Bar;
	int m_AllyP3Bar;
	int m_AllyP4Bar;
	int m_AllyP5Bar;

	int m_AllyP1Time;
	int m_AllyP2Time;
	int m_AllyP3Time;
	int m_AllyP4Time;
	int m_AllyP5Time;

	bool m_Active = false;

	Timer m_TelosTimer;

	WindowRect m_TelosP1Bar;
	WindowRect m_TelosP2Bar;
	WindowRect m_TelosP3Bar;
	WindowRect m_TelosP4Bar;
	WindowRect m_TelosP5Bar;

	WindowRect m_AllyP1BarImg;
	WindowRect m_AllyP2BarImg;
	WindowRect m_AllyP3BarImg;
	WindowRect m_AllyP4BarImg;
	WindowRect m_AllyP5BarImg;

	int m_DeathCheckCounter = 0;

	int BarLength;

	//For use with the time labels
	int m_Seconds;
	int m_Minutes;
	string m_StrPrevPhaseTime;

	void WipeBarsAndValues();
	void ReportPhase1();
	void ReportPhase2();
	void ReportPhase3();
	void ReportPhase4();
	void ReportPhase5();
	void ReportBestFight();
	void ParseBest();
	void CompareBest();
	void SaveBest();

	DataHandler m_TelosData;
	string m_TelosBestString;

};


#endif