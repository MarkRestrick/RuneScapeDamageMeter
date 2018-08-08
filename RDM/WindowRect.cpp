#include "WindowRect.h"
#include <SDL_image.h>
#include <iostream>

WindowRect::WindowRect(int w, int h, int x, int y, int r, int g, int b, int a)
{
	
	m_Width = w;
	m_Height = h;
	m_x = x;
	m_y = y;
	m_r = r;
	m_g = g;
	m_b = b;
	m_a = a;
	
}

WindowRect::WindowRect(int w, int h, int x, int y, const std::string & image_path)
{
	
	m_Width = w;
	m_Height = h;
	m_x = x;
	m_y = y;

	auto surface = IMG_Load(image_path.c_str());
	if (!surface)
	{
		std::cout << "Failed to create surface \n";
	}
	
	m_Texture = SDL_CreateTextureFromSurface(Window::renderer, surface);
	if (!m_Texture)
	{
		std::cout << "Failed to create texture \n";
	}

	SDL_FreeSurface(surface);
	
}

WindowRect::WindowRect()
{
}

WindowRect::~WindowRect()
{
	SDL_DestroyTexture(m_Texture);
}

void WindowRect::draw() const
{
	
	SDL_Rect rect = { m_x, m_y, m_Width, m_Height };

	if (m_Texture)
	{
		SDL_RenderCopy(Window::renderer, m_Texture, nullptr, &rect);
	}
	else
	{
		SDL_SetRenderDrawColor(Window::renderer, m_r, m_g, m_b, m_a);
		SDL_RenderFillRect(Window::renderer, &rect);
	}
	


	
	
}

void WindowRect::initialise(int w, int h, int x, int y, const std::string & image_path)
{
	m_Width = w;
	m_Height = h;
	m_x = x;
	m_y = y;

	auto surface = IMG_Load(image_path.c_str());
	if (!surface)
	{
		std::cout << "Failed to create surface \n";
	}

	m_Texture = SDL_CreateTextureFromSurface(Window::renderer, surface);
	if (!m_Texture)
	{
		std::cout << "Failed to create texture \n";
	}

	SDL_FreeSurface(surface);
}


