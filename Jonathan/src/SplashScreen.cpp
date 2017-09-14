#include "stdafx.h"

#include "SplashScreen.h"

SplashScreen::SplashScreen()
{
}

SplashScreen::~SplashScreen()
{
}

void SplashScreen::Show(sf::RenderWindow& window, float xRes, float yRes)
{
	sf::Event event;
	sf::Clock clock;
	float fadeIn = 2;
	float stayTime = 3;
	float fadeOut = 3;
	if (!texture.loadFromFile("res/img/TempSplash.png"))
	{
		throw std::invalid_argument("Error Loading Texture");
	}

	sprite.setTexture(texture);
	sprite.setScale(sf::Vector2f(xRes / texture.getSize().x, yRes / texture.getSize().y));

	while (true)
	{
		float currentTime = clock.getElapsedTime().asSeconds();

		if (currentTime < fadeIn)
		{
			float fade = currentTime * 255 / fadeIn;
			sprite.setColor(sf::Color(fade, fade, fade, 255));
		}
		if (currentTime > fadeIn+stayTime)
		{
			float fade = (fadeIn + stayTime + fadeOut - currentTime) * 255 / fadeOut;
			sprite.setColor(sf::Color(fade, fade, fade, 255));
		}
		if (currentTime > fadeIn + stayTime + fadeOut)
		{
			return;
		}

		window.draw(sprite);
		window.display();

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			if (event.type == sf::Event::EventType::KeyPressed || event.type == sf::Event::EventType::MouseButtonPressed)
			{
				return;
			}
		}
	}
}
