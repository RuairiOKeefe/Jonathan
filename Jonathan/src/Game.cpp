#include "Game.h"

void Game::Load()
{
	float xScale = 2;
	player.SetTexture("res/img/ship.png");
	player.shot.SetTexture("res/img/BasicShot.png");
	player.fireRate = 0.2f;

	EnemyShip* strafer = new EnemyShip();
	strafer->SetTexture("res/img/Strafer.png");
	strafer->sprite.setPosition(sf::Vector2f(300, 500));
	hostileVec.push_back(*strafer);
}

void Game::Update()
{
	static sf::Clock clock;
	float dt = clock.restart().asSeconds();
	player.sprite.rotate(dt*100.0f);
	player.Update(dt, projectileVec);
	std::vector<EnemyShip>::iterator ships = hostileVec.begin();
	while (ships != hostileVec.end())
	{
		//ships->Update(dt);
		ships++;
	}
	std::vector<Projectile>::iterator shot = projectileVec.begin();
	while (shot != projectileVec.end())
	{
		shot->Update(dt);
		shot++;
	}
}

void Game::Render(sf::RenderWindow &window)
{
	window.draw(player.sprite);
	std::vector<Projectile>::iterator shot = projectileVec.begin();
	std::vector<EnemyShip>::iterator ships = hostileVec.begin();
	while (ships != hostileVec.end())
	{
		window.draw(ships->sprite);
		ships++;
	}
	while (shot != projectileVec.end())
	{
		window.draw(shot->sprite);
		shot++;
	}
}
