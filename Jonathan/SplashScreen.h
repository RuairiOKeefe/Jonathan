#pragma once
#include <SFML/Graphics.hpp>

class SplashScreen
{
public:
	sf::Texture texture;
	sf::Sprite sprite;

	void Show(sf::RenderWindow& window, float xRes, float yRes);
private:

};