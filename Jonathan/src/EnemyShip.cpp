#include "EnemyShip.h"

EnemyShip::EnemyShip()
{
}

EnemyShip::~EnemyShip()
{
}

float EnemyShip::TurnTo(sf::Vector2f position)
{
	sf::Vector2f targetVec = position - sprite.getPosition();
	targetVec = targetVec / sqrtf((targetVec.x * targetVec.x) + (targetVec.y * targetVec.y));
	float targetAngle = (atan2(targetVec.x, -targetVec.y) * 180 / M_PI);
	float angleDifference = targetAngle - sprite.getRotation();
	angleDifference += 180;
	float mod = angleDifference - floor(angleDifference / 360) * 360;
	mod -= 180;
	return mod;
}
