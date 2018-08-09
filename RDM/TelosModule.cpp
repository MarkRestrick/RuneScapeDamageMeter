#include "TelosModule.h"
#include "WindowText.h"



TelosModule::TelosModule()
{
	if (m_FirstTime)
	{
		m_FirstTime = false;
		TelosImages.TelosSetup();
		m_TelosBestString = m_TelosData.GrabFile("Data/TelosBest.txt");
		//cout << "\n The value fo the grabbed string was: " << m_TelosBestString << "\n";

		string ArialFont = "Images/Fonts/arial.ttf";

		TextTelosReportHeader.Create("Images/Fonts/arial.ttf", 30, "Damage Report for Telos", { 255, 255, 255, 255 });
		/*
		TextTelosReportHeader2.Create("Images/Fonts/arial.ttf", 30, "Ally Damage in Red", { 255, 0, 0, 255 });
		TextTelosTotalDamage.Create("Images/Fonts/arial.ttf", 30, "Total Damage Dealt:", { 255, 255, 255, 255 });
		TextTelosArms.Create("Images/Fonts/arial.ttf", 30, "Arms Dmg", { 255, 255, 255, 255 });
		TextTelosLegs.Create("Images/Fonts/arial.ttf", 30, "Legs Dmg", { 255, 255, 255, 255 });
		TextTelosCore.Create("Images/Fonts/arial.ttf", 30, "Core Dmg", { 255, 255, 255, 255 });
		TextTelosPhase1.Create("Images/Fonts/arial.ttf", 30, "Phase 1", { 255, 255, 255, 255 });
		TextTelosPhase2.Create("Images/Fonts/arial.ttf", 30, "Phase 2", { 255, 255, 255, 255 });
		TextTelosPhase3.Create("Images/Fonts/arial.ttf", 30, "Phase 3", { 255, 255, 255, 255 });
		TextTelosPhase4.Create("Images/Fonts/arial.ttf", 30, "Phase 4", { 255, 255, 255, 255 });
		TextTelosRoots.Create("Images/Fonts/arial.ttf", 30, "Boss", { 255, 255, 255, 255 });
		TextTelosP1TotalDmg.Create("Images/Fonts/arial.ttf", 30, "Phase 1 Totals", { 255, 255, 255, 255 });

		for (int j = 0; j < 4; j++)
		{
		TextTelosP1Dmg[j].Create("Images/Fonts/arial.ttf", 30, "0", { 0, 255, 0, 255 });
		TextTelosArmsDmg[j].Create("Images/Fonts/arial.ttf", 30, "0", { 0, 255, 0, 255 });
		TextTelosLegsDmg[j].Create("Images/Fonts/arial.ttf", 30, "0", { 0, 255, 0, 255 });
		TextTelosCoreDmg[j].Create("Images/Fonts/arial.ttf", 30, "0", { 0, 255, 0, 255 });

		TextAllyArmsDmg[j].Create("Images/Fonts/arial.ttf", 30, "0", { 255, 0, 0, 255 });
		TextAllyLegsDmg[j].Create("Images/Fonts/arial.ttf", 30, "0", { 255, 0, 0, 255 });

		}


		TextTelosP2Dmg.Create("Images/Fonts/arial.ttf", 30, "0", { 0, 255, 0, 255 });
		TextTelosP3Dmg.Create("Images/Fonts/arial.ttf", 30, "0", { 0, 255, 0, 255 });
		TextTelosP4Dmg.Create("Images/Fonts/arial.ttf", 30, "0", { 0, 255, 0, 255 });

		TextAllyCoreDmg.Create("Images/Fonts/arial.ttf", 30, "0", { 255, 0, 0, 255 });
		TextAllyP1Dmg.Create("Images/Fonts/arial.ttf", 30, "0", { 255, 0, 0, 255 });
		TextAllyP2Dmg.Create("Images/Fonts/arial.ttf", 30, "0", { 255, 0, 0, 255 });
		TextAllyP3Dmg.Create("Images/Fonts/arial.ttf", 30, "0", { 255, 0, 0, 255 });
		TextAllyP4Dmg.Create("Images/Fonts/arial.ttf", 30, "0", { 255, 0, 0, 255 });


		TextTelosDmg.Create("Images/Fonts/arial.ttf", 30, "0", { 0, 255, 0, 255 });

		TextTelosDuoActive.Create(ArialFont, 30, "Telos (Duo Mode)", { 0, 255, 0, 255 });
		TextTelosTeamActive.Create(ArialFont, 30, "Telos (7 Man)", { 0, 255, 0, 255 });
		*/



	}
	//std::string FontLoc = "Images/Fonts/arial.ttf";

	//WindowRect TextTest();
}

TelosModule::~TelosModule()
{
}

void TelosModule::SaveFight()
{
	string fightString;
	int totalDamage = m_P1DPS + m_P2DPS + m_P3DPS + m_P4DPS + m_P5DPS;
	if (m_P1Damage + m_P2Damage + m_P3Damage < 415000)
	{
		totalDamage = totalDamage / 10;
	}
	if (m_P5Damage == 0)
	{
		totalDamage = totalDamage / 10;
	}
	string savedDamage = to_string(totalDamage);

	fightString = "A" + to_string(m_P1Damage) + "B" + m_StrP1DPS + "C" + to_string(m_P1Time) + "D" + to_string(m_P2Damage)
		+ "E" + m_StrP2DPS + "F" + to_string(m_P2Time) + "G" + to_string(m_P3Damage) + "H" + m_StrP3DPS
		+ "I" + to_string(m_P3Time) + "J" + to_string(m_P4Damage) + "K" + m_StrP4DPS + "L" + to_string(m_P4Time) + "M" + to_string(m_P5Damage)
		+ "N" + m_StrP5DPS + "O" + to_string(m_P5Time) + "P" + savedDamage;

	m_TelosData.AddLine("Data/Telos.txt", fightString);
}

void TelosModule::Update(Mat1b& Screenshot, unsigned int Damage, Mat1b& ChatScreen)
{
	if (TextTelosReportHeader.GetTexFail())
	{
		//std::cout << "WE HAD TO REMAKE THE TEXTURES";
		TextTelosReportHeader.Create("Images/Fonts/arial.ttf", 30, "Damage Report for Telos", { 255, 255, 255, 255 });



		
		TextTelosP1Dmg.Create("Images/Fonts/arialbd.ttf", 16, "0", { 0, 162, 232, 255 });
		TextTelosP2Dmg.Create("Images/Fonts/arialbd.ttf", 16, "0", { 0, 162, 232, 255 });
		TextTelosP3Dmg.Create("Images/Fonts/arialbd.ttf", 16, "0", { 0, 162, 232, 255 });
		TextTelosP4Dmg.Create("Images/Fonts/arialbd.ttf", 16, "0", { 0, 162, 232, 255 });
		TextTelosP5Dmg.Create("Images/Fonts/arialbd.ttf", 16, "0", { 0, 162, 232, 255 });

		TextTelosP1Time.Create("Images/Fonts/arialbd.ttf", 16, "Current: ", { 0, 162, 232, 255 });
		TextTelosP2Time.Create("Images/Fonts/arialbd.ttf", 16, "Current: ", { 0, 162, 232, 255 });
		TextTelosP3Time.Create("Images/Fonts/arialbd.ttf", 16, "Current: ", { 0, 162, 232, 255 });
		TextTelosP4Time.Create("Images/Fonts/arialbd.ttf", 16, "Current: ", { 0, 162, 232, 255 });
		TextTelosP5Time.Create("Images/Fonts/arialbd.ttf", 16, "Current: ", { 0, 162, 232, 255 });




		//TextTelosDuoActive.Create("Images/Fonts/arial.ttf", 30, "Telos (Duo Mode)", { 0, 255, 0, 255 });
		//TextTelosTeamActive.Create("Images/Fonts/arial.ttf", 30, "Telos (7 Man)", { 0, 255, 0, 255 });

		//Bars for fight
		m_TelosP1Bar.initialise(1, 16, 38, 178, "Images/UI/DamageBar.png");
		m_TelosP2Bar.initialise(1, 16, 38, 288, "Images/UI/DamageBar.png");
		m_TelosP3Bar.initialise(1, 16, 38, 408, "Images/UI/DamageBar.png");
		m_TelosP4Bar.initialise(1, 16, 38, 527, "Images/UI/DamageBar.png");
		m_TelosP5Bar.initialise(1, 16, 38, 636, "Images/UI/DamageBar.png");

		ParseBest();
	}


	m_DeathCheckCounter++;
	if (m_DeathCheckCounter > 10)
	{
		if (TelosMatch.GetMatch(ChatScreen, TelosImages.GetPlayerDeath(), 0.82f))
		{
			m_FightEnded = true;
			//cout << "We ended the fight";
			m_DeathCheckCounter = 0;
		}
	}


	ReportDamage();

	//Check if this is the first frame since entering the fight
	if (!m_FightStarted)
	{
		m_BaseDamage = Damage;
		m_DamageLastCheckpoint = Damage;
		//m_FightStarted = true;
	}


	//If no phase is currently active, we must be in the room but have not started the fight, set phase 1 to be active
	if (!m_Phase1Active && !m_Phase2Active && !m_Phase3Active && !m_Phase4Active)
	{
		m_Phase1Active = true;
	}

	if (m_Phase1Active && !m_FightStarted && TelosMatch.GetMatch(Screenshot, TelosImages.GetTelosTarget(), 0.95f))
	{
		m_FightStarted = true;
		m_TelosBestString = m_TelosData.GrabFile("Data/TelosBest.txt");
		//cout << "\n" << m_TelosBestString << "\n";
		WipeBarsAndValues();
		ParseBest();
		m_TelosTimer.Start();
	}

	if (m_Phase1Active && m_FightStarted)
	{
		//m_P3Time = m_TelosTimer.GetTime();
	}

		

		//If arms, legs and core are not active but we see the phase end emote, advance the phase
		if (m_Phase1Active && m_FightStarted && TelosMatch.GetMatch(Screenshot, TelosImages.GetTelosPhase2(), 0.99f))
		{
			cout << "We're trying to advance to phase 2" << endl;
			m_Phase1Active = false;
			m_Phase2Active = true;
			m_P1Time = int (m_TelosTimer.GetTime());
			cout << m_P1Time << endl;
			m_P1Damage = Damage - m_DamageLastCheckpoint;
			m_TotalDamage += m_P1Damage;
			m_DamageLastCheckpoint = Damage;
			m_P1DPS = round(m_P1Damage / m_P1Time);

			
			m_StrP1DPS = to_string(m_P1DPS);
			m_StrP1Damage = m_StrP1DPS + " DPS (" + to_string(m_P1Damage) + " damage)";
			m_StrP1Time = to_string(m_P1Time);
			BarLength = m_P1DPS / 5;
			m_TelosP1Bar.initialise(BarLength, 16, 38, 178, "Images/UI/DamageBar.png");
			TextTelosP1Dmg.Create("Images/Fonts/arialbd.ttf", 16, m_StrP1Damage, { 0, 162, 232, 255 });

			m_Minutes = m_P1Time / 60;
			m_Seconds = m_P1Time % 60;

			if (m_Seconds < 10)
			{
				m_StrP1Time = "Current: 0:00 - " + to_string(m_Minutes) + ":0" + to_string(m_Seconds) + " (" + to_string(m_P1Time) + " Secs)";
			}
			else
			{
				m_StrP1Time = "Current: 0:00 - " + to_string(m_Minutes) + ":" + to_string(m_Seconds) + " (" + to_string(m_P1Time) + " Secs)";
			}
			
			TextTelosP1Time.Create("Images/Fonts/arialbd.ttf", 16, m_StrP1Time, { 0, 162, 232, 255 });
			
			m_DamageWasUpdated = true;

			return;
		}
	

	if (m_Phase2Active && TelosMatch.GetMatch(Screenshot, TelosImages.GetTelosPhase3(), 0.99f))
	{
		m_Phase2Active = false;
		m_Phase3Active = true;
		m_P2Time = int(m_TelosTimer.GetTime()) - m_P1Time;
		cout << m_P2Time << endl;
		m_P2Damage = Damage - m_DamageLastCheckpoint;
		m_TotalDamage += m_P2Damage;
		m_DamageLastCheckpoint = Damage;
		m_P2DPS = round(m_P2Damage / m_P2Time);


		m_StrP2DPS = to_string(m_P2DPS);
		m_StrP2Damage = m_StrP2DPS + " DPS (" + to_string(m_P2Damage) + " Damage)";
		m_StrP2Time = to_string(m_P2Time);
		BarLength = m_P2DPS / 5;
		m_TelosP2Bar.initialise(BarLength, 16, 38, 288, "Images/UI/DamageBar.png");
		TextTelosP2Dmg.Create("Images/Fonts/arialbd.ttf", 16, m_StrP2Damage, { 0, 162, 232, 255 });

		m_Minutes = (m_P1Time + m_P2Time) / 60;
		m_Seconds = (m_P1Time + m_P2Time) % 60;
		m_StrPrevPhaseTime = m_StrP1Time.substr(16, 5);
		if (m_Seconds < 10)
		{
			m_StrP2Time = "Current: " + m_StrPrevPhaseTime + "- " + to_string(m_Minutes) + ":0" + to_string(m_Seconds) + " (" + to_string(m_P2Time) + " Secs)";
		}
		else
		{
			m_StrP2Time = "Current: " + m_StrPrevPhaseTime + "- " + to_string(m_Minutes) + ":" + to_string(m_Seconds) + " (" + to_string(m_P2Time) + " Secs)";
		}
		TextTelosP2Time.Create("Images/Fonts/arialbd.ttf", 16, m_StrP2Time, { 0, 162, 232, 255 });



		m_DamageWasUpdated = true;

		return;
	}

	if (m_Phase3Active && TelosMatch.GetMatch(Screenshot, TelosImages.GetTelosPhase4(), 0.99f))
	{
		m_Phase3Active = false;
		m_Phase4Active = true;
		m_P3Time = int(m_TelosTimer.GetTime()) - m_P2Time - m_P1Time;
		m_P3Damage = Damage - m_DamageLastCheckpoint;
		m_TotalDamage += m_P3Damage;
		m_DamageLastCheckpoint = Damage;
		m_P3DPS = round(m_P3Damage / m_P3Time);


		m_StrP3DPS = to_string(m_P3DPS);
		m_StrP3Damage = m_StrP3DPS + " DPS (" + to_string(m_P3Damage) + " Damage)";
		m_StrP3Time = to_string(m_P3Time);
		BarLength = m_P3DPS / 5;
		m_TelosP3Bar.initialise(BarLength, 16, 38, 408, "Images/UI/DamageBar.png");
		TextTelosP3Dmg.Create("Images/Fonts/arialbd.ttf", 16, m_StrP3Damage, { 0, 162, 232, 255 });

		m_Minutes = (m_P1Time + m_P2Time + m_P3Time) / 60;
		m_Seconds = (m_P1Time + m_P2Time + m_P3Time) % 60;
		m_StrPrevPhaseTime = m_StrP2Time.substr(16, 5);
		if (m_Seconds < 10)
		{
			m_StrP3Time = "Current: " + m_StrPrevPhaseTime + "- " + to_string(m_Minutes) + ":0" + to_string(m_Seconds) + " (" + to_string(m_P3Time) + " Secs)";
		}
		else
		{
			m_StrP3Time = "Current: " + m_StrPrevPhaseTime + "- " + to_string(m_Minutes) + ":" + to_string(m_Seconds) + " (" + to_string(m_P3Time) + " Secs)";
		}
		TextTelosP3Time.Create("Images/Fonts/arialbd.ttf", 16, m_StrP3Time, { 0, 162, 232, 255 });

		m_DamageWasUpdated = true;

		return;
		

	}

	if (m_Phase4Active && TelosMatch.GetMatch(Screenshot, TelosImages.GetTelosPhase5(), 0.99f))
	{
		m_Phase4Active = false;
		m_Phase5Active = true;
		m_P4Time = int(m_TelosTimer.GetTime()) - m_P3Time - m_P2Time - m_P1Time;
		m_P4Damage = Damage - m_DamageLastCheckpoint;
		m_TotalDamage += m_P4Damage;
		m_DamageLastCheckpoint = Damage;
		m_P4DPS = round(m_P4Damage / m_P4Time);


		m_StrP4DPS = to_string(m_P4DPS);
		m_StrP4Damage = m_StrP4DPS + " DPS (" + to_string(m_P4Damage) + " damage)";
		m_StrP4Time = to_string(m_P4Time);
		BarLength = m_P4DPS / 5;
		m_TelosP4Bar.initialise(BarLength, 16, 38, 527, "Images/UI/DamageBar.png");
		TextTelosP4Dmg.Create("Images/Fonts/arialbd.ttf", 16, m_StrP4Damage, { 0, 162, 232, 255 });

		m_Minutes = (m_P1Time + m_P2Time + m_P3Time + m_P4Time) / 60;
		m_Seconds = (m_P1Time + m_P2Time + m_P3Time + m_P4Time) % 60;
		m_StrPrevPhaseTime = m_StrP3Time.substr(16, 5);
		if (m_Seconds < 10)
		{
			m_StrP4Time = "Current: " + m_StrPrevPhaseTime + "- " + to_string(m_Minutes) + ":0" + to_string(m_Seconds) + " (" + to_string(m_P4Time) + " Secs)";
		}
		else
		{
			m_StrP4Time = "Current: " + m_StrPrevPhaseTime + "- " + to_string(m_Minutes) + ":" + to_string(m_Seconds) + " (" + to_string(m_P4Time) + " Secs)";
		}
		TextTelosP4Time.Create("Images/Fonts/arialbd.ttf", 16, m_StrP4Time, { 0, 162, 232, 255 });

		m_DamageWasUpdated = true;

		return;


	}

	if (m_Phase5Active && TelosMatch.GetMatch(Screenshot, TelosImages.GetTelosFightEnd(), 0.9f))
	{
		

		m_Phase5Active = false;
		m_P5Time = int(m_TelosTimer.GetTime()) - m_P4Time - m_P3Time - m_P2Time - m_P1Time;
		m_P5Damage = Damage - m_DamageLastCheckpoint;
		m_TotalDamage += m_P5Damage;
		m_DamageLastCheckpoint = Damage;
		m_P5DPS = round(m_P5Damage / m_P5Time);


		m_StrP5DPS = to_string(m_P5DPS);
		m_StrP5Damage = m_StrP5DPS + " DPS (" + to_string(m_P5Damage) + " damage)";
		m_StrP5Time = to_string(m_P5Time);
		BarLength = m_P5DPS / 5;
		m_TelosP5Bar.initialise(BarLength, 16, 38, 636, "Images/UI/DamageBar.png");
		TextTelosP5Dmg.Create("Images/Fonts/arialbd.ttf", 16, m_StrP5Damage, { 0, 162, 232, 255 });

		m_Minutes = (m_P1Time + m_P2Time + m_P3Time + m_P4Time + m_P5Time) / 60;
		m_Seconds = (m_P1Time + m_P2Time + m_P3Time + m_P4Time + m_P5Time) % 60;
		m_StrPrevPhaseTime = m_StrP4Time.substr(16, 5);
		if (m_Seconds < 10)
		{
			m_StrP5Time = "Current: " + m_StrPrevPhaseTime + "- " + to_string(m_Minutes) + ":0" + to_string(m_Seconds) + " (" + to_string(m_P5Time) + " Secs)";
		}
		else
		{
			m_StrP5Time = "Current: " + m_StrPrevPhaseTime + "- " + to_string(m_Minutes) + ":" + to_string(m_Seconds) + " (" + to_string(m_P5Time) + " Secs)";
		}
		TextTelosP5Time.Create("Images/Fonts/arialbd.ttf", 16, m_StrP5Time, { 0, 162, 232, 255 });

		m_FightEnded = true;
		m_DamageWasUpdated = true;
		CompareBest();

		return;

	}

	if (m_Phase4Active && TelosMatch.GetMatch(Screenshot, TelosImages.GetTelosFightEnd(), 0.9f))
	{

		m_Phase4Active = false;
		m_Phase5Active = true;
		m_P4Time = m_TelosTimer.GetTime() - m_P3Time - m_P2Time - m_P1Time;
		m_P4Damage = Damage - m_DamageLastCheckpoint;
		m_TotalDamage += m_P4Damage;
		m_DamageLastCheckpoint = Damage;
		m_P4DPS = round(m_P4Damage / m_P4Time);


		m_StrP4DPS = to_string(m_P4DPS);
		m_StrP4Damage = to_string(m_P4Damage) + " (" + m_StrP4DPS + " dps)";
		m_StrP4Time = to_string(m_P4Time);
		BarLength = m_P4DPS / 5;
		m_TelosP4Bar.initialise(BarLength, 16, 38, 527, "Images/UI/DamageBar.png");
		TextTelosP4Dmg.Create("Images/Fonts/arialbd.ttf", 16, m_StrP4Damage, { 0, 162, 232, 255 });

		m_Minutes = (m_P1Time + m_P2Time + m_P3Time + m_P4Time) / 60;
		m_Seconds = (m_P1Time + m_P2Time + m_P3Time + m_P4Time) % 60;
		m_StrPrevPhaseTime = m_StrP3Time.substr(16, 5);
		if (m_Seconds < 10)
		{
			m_StrP4Time = "Current: " + m_StrPrevPhaseTime + "- " + to_string(m_Minutes) + ":0" + to_string(m_Seconds) + " (" + to_string(m_P4Time) + " Secs)";
		}
		else
		{
			m_StrP4Time = "Current: " + m_StrPrevPhaseTime + "- " + to_string(m_Minutes) + ":" + to_string(m_Seconds) + " (" + to_string(m_P4Time) + " Secs)";
		}
		TextTelosP4Time.Create("Images/Fonts/arialbd.ttf", 16, m_StrP4Time, { 0, 162, 232, 255 });


		m_FightEnded = true;
		m_DamageWasUpdated = true;
		CompareBest();

		return;

	}



}

void TelosModule::Reset()
{
	m_BaseDamage = m_TotalDamage = m_TempDamage = m_P1Damage = 0;
	m_P2Damage = m_P3Damage = m_P4Damage = m_P5Damage = 0;
	m_DamageLastCheckpoint = 0;
	m_P1DPS = m_P2DPS = m_P3DPS = m_P4DPS = m_P5DPS = 0;
	m_P1Time = m_P2Time = m_P3Time = m_P4Time = m_P5Time = 0;

	/*
	m_AllyP1Dmg = m_AllyP2Dmg = m_AllyP3Dmg = m_AllyP4Dmg = m_AllyP5Dmg = m_AllyDmgTotal = 0;
	m_AllyP1DPS = m_AllyP2DPS = m_AllyP3DPS = m_AllyP4DPS = m_AllyP4DPS = 0;
	*/
	

	m_FightStarted = m_Phase1Active = m_Phase2Active = m_Phase3Active = m_Phase4Active = m_Phase5Active = m_FightEnded = false;
	m_Active = m_FightEnded = false;


}

void TelosModule::ReportDamage()
{






	ReportPhase1();

	if (m_FightEnded)
	{
		Reset();
		m_FightEnded = false;
	}
}

void TelosModule::WipeBarsAndValues()
{


	TextTelosP1Dmg.Create("Images/Fonts/arialbd.ttf", 16, "0", { 0, 162, 232, 255 });
	TextTelosP2Dmg.Create("Images/Fonts/arialbd.ttf", 16, "0", { 0, 162, 232, 255 });
	TextTelosP3Dmg.Create("Images/Fonts/arialbd.ttf", 16, "0", { 0, 162, 232, 255 });
	TextTelosP4Dmg.Create("Images/Fonts/arialbd.ttf", 16, "0", { 0, 162, 232, 255 });
	TextTelosP5Dmg.Create("Images/Fonts/arialbd.ttf", 16, "0", { 0, 162, 232, 255 });


	//TextTelosDuoActive.Create("Images/Fonts/arial.ttf", 30, "Telos (Duo Mode)", { 0, 255, 0, 255 });
	//TextTelosTeamActive.Create("Images/Fonts/arial.ttf", 30, "Telos (7 Man)", { 0, 255, 0, 255 });

	//Bars for fight
	m_TelosP1Bar.initialise(1, 16, 38, 178, "Images/UI/DamageBar.png");
	m_TelosP2Bar.initialise(1, 16, 38, 288, "Images/UI/DamageBar.png");
	m_TelosP3Bar.initialise(1, 16, 38, 408, "Images/UI/DamageBar.png");
	m_TelosP4Bar.initialise(1, 16, 38, 527, "Images/UI/DamageBar.png");
	m_TelosP5Bar.initialise(1, 16, 38, 636, "Images/UI/DamageBar.png");

}

void TelosModule::ReportPhase1()
{
	/*
	if (m_DamageWasUpdated)
	{
		m_DamageWasUpdated = false;
		m_StrTotalDamage = to_string(m_TotalDamage);
		//TextTelosDmg.display(300, 180, m_StrTotalDamage);
	}
	else
	{
		//TextTelosDmg.display(300, 180);
	}
	*/


	TextTelosP1Dmg.display(38, 160);
	TextTelosP1Time.display(300, 131);
	m_TelosP1Bar.draw();
	ReportPhase2();

}

void TelosModule::ReportPhase2()
{

	TextTelosP2Dmg.display(38, 270);
	m_TelosP2Bar.draw();
	TextTelosP2Time.display(300, 245);
	ReportPhase3();
}

void TelosModule::ReportPhase3()
{
	m_TelosP3Bar.draw();
	TextTelosP3Dmg.display(38, 390);
	TextTelosP3Time.display(300, 362);
	ReportPhase4();
}

void TelosModule::ReportPhase4()
{
	m_TelosP4Bar.draw();
	TextTelosP4Dmg.display(38, 509);
	TextTelosP4Time.display(300, 482);
	ReportPhase5();
}

void TelosModule::ReportPhase5()
{
	m_TelosP5Bar.draw();
	TextTelosP5Dmg.display(38, 618);
	TextTelosP5Time.display(300, 592);
	ReportBestFight();
}

void TelosModule::ReportBestFight()
{

	TextAllyP1Dmg.display(38, 212);
	m_AllyP1BarImg.draw();
	TextAllyP1Time.display(581, 131);

	TextAllyP2Dmg.display(38, 332);
	m_AllyP2BarImg.draw();
	TextAllyP2Time.display(581, 246);

	TextAllyP3Dmg.display(38, 442);
	m_AllyP3BarImg.draw();
	TextAllyP3Time.display(581, 362);

	m_AllyP4BarImg.draw();
	TextAllyP4Dmg.display(38, 561);
	TextAllyP4Time.display(581, 483);

	m_AllyP5BarImg.draw();
	TextAllyP5Dmg.display(38, 670);
	TextAllyP5Time.display(581, 592);

}


void TelosModule::ParseBest()
{
	//Fight integer locations
	int DAM1, DPS1, TIM1 = 0;
	int DAM2, DPS2, TIM2 = 0;
	int DAM3, DPS3, TIM3 = 0;
	int DAM4, DPS4, TIM4 = 0;
	int DAM5, DPS5, TIM5 = 0;
	int DAMO = 0;


	for (int r = 0; r < m_TelosBestString.length(); r++)
	{
		if (m_TelosBestString[r] == 'A')
		{
			DAM1 = r;

		}
		else if (m_TelosBestString[r] == 'B')
		{
			DPS1 = r;

		}
		else if (m_TelosBestString[r] == 'C')
		{
			TIM1 = r;
		}
		else if (m_TelosBestString[r] == 'D')
		{
			DAM2 = r;
		}
		else if (m_TelosBestString[r] == 'E')
		{
			DPS2 = r;
		}
		else if (m_TelosBestString[r] == 'F')
		{
			TIM2 = r;
		}
		else if (m_TelosBestString[r] == 'G')
		{
			DAM3 = r;
		}
		else if (m_TelosBestString[r] == 'H')
		{
			DPS3 = r;
		}
		else if (m_TelosBestString[r] == 'I')
		{
			TIM3 = r;
		}
		else if (m_TelosBestString[r] == 'J')
		{
			DAM4 = r;
		}
		else if (m_TelosBestString[r] == 'K')
		{
			DPS4 = r;
		}
		else if (m_TelosBestString[r] == 'L')
		{
			TIM4 = r;
		}
		else if (m_TelosBestString[r] == 'M')
		{
			DAM5 = r;
		}
		else if (m_TelosBestString[r] == 'N')
		{
			DPS5 = r;
		}
		else if (m_TelosBestString[r] == 'O')
		{
			TIM5 = r;
		}
		else if (m_TelosBestString[r] == 'P')
		{
			DAMO = r;
		}


	}

	//Extract the strings from the code
	m_StrAllyP1Dmg = m_TelosBestString.substr(DAM1 + 1, DPS1 - DAM1 - 1);
	m_StrAllyP1DPS = m_TelosBestString.substr(DPS1 + 1, TIM1 - DPS1 - 1);
	m_StrAllyP1Time = m_TelosBestString.substr(TIM1 + 1, DAM2 - TIM1 - 1);
	m_StrAllyP2Dmg = m_TelosBestString.substr(DAM2 + 1, DPS2 - DAM2 - 1);
	m_StrAllyP2DPS = m_TelosBestString.substr(DPS2 + 1, TIM2 - DPS2 - 1);
	m_StrAllyP2Time = m_TelosBestString.substr(TIM2 + 1, DAM3 - TIM2 - 1);
	m_StrAllyP3Dmg = m_TelosBestString.substr(DAM3 + 1, DPS3 - DAM3 - 1);
	m_StrAllyP3DPS = m_TelosBestString.substr(DPS3 + 1, TIM3 - DPS3 - 1);
	m_StrAllyP3Time = m_TelosBestString.substr(TIM3 + 1, DAM4 - TIM3 - 1);
	m_StrAllyP4Dmg = m_TelosBestString.substr(DAM4 + 1, DPS4 - DAM4 - 1);
	m_StrAllyP4DPS = m_TelosBestString.substr(DPS4 + 1, TIM4 - DPS4 - 1);
	m_StrAllyP4Time = m_TelosBestString.substr(TIM4 + 1, DAM5 - TIM4 - 1);
	m_StrAllyP5Dmg = m_TelosBestString.substr(DAM5 + 1, DPS5 - DAM5 - 1);
	m_StrAllyP5DPS = m_TelosBestString.substr(DPS5 + 1, TIM5 - DPS5 - 1);
	m_StrAllyP5Time = m_TelosBestString.substr(TIM5 + 1, DAMO - TIM5 - 1);
	m_StrBestDmg = m_TelosBestString.substr(DAMO + 1);
	cout << m_StrBestDmg << endl;

	//Convert the strings to integers

	m_AllyP1Dmg = atoi(m_StrAllyP1Dmg.c_str());
	m_AllyP2Dmg = atoi(m_StrAllyP2Dmg.c_str());
	m_AllyP3Dmg = atoi(m_StrAllyP3Dmg.c_str());
	m_AllyP4Dmg = atoi(m_StrAllyP4Dmg.c_str());
	m_AllyP5Dmg = atoi(m_StrAllyP5Dmg.c_str());
	m_AllyBestDmg = atoi(m_StrBestDmg.c_str());

	m_AllyP1DPS = atoi(m_StrAllyP1DPS.c_str());
	m_AllyP2DPS = atoi(m_StrAllyP2DPS.c_str());
	m_AllyP3DPS = atoi(m_StrAllyP3DPS.c_str());
	m_AllyP4DPS = atoi(m_StrAllyP4DPS.c_str());
	m_AllyP5DPS = atoi(m_StrAllyP5DPS.c_str());

	m_AllyP1Time = atoi(m_StrAllyP1Time.c_str());
	m_AllyP2Time = atoi(m_StrAllyP2Time.c_str());
	m_AllyP3Time = atoi(m_StrAllyP3Time.c_str());
	m_AllyP4Time = atoi(m_StrAllyP4Time.c_str());
	m_AllyP5Time = atoi(m_StrAllyP5Time.c_str());

	//Work out the best bar length (1 pixel = 1k damage)

	m_AllyP1Bar = round(m_AllyP1DPS / 5);
	m_AllyP2Bar = round(m_AllyP2DPS / 5);
	m_AllyP3Bar = round(m_AllyP3DPS / 5);
	m_AllyP4Bar = round(m_AllyP4DPS / 5);
	m_AllyP5Bar = round(m_AllyP5DPS / 5);

	m_StrAllyP1Dmg = m_StrAllyP1DPS + " DPS (" + to_string(m_AllyP1Dmg) + " damage)";
	m_StrAllyP2Dmg = m_StrAllyP2DPS + " DPS (" + to_string(m_AllyP2Dmg) + " damage)";
	m_StrAllyP3Dmg = m_StrAllyP3DPS + " DPS (" + to_string(m_AllyP3Dmg) + " damage)";
	m_StrAllyP4Dmg = m_StrAllyP4DPS + " DPS (" + to_string(m_AllyP4Dmg) + " damage)";
	m_StrAllyP5Dmg = m_StrAllyP5DPS + " DPS (" + to_string(m_AllyP5Dmg) + " damage)";

	TextAllyP1Dmg.Create("Images/Fonts/arialbd.ttf", 16, m_StrAllyP1Dmg, { 255, 201, 14, 255 });
	TextAllyP2Dmg.Create("Images/Fonts/arialbd.ttf", 16, m_StrAllyP2Dmg, { 255, 201, 14, 255 });
	TextAllyP3Dmg.Create("Images/Fonts/arialbd.ttf", 16, m_StrAllyP3Dmg, { 255, 201, 14, 255 });
	TextAllyP4Dmg.Create("Images/Fonts/arialbd.ttf", 16, m_StrAllyP4Dmg, { 255, 201, 14, 255 });
	TextAllyP5Dmg.Create("Images/Fonts/arialbd.ttf", 16, m_StrAllyP5Dmg, { 255, 201, 14, 255 });

	

	//Bars for fight
	m_AllyP1BarImg.initialise(m_AllyP1Bar, 16, 38, 196, "Images/UI/AllyBar.png");
	m_AllyP2BarImg.initialise(m_AllyP2Bar, 16, 38, 306, "Images/UI/AllyBar.png");
	m_AllyP3BarImg.initialise(m_AllyP3Bar, 16, 38, 426, "Images/UI/AllyBar.png");
	m_AllyP4BarImg.initialise(m_AllyP4Bar, 16, 38, 545, "Images/UI/AllyBar.png");
	m_AllyP5BarImg.initialise(m_AllyP5Bar, 16, 38, 654, "Images/UI/AllyBar.png");

	//Time Reports
	m_Minutes = m_AllyP1Time / 60;
	m_Seconds = m_AllyP1Time % 60;
	if (m_Seconds < 10)
	{
		m_StrAllyP1Time = "Best: 0:00 - " + to_string(m_Minutes) + ":0" + to_string(m_Seconds) + " (" + to_string(m_AllyP1Time) + " Secs)";
	}
	else
	{
		m_StrAllyP1Time = "Best: 0:00 - " + to_string(m_Minutes) + ":" + to_string(m_Seconds) + " (" + to_string(m_AllyP1Time) + " Secs)";
	}
	TextAllyP1Time.Create("Images/Fonts/arialbd.ttf", 16, m_StrAllyP1Time, { 255, 201, 14, 255 });

	m_Minutes = (m_AllyP1Time + m_AllyP2Time) / 60;
	m_Seconds = (m_AllyP1Time + m_AllyP2Time) % 60;
	m_StrPrevPhaseTime = m_StrAllyP1Time.substr(13, 5);
	if (m_Seconds < 10)
	{
		m_StrAllyP2Time = "Best: " + m_StrPrevPhaseTime + "- " + to_string(m_Minutes) + ":0" + to_string(m_Seconds) + " (" + to_string(m_AllyP2Time) + " Secs)";
	}
	else
	{
		m_StrAllyP2Time = "Best: " + m_StrPrevPhaseTime + "- " + to_string(m_Minutes) + ":" + to_string(m_Seconds) + " (" + to_string(m_AllyP2Time) + " Secs)";
	}
	TextAllyP2Time.Create("Images/Fonts/arialbd.ttf", 16, m_StrAllyP2Time, { 255, 201, 14, 255 });

	m_Minutes = (m_AllyP1Time + m_AllyP2Time + m_AllyP3Time) / 60;
	m_Seconds = (m_AllyP1Time + m_AllyP2Time + m_AllyP3Time) % 60;
	m_StrPrevPhaseTime = m_StrAllyP2Time.substr(13, 5);
	if (m_Seconds < 10)
	{
		m_StrAllyP3Time = "Best: " + m_StrPrevPhaseTime + "- " + to_string(m_Minutes) + ":0" + to_string(m_Seconds) + " (" + to_string(m_AllyP3Time) + " Secs)";
	}
	else
	{
		m_StrAllyP3Time = "Best: " + m_StrPrevPhaseTime + "- " + to_string(m_Minutes) + ":" + to_string(m_Seconds) + " (" + to_string(m_AllyP3Time) + " Secs)";
	}
	TextAllyP3Time.Create("Images/Fonts/arialbd.ttf", 16, m_StrAllyP3Time, { 255, 201, 14, 255 });


	m_Minutes = (m_AllyP1Time + m_AllyP2Time + m_AllyP3Time + m_AllyP4Time) / 60;
	m_Seconds = (m_AllyP1Time + m_AllyP2Time + m_AllyP3Time + m_AllyP4Time) % 60;
	m_StrPrevPhaseTime = m_StrAllyP3Time.substr(13, 5);
	if (m_Seconds < 10)
	{
		m_StrAllyP4Time = "Best: " + m_StrPrevPhaseTime + "- " + to_string(m_Minutes) + ":0" + to_string(m_Seconds) + " (" + to_string(m_AllyP4Time) + " Secs)";
	}
	else
	{
		m_StrAllyP4Time = "Best: " + m_StrPrevPhaseTime + "- " + to_string(m_Minutes) + ":" + to_string(m_Seconds) + " (" + to_string(m_AllyP4Time) + " Secs)";
	}
	TextAllyP4Time.Create("Images/Fonts/arialbd.ttf", 16, m_StrAllyP4Time, { 255, 201, 14, 255 });

	m_Minutes = (m_AllyP1Time + m_AllyP2Time + m_AllyP3Time + m_AllyP4Time + m_AllyP5Time) / 60;
	m_Seconds = (m_AllyP1Time + m_AllyP2Time + m_AllyP3Time + m_AllyP4Time + m_AllyP5Time) % 60;
	m_StrPrevPhaseTime = m_StrAllyP4Time.substr(13, 5);
	if (m_Seconds < 10)
	{
		m_StrAllyP5Time = "Best: " + m_StrPrevPhaseTime + "- " + to_string(m_Minutes) + ":0" + to_string(m_Seconds) + " (" + to_string(m_AllyP5Time) + " Secs)";
	}
	else
	{
		m_StrAllyP5Time = "Best: " + m_StrPrevPhaseTime + "- " + to_string(m_Minutes) + ":" + to_string(m_Seconds) + " (" + to_string(m_AllyP5Time) + " Secs)";
	}
	TextAllyP5Time.Create("Images/Fonts/arialbd.ttf", 16, m_StrAllyP5Time, { 255, 201, 14, 255 });



}

void TelosModule::CompareBest()
{
	//Grab the DPS from the first three phases
	m_BestCompareDamage = m_P1DPS + m_P2DPS + m_P3DPS;

	//Penalise the value if the player was not at or very close to 200% enrage
	if (m_P1Damage + m_P2Damage + m_P3Damage < 415000)
	{
		m_BestCompareDamage = m_BestCompareDamage / 10;
	}

	//Penalise the value if the player was below 100% enrage (And so did not do P5)
	if (m_P5Damage == 0)
	{
		m_BestCompareDamage = m_BestCompareDamage / 10;
	}
	cout << m_BestCompareDamage << endl;
	if (m_BestCompareDamage > m_AllyBestDmg)
	{
		SaveBest();
	}
}

void TelosModule::SaveBest()
{
	//cout << "We tried to save the fight we just fucking suck at it" << endl;
	string fightString;
	int totalDamage = m_P1DPS + m_P2DPS + m_P3DPS + m_P4DPS + m_P5DPS;
	if (m_P1Damage + m_P2Damage + m_P3Damage < 415000)
	{
		totalDamage = totalDamage/10;
	}
	if (m_P5Damage == 0)
	{
		totalDamage = totalDamage / 10;
	}
	string savedDamage = to_string(totalDamage);

	fightString = "A" + to_string(m_P1Damage) + "B" + m_StrP1DPS + "C" + to_string(m_P1Time) + "D" + to_string(m_P2Damage)
		+ "E" + m_StrP2DPS + "F" + to_string(m_P2Time) + "G" + to_string(m_P3Damage) + "H" + m_StrP3DPS
		+ "I" + to_string(m_P3Time) + "J" + to_string(m_P4Damage) + "K" + m_StrP4DPS + "L" + to_string(m_P4Time) + "M" + to_string(m_P5Damage)
		+ "N" + m_StrP5DPS + "O" + to_string(m_P5Time) + "P" + savedDamage;


	m_TelosData.ReplaceString("Data/TelosBest.txt", fightString);
}
