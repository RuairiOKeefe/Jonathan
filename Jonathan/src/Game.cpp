#include "Game.h"

void Game::Load()
{
	float xScale = 2;

	for (int i = 0; i < 10; i++)
	{
		Strafer* strafer = new Strafer(sf::Vector2f(10.0f - (i * 32), 300), sf::Vector2f(1, 0));
		hostileVec.push_back(strafer);
	}
}

void Game::Update()
{
	static sf::Clock clock;
	float dt = clock.restart().asSeconds();
	//player.sprite.rotate(dt*100.0f);
	std::vector<Projectile>::iterator shot = projectileVec.begin();
	while (shot != projectileVec.end())
	{
		shot->Update(dt);
		std::vector<EnemyShip*>::iterator ships = hostileVec.begin();
		while (ships != hostileVec.end())
		{
			if(shot->playerShot)
				(*ships)->TakeDamage(shot->CheckHit((*ships)->sprite));
			else
				player.TakeDamage(shot->CheckHit(player.sprite));
			ships++;
		}

		shot++;
	}

	for (std::vector<Projectile*>::size_type n = 0; n < projectileVec.size();)
	{
		if (projectileVec[n].despawn)
		{
			projectileVec[n].~Projectile();
			projectileVec.erase(projectileVec.begin() + n);
		}
		else
			n++;
	}
	projectileVec.shrink_to_fit();

	std::vector<EnemyShip*>::iterator ships = hostileVec.begin();
	while (ships != hostileVec.end())
	{
		(*ships)->Update(dt, projectileVec, player.sprite.getPosition());
		ships++;
	}

	for (std::vector<EnemyShip*>::size_type n = 0; n < hostileVec.size();)
	{
		if (hostileVec[n]->despawn)
		{
			hostileVec[n]->~EnemyShip();
			hostileVec.erase(hostileVec.begin() + n);
		}
		else
			n++;
	}
	hostileVec.shrink_to_fit();

	player.Update(dt, projectileVec);
}

void Game::Render(sf::RenderWindow &window)
{
	std::vector<Projectile>::iterator shot = projectileVec.begin();
	while (shot != projectileVec.end())
	{
		window.draw(shot->sprite);
		shot++;
	}
	window.draw(player.sprite);
	std::vector<EnemyShip*>::iterator ships = hostileVec.begin();
	while (ships != hostileVec.end())
	{
		window.draw((*ships)->sprite);
		ships++;
	}
}
