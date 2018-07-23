#include "SolakModule.h"
#include "WindowText.h"



SolakModule::SolakModule()
{
	if (m_FirstTime)
	{
		m_FirstTime = false;
		SolakImages.SolakSetup();
		
		string ArialFont = "Images/Fonts/arial.ttf";

		TextSolakReportHeader.Create("Images/Fonts/arial.ttf", 30, "Damage Report for Solak", { 255, 255, 255, 255 });
		/*
		TextSolakReportHeader2.Create("Images/Fonts/arial.ttf", 30, "Ally Damage in Red", { 255, 0, 0, 255 });
		TextSolakTotalDamage.Create("Images/Fonts/arial.ttf", 30, "Total Damage Dealt:", { 255, 255, 255, 255 });
		TextSolakArms.Create("Images/Fonts/arial.ttf", 30, "Arms Dmg", { 255, 255, 255, 255 });
		TextSolakLegs.Create("Images/Fonts/arial.ttf", 30, "Legs Dmg", { 255, 255, 255, 255 });
		TextSolakCore.Create("Images/Fonts/arial.ttf", 30, "Core Dmg", { 255, 255, 255, 255 });
		TextSolakPhase1.Create("Images/Fonts/arial.ttf", 30, "Phase 1", { 255, 255, 255, 255 });
		TextSolakPhase2.Create("Images/Fonts/arial.ttf", 30, "Phase 2", { 255, 255, 255, 255 });
		TextSolakPhase3.Create("Images/Fonts/arial.ttf", 30, "Phase 3", { 255, 255, 255, 255 });
		TextSolakPhase4.Create("Images/Fonts/arial.ttf", 30, "Phase 4", { 255, 255, 255, 255 });
		TextSolakRoots.Create("Images/Fonts/arial.ttf", 30, "Boss", { 255, 255, 255, 255 });
		TextSolakP1TotalDmg.Create("Images/Fonts/arial.ttf", 30, "Phase 1 Totals", { 255, 255, 255, 255 });
		
		for (int j = 0; j < 4; j++)
		{
			TextSolakP1Dmg[j].Create("Images/Fonts/arial.ttf", 30, "0", { 0, 255, 0, 255 });
			TextSolakArmsDmg[j].Create("Images/Fonts/arial.ttf", 30, "0", { 0, 255, 0, 255 });
			TextSolakLegsDmg[j].Create("Images/Fonts/arial.ttf", 30, "0", { 0, 255, 0, 255 });
			TextSolakCoreDmg[j].Create("Images/Fonts/arial.ttf", 30, "0", { 0, 255, 0, 255 });

			TextAllyArmsDmg[j].Create("Images/Fonts/arial.ttf", 30, "0", { 255, 0, 0, 255 });
			TextAllyLegsDmg[j].Create("Images/Fonts/arial.ttf", 30, "0", { 255, 0, 0, 255 });
			
		}

		
		TextSolakP2Dmg.Create("Images/Fonts/arial.ttf", 30, "0", { 0, 255, 0, 255 });
		TextSolakP3Dmg.Create("Images/Fonts/arial.ttf", 30, "0", { 0, 255, 0, 255 });
		TextSolakP4Dmg.Create("Images/Fonts/arial.ttf", 30, "0", { 0, 255, 0, 255 });

		TextAllyCoreDmg.Create("Images/Fonts/arial.ttf", 30, "0", { 255, 0, 0, 255 });
		TextAllyP1Dmg.Create("Images/Fonts/arial.ttf", 30, "0", { 255, 0, 0, 255 });
		TextAllyP2Dmg.Create("Images/Fonts/arial.ttf", 30, "0", { 255, 0, 0, 255 });
		TextAllyP3Dmg.Create("Images/Fonts/arial.ttf", 30, "0", { 255, 0, 0, 255 });
		TextAllyP4Dmg.Create("Images/Fonts/arial.ttf", 30, "0", { 255, 0, 0, 255 });

		
		TextSolakDmg.Create("Images/Fonts/arial.ttf", 30, "0", { 0, 255, 0, 255 });

		TextSolakDuoActive.Create(ArialFont, 30, "Solak (Duo Mode)", { 0, 255, 0, 255 });
		TextSolakTeamActive.Create(ArialFont, 30, "Solak (7 Man)", { 0, 255, 0, 255 });
		*/
		
	}
	//std::string FontLoc = "Images/Fonts/arial.ttf";
	
	//WindowRect TextTest();
}

SolakModule::~SolakModule()
{
}

void SolakModule::Update(Mat1b Screenshot, unsigned int Damage, Mat1b ChatScreen)
{
	if (TextSolakReportHeader.GetTexFail())
	{
		std::cout << "WE HAD TO REMAKE THE TEXTURES";
		TextSolakReportHeader.Create("Images/Fonts/arial.ttf", 30, "Damage Report for Solak", { 255, 255, 255, 255 });
		TextSolakReportHeader2.Create("Images/Fonts/arial.ttf", 30, "Ally Damage in Red", { 255, 0, 0, 255 });
		TextSolakTotalDamage.Create("Images/Fonts/arial.ttf", 30, "Total Damage Dealt:", { 255, 255, 255, 255 });
		TextSolakArms.Create("Images/Fonts/arial.ttf", 30, "Arms Dmg", { 255, 255, 255, 255 });
		TextSolakLegs.Create("Images/Fonts/arial.ttf", 30, "Legs Dmg", { 255, 255, 255, 255 });
		TextSolakCore.Create("Images/Fonts/arial.ttf", 30, "Core Dmg", { 255, 255, 255, 255 });
		TextSolakPhase1.Create("Images/Fonts/arial.ttf", 30, "Phase 1", { 255, 255, 255, 255 });
		TextSolakPhase2.Create("Images/Fonts/arial.ttf", 30, "Phase 2", { 255, 255, 255, 255 });
		TextSolakPhase3.Create("Images/Fonts/arial.ttf", 30, "Phase 3", { 255, 255, 255, 255 });
		TextSolakPhase4.Create("Images/Fonts/arial.ttf", 30, "Phase 4", { 255, 255, 255, 255 });
		TextSolakRoots.Create("Images/Fonts/arial.ttf", 30, "Boss/Roots", { 255, 255, 255, 255 });
		TextSolakP1TotalDmg.Create("Images/Fonts/arial.ttf", 30, "Phase 1 Totals", { 255, 255, 255, 255 });

		for (int j = 0; j < 4; j++)
		{
			TextSolakP1Dmg[j].Create("Images/Fonts/arial.ttf", 30, "0", { 0, 255, 0, 255 });
			TextSolakArmsDmg[j].Create("Images/Fonts/arial.ttf", 30, "0", { 0, 255, 0, 255 });
			TextSolakLegsDmg[j].Create("Images/Fonts/arial.ttf", 30, "0", { 0, 255, 0, 255 });
			TextSolakCoreDmg[j].Create("Images/Fonts/arial.ttf", 30, "0", { 0, 255, 0, 255 });

			TextAllyArmsDmg[j].Create("Images/Fonts/arial.ttf", 30, "0", { 255, 0, 0, 255 });
			TextAllyLegsDmg[j].Create("Images/Fonts/arial.ttf", 30, "0", { 255, 0, 0, 255 });
		}

		/*
		TextSolakP1Dmg.Create("Images/Fonts/arial.ttf", 30, "0", { 0, 255, 0, 255 });
		TextSolakArmsDmg.Create("Images/Fonts/arial.ttf", 30, "0", { 0, 255, 0, 255 });
		TextSolakLegsDmg.Create("Images/Fonts/arial.ttf", 30, "0", { 0, 255, 0, 255 });
		TextSolakCoreDmg.Create("Images/Fonts/arial.ttf", 30, "0", { 0, 255, 0, 255 });
		*/
		TextSolakP2Dmg.Create("Images/Fonts/arial.ttf", 30, "0", { 0, 255, 0, 255 });
		TextSolakP3Dmg.Create("Images/Fonts/arial.ttf", 30, "0", { 0, 255, 0, 255 });
		TextSolakP4Dmg.Create("Images/Fonts/arial.ttf", 30, "0", { 0, 255, 0, 255 });

		TextAllyCoreDmg.Create("Images/Fonts/arial.ttf", 30, "0", { 255, 0, 0, 255 });
		TextAllyP1Dmg.Create("Images/Fonts/arial.ttf", 30, "0", { 255, 0, 0, 255 });
		TextAllyP2Dmg.Create("Images/Fonts/arial.ttf", 30, "0", { 255, 0, 0, 255 });
		TextAllyP3Dmg.Create("Images/Fonts/arial.ttf", 30, "0", { 255, 0, 0, 255 });
		TextAllyP4Dmg.Create("Images/Fonts/arial.ttf", 30, "0", { 255, 0, 0, 255 });


		TextSolakDmg.Create("Images/Fonts/arial.ttf", 30, "0", { 0, 255, 0, 255 });
		

		TextSolakDuoActive.Create("Images/Fonts/arial.ttf", 30, "Solak (Duo Mode)", { 0, 255, 0, 255 });
		TextSolakTeamActive.Create("Images/Fonts/arial.ttf", 30, "Solak (7 Man)", { 0, 255, 0, 255 });
	}
	
	

	

	ReportDamage();

	//Check if this is the first frame since entering the fight
	if (!m_FightStarted)
	{
		m_BaseDamage = Damage;
		m_DamageLastCheckpoint = Damage;
		m_FightStarted = true;
	}

	if (m_DuoActive)
	{
		TextSolakDuoActive.display(220, 110);
	}
	else
	{
		TextSolakTeamActive.display(220, 110);
	}
	//If no phase is currently active, we must be in the room but have not started the fight, set phase 1 to be active
	if (!m_Phase1Active && !m_Phase2Active && !m_Phase3Active && !m_Phase4Active)
	{
		m_Phase1Active = true;
	}

	if (m_Phase1Active)
	{
		//If Arms Active boolean is false and legs/core, but we match arms active picture, set it to be true
		if (!m_ArmsActive && !m_LegsActive && !m_CoreActive && SolakMatch.GetMatch(Screenshot, SolakImages.GetSolakLeftArm(), 0.82f))
		{
			m_P1Damage[m_Phase1Counter] = Damage - m_DamageLastCheckpoint;
			m_TotalDamage += (Damage - m_DamageLastCheckpoint);
			m_DamageLastCheckpoint = Damage;
			m_ArmsActive = true;
			cout << "P1 Damage was: " << m_P1Damage[m_Phase1Counter] << " \n";
			//Update the P1 Damage Counter
			m_StrP1Damage[m_Phase1Counter] = to_string(m_P1Damage[m_Phase1Counter]);
			TextSolakP1Dmg[m_Phase1Counter].Create("Images/Fonts/arial.ttf", 30, m_StrP1Damage[m_Phase1Counter], { 0, 255, 0, 255 });
			//Flag the fight damage to be updated
			m_DamageWasUpdated = true;
			return;
		}

		if (!m_ArmsActive && !m_LegsActive && !m_CoreActive && SolakMatch.GetMatch(Screenshot, SolakImages.GetSolakRightArm(), 0.82f))
		{
			m_P1Damage[m_Phase1Counter] = Damage - m_DamageLastCheckpoint;
			m_TotalDamage += (Damage - m_DamageLastCheckpoint);
			m_DamageLastCheckpoint = Damage;
			m_ArmsActive = true;
			cout << "P1 Damage was: " << m_P1Damage[m_Phase1Counter] << " \n";
			//Update the P1 Damage Counter
			m_StrP1Damage[m_Phase1Counter] = to_string(m_P1Damage[m_Phase1Counter]);
			TextSolakP1Dmg[m_Phase1Counter].Create("Images/Fonts/arial.ttf", 30, m_StrP1Damage[m_Phase1Counter], { 0, 255, 0, 255 });
			//Flag the fight damage to be updated
			m_DamageWasUpdated = true;
			return;
		}


		//If Arms active boolean is true but we match legs picture, set legs to be true and arms to be false
		if (m_ArmsActive && SolakMatch.GetMatch(Screenshot, SolakImages.GetSolakLeftLeg(), 0.82f))
		{
			m_ArmsDamage[m_Phase1Counter] = Damage - m_DamageLastCheckpoint;
			m_TotalDamage += (Damage - m_DamageLastCheckpoint);
			m_DamageLastCheckpoint = Damage;
			m_ArmsActive = false;
			m_LegsActive = true;
			cout << "Arms Damage was: " << m_ArmsDamage[m_Phase1Counter] << " \n";
			//Update the Arms Damage Counter
			m_StrArmsDamage[m_Phase1Counter] = to_string(m_ArmsDamage[m_Phase1Counter]);
			TextSolakArmsDmg[m_Phase1Counter].Create("Images/Fonts/arial.ttf", 30, m_StrArmsDamage[m_Phase1Counter], { 0, 255, 0, 255 });

			//Work out the ally's damage, take damage dealt away from total arms health
			if (m_DuoActive)
			{
				m_AllyArmsDmg[m_Phase1Counter] = (m_DuoArmHealth*2) - m_ArmsDamage[m_Phase1Counter];
			}
			else
			{
				//Work out remaining damage, then average it between the six other members
				m_AllyArmsDmg[m_Phase1Counter] = ((m_TeamArmHealth * 2) - m_ArmsDamage[m_Phase1Counter])/6;
			}
			
			m_StrAllyArmsDmg[m_Phase1Counter] = to_string(m_AllyArmsDmg[m_Phase1Counter]);
			TextAllyArmsDmg[m_Phase1Counter].Create("Images/Fonts/arial.ttf", 30, m_StrAllyArmsDmg[m_Phase1Counter], { 255, 0, 0, 255 });

			//Flag the fight damage to be updated
			m_DamageWasUpdated = true;
			return;
		}

		if (m_ArmsActive && SolakMatch.GetMatch(Screenshot, SolakImages.GetSolakRightLeg(), 0.82f))
		{
			m_ArmsDamage[m_Phase1Counter] = Damage - m_DamageLastCheckpoint;
			m_TotalDamage += (Damage - m_DamageLastCheckpoint);
			m_DamageLastCheckpoint = Damage;
			m_ArmsActive = false;
			m_LegsActive = true;
			cout << "Arms Damage was: " << m_ArmsDamage[m_Phase1Counter] << " \n";
			//Update the Arms Damage Counter
			m_StrArmsDamage[m_Phase1Counter] = to_string(m_ArmsDamage[m_Phase1Counter]);
			TextSolakArmsDmg[m_Phase1Counter].Create("Images/Fonts/arial.ttf", 30, m_StrArmsDamage[m_Phase1Counter], { 0, 255, 0, 255 });

			//Work out the ally's damage, take damage dealt away from total arms health
			if (m_DuoActive)
			{
				m_AllyArmsDmg[m_Phase1Counter] = (m_DuoArmHealth * 2) - m_ArmsDamage[m_Phase1Counter];
			}
			else
			{
				//Work out remaining damage, then average it between the six other members
				m_AllyArmsDmg[m_Phase1Counter] = ((m_TeamArmHealth * 2) - m_ArmsDamage[m_Phase1Counter]) / 6;
			}

			m_StrAllyArmsDmg[m_Phase1Counter] = to_string(m_AllyArmsDmg[m_Phase1Counter]);
			TextAllyArmsDmg[m_Phase1Counter].Create("Images/Fonts/arial.ttf", 30, m_StrAllyArmsDmg[m_Phase1Counter], { 255, 0, 0, 255 });

			//Flag the fight damage to be updated
			m_DamageWasUpdated = true;
			return;
		}
		//If legs boolean is true but we match core picture, set core to be true and legs to be false
		if (m_LegsActive && SolakMatch.GetMatch(Screenshot, SolakImages.GetSolakCore(), 0.82f))
		{
			m_LegsDamage[m_Phase1Counter] = Damage - m_DamageLastCheckpoint;
			m_TotalDamage += (Damage - m_DamageLastCheckpoint);
			m_DamageLastCheckpoint = Damage;
			m_LegsActive = false;
			m_CoreActive = true;
			cout << "Legs Damage was: " << m_LegsDamage[m_Phase1Counter] << " \n";
			m_StrLegsDamage[m_Phase1Counter] = to_string(m_LegsDamage[m_Phase1Counter]);
			TextSolakLegsDmg[m_Phase1Counter].Create("Images/Fonts/arial.ttf", 30, m_StrLegsDamage[m_Phase1Counter], { 0, 255, 0, 255 });


			//Work out the ally's damage, take damage dealt away from total arms health
			if (m_DuoActive)
			{
				m_AllyLegsDmg[m_Phase1Counter] = (m_DuoLegHealth * 2) - m_LegsDamage[m_Phase1Counter];
			}
			else
			{
				//Work out remaining damage, then average it between the six other members
				m_AllyLegsDmg[m_Phase1Counter] = ((m_TeamLegHealth * 2) - m_LegsDamage[m_Phase1Counter]) / 6;
			}


			m_StrAllyLegsDmg[m_Phase1Counter] = to_string(m_AllyLegsDmg[m_Phase1Counter]);
			TextAllyLegsDmg[m_Phase1Counter].Create("Images/Fonts/arial.ttf", 30, m_StrAllyLegsDmg[m_Phase1Counter], { 255, 0, 0, 255 });

			//Flag the fight damage to be updated
			m_DamageWasUpdated = true;
			return;
		}
		//If core boolean is true, but we see the end of core speech, set core to be false and increment the phase 1 counter
		if (m_CoreActive && SolakMatch.GetMatch(ChatScreen, SolakImages.GetSolakCoreEnd(), 0.82f))
		{
			m_CoreDamage[m_Phase1Counter] = Damage - m_DamageLastCheckpoint;
			m_TotalDamage += (Damage - m_DamageLastCheckpoint);
			m_DamageLastCheckpoint = Damage;
			m_CoreActive = false;
			cout << "LCore Damage was: " << m_CoreDamage[m_Phase1Counter] << " \n";

			//Update the Core Damage Counter
			m_StrCoreDamage[m_Phase1Counter] = to_string(m_CoreDamage[m_Phase1Counter]);
			TextSolakCoreDmg[m_Phase1Counter].Create("Images/Fonts/arial.ttf", 30, m_StrCoreDamage[m_Phase1Counter], { 0, 255, 0, 255 });
			//Flag the fight damage to be updated
			m_DamageWasUpdated = true;

			m_Phase1Counter++;
			return;
			
		}

		//If arms, legs and core are not active but we see the phase end emote, advance the phase
		if (!m_ArmsActive && !m_LegsActive && !m_CoreActive && SolakMatch.GetMatch(ChatScreen, SolakImages.GetSolakP2Start(), 0.82f))
		{
			m_Phase1Active = false;
			m_Phase2Active = true;
			

			m_Phase1Counter--; //Decrease the phase counter since we just skipped into phase 2 and don't need to record additional phase 1 data
			
			//Sum up the damages for the phase
			for (int k = 0; k <= m_Phase1Counter; k++)
			{
				m_P1DamageTotal += m_P1Damage[k];
				m_LegsDamageTotal += m_LegsDamage[k];
				m_ArmsDamageTotal += m_ArmsDamage[k];
				m_CoreDamageTotal += m_CoreDamage[k];
				m_AllyArmsDmgTotal += m_AllyArmsDmg[k];
				m_AllyLegsDmgTotal += m_AllyLegsDmg[k];
			}

			
			m_StrP1DamageTotal = to_string(m_P1DamageTotal);
			TextSolakPhase1Total.Create("Images/Fonts/arial.ttf", 30, m_StrP1DamageTotal, { 0, 255, 0, 255 });

			m_StrLegsDamageTotal = to_string(m_LegsDamageTotal);
			TextSolakLegsTotal.Create("Images/Fonts/arial.ttf", 30, m_StrLegsDamageTotal, { 0, 255, 0, 255 });

			m_StrArmsDamageTotal = to_string(m_ArmsDamageTotal);
			TextSolakArmsTotal.Create("Images/Fonts/arial.ttf", 30, m_StrArmsDamageTotal, { 0, 255, 0, 255 });

			m_StrCoreDamageTotal = to_string(m_CoreDamageTotal);
			TextSolakCoreTotal.Create("Images/Fonts/arial.ttf", 30, m_StrCoreDamageTotal, { 0, 255, 0, 255 });

			m_StrAllyLegsDmgTotal = to_string(m_AllyLegsDmgTotal);
			TextAllyLegsTotal.Create("Images/Fonts/arial.ttf", 30, m_StrAllyLegsDmgTotal, { 255, 0, 0, 255 });

			m_StrAllyArmsDmgTotal = to_string(m_AllyArmsDmgTotal);
			TextAllyArmsTotal.Create("Images/Fonts/arial.ttf", 30, m_StrAllyArmsDmgTotal, { 255, 0, 0, 255 });

			//Work out the ally's damage, take damage dealt away from total core health
			if (m_DuoActive)
			{
				m_AllyCoreDmg = m_DuoCoreHealth - m_CoreDamageTotal;
			}
			else
			{
				//Work out remaining damage, then average it between the six other members
				m_AllyCoreDmg = (m_TeamCoreHealth - m_CoreDamageTotal) / 6;
			}


			m_StrAllyCoreDmg = to_string(m_AllyCoreDmg);
			TextAllyCoreTotal.Create("Images/Fonts/arial.ttf", 30, m_StrAllyCoreDmg, { 255, 0, 0, 255 });

			//Work out the ally's damage, take their total damage in phase 1 and subtract it from Solak + Root's total health
			//Base health is 750k + (Number of phases*(8 * 20,000))  to account for roots for each phase
			//m_AllyP1Dmg = (750000 + ((m_Phase1Counter + 1) * 160000)) - m_P1DamageTotal;
			if (m_DuoActive)
			{
				m_AllyP1Dmg = (m_DuoP1Health + ((m_Phase1Counter+1) * (m_DuoRootHealth*8))) - m_P1DamageTotal;
			}
			else
			{
				//Work out remaining damage, then average it between the six other members
				m_AllyP1Dmg = ((m_TeamP1Health + ((m_Phase1Counter + 1) * (m_TeamRootHealth * 8))) - m_P1DamageTotal) / 6;
			}


			m_StrAllyP1Dmg = to_string(m_AllyP1Dmg);
			TextAllyP1Dmg.Create("Images/Fonts/arial.ttf", 30, m_StrAllyP1Dmg, { 255, 0, 0, 255 });

			return;
		}
	}

	if (m_Phase2Active)
	{
		if (SolakMatch.GetMatch(Screenshot, SolakImages.GetSolakP3Start(), 0.82f))
		{

			m_P2Damage = Damage - m_DamageLastCheckpoint;
			m_TotalDamage += (Damage - m_DamageLastCheckpoint);
			m_DamageLastCheckpoint = Damage;
			m_Phase2Active = false;
			m_Phase3Active = true;
			cout << "Phase 2 Damage was: " << m_P2Damage << " \n";

			//Update the Phase 2 Counter
			m_StrP2Damage = to_string(m_P2Damage);
			TextSolakP2Dmg.Create("Images/Fonts/arial.ttf", 30, m_StrP2Damage, { 0, 255, 0, 255 });

			//Ally's Damage is equal to (Estimated Blight storm health + Solak's phase health + 4 Anima Blight Storm Healths) - damage you did in phase 2.
			//The blight storm really throws off the phase's damage, ideally I should seperate the blight stage from the rest of the phase
			//m_AllyP2Dmg = (350000 + 1050000 + 100000) - m_P2Damage;

			if (m_DuoActive)
			{
				m_AllyP2Dmg = (m_DuoAnimaStormHealth + m_DuoP2Health + (m_DuoAnimaFontHealth*4)) - m_P2Damage;
			}
			else
			{
				//Work out remaining damage, then average it between the six other members
				m_AllyP2Dmg = ((m_TeamAnimaStormHealth + m_TeamP2Health + (m_TeamAnimaFontHealth * 4)) - m_P2Damage) / 6;
			}

			m_StrAllyP2Dmg = to_string(m_AllyP2Dmg);
			TextAllyP2Dmg.Create("Images/Fonts/arial.ttf", 30, m_StrAllyP2Dmg, { 255, 0, 0, 255 });
			//Flag the fight damage to be updated
			m_DamageWasUpdated = true;
			return;
		}
	}

	if (m_Phase3Active)
	{
		if (SolakMatch.GetMatch(Screenshot, SolakImages.GetSolakP4Start(), 0.82f))
		{
			m_P3Damage = Damage - m_DamageLastCheckpoint;
			m_TotalDamage += (Damage - m_DamageLastCheckpoint);
			m_DamageLastCheckpoint = Damage;
			m_Phase3Active = false;
			m_Phase4Active = true;
			cout << "Phase 3 Damage was: " << m_P3Damage << " \n";
			//Update the Phase 2 Counter
			m_StrP3Damage = to_string(m_P3Damage);
			TextSolakP3Dmg.Create("Images/Fonts/arial.ttf", 30, m_StrP3Damage, { 0, 255, 0, 255 });

			//Phase health minus damage you dealt to boss. Does not factor in mind realm.
			//m_AllyP3Dmg = (900000) - m_P3Damage;
			if (m_DuoActive)
			{
				m_AllyP3Dmg = m_DuoP3Health - m_P3Damage;
			}
			else
			{
				//Work out remaining damage, then average it between the six other members
				m_AllyP3Dmg = (m_TeamP3Health - m_P3Damage) / 6;
			}

			m_StrAllyP3Dmg = to_string(m_AllyP3Dmg);
			TextAllyP3Dmg.Create("Images/Fonts/arial.ttf", 30, m_StrAllyP3Dmg, { 255, 0, 0, 255 });
			//Flag the fight damage to be updated
			m_DamageWasUpdated = true;
			return;
		}

	}

	if (m_Phase4Active)
	{
		if (!m_P4MindDebuff && SolakMatch.GetMatch(Screenshot, SolakImages.GetSolakMindDebuff(), 0.9f))
		{
			m_P4MindDebuff = true;
			m_P4DamageMindCapped = Damage;
			return;
		}

		if (SolakMatch.GetMatch(Screenshot, SolakImages.GetSolakEnd(), 0.82f))
		{
			if (m_P4DamageMindCapped != 0)
			{
				m_P4Damage = m_P4DamageMindCapped - m_DamageLastCheckpoint;
				m_TotalDamage += m_P4Damage;
				m_DamageLastCheckpoint = Damage;
				m_Phase4Active = false;
			}
			else
			{
				m_P4Damage = Damage - m_DamageLastCheckpoint;
				m_TotalDamage += (Damage - m_DamageLastCheckpoint);
				m_DamageLastCheckpoint = Damage;
				m_Phase4Active = false;
			}

			cout << "Phase 4 Damage was: " << m_P4Damage << " \n";
			m_ReportDamage = true;
			//Update the Phase 2 Counter
			m_StrP4Damage = to_string(m_P4Damage);
			TextSolakP4Dmg.Create("Images/Fonts/arial.ttf", 30, m_StrP4Damage, { 0, 255, 0, 255 });

			//Phase health minus damage dealt to boss
			//m_AllyP4Dmg = (300000) - m_P4Damage;
			if (m_DuoActive)
			{
				m_AllyP4Dmg = m_DuoP4Health - m_P4Damage;
			}
			else
			{
				//Work out remaining damage, then average it between the six other members
				m_AllyP4Dmg = (m_TeamP4Health - m_P4Damage) / 6;
			}
			m_StrAllyP4Dmg = to_string(m_AllyP4Dmg);
			TextAllyP4Dmg.Create("Images/Fonts/arial.ttf", 30, m_StrAllyP4Dmg, { 255, 0, 0, 255 });
			//Flag the fight damage to be updated
			m_FightEnded = true;
			m_DamageWasUpdated = true;
			return;
		}
	}


}

void SolakModule::Reset()
{
	m_BaseDamage = m_TotalDamage = m_TempDamage = m_P1Damage[0] = m_P1Damage[1] = m_P1Damage[2] = m_P1Damage[3] = 0;
	m_ArmsDamage[0] = m_ArmsDamage[1] = m_ArmsDamage[2] = m_ArmsDamage[3] = m_LegsDamage[0] = m_LegsDamage[1] = m_LegsDamage[2] = m_LegsDamage[3] = 0;
	m_CoreDamage[0] = m_CoreDamage[1] = m_CoreDamage[2] = m_CoreDamage[3] = m_P2Damage = m_P3Damage = m_P4Damage = m_P4DamageMindCapped = 0;
	m_ArmsDamageTotal = m_LegsDamageTotal = m_CoreDamageTotal = m_DamageLastCheckpoint = 0;

	m_AllyP1Dmg = m_AllyArmsDmg[0] = m_AllyArmsDmg[1] = m_AllyArmsDmg[2] = m_AllyArmsDmg[3] = m_AllyLegsDmg[0] = m_AllyLegsDmg[1] = 0;
	m_AllyLegsDmg[2] = m_AllyLegsDmg[3] = m_AllyCoreDmg = m_AllyP2Dmg = m_AllyP3Dmg = m_AllyP4Dmg = m_AllyDmgTotal = 0;
	m_AllyArmsDmgTotal = m_AllyLegsDmgTotal = 0;

	m_FightStarted = m_Phase1Active = m_ArmsActive = m_LegsActive = m_CoreActive = m_Phase2Active = m_Phase3Active = m_Phase4Active = m_FightEnded = false;
	m_P4MindDebuff = m_DuoActive = m_TeamActive = m_FightEnded = false;

	m_P1DamageTotal = 0;

	m_Phase1Counter = 0;
}

void SolakModule::ReportDamage()
{
	
	if (m_DamageWasUpdated)
	{
		m_DamageWasUpdated = false;
		m_StrTotalDamage = to_string(m_TotalDamage);
		TextSolakDmg.display(300, 180, m_StrTotalDamage);
	}
	else
	{
		TextSolakDmg.display(300, 180);
	}
	

	TextSolakReportHeader.display(50, 150);
	TextSolakReportHeader2.display(400, 150);

	TextSolakTotalDamage.display(20, 180);
	

	//cout << "Damage report for Solak \n";
	//cout << "Total Damage Dealt: " << m_TotalDamage << " \n \n";
	TextSolakPhase1.display(20, 210);
	TextSolakRoots.display(20, 240);
	TextSolakArms.display(180, 240);
	TextSolakLegs.display(360, 240);
	TextSolakCore.display(540, 240);

	for (int i = 0; i <= 2; i++)
	{
		/*
		m_StrP1Damage[i] = to_string(m_P1Damage[i]);
		m_StrArmsDamage[i] = to_string(m_ArmsDamage[i]);
		m_StrLegsDamage[i] = to_string(m_LegsDamage[i]);
		m_StrCoreDamage[i] = to_string(m_CoreDamage[i]);

		TextSolakPhase1.display(20, 210);
		TextSolakArms.display(150, 210);
		TextSolakLegs.display(300, 210);
		TextSolakCore.display(450, 210);
		
		TextSolakP1Dmg[i].display(20, 240 + (i * 60), m_StrP1Damage[i]);
		TextSolakArmsDmg[i].display(150, 240 + (i * 60), m_StrArmsDamage[i]);
		TextSolakLegsDmg[i].display(300, 240 + (i * 60), m_StrLegsDamage[i]);
		TextSolakCoreDmg[i].display(450, 240 + (i * 60), m_StrCoreDamage[i]);
		*/
		TextSolakP1Dmg[i].display(20, 270 + (i * 60));
		TextSolakArmsDmg[i].display(180, 270 + (i * 60));
		TextSolakLegsDmg[i].display(360, 270 + (i * 60));
		TextSolakCoreDmg[i].display(540, 270 + (i * 60));

		TextAllyArmsDmg[i].display(180, 300 + (i * 60));
		TextAllyLegsDmg[i].display(360, 300 + (i * 60));

		/*
		cout << "PHASE 1 PART" << (i+1) << " \n";
		cout << "Damage: " << m_P1Damage[i] << " \n";
		cout << "Arms Damage: " << m_ArmsDamage[i] << " \n";
		cout << "Legs Damage: " << m_LegsDamage[i] << " \n";
		cout << "Core Damage: " << m_CoreDamage[i] << " \n \n";
		*/
	}
	TextSolakP1TotalDmg.display(20, 450);
	TextSolakPhase1Total.display(20, 480);
	TextSolakArmsTotal.display(180, 480);
	TextSolakLegsTotal.display(360, 480);
	TextSolakCoreTotal.display(540, 480);
	TextAllyP1Dmg.display(20, 510);
	TextAllyArmsTotal.display(180, 510);
	TextAllyLegsTotal.display(360, 510);
	TextAllyCoreTotal.display(540, 510);

	TextSolakPhase2.display(20, 540);
	//m_StrP2Damage = to_string(m_P2Damage);
	TextSolakP2Dmg.display(180, 540);
	TextAllyP2Dmg.display(360, 540);

	TextSolakPhase3.display(20, 570);
	//m_StrP3Damage = to_string(m_P3Damage);
	TextSolakP3Dmg.display(180, 570);
	TextAllyP3Dmg.display(360, 570);

	TextSolakPhase4.display(20, 600);
	//m_StrP4Damage = to_string(m_P4Damage);
	TextSolakP4Dmg.display(180, 600);
	TextAllyP4Dmg.display(360, 600);

	/*
	cout << "PHASE 2 \n";
	cout << "Damage: " << m_P2Damage << " \n \n";

	cout << "Phase 3 \n";
	cout << "Damage: " << m_P3Damage << " \n \n";

	cout << "Phase 4 \n";
	cout << "Damage: " << m_P4Damage << " \n \n";
	*/
	if (m_FightEnded)
	{
		Reset();
		m_FightEnded = false;
	}
}
