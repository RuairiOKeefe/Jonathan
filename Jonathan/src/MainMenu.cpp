#include "MainMenu.h"

MainMenu::MainMenu()
{
}

MainMenu::~MainMenu()
{
}

void MainMenu::Load(float xRes, float yRes)
{
	if (!menuTexture.loadFromFile("res/img/MenuScreen.png")) //Uses Ebrima Bold
	{
		throw std::invalid_argument("Error Loading Texture");
	}
	menuSprite.setTexture(menuTexture);
	//menuSprite.setScale(sf::Vector2f(xRes / 1920, yRes / 1080));

	Button startButton;
	if (!startTexture.loadFromFile("res/img/StartButton.png"))
	{
		throw std::invalid_argument("Error Loading Texture");
	}
	startButton.sprite.setTexture(startTexture);
	startButton.sprite.setOrigin(sf::Vector2f(startTexture.getSize().x / 2, startTexture.getSize().y / 2));
	//startButton.sprite.setScale(sf::Vector2f(xRes / 1920, yRes / 1080));
	startButton.sprite.setPosition(sf::Vector2f(xRes / 2, yRes / 2));
	startButton.action = Start;

	Button optionsButton;
	if (!optionsTexture.loadFromFile("res/img/OptionsButton.png"))
	{
		throw std::invalid_argument("Error Loading Texture");
	}
	optionsButton.sprite.setTexture(optionsTexture);
	optionsButton.sprite.setOrigin(sf::Vector2f(optionsTexture.getSize().x / 2, optionsTexture.getSize().y / 2));
	//optionsButton.sprite.setScale(sf::Vector2f(xRes / 1920, yRes / 1080));
	optionsButton.sprite.setPosition(sf::Vector2f(xRes / 2, (yRes / 2) + optionsTexture.getSize().y * 1.5f));
	optionsButton.action = Options;

	Button exitButton;
	if (!exitTexture.loadFromFile("res/img/ExitButton.png"))
	{
		throw std::invalid_argument("Error Loading Texture");
	}
	exitButton.sprite.setTexture(exitTexture);
	exitButton.sprite.setOrigin(sf::Vector2f(exitTexture.getSize().x / 2, exitTexture.getSize().y / 2));
	//exitButton.sprite.setScale(sf::Vector2f(xRes / 1920, yRes / 1080));
	exitButton.sprite.setPosition(sf::Vector2f(xRes / 2, (yRes / 2) + exitTexture.getSize().y * 3.0f));
	exitButton.action = Exit;

	buttons.push_back(startButton);
	buttons.push_back(optionsButton);
	buttons.push_back(exitButton);
}

MainMenu::Selection MainMenu::GetMenuResponse(sf::RenderWindow & window)
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::MouseButtonPressed)
		{
			return HandleClick(event.mouseButton.x, event.mouseButton.y);
		}
		if (event.type == sf::Event::Closed)
		{
			return Exit;
		}
	}
	return Null;
}

void MainMenu::Render(sf::RenderWindow & window)
{
	window.draw(menuSprite);
	for each (Button btn in buttons)
	{
		window.draw(btn.sprite);
	}
}

MainMenu::Selection MainMenu::HandleClick(int x, int y)
{
	std::list<Button>::iterator it;

	for (it = buttons.begin(); it != buttons.end(); it++)
	{
		sf::Sprite sprite = (*it).sprite;

		if (sprite.getGlobalBounds().contains(sf::Vector2f(x, y)))
		{
			return (*it).action;
		}
	}
	return Null;
}
