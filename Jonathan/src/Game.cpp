#include "Game.h"

void Game::Load()
{
	float xScale = 2;
	player.SetTexture("res/img/ship.png");
	player.shot.SetTexture("res/img/BasicShot.png");
}

void Game::Update()
{
	static sf::Clock clock;
	float dt = clock.restart().asSeconds();
	player.Update(dt, projectileList);
}

void Game::Render(sf::RenderWindow &window)
{
	window.draw(player.sprite);
	for each (GameObject shot in projectileList)
	{
		window.draw(shot.sprite);
	}
}
