#include "TemplateMatcher.h"

TemplateMatcher::TemplateMatcher()
{
}

TemplateMatcher::~TemplateMatcher()
{
}

bool TemplateMatcher::GetMatch(Mat1b Source, Mat1b Template, float Thresh)
{
	
	matchTemplate(Source, Template, m_MatchResult, TM_CCOEFF_NORMED);
	
	
	minMaxLoc(m_MatchResult, NULL, NULL, NULL, &m_MatchPoint);

	if (m_MatchResult(m_MatchPoint) > Thresh)
	{
		//m_DamageArea = Rect(m_MatchPoint.x - 5, m_MatchPoint.y, 100, 50);

		//cout << "We matched \n";
		//Draw the red rectangle
		//rectangle(Source, Rect(m_MatchPoint, Template.size()), Scalar(0, 0, 255), 2);
		//imshow("Matched Location", Source(m_DamageArea));
		return true;
	}
	
	
	return false;
	
}


