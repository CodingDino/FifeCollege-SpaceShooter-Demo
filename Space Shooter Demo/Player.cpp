#include "Player.h"

Player::Player(Game* newGame)
	: Ship			(newGame)
	, playerTexture	()
{
	playerTexture.loadFromFile("Assets/Graphics/player.png");
	objectSprite.setTexture(playerTexture);

	moveSpeed = 500.0f;
	fireCooldown = 0.5f;
	firingOffset = sf::Vector2f(75, 43);
}

void Player::Update(sf::Time deltaTime)
{
	// First, check input from the player before moving
	// (sets the velocity)
	Input();

	// Call base class version of update ( this will go up the inheritance chain
	// and call GameObject.Update automatically)
	// This will move us based on our velocity
	Ship::Update(deltaTime);
}

void Player::Input()
{

	sf::Vector2f moveDirection(0, 0);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		moveDirection.y = -1.0f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		moveDirection.y = 1.0f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		moveDirection.x = -1.0f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		moveDirection.x = 1.0f;
	}

	Move(moveDirection);

	// Firing
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		Fire();
	}
}
