#include "Game.h"

void Game::Load()
{
	float xScale = 2;
	gameObject.SetTexture("res/img/ship.png", xScale);
}

void Game::Update()
{
	static sf::Clock clock;
	float dt = clock.restart().asSeconds();
	gameObject.Update(dt);
}

void Game::Render(sf::RenderWindow &window)
{
	window.draw(gameObject.sprite);
}

void Game::Sequence(sf::RenderWindow &window)
{
	Load();
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();//This should obviously just bring up the pause button when I'm done
		}
		Update();
		window.clear(sf::Color::Color(48, 40, 100, 255));
		Render(window);
		window.display();
	}
}
