#ifndef SOLAKMODULE_H
#define SOLAKMODULE_H

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


using namespace cv;
using namespace std;

//The purpose of this class is to grab a screenshot of the desktop and return it as a Mat file

class SolakModule
{
public:
	SolakModule();
	~SolakModule();
	void Update(Mat1b Screenshot, unsigned int Damage, Mat1b ChatScreen);
	void Reset(); //Resets all values to default
	void SetBaseDamage(unsigned int Damage) { m_BaseDamage = Damage; };
	void ReportDamage(); //Reports the damage from the encounter
	void SetDuoActive(bool status) { m_DuoActive = status; };
	bool GetFightEnded() { return m_FightEnded; };

	

private:
	
	TemplateMatcher SolakMatch;
	ImageSetup SolakImages;
	//WindowText TextSolakDuoActive;


	bool m_FirstTime = true;

	//Overal integers
	unsigned int m_BaseDamage; //The damage value before the encounter has begun
	unsigned int m_TotalDamage; //Total damage dealt throughout the encounter
	unsigned int m_TempDamage; //Used to store values temporarily
	unsigned int m_DamageLastCheckpoint;
	//Phase 1 integers
	unsigned int m_P1Damage[4]; //The damage value dealt to Solak in up to 4 iterations of Phase 1
	unsigned int m_ArmsDamage[4]; //The damage values dealt to Solak's arms up to 4 times
	unsigned int m_LegsDamage[4]; //The damage values dealt to Solak's legs up to 4 times
	unsigned int m_CoreDamage[4]; //The damage values dealt to the Core up to 4 times
	unsigned int m_P1DamageTotal;
	unsigned int m_ArmsDamageTotal;
	unsigned int m_LegsDamageTotal;
	unsigned int m_CoreDamageTotal;
	unsigned int m_P4DamageMindCapped;
	int m_Phase1Counter = 0; //Used to track how many phase 1s we've done

	//Phase 2 integers
	unsigned int m_P2Damage;

	//Phase 3 integers
	unsigned int m_P3Damage;

	//Phase 4 integers
	unsigned int m_P4Damage;

	//Report Strings
	string m_StrTotalDamage;
	string m_StrP1Damage[4];
	string m_StrArmsDamage[4];
	string m_StrLegsDamage[4];
	string m_StrCoreDamage[4];
	string m_StrP2Damage;
	string m_StrP3Damage;
	string m_StrP4Damage;
	string m_StrP1DamageTotal;
	string m_StrArmsDamageTotal;
	string m_StrLegsDamageTotal;
	string m_StrCoreDamageTotal;

	//Booleans used to track fight progress
	bool m_FightStarted = false;
	bool m_Phase1Active = false;
	bool m_ArmsActive = false;
	bool m_LegsActive = false;
	bool m_CoreActive = false;

	bool m_Phase2Active = false;
	bool m_Phase3Active = false;
	bool m_Phase4Active = false;
	bool m_FightEnded = false;

	bool m_P4MindDebuff = false;

	bool m_ReportDamage = true;
	bool m_DamageWasUpdated = false; //Used to track if we should update the total damage label
	//Text textures
	WindowText TextSolakDuoActive;
	WindowText TextSolakTeamActive;
	WindowText TextSolakReportHeader;
	WindowText TextSolakReportHeader2;
	WindowText TextSolakTotalDamage;
	WindowText TextSolakArms;
	WindowText TextSolakLegs;
	WindowText TextSolakCore;
	WindowText TextSolakPhase1;
	WindowText TextSolakPhase2;
	WindowText TextSolakPhase3;
	WindowText TextSolakPhase4;
	WindowText TextSolakRoots;
	WindowText TextSolakPhase1Total;
	WindowText TextSolakLegsTotal;
	WindowText TextSolakArmsTotal;
	WindowText TextSolakCoreTotal;
	

	WindowText TextSolakP1Dmg[4];
	WindowText TextSolakP1DmgTotal;
	WindowText TextSolakArmsDmg[4];
	WindowText TextSolakLegsDmg[4];
	WindowText TextSolakCoreDmg[4];
	WindowText TextSolakP2Dmg;
	WindowText TextSolakP3Dmg;
	WindowText TextSolakP4Dmg;
	WindowText TextSolakP1TotalDmg;


	WindowText TextSolakDmg;

	//Ally variables
	WindowText TextAllyP1Dmg;
	WindowText TextAllyArmsDmg[4];
	WindowText TextAllyLegsDmg[4];
	WindowText TextAllyCoreDmg;
	WindowText TextAllyP2Dmg;
	WindowText TextAllyP3Dmg;
	WindowText TextAllyP4Dmg;
	WindowText TextAllyDmgTotal;
	WindowText TextAllyArmsTotal;
	WindowText TextAllyLegsTotal;
	WindowText TextAllyCoreTotal;

	string m_StrAllyP1Dmg;
	string m_StrAllyArmsDmg[4];
	string m_StrAllyLegsDmg[4];
	string m_StrAllyCoreDmg;
	string m_StrAllyP2Dmg;
	string m_StrAllyP3Dmg;
	string m_StrAllyP4Dmg;
	string m_StrAllyDmgTotal;
	string m_StrAllyArmsDmgTotal;
	string m_StrAllyLegsDmgTotal;

	int m_AllyP1Dmg;
	int m_AllyArmsDmg[4];
	int m_AllyLegsDmg[4];
	int m_AllyCoreDmg;
	int m_AllyP2Dmg;
	int m_AllyP3Dmg;
	int m_AllyP4Dmg;
	int m_AllyDmgTotal;
	int m_AllyArmsDmgTotal;
	int m_AllyLegsDmgTotal;

	bool m_DuoActive = false;
	bool m_TeamActive = false;

	int m_DuoP1Health = 750000;
	int m_DuoRootHealth = 20000;
	int m_DuoArmHealth = 60000;
	int m_DuoLegHealth = 50000;
	int m_DuoCoreHealth = 250000;
	int m_DuoAnimaFontHealth = 33333;
	int m_DuoAnimaStormHealth = 350000;
	int m_DuoP2Health = 1050000;
	int m_DuoP3Health = 900000;
	int m_DuoP4Health = 300000;

	int m_TeamP1Health = 1800000;
	int m_TeamRootHealth = 80000;
	int m_TeamArmHealth = 120000;
	int m_TeamLegHealth = 100000;
	int m_TeamCoreHealth = 1000000;
	int m_TeamAnimaFontHealth = 100000;
	int m_TeamAnimaStormHealth = 1000000;
	int m_TeamP2Health = 3000000;
	int m_TeamP3Health = 3000000;
	int m_TeamP4Health = 700000;
	
};


#endif