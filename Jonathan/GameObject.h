#pragma once
#include <SFML/Graphics.hpp>

class GameObject
{
	
public:
	sf::Sprite sprite;
	sf::Texture texture;

	GameObject();
	~GameObject();
	void SetTexture(std::string location, float xScale);
	void ChangeResolution(float res);
	void SetPosition(sf::Vector2f position);
	void Move(sf::Vector2f move);
	void Update(float dt);

private:

};