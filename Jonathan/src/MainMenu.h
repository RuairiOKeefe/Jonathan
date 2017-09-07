#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <list>

class MainMenu
{
public:
	enum Selection
	{
		Null,
		Start,
		Options,
		Exit
	};

	struct Button
	{
	public:
		//sf::Texture texture;
		sf::Sprite sprite;
		Selection action;
	};

	MainMenu();
	~MainMenu();

	void Load(float xRes, float yRes);
	Selection GetMenuResponse(sf::RenderWindow &window);
	void Render(sf::RenderWindow &window);
private:
	sf::Texture menuTexture;
	sf::Texture startTexture;
	sf::Texture optionsTexture;
	sf::Texture exitTexture;
	sf::Sprite menuSprite;

	Selection HandleClick(int x, int y);
	std::list<Button> buttons;
};
