#pragma once
#include <SDL_ttf.h>
#include <SDL.h>
#include <string>
#include <iostream>

class WindowText {
public:
	WindowText();

	void display(int x, int y);
	void display(int x, int y, std::string &new_text);

	void Create(std::string font_path, int font_size, std::string message_text, const SDL_Color &color);

	bool GetTexFail() { return m_TexFail; };

	static SDL_Texture *loadFont(std::string font_path, int font_size, std::string message_text, const SDL_Color &color);

private:

	std::string m_FontPath;
	int m_FontSize;
	SDL_Color m_Color;

	bool m_TexFail = false;
	SDL_Texture *m_TextTexture = nullptr;
	SDL_Rect m_TextRect;
};