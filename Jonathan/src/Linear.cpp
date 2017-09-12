#include "linear.h"

Linear::Linear() : Weapon()
{
}

Linear::Linear(float shotNumber, float spacing, std::string shotSprite, float speed, float damage, bool playerShot, float fireRate) : Weapon()
{
	this->shotNumber = shotNumber;
	this->spacing = spacing;
	shot = new Projectile(shotSprite, speed, damage, playerShot);
	this->fireRate = fireRate;
}

Linear::~Linear()
{
}

void Linear::Shoot(std::vector<Projectile>& projectileList, Projectile shot, sf::Vector2f shotOrigin, float inAngle)
{
	Projectile* newShot = new Projectile();
	newShot->SetTexture("res/img/BasicShot.png");
	newShot->playerShot = shot.playerShot;
	newShot->speed = shot.speed;
	newShot->damage = shot.damage;
	newShot->radius = shot.radius;
	newShot->SetPosition(shotOrigin);
	newShot->sprite.setRotation(inAngle);
	newShot->angle = inAngle;
	projectileList.push_back(*newShot);
}

void Linear::Update(float dt, float angle, sf::Vector2f shotOrigin, std::vector<Projectile>& projectileList)
{
	float radAngle = angle / 180 * M_PI;//?????
	sf::Vector2f angleVector = sf::Vector2f(cosf(radAngle), -sinf(radAngle));
	angleVector = sf::Vector2f(angleVector.y, -angleVector.x);
	angleVector = angleVector / sqrtf((angleVector.x * angleVector.x) + (angleVector.y * angleVector.y));
	if (fireCD.getElapsedTime().asSeconds() >= fireRate)
	{
		for (int i = 0; i < shotNumber; i++)
		{
			Shoot(projectileList, *shot, shotOrigin + (angleVector * spacing * (float) i), angle);
		}
		fireCD.restart();
	}
}
