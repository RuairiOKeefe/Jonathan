#include "stdafx.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdexcept>
#include "SFMLSoundProvider.h"
#include "ServiceLocator.h"
#include "SplashScreen.h"
#include "MainMenu.h"
#include "GameObject.h"
#include "Game.h"

using namespace sf;

enum State
{
	Splash,
	Menu,
	Game,
	Pause
};

Vector2i defaultRes = Vector2i(1920, 1080); //MaybeDefine
Vector2i resolution;
SFMLSoundProvider soundProvider;

State state = Splash;
SplashScreen splashScreen;
MainMenu mainMenu;
class Game game;


void Load()
{
	mainMenu.Load((float)resolution.x, (float)resolution.y);
}

void MenuHandler(RenderWindow& window)
{
	mainMenu.Render(window);

	switch (mainMenu.GetMenuResponse(window))
	{
	case MainMenu::Start:
		state = Game;
		game.Load((float)resolution.x / 2.0f, (float)resolution.y / 2.0f);
		break;
	case MainMenu::Options:
		mainMenu.options = true;
		break;
	case MainMenu::Exit:
		window.close();
		break;
	case MainMenu::Res1:
		window.setSize(sf::Vector2u(1920, 1080));
		window.setView(sf::View(sf::FloatRect(0, 0, defaultRes.x, defaultRes.y)));
		break;
	case MainMenu::Res2:
		window.setSize(sf::Vector2u(1600, 900));
		window.setView(sf::View(sf::FloatRect(0, 0, defaultRes.x, defaultRes.y)));
		break;
	case MainMenu::Res3:
		window.setSize(sf::Vector2u(1280, 720));
		window.setView(sf::View(sf::FloatRect(0, 0, defaultRes.x, defaultRes.y)));
		break;
	case MainMenu::Fullscreen:
		window.create(sf::VideoMode(window.getSize().x, window.getSize().y), "Superluminal", sf::Style::Fullscreen);
		window.setView(sf::View(sf::FloatRect(0, 0, defaultRes.x, defaultRes.y)));
		break;
	case MainMenu::Windowed:
		window.create(sf::VideoMode(window.getSize().x, window.getSize().y), "Superluminal", sf::Style::Default);
		window.setView(sf::View(sf::FloatRect(0, 0, defaultRes.x, defaultRes.y)));
		break;
	case MainMenu::Back:
		mainMenu.options = false;
		break;
	default:
		break;
	};
}

void Update()
{

}

void Render(RenderWindow &window)
{

}

int main()
{
	resolution = defaultRes;
	RenderWindow window(VideoMode(resolution.x, resolution.y), "Superluminal");
	ServiceLocator::RegisterServiceLocator(&soundProvider);
	try
	{
		Load();
	}
	catch (const std::exception &)
	{
		std::cerr << "Load error" << std::endl;
		return 1;
	}
	while (window.isOpen())
	{
		window.clear(Color::Color(48, 40, 100, 255));

		switch (state)
		{
		case Splash:
			splashScreen.Show(window, (float)resolution.x, (float)resolution.y);
			state = Menu;
			break;
		case Menu:
			MenuHandler(window);
			break;
		case Game:
			Event event;
			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed)
				{
					window.close();
				}
			}
			if (!game.Update((float)resolution.x, (float)resolution.y, soundProvider))
			{
				game.Reset();
				state = Menu;
			}
			game.Render(window);
			break;
		case Pause:
			break;
		}
		Update();
		Render(window);
		window.display();
	}

	return 0;
}