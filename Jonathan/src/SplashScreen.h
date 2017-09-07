#pragma once
#include <SFML/Graphics.hpp>

class SplashScreen
{
public:
	sf::Texture texture;
	sf::Sprite sprite;

	SplashScreen();
	~SplashScreen();

	void Show(sf::RenderWindow& window, float xRes, float yRes);
private:

};