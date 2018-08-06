#pragma once


#include <vector>
#include <chrono>
#include <iostream>

using namespace std;
using namespace std::chrono;

class Timer {
public:
	Timer();
	~Timer();

	void Start();
	void ReportTime();
	double GetTime();




private:
	
	steady_clock::time_point m_StartTime;
	steady_clock::time_point m_EndTime;
	double m_TimeSpan;

};