#include "Timer.h"


Timer::Timer()
{

}

Timer::~Timer()
{
}

void Timer::Start()
{
	m_StartTime = steady_clock::now();
}

void Timer::ReportTime()
{
	m_EndTime = steady_clock::now();

	m_TimeSpan = double (duration_cast <seconds> (m_EndTime - m_StartTime).count());

	//cout << m_TimeSpan << endl;
}

double Timer::GetTime()
{
	m_TimeSpan = double(duration_cast <seconds> (m_EndTime - m_StartTime).count());
	return m_TimeSpan;
}
