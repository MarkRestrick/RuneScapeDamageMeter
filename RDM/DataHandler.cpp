#include "DataHandler.h"


DataHandler::DataHandler()
{


}

DataHandler::~DataHandler()
{
}

void DataHandler::AddLine(string fileName, string stringToAdd)
{
	outFile.open(fileName, ofstream::app);
	//Check for error
	if (outFile.fail())
	{
		cerr << "Error Opening File /n";
	}

	outFile << stringToAdd << endl;

	outFile.close();


}

void DataHandler::ReplaceString(string fileName, string stringToReplace)
{
	outFile.open(fileName);
	//Check for error
	if (outFile.fail())
	{
		cerr << "Error Opening File /n";
	}

	outFile << stringToReplace << endl;

	outFile.close();
}

string DataHandler::GrabFile(string fileName)
{
	//cout << "We're in grab file baby!" << endl;
	inFile.open(fileName);
	//cout << "We opened " << fileName << endl;

	if (inFile.fail())
	{
		cerr << "Error opening file!";
	}


	string itemToReturn;

	while (!inFile.eof())
	{
		inFile >> itemToReturn;
		//cout << "It contained " << itemToReturn << endl;
	}

	inFile.close();

	return itemToReturn;

}

void DataHandler::Start()
{
	/*
	inFile.open("Data/SolakDuo.txt");

	//Check for error
	if (inFile.fail())
	{
		cerr << "Error Opening File /n";
	}

	string item;
	int counter = 0;

	//Read a file until the end
	while (!inFile.eof())
	{
		inFile >> item;
		counter++;
	}

	//cout << counter << " items found! " << endl;

	inFile.close();
	*/
}
