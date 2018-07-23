#include "DamageCheck.h"
#include "ImageSetup.h"




DamageCheck::DamageCheck()
{
	//Grab all the images needed for the damage check functionality
	m_DmgImgStore.DmgSetup();
}

DamageCheck::~DamageCheck()
{
}

unsigned int DamageCheck::GetDamage(Mat1b Source)
{

	m_DamageFramesCounter++;

	//Going to loop over every character in the image until we reach the end to establish how many characters there are
	// If we get to the number 14 something has gone wrong as we have surpassed 10 Billion damage which shouldn't be possible (2.5B limit)
	for (int a = 0; a < 14; a++)
	{

		//cout << m_DmgRect.x + (a*m_DmgRect.width);

		m_DmgCrops[a] = (Source(Rect(m_DmgRect.x + (a*m_DmgRect.width) + a, m_DmgRect.y, m_DmgRect.width, m_DmgRect.height)));

		//imshow("Being Analysed", m_DmgCrops[a]);
		//waitKey(1);

		if (m_DmgTemplate.GetMatch(m_DmgCrops[a], m_DmgImgStore.GetDamageNull(), 0.8f))
		{

			//cout << "We matched on number " << a;
			m_DamageValsCount = a;
			break;
		}

	}


	switch (m_DamageValsCount)
	{
	case 11:
		HundredMillions(Source);
		break;
	case 1:
		Units(Source);
		break;
	case 2:
		Tens(Source);
		break;
	case 3:
		Hundreds(Source);
		break;
	case 5:
		Thousands(Source);
		break;
	case 6:
		TenThousands(Source);
		break;
	case 7:
		HundredThousands(Source);
		break;
	case 8:
		Millions(Source);
		break;
	case 9:
		TenMillions(Source);
		break;
	case 10:
		HundredMillions(Source);
		break;
	default:
		cout << "Ruh roh";
	}

	return m_TotalDamage;
}


void DamageCheck::Units(Mat1b Source)
{
	m_TotalDamage = 0;

	m_DmgCrops[0] = Source(Rect(m_DmgRect.x + (0 * m_DmgRect.width) + 0, m_DmgRect.y, m_DmgRect.width, m_DmgRect.height));

	
	//imshow("Number 1", m_DmgCrops[0]);
	


	m_TotalDamage += 1 * IdentifyNumber(m_DmgCrops[0]);


	cout << "Total damage is: " << m_TotalDamage << "\n";
}

void DamageCheck::Tens(Mat1b Source)
{
	m_TotalDamage = 0;

	m_DmgCrops[0] = Source(Rect(m_DmgRect.x + (0 * m_DmgRect.width) + 0, m_DmgRect.y, m_DmgRect.width, m_DmgRect.height));
	m_DmgCrops[1] = Source(Rect(m_DmgRect.x + (1 * m_DmgRect.width) + 1, m_DmgRect.y, m_DmgRect.width, m_DmgRect.height));

	/*
	imshow("Number 1", m_DmgCrops[0]);
	imshow("Number 2", m_DmgCrops[1]);

	*/


	m_TotalDamage += 10 * IdentifyNumber(m_DmgCrops[0]);
	m_TotalDamage += 1 * IdentifyNumber(m_DmgCrops[1]);

	if (m_DamageFramesCounter > 5)
	{
		cout << "Total damage is: " << m_TotalDamage << "\n";
	}
	
}

void DamageCheck::Hundreds(Mat1b Source)
{
	m_TotalDamage = 0;

	m_DmgCrops[0] = Source(Rect(m_DmgRect.x + (0 * m_DmgRect.width) + 0, m_DmgRect.y, m_DmgRect.width, m_DmgRect.height));
	m_DmgCrops[1] = Source(Rect(m_DmgRect.x + (1 * m_DmgRect.width) + 1, m_DmgRect.y, m_DmgRect.width, m_DmgRect.height));
	m_DmgCrops[2] = Source(Rect(m_DmgRect.x + (2 * m_DmgRect.width) + 2, m_DmgRect.y, m_DmgRect.width, m_DmgRect.height));


	/*
	imshow("Number 1", m_DmgCrops[0]);
	imshow("Number 2", m_DmgCrops[1]);
	imshow("Number 3", m_DmgCrops[2]);

	*/


	m_TotalDamage += 100 * IdentifyNumber(m_DmgCrops[0]);
	m_TotalDamage += 10 * IdentifyNumber(m_DmgCrops[1]);
	m_TotalDamage += 1* IdentifyNumber(m_DmgCrops[2]);


	cout << "Total damage is: " << m_TotalDamage << "\n";
}

void DamageCheck::Thousands(Mat1b Source)
{
	m_TotalDamage = 0;

	m_DmgCrops[0] = Source(Rect(m_DmgRect.x + (0 * m_DmgRect.width) + 0, m_DmgRect.y, m_DmgRect.width, m_DmgRect.height));
	m_DmgCrops[1] = Source(Rect(m_DmgRect.x + (1 * m_DmgRect.width) + 4, m_DmgRect.y, m_DmgRect.width, m_DmgRect.height));
	m_DmgCrops[2] = Source(Rect(m_DmgRect.x + (2 * m_DmgRect.width) + 5, m_DmgRect.y, m_DmgRect.width, m_DmgRect.height));

	m_DmgCrops[3] = Source(Rect(m_DmgRect.x + (3 * m_DmgRect.width) + 6, m_DmgRect.y, m_DmgRect.width, m_DmgRect.height));


	/*
	imshow("Number 1", m_DmgCrops[0]);
	imshow("Number 2", m_DmgCrops[1]);
	imshow("Number 3", m_DmgCrops[2]);

	imshow("Number 4", m_DmgCrops[3]);

	*/


	m_TotalDamage += 1000 * IdentifyNumber(m_DmgCrops[0]);
	m_TotalDamage += 100 * IdentifyNumber(m_DmgCrops[1]);
	m_TotalDamage += 10 * IdentifyNumber(m_DmgCrops[2]);
	m_TotalDamage += 1 * IdentifyNumber(m_DmgCrops[3]);


	cout << "Total damage is: " << m_TotalDamage << "\n";
}

void DamageCheck::TenThousands(Mat1b Source)
{
	m_TotalDamage = 0;

	m_DmgCrops[0] = Source(Rect(m_DmgRect.x + (0 * m_DmgRect.width) + 0, m_DmgRect.y, m_DmgRect.width, m_DmgRect.height));
	m_DmgCrops[1] = Source(Rect(m_DmgRect.x + (1 * m_DmgRect.width) + 1, m_DmgRect.y, m_DmgRect.width, m_DmgRect.height));
	m_DmgCrops[2] = Source(Rect(m_DmgRect.x + (2 * m_DmgRect.width) + 5, m_DmgRect.y, m_DmgRect.width, m_DmgRect.height));

	m_DmgCrops[3] = Source(Rect(m_DmgRect.x + (3 * m_DmgRect.width) + 6, m_DmgRect.y, m_DmgRect.width, m_DmgRect.height));
	m_DmgCrops[4] = Source(Rect(m_DmgRect.x + (4 * m_DmgRect.width) + 7, m_DmgRect.y, m_DmgRect.width, m_DmgRect.height));


	/*
	imshow("Number 1", m_DmgCrops[0]);
	imshow("Number 2", m_DmgCrops[1]);
	imshow("Number 3", m_DmgCrops[2]);

	imshow("Number 4", m_DmgCrops[3]);
	imshow("Number 5", m_DmgCrops[4]);
	*/


	m_TotalDamage += 10000 * IdentifyNumber(m_DmgCrops[0]);
	m_TotalDamage += 1000 * IdentifyNumber(m_DmgCrops[1]);
	m_TotalDamage += 100 * IdentifyNumber(m_DmgCrops[2]);
	m_TotalDamage += 10 * IdentifyNumber(m_DmgCrops[3]);
	m_TotalDamage += 1* IdentifyNumber(m_DmgCrops[4]);


	cout << "Total damage is: " << m_TotalDamage << "\n";
}

void DamageCheck::HundredThousands(Mat1b Source)
{
	m_TotalDamage = 0;

	m_DmgCrops[0] = Source(Rect(m_DmgRect.x + (0 * m_DmgRect.width) + 0, m_DmgRect.y, m_DmgRect.width, m_DmgRect.height));
	m_DmgCrops[1] = Source(Rect(m_DmgRect.x + (1 * m_DmgRect.width) + 1, m_DmgRect.y, m_DmgRect.width, m_DmgRect.height));
	m_DmgCrops[2] = Source(Rect(m_DmgRect.x + (2 * m_DmgRect.width) + 2, m_DmgRect.y, m_DmgRect.width, m_DmgRect.height));

	m_DmgCrops[3] = Source(Rect(m_DmgRect.x + (3 * m_DmgRect.width) + 6, m_DmgRect.y, m_DmgRect.width, m_DmgRect.height));
	m_DmgCrops[4] = Source(Rect(m_DmgRect.x + (4 * m_DmgRect.width) + 7, m_DmgRect.y, m_DmgRect.width, m_DmgRect.height));
	m_DmgCrops[5] = Source(Rect(m_DmgRect.x + (5 * m_DmgRect.width) + 8, m_DmgRect.y, m_DmgRect.width, m_DmgRect.height));



	/*
	imshow("Number 1", m_DmgCrops[0]);
	imshow("Number 2", m_DmgCrops[1]);
	imshow("Number 3", m_DmgCrops[2]);

	imshow("Number 4", m_DmgCrops[3]);
	imshow("Number 5", m_DmgCrops[4]);
	imshow("Number 6", m_DmgCrops[5]);

	*/


	m_TotalDamage += 100000 * IdentifyNumber(m_DmgCrops[0]);
	m_TotalDamage += 10000 * IdentifyNumber(m_DmgCrops[1]);
	m_TotalDamage += 1000 * IdentifyNumber(m_DmgCrops[2]);
	m_TotalDamage += 100 * IdentifyNumber(m_DmgCrops[3]);
	m_TotalDamage += 10 * IdentifyNumber(m_DmgCrops[4]);
	m_TotalDamage += 1 * IdentifyNumber(m_DmgCrops[5]);


	cout << "Total damage is: " << m_TotalDamage << "\n";
}

void DamageCheck::Millions(Mat1b Source)
{
	m_TotalDamage = 0;

	m_DmgCrops[0] = Source(Rect(m_DmgRect.x + (0 * m_DmgRect.width) + 0, m_DmgRect.y, m_DmgRect.width, m_DmgRect.height));
	m_DmgCrops[1] = Source(Rect(m_DmgRect.x + (1 * m_DmgRect.width) + 4, m_DmgRect.y, m_DmgRect.width, m_DmgRect.height));
	m_DmgCrops[2] = Source(Rect(m_DmgRect.x + (2 * m_DmgRect.width) + 5, m_DmgRect.y, m_DmgRect.width, m_DmgRect.height));

	m_DmgCrops[3] = Source(Rect(m_DmgRect.x + (3 * m_DmgRect.width) + 6, m_DmgRect.y, m_DmgRect.width, m_DmgRect.height));
	m_DmgCrops[4] = Source(Rect(m_DmgRect.x + (4 * m_DmgRect.width) + 10, m_DmgRect.y, m_DmgRect.width, m_DmgRect.height));
	m_DmgCrops[5] = Source(Rect(m_DmgRect.x + (5 * m_DmgRect.width) + 11, m_DmgRect.y, m_DmgRect.width, m_DmgRect.height));

	m_DmgCrops[6] = Source(Rect(m_DmgRect.x + (6 * m_DmgRect.width) + 12, m_DmgRect.y, m_DmgRect.width, m_DmgRect.height));


	/*
	imshow("Number 1", m_DmgCrops[0]);
	imshow("Number 2", m_DmgCrops[1]);
	imshow("Number 3", m_DmgCrops[2]);

	imshow("Number 4", m_DmgCrops[3]);
	imshow("Number 5", m_DmgCrops[4]);
	imshow("Number 6", m_DmgCrops[5]);

	imshow("Number 7", m_DmgCrops[6]);
	*/
	


	m_TotalDamage += 1000000 * IdentifyNumber(m_DmgCrops[0]);
	m_TotalDamage += 100000 * IdentifyNumber(m_DmgCrops[1]);
	m_TotalDamage += 10000 * IdentifyNumber(m_DmgCrops[2]);
	m_TotalDamage += 1000 * IdentifyNumber(m_DmgCrops[3]);
	m_TotalDamage += 100 * IdentifyNumber(m_DmgCrops[4]);
	m_TotalDamage += 10 * IdentifyNumber(m_DmgCrops[5]);
	m_TotalDamage += 1 * IdentifyNumber(m_DmgCrops[6]);


	
	if (m_DamageFramesCounter > m_DamageFramesLimit)
	{
		m_DamageFramesCounter = 0;
		cout << "Total damage is: " << m_TotalDamage << "\n";
	}

}

void DamageCheck::TenMillions(Mat1b Source)
{
	m_TotalDamage = 0;

	m_DmgCrops[0] = Source(Rect(m_DmgRect.x + (0 * m_DmgRect.width) + 0, m_DmgRect.y, m_DmgRect.width, m_DmgRect.height));
	m_DmgCrops[1] = Source(Rect(m_DmgRect.x + (1 * m_DmgRect.width) + 1, m_DmgRect.y, m_DmgRect.width, m_DmgRect.height));
	m_DmgCrops[2] = Source(Rect(m_DmgRect.x + (2 * m_DmgRect.width) + 5, m_DmgRect.y, m_DmgRect.width, m_DmgRect.height));

	m_DmgCrops[3] = Source(Rect(m_DmgRect.x + (3 * m_DmgRect.width) + 6, m_DmgRect.y, m_DmgRect.width, m_DmgRect.height));
	m_DmgCrops[4] = Source(Rect(m_DmgRect.x + (4 * m_DmgRect.width) + 7, m_DmgRect.y, m_DmgRect.width, m_DmgRect.height));
	m_DmgCrops[5] = Source(Rect(m_DmgRect.x + (5 * m_DmgRect.width) + 11, m_DmgRect.y, m_DmgRect.width, m_DmgRect.height));

	m_DmgCrops[6] = Source(Rect(m_DmgRect.x + (6 * m_DmgRect.width) + 12, m_DmgRect.y, m_DmgRect.width, m_DmgRect.height));
	m_DmgCrops[7] = Source(Rect(m_DmgRect.x + (7 * m_DmgRect.width) + 13, m_DmgRect.y, m_DmgRect.width, m_DmgRect.height));


	/*
	imshow("Number 1", m_DmgCrops[0]);
	imshow("Number 2", m_DmgCrops[1]);
	imshow("Number 3", m_DmgCrops[2]);

	imshow("Number 4", m_DmgCrops[3]);
	imshow("Number 5", m_DmgCrops[4]);
	imshow("Number 6", m_DmgCrops[5]);

	imshow("Number 7", m_DmgCrops[6]);
	imshow("Number 8", m_DmgCrops[7]);
	imshow("Number 9", m_DmgCrops[8]);
	*/
	

	
	m_TotalDamage += 10000000 * IdentifyNumber(m_DmgCrops[0]);
	m_TotalDamage += 1000000 * IdentifyNumber(m_DmgCrops[1]);
	m_TotalDamage += 100000 * IdentifyNumber(m_DmgCrops[2]);
	m_TotalDamage += 10000 * IdentifyNumber(m_DmgCrops[3]);
	m_TotalDamage += 1000 * IdentifyNumber(m_DmgCrops[4]);
	m_TotalDamage += 100 * IdentifyNumber(m_DmgCrops[5]);
	m_TotalDamage += 10 * IdentifyNumber(m_DmgCrops[6]);
	m_TotalDamage += 1 * IdentifyNumber(m_DmgCrops[7]);
	

	//cout << "Total damage is: " << m_TotalDamage << "\n";
}



void DamageCheck::HundredMillions(Mat1b Source)
{
	m_TotalDamage = 0;

	m_DmgCrops[0] = Source(Rect(m_DmgRect.x + (0 * m_DmgRect.width) + 0, m_DmgRect.y, m_DmgRect.width, m_DmgRect.height));
	m_DmgCrops[1] = Source(Rect(m_DmgRect.x + (1 * m_DmgRect.width) + 1, m_DmgRect.y, m_DmgRect.width, m_DmgRect.height));
	m_DmgCrops[2] = Source(Rect(m_DmgRect.x + (2 * m_DmgRect.width) + 2, m_DmgRect.y, m_DmgRect.width, m_DmgRect.height));

	m_DmgCrops[3] = Source(Rect(m_DmgRect.x + (3 * m_DmgRect.width) + 6, m_DmgRect.y, m_DmgRect.width, m_DmgRect.height));
	m_DmgCrops[4] = Source(Rect(m_DmgRect.x + (4 * m_DmgRect.width) + 7, m_DmgRect.y, m_DmgRect.width, m_DmgRect.height));
	m_DmgCrops[5] = Source(Rect(m_DmgRect.x + (5 * m_DmgRect.width) + 8, m_DmgRect.y, m_DmgRect.width, m_DmgRect.height));

	m_DmgCrops[6] = Source(Rect(m_DmgRect.x + (6 * m_DmgRect.width) + 12, m_DmgRect.y, m_DmgRect.width, m_DmgRect.height));
	m_DmgCrops[7] = Source(Rect(m_DmgRect.x + (7 * m_DmgRect.width) + 13, m_DmgRect.y, m_DmgRect.width, m_DmgRect.height));
	m_DmgCrops[8] = Source(Rect(m_DmgRect.x + (8 * m_DmgRect.width) + 14, m_DmgRect.y, m_DmgRect.width, m_DmgRect.height));

	/*
	imshow("Number 1", m_DmgCrops[0]);
	imshow("Number 2", m_DmgCrops[1]);
	imshow("Number 3", m_DmgCrops[2]);

	imshow("Number 4", m_DmgCrops[3]);
	imshow("Number 5", m_DmgCrops[4]);
	imshow("Number 6", m_DmgCrops[5]);

	imshow("Number 7", m_DmgCrops[6]);
	imshow("Number 8", m_DmgCrops[7]);
	imshow("Number 9", m_DmgCrops[8]);
	*/
	

	m_TotalDamage += 100000000 * IdentifyNumber(m_DmgCrops[0]);
	m_TotalDamage += 10000000 * IdentifyNumber(m_DmgCrops[1]);
	m_TotalDamage += 1000000 * IdentifyNumber(m_DmgCrops[2]);
	m_TotalDamage += 100000 * IdentifyNumber(m_DmgCrops[3]);
	m_TotalDamage += 10000 * IdentifyNumber(m_DmgCrops[4]);
	m_TotalDamage += 1000 * IdentifyNumber(m_DmgCrops[5]);
	m_TotalDamage += 100 * IdentifyNumber(m_DmgCrops[6]);
	m_TotalDamage += 10 * IdentifyNumber(m_DmgCrops[7]);
	m_TotalDamage += 1 * IdentifyNumber(m_DmgCrops[8]);

	cout << "Total damage is: " << m_TotalDamage << "\n";
}

int DamageCheck::IdentifyNumber(Mat1b NumberImg)
{

	int IdentifiedNumber = 22;

	for (int b = 0; b <= 9; b++)
	{
		if (m_DmgTemplate.GetMatch(NumberImg, m_DmgImgStore.GetDamage(b), 0.95f))
		{
			IdentifiedNumber = b;
			break;
		}
	}

	if(IdentifiedNumber != 22)
	{
		return IdentifiedNumber;
	}
	else
	{
		cout << "Could not match \n";
		return 0;
	}
	

	/*
	switch (IdentifiedNumber)
	{

	}
	*/
	
}
