#include "stdafx.h"

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

	Button startButton;
	if (!startTexture.loadFromFile("res/img/StartButton.png"))
	{
		throw std::invalid_argument("Error Loading Texture");
	}
	startButton.sprite.setTexture(startTexture);
	startButton.sprite.setOrigin(sf::Vector2f(startTexture.getSize().x / 2, startTexture.getSize().y / 2));
	startButton.sprite.setPosition(sf::Vector2f(xRes / 2, yRes / 2));
	startButton.action = Start;

	Button optionsButton;
	if (!optionsTexture.loadFromFile("res/img/OptionsButton.png"))
	{
		throw std::invalid_argument("Error Loading Texture");
	}
	optionsButton.sprite.setTexture(optionsTexture);
	optionsButton.sprite.setOrigin(sf::Vector2f(optionsTexture.getSize().x / 2, optionsTexture.getSize().y / 2));
	optionsButton.sprite.setPosition(sf::Vector2f(xRes / 2, (yRes / 2) + optionsTexture.getSize().y * 1.5f));
	optionsButton.action = Options;

	Button exitButton;
	if (!exitTexture.loadFromFile("res/img/ExitButton.png"))
	{
		throw std::invalid_argument("Error Loading Texture");
	}
	exitButton.sprite.setTexture(exitTexture);
	exitButton.sprite.setOrigin(sf::Vector2f(exitTexture.getSize().x / 2, exitTexture.getSize().y / 2));
	exitButton.sprite.setPosition(sf::Vector2f(xRes / 2, (yRes / 2) + exitTexture.getSize().y * 3.0f));
	exitButton.action = Exit;

	if (!optionsMenuTexture.loadFromFile("res/img/OptionsScreen.png")) //Uses Ebrima Bold
	{
		throw std::invalid_argument("Error Loading Texture");
	}
	optionsMenuSprite.setTexture(optionsMenuTexture);

	Button res1Button;
	if (!res1Texture.loadFromFile("res/img/res1.png"))
	{
		throw std::invalid_argument("Error Loading Texture");
	}
	res1Button.sprite.setTexture(res1Texture);
	res1Button.sprite.setOrigin(sf::Vector2f(res1Texture.getSize().x / 2, res1Texture.getSize().y / 2));
	res1Button.sprite.setPosition(sf::Vector2f(xRes / 2, (yRes / 2) - res1Texture.getSize().y * 2.0f));
	res1Button.action = Res1;

	Button res2Button;
	if (!res2Texture.loadFromFile("res/img/res2.png"))
	{
		throw std::invalid_argument("Error Loading Texture");
	}
	res2Button.sprite.setTexture(res2Texture);
	res2Button.sprite.setOrigin(sf::Vector2f(res2Texture.getSize().x / 2, res2Texture.getSize().y / 2));
	res2Button.sprite.setPosition(sf::Vector2f(xRes / 2, (yRes / 2) - res2Texture.getSize().y));
	res2Button.action = Res2;

	Button res3Button;
	if (!res3Texture.loadFromFile("res/img/res3.png"))
	{
		throw std::invalid_argument("Error Loading Texture");
	}
	res3Button.sprite.setTexture(res3Texture);
	res3Button.sprite.setOrigin(sf::Vector2f(res3Texture.getSize().x / 2, res3Texture.getSize().y / 2));
	res3Button.sprite.setPosition(sf::Vector2f(xRes / 2, (yRes / 2)));
	res3Button.action = Res3;

	Button fullscreenButton;
	if (!fullscreenTexture.loadFromFile("res/img/Fullscreen.png"))
	{
		throw std::invalid_argument("Error Loading Texture");
	}
	fullscreenButton.sprite.setTexture(fullscreenTexture);
	fullscreenButton.sprite.setOrigin(sf::Vector2f(fullscreenTexture.getSize().x / 2, fullscreenTexture.getSize().y / 2));
	fullscreenButton.sprite.setPosition(sf::Vector2f(xRes / 2, (yRes / 2) + fullscreenTexture.getSize().y));
	fullscreenButton.action = Fullscreen;

	Button windowedButton;
	if (!windowedTexture.loadFromFile("res/img/Windowed.png"))
	{
		throw std::invalid_argument("Error Loading Texture");
	}
	windowedButton.sprite.setTexture(windowedTexture);
	windowedButton.sprite.setOrigin(sf::Vector2f(windowedTexture.getSize().x / 2, windowedTexture.getSize().y / 2));
	windowedButton.sprite.setPosition(sf::Vector2f(xRes / 2, (yRes / 2) + windowedTexture.getSize().y * 2.0f));
	windowedButton.action = Windowed;

	Button backButton;
	if (!backTexture.loadFromFile("res/img/Back.png"))
	{
		throw std::invalid_argument("Error Loading Texture");
	}
	backButton.sprite.setTexture(backTexture);
	backButton.sprite.setOrigin(sf::Vector2f(backTexture.getSize().x / 2, backTexture.getSize().y / 2));
	backButton.sprite.setPosition(sf::Vector2f(xRes / 2, (yRes / 2) + backTexture.getSize().y *3.0f));
	backButton.action = Back;

	mainButtons.push_back(startButton);
	mainButtons.push_back(optionsButton);
	mainButtons.push_back(exitButton);

	optionsButtons.push_back(res1Button);
	optionsButtons.push_back(res2Button);
	optionsButtons.push_back(res3Button);
	optionsButtons.push_back(fullscreenButton);
	optionsButtons.push_back(windowedButton);
	optionsButtons.push_back(backButton);
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
	if (!options)
	{
		window.draw(menuSprite);
		for each (Button btn in mainButtons)
		{
			window.draw(btn.sprite);
		}
	}
	else
	{
		window.draw(optionsMenuSprite);
		for each (Button btn in optionsButtons)
		{
			window.draw(btn.sprite);
		}
	}
}

MainMenu::Selection MainMenu::HandleClick(int x, int y)
{
	if (!options)
	{
		std::list<Button>::iterator it;
		for (it = mainButtons.begin(); it != mainButtons.end(); it++)
		{
			sf::Sprite sprite = (*it).sprite;

			if (sprite.getGlobalBounds().contains(sf::Vector2f(x, y)))
			{
				return (*it).action;
			}
		}
	}
	else
	{
		std::list<Button>::iterator it;
		for (it = optionsButtons.begin(); it != optionsButtons.end(); it++)
		{
			sf::Sprite sprite = (*it).sprite;

			if (sprite.getGlobalBounds().contains(sf::Vector2f(x, y)))
			{
				return (*it).action;
			}
		}
	}
	return Null;
}