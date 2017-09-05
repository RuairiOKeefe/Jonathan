#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdexcept>

#include "GameObject.h"

using namespace sf;

enum State
{
	Splash,
	Menu,
	Game,
	Pause,
	Exit
};

Vector2i resolution = Vector2i(1920, 1080);

GameObject gameObject;

void Load()
{
	float xScale = 2;
	gameObject.SetTexture("res/img/ship.png", xScale);
}

void Update()
{
	static sf::Clock clock;
	float dt = clock.restart().asSeconds();
	gameObject.Update(dt);
}

void Render(RenderWindow &window)//Make sure to make dependant on state
{
	window.draw(gameObject.sprite);
}

int main()
{
	RenderWindow window(VideoMode(resolution.x, resolution.y), "ArseBiscuits");

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

		window.clear(Color::Color(48, 40, 100, 255));
		Update();
		Render(window);
		window.display();
	}

	return 0;
}