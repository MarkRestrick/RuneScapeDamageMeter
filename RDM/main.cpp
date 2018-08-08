

#include<opencv2\opencv.hpp>
#include <Windows.h>
#include<stdint.h>
#include "ScreenCapture.h"
#include "ImageSetup.h"
#include "TemplateMatcher.h"
#include "DamageCheck.h"
#include "SolakModule.h"
#include <SDL.h>
#include <SDL_image.h>
#include "Window.h"
#include "WindowRect.h"
#include "WindowText.h"
#include <string>
#include "DataHandler.h"
#include "Timer.h"
#include "TelosModule.h"






const int SCREEN_WIDTH = 300;
const int SCREEN_HEIGHT = 300;


SDL_Window* window = NULL;
//SDL_Surface* screen = NULL;

string WindowName = "RuneScape Damage Meter (Beta 1.0)";


using namespace cv;
using namespace std;

const int fps = 40;

bool BossActive = false;
bool SolakActive = false;
bool SolakGroupActive = false;
bool TelosActive = false;
bool fillerBool;

ImageSetup ImageStore;
TemplateMatcher TemplateMatch;
SolakModule Solak;
TelosModule Telos;


bool BossActiveCheck(Mat1b Screenshot)
{
	if (TemplateMatch.GetMatch(Screenshot, ImageStore.GetSolakTagA(), 0.9f))
	{
		BossActive = true;
		SolakActive = false;
		SolakGroupActive = true;
		TelosActive = false;
		Telos.SetActive(false);
		//cout << "We're gonna fight Solak! \n";
		Solak.Reset();
		Solak.SetDuoActive(false);
		return true;
	}
	else if (TemplateMatch.GetMatch(Screenshot, ImageStore.GetSolakTagB(), 0.9f))
	{
		BossActive = true;
		SolakActive = true;
		SolakGroupActive = false;
		TelosActive = false;
		Telos.SetActive(false);
		//cout << "We're gonna fight Solak! \n";
		Solak.Reset();
		Solak.SetDuoActive(true);
		return true;
	}
	else if (TemplateMatch.GetMatch(Screenshot, ImageStore.GetTelosTag(), 0.9f))
	{
		BossActive = true;
		SolakActive = false;
		SolakGroupActive = false;
		TelosActive = true;
		//cout << "We're gonna fight Solak! \n";
		Telos.Reset();
		Telos.SetActive(true);
		return true;
	}
	
	return false;
}

#undef main //Stops a really stupid error that has been plagueing me for the past 2 hours. Holy hell why does SDL try to overwrite the main function jesus.

int main()
{
	
	HWND hwnd = GetConsoleWindow();
	ShowWindow(hwnd, 0);
	
	//Hides the console window :D

	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Window window(WindowName, 800, 700);

	//_CrtSetBreakAlloc(153);

	DataHandler SolakData;
	SolakData.Start();

	Timer StopWatch;
	StopWatch.Start();


	ScreenCapture Screener;

	DamageCheck DmgCheck;
	unsigned int BossStartingDamage;
	unsigned int Damage = 0;
	unsigned int DamageLastFrame;
	string DamageString = "0";
	string ArialFont = "Images/Fonts/arial.ttf";

	int DamageStringLength;

	Mat1b Screenshot;
	Mat1b DamageScreenshot;
	Mat1b ChatScreenshot;

	int key = 0;

	//Window Strings
	string DamageAreaStatus = "Damage Area not found";

	ImageStore.GeneralSetup();

	WindowRect HeaderImg(800, 129, 0, 0, "Images/UI/Head.png");
	WindowRect SolakImg(800, 574, 0, 129, "Images/UI/SolakLayout.png");
	WindowRect TelosImg(800, 574, 0, 129, "Images/UI/TelosLayout.png");
	WindowRect DmgImg(49, 41, 0, 0, "Images/UI/DamageFound.png");
	WindowRect NoDmgImg(49, 41, 0, 0, "Images/UI/DamageNotFound.png");
	WindowRect ChatImg(49, 41, 50, 0, "Images/UI/ChatFound.png");
	WindowRect NoChatImg(49, 41, 50, 0, "Images/UI/ChatNotFound.png");

	//WindowText TextNoDamageArea;
	//WindowText TextFoundDamageArea;
	WindowText TextCurrentOverallDamage;
	//WindowText TextNoChatArea;
	//WindowText TextFoundChatArea;
	WindowText TextCurrentBoss;
	WindowText TextSolakDuo;
	WindowText TextSolakGroup;
	WindowText TextNoBoss;
	WindowText TextTelos;
	
	
	//TextNoDamageArea.Create(ArialFont, 30, "Could not find Damage Area", { 255, 0, 0, 255 });
	//TextFoundDamageArea.Create(ArialFont, 30, "Found Damage Area", { 0, 255, 0, 255 });
	TextCurrentOverallDamage.Create(ArialFont, 20, DamageString, { 0, 255, 0, 255 });
	//TextNoChatArea.Create(ArialFont, 30, "Could not find Chat Area", { 255, 0, 0, 255 });
	//TextFoundChatArea.Create(ArialFont, 30, "Found Chat Area", { 0, 255, 0, 255 });
	TextCurrentBoss.Create(ArialFont, 16, "Current Boss: ", { 255, 255, 255, 255 });
	TextSolakDuo.Create(ArialFont, 16, "Solak (Duo Mode)", { 255, 255, 255, 255 });
	TextSolakGroup.Create(ArialFont, 16, "Solak (Group Mode)", { 255, 255, 255, 255 });
	TextTelos.Create(ArialFont, 16, "Telos, the Warden", { 255, 255, 255, 255 });
	TextNoBoss.Create(ArialFont, 16, "None", { 255, 255, 255, 255 });
	
	while (!window.isClosed())
	{


		window.pollEvents();
		window.clear();

		HeaderImg.draw();
		
		if (ImageStore.GetDamageArea().empty() || DmgCheck.IsAreaLost())
		{
			//TextNoDamageArea.display(20, 20);
			NoDmgImg.draw();
		}
		else
		{
			//Reset String length to minimum value
			//DamageStringLength = 1;
			DmgImg.draw();
			//TextFoundDamageArea.display(20, 20);
			//DamageString = std::to_string(Damage);

			//Formatting with commas for readability
			/*
			DamageStringLength = DamageString.length() -3;
			while (DamageStringLength > 0)
			{
				DamageString.insert(DamageStringLength, ",");
				DamageStringLength -= 3;
			}
			*/
			

			//TextCurrentOverallDamage.display(20, 60, DamageString);
			//cout << DamageString;
		}
		
		if (ImageStore.GetChatArea().empty())
		{
			NoChatImg.draw();
			//TextNoChatArea.display(20, 80);
		}
		else
		{
			ChatImg.draw();
			//TextFoundChatArea.display(20, 80);
		}
		
		TextCurrentBoss.display(250, 101);
		
		//If statement to determine which boss label to currently display
		if (SolakActive)
		{
			SolakImg.draw();
			TextSolakDuo.display(350, 101);
		}
		else if (SolakGroupActive)
		{
			SolakImg.draw();
			TextSolakGroup.display(350, 101);
		}
		else if (TelosActive)
		{
			TelosImg.draw();
			TextTelos.display(350, 101);
		}
		else
		{
			TextNoBoss.display(350, 101);
		}
		
		

		

		//StopWatch.ReportTime();

		Screenshot = Screener.GetScreen(); //Grab a screenshot of the desktop
		
		
		if (ImageStore.GetDamageArea().empty() || DmgCheck.IsAreaLost()) //If there's no damage area recorded or we have since lost it
		{
			//cout << "There was no damage area";
			//WindowText TextTest("Images/Fonts/arial.ttf", 30, "Damage Area not found", { 255, 0, 0, 255 });
			
			if (TemplateMatch.GetMatch(Screenshot, ImageStore.GetDamageTag(), 0.7f)) //Look for the damage area
			{
				
				//cout << "Then we found the damage area";
				//If we found the damage area, record it to the ImageStore
				DamageAreaStatus = "Damage area located";
				DmgCheck.SetAreaLost(false);
				
				Rect DamageAreaRect = Rect(TemplateMatch.GetPoint().x, TemplateMatch.GetPoint().y + 23, 100, 10);
				
				ImageStore.SetDamageArea(DamageAreaRect); //Record the area where the damage is located so that other functions can use it
				
			}
			
		}

		
		
		if (ImageStore.GetChatArea().empty()) //If there's no chat area recorded
		{
			if (TemplateMatch.GetMatch(Screenshot, ImageStore.GetChatTag(), 0.80f)) //Look for the chat area
			{
				//cout << "We found the chat Area! /n";
				Rect ChatAreaRect = Rect(TemplateMatch.GetPoint().x, TemplateMatch.GetPoint().y - 35, 300, 52);
				ImageStore.SetChatArea(ChatAreaRect); //Record the chat area's location
			}
		}
		
		

		//key = waitKey(1000 / fps);
		if (!ImageStore.GetDamageArea().empty())
		{
			DamageScreenshot = Screenshot(ImageStore.GetDamageArea()); //Crop out the damage area from the screenshot
			//imshow("Dmg", DamageScreenshot);
			Damage = DmgCheck.GetDamage(DamageScreenshot);
		}

		if (!ImageStore.GetChatArea().empty())
		{
			ChatScreenshot = Screenshot(ImageStore.GetChatArea()); //Crop out the chat area from the screenshot
			//imshow("Dmg", ChatScreenshot);

		}

		if (!BossActive)//If no boss is currently active
		{

			if (!BossActiveCheck(Screenshot))
			{
				//cout << "No boss detected exitting early";
				//continue;
			}
			//If we've detected a boss interface, set the starting damage
			BossStartingDamage = Damage;

		}

		//cout << "Oh shit we found a boss and we doin shit now /n";
		if (SolakActive || SolakGroupActive)
		{
			//If the fight hasn't actually started, make sure the player isn't starting a different instance
			if(!Solak.GetFightStarted())
			{
				fillerBool = BossActiveCheck(Screenshot);
			}

			if (!ImageStore.GetChatArea().empty() && !ImageStore.GetDamageArea().empty())
			{
				Solak.Update(Screenshot, Damage, ChatScreenshot);
			}

			if (Solak.GetFightEnded())
			{
				Solak.SaveFight();
				Solak.Reset();
				//SolakActive = false;
				//SolakGroupActive = false;
				//BossActive = false;
			}
		}

		if (TelosActive)
		{
			if (!Telos.GetFightStarted())
			{
				fillerBool = BossActiveCheck(Screenshot);
			}

			if (!ImageStore.GetChatArea().empty() && !ImageStore.GetDamageArea().empty())
			{
				Telos.Update(Screenshot, Damage, ChatScreenshot);
			}

			if (Telos.GetFightEnded())
			{
				Telos.SaveFight();
				Telos.Reset();

			}
		}
		
		
		
	

		
		//DamageLastFrame = Damage;



		//window.clear();

		//Screenshot.release();
		//DamageScreenshot.release();
		//ChatScreenshot.release();


		//key = waitKey(1000/fps);

		
		
		
	}
	
	//_CrtDumpMemoryLeaks();

	return 0;
}


