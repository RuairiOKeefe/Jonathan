#include "Game.h"

void Game::Load()
{
	float xScale = 2;
	player.SetTexture("res/img/ship.png");
	player.shot.SetTexture("res/img/BasicShot.png");
	player.fireRate = 0.2f;

}

void Game::Update()
{
	static sf::Clock clock;
	float dt = clock.restart().asSeconds();
	player.Update(dt, projectileList);
	std::vector<Projectile>::iterator shot = projectileList.begin();
	while (shot != projectileList.end())
	{
		shot->Update(dt);
		shot++;
	}
}

void Game::Render(sf::RenderWindow &window)
{
	window.draw(player.sprite);
	std::vector<Projectile>::iterator shot = projectileList.begin();
	while (shot != projectileList.end())
	{
		window.draw(shot->sprite);
		shot++;
	}
}
