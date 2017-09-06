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
