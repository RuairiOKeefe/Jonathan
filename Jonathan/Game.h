#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"

class Game
{
public:
	GameObject gameObject;//Use a collection later ofc

	void Load();
	void Update();
	void Render(sf::RenderWindow &window);
private:

};
