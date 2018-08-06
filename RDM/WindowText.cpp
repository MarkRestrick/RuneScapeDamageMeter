#include "WindowText.h"
#include "Window.h"

WindowText::WindowText()
{

}

WindowText::~WindowText()
{
	SDL_DestroyTexture(m_TextTexture);
	TTF_CloseFont(font);
	
}

void WindowText::display(int x, int y)
{
	m_TextRect.x = x;
	m_TextRect.y = y;

	SDL_RenderCopy(Window::renderer, m_TextTexture, NULL, &m_TextRect);

}

void WindowText::display(int x, int y, std::string & new_text)
{
	m_TextTexture = loadFont(m_FontPath, m_FontSize, new_text, m_Color);
	SDL_QueryTexture(m_TextTexture, NULL, NULL, &m_TextRect.w, &m_TextRect.h);
	m_TextRect.x = x;
	m_TextRect.y = y;

	SDL_RenderCopy(Window::renderer, m_TextTexture, nullptr, &m_TextRect);

}

void WindowText::Create(std::string font_path, int font_size, std::string message_text, const SDL_Color & color)
{
	m_FontPath = font_path;
	m_FontSize = font_size;
	m_Color = color;

	m_TextTexture = loadFont(font_path, font_size, message_text, color);
	if (m_TextTexture == NULL)
	{
		m_TexFail = true;
	}
	else
	{
		m_TexFail = false;
	}
	SDL_QueryTexture(m_TextTexture, nullptr, nullptr, &m_TextRect.w, &m_TextRect.h);
}

SDL_Texture *WindowText::loadFont(std::string font_path, int font_size, std::string message_text, const SDL_Color & color)
{
	font = TTF_OpenFont(font_path.c_str(), font_size);
	if (!font)
	{
		std::cout << "failed to load font \n";
	}

	if (!m_TextSurface)
	{
		SDL_FreeSurface(m_TextSurface);
	}

	m_TextSurface = TTF_RenderText_Solid(font, message_text.c_str(), color);

	if (!m_TextSurface)
	{
		std::cout << "Failed to create text surface";
	}

	m_TextTexture = SDL_CreateTextureFromSurface(Window::renderer, m_TextSurface);
	
	if (!m_TextTexture)
	{
		std::cout << "Failed to create text texture";
		
	}

	SDL_FreeSurface(m_TextSurface);
	
	
	return m_TextTexture;
}
