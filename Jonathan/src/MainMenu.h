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
		Exit,
		Res1,
		Res2,
		Res3,
		Fullscreen,
		Windowed,
		Back
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

	bool options = false;
	int hoveredItem = 1;
	sf::Clock scrollClock;
	float scrollTimer = 0.1;
	sf::Clock buttonClock;
	float buttonTimer = 0.5;


	void Load(float xRes, float yRes);
	Selection GetMenuResponse(sf::RenderWindow &window, float xRes, float yRes);
	void Render(sf::RenderWindow &window);
private:
	sf::Texture menuTexture;
	sf::Texture startTexture;
	sf::Texture optionsTexture;
	sf::Texture exitTexture;
	sf::Sprite menuSprite;

	sf::Texture optionsMenuTexture;
	sf::Texture res1Texture;
	sf::Texture res2Texture;
	sf::Texture res3Texture;
	sf::Texture fullscreenTexture;
	sf::Texture windowedTexture;
	sf::Texture backTexture;
	sf::Sprite optionsMenuSprite;

	sf::Texture selectorTexture;
	sf::Sprite selectorSprite;

	Selection HandleClick(int x, int y);
	std::list<Button> mainButtons;
	std::list<Button> optionsButtons;
};
