#pragma once

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class DataHandler {
public:
	DataHandler();
	~DataHandler();

	void AddLine(string fileName, string stringToAdd);
	void ReplaceString(string fileName, string stringToReplace);

	string GrabFile(string fileName);

	void Start();
	


private:
	ifstream inFile;
	ofstream outFile;
	int m_Width, m_Height;
	int m_x, m_y;
	int m_r, m_g, m_b, m_a;

};