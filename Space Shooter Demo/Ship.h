#pragma once
#include "GameObject.h"
#include <SFML/Graphics.hpp>

// Forward Declaration
class Game;

class Ship : public GameObject
{
public:

	Ship(Game* newGame);

	// Overridden Functions
	virtual void Update(sf::Time deltaTime) override;

	void TakeDamage(int damage);
	bool IsAlive();

protected:

	void Move(sf::Vector2f direction);
	void Fire();

	float moveSpeed;
	float fireCooldown;
	sf::Vector2f firingOffset;
	int maxHealth;
	int currentHealth;

private:

	Game* myGame;
	sf::Time timeSinceFire;

};

