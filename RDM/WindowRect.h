#pragma once


#include "Window.h"
#include <string>

class WindowRect {
public:
	WindowRect(int w, int h, int x, int y, int r, int g, int b, int a);
	WindowRect(int w, int h, int x, int y, const std::string &image_path);
	WindowRect();
	~WindowRect();
	void draw() const;
	void initialise(int w, int h, int x, int y, const std::string &image_path);


private:
	int m_Width, m_Height;
	int m_x, m_y;
	int m_r, m_g, m_b, m_a;
	SDL_Texture *m_Texture = nullptr;
};