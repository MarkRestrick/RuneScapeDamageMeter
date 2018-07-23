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


const int SCREEN_WIDTH = 300;
const int SCREEN_HEIGHT = 300;


SDL_Window* window = NULL;
//SDL_Surface* screen = NULL;

string WindowName = "RuneScape Damage Meter (Solak Prototype)";


using namespace cv;
using namespace std;

const int fps = 40;

bool BossActive = false;
bool SolakActive = false;

ImageSetup ImageStore;
TemplateMatcher TemplateMatch;
SolakModule Solak;

bool BossActiveCheck(Mat1b Screenshot)
{
	if (TemplateMatch.GetMatch(Screenshot, ImageStore.GetSolakTagA(), 0.9f))
	{
		BossActive = true;
		SolakActive = true;
		cout << "We're gonna fight Solak! \n";
		Solak.Reset();
		Solak.SetDuoActive(false);
		return true;
	}
	if (TemplateMatch.GetMatch(Screenshot, ImageStore.GetSolakTagB(), 0.9f))
	{
		BossActive = true;
		SolakActive = true;
		cout << "We're gonna fight Solak! \n";
		Solak.Reset();
		Solak.SetDuoActive(true);
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

	Window window(WindowName, 800, 700);


	ScreenCapture Screener;

	DamageCheck DmgCheck;
	unsigned int BossStartingDamage;
	unsigned int Damage;
	unsigned int DamageLastFrame;
	string DamageString = "0";
	string ArialFont = "Images/Fonts/arial.ttf";

	Mat Screenshot;
	Mat1b ScreenshotGray;
	Mat1b DamageScreenshot;
	Mat1b ChatScreenshot;

	int key = 0;

	//Window Strings
	string DamageAreaStatus = "Damage Area not found";

	ImageStore.GeneralSetup();

	//WindowRect TestImage(120, 120, 300, 300, "Images/BossImages/Solak_A.png");
	//WindowRect WindowRecl(120, 120, 400, 400, "Images/BossImages/Solak_B.png");

	WindowText TextNoDamageArea;
	WindowText TextFoundDamageArea;
	WindowText TextCurrentOverallDamage;
	WindowText TextNoChatArea;
	WindowText TextFoundChatArea;
	WindowText TextCurrentBoss;

	TextNoDamageArea.Create(ArialFont, 30, "Could not find Damage Area", { 255, 0, 0, 255 });
	TextFoundDamageArea.Create(ArialFont, 30, "Found Damage Area", { 0, 255, 0, 255 });
	TextCurrentOverallDamage.Create(ArialFont, 30, DamageString, { 0, 255, 0, 255 });
	TextNoChatArea.Create(ArialFont, 30, "Could not find Chat Area", { 255, 0, 0, 255 });
	TextFoundChatArea.Create(ArialFont, 30, "Found Chat Area", { 0, 255, 0, 255 });
	TextCurrentBoss.Create(ArialFont, 30, "Current Boss: ", { 0, 255, 0, 255 });
	
	while (!window.isClosed())
	{

		//TestImage.draw();
		if (ImageStore.GetDamageArea().empty())
		{
			TextNoDamageArea.display(20, 20);
		}
		else
		{
			TextFoundDamageArea.display(20, 20);
			DamageString = std::to_string(Damage);
			TextCurrentOverallDamage.display(20, 50, DamageString);
			//cout << DamageString;
		}

		if (ImageStore.GetChatArea().empty())
		{
			TextNoChatArea.display(20, 80);
		}
		else
		{
			TextFoundChatArea.display(20, 80);
		}
		TextCurrentBoss.display(20, 110);

		window.pollEvents();
		window.clear();

		
		Screenshot = Screener.GetScreen(); //Grab a screenshot of the desktop

		if (ImageStore.GetDamageArea().empty()) //If there's no damage area recorded
		{
			//cout << "There was no damage area";
			//WindowText TextTest("Images/Fonts/arial.ttf", 30, "Damage Area not found", { 255, 0, 0, 255 });
			if (TemplateMatch.GetMatch(Screenshot, ImageStore.GetDamageTag(), 0.7f)) //Look for the damage area
			{
				//cout << "Then we found the damage area";
				//If we found the damage area, record it to the ImageStore
				DamageAreaStatus = "Damage area located";
				Rect DamageAreaRect = Rect(TemplateMatch.GetPoint().x, TemplateMatch.GetPoint().y + 23, 100, 10);

				ImageStore.SetDamageArea(DamageAreaRect); //Record the area where the damage is located so that other functions can use it
			}
		}

		if (ImageStore.GetChatArea().empty()) //If there's no chat area recorded
		{
			if (TemplateMatch.GetMatch(Screenshot, ImageStore.GetChatTag(), 0.80f)) //Look for the chat area
			{
				//cout << "We found the chat Area! /n";
				Rect ChatAreaRect = Rect(TemplateMatch.GetPoint().x, TemplateMatch.GetPoint().y - 23, 300, 40);
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
				continue;
			}
			//If we've detected a boss interface, set the starting damage
			BossStartingDamage = Damage;

		}

		//cout << "Oh shit we found a boss and we doin shit now /n";
		if (SolakActive)
		{

			if (!ImageStore.GetChatArea().empty() && !ImageStore.GetDamageArea().empty())
			{
				Solak.Update(Screenshot, Damage, ChatScreenshot);
			}

			if (Solak.GetFightEnded())
			{
				//SolakActive = false;
				//BossActive = false;
			}
		}


		
		
		
		if (!ImageStore.GetDamageArea().empty())
		{
			//imshow("Desktop", DamageScreenshot);
		}
		


		DamageLastFrame = Damage;



		//window.clear();




		//key = waitKey(1000/fps);
		

		
		
	}
	
	return 0;
}


