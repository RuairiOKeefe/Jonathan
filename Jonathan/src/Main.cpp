#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdexcept>

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

State state = Splash;
SplashScreen splashScreen;
MainMenu mainMenu;
class Game game;


void Load()
{
	mainMenu.Load(resolution.x, resolution.y);
}

void MenuHandler(RenderWindow& window)
{
	mainMenu.Render(window);
	switch(mainMenu.GetMenuResponse(window))
	{
	case MainMenu::Start:
		state = Game;
		game.Load(resolution.x / 2, resolution.y / 2);
		break;
	case MainMenu::Options:

		break;
	case MainMenu::Exit:
		window.close();
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
	RenderWindow window(VideoMode(resolution.x, resolution.y), "ArseBiscuits");//Look into fullscreening
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
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}

		window.clear(Color::Color(48, 40, 100, 255));

		switch (state)
		{
		case Splash:
			splashScreen.Show(window, resolution.x, resolution.y);
			state = Menu;
			break;
		case Menu:
			MenuHandler(window);
			break;
		case Game:
			Event event; //I hate everything this stands for.
			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed)
				{
					window.close();
				}
			}
			game.Update(resolution.x, resolution.y);
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