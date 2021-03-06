#pragma once
#include <SFML/Graphics.hpp>

class GameObject
{
	
public:
	sf::Texture texture;
	sf::Sprite sprite;
	float radius;

	GameObject();
	~GameObject();

	void SetTexture(std::string location);
	void ChangeScale(float scale);
	void SetPosition(sf::Vector2f position);
	void Move(sf::Vector2f move);
	virtual void Update(float dt) { throw std::invalid_argument("Error: Inherited method has no Update method"); };

private:

};