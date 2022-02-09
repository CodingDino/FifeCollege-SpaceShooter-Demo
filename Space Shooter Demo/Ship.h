#pragma once
#include "GameObject.h"
#include <SFML/Graphics.hpp>

// Forward Declaration
class Game;

class Ship : public GameObject
{
public:

	Ship(Game* newGame);

protected:

	void Move(sf::Vector2f direction);
	void Fire();

	float moveSpeed;

private:

	Game* myGame;

};

