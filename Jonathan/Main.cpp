#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdexcept>

#include "GameObject.h"
#include "SplashScreen.h"
#include "Game.h"

using namespace sf;

enum State
{
	Splash,
	Menu,
	Game,
	Pause
};

Vector2i resolution = Vector2i(1920, 1080);

SplashScreen splashScreen;
State state = Splash;
class Game game;

void Load()
{

}

void Update()
{
	
}

void Render(RenderWindow &window)
{

}

int main()
{
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
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}

		switch (state)
		{
		case Splash:
			splashScreen.Show(window, resolution.x, resolution.y);
			state = Game;
			break;
		case Menu:
			break;
		case Game:
			game.Sequence(window);//Determine if we want to do this or use a case statement in update and render
			break;
		case Pause: //This one may not be needed
			break;
		}

		window.clear(Color::Color(48, 40, 100, 255));
		Update();
		Render(window);
		window.display();
	}

	return 0;
}