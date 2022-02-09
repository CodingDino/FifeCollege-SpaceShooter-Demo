#include "Ship.h"
#include "Bullet.h"
#include "Game.h"

Ship::Ship(Game* newGame)
	: moveSpeed (0)
	, myGame	(newGame)
{
}

void Ship::Move(sf::Vector2f direction)
{
	float magnitude = sqrtf(direction.x * direction.x + direction.y * direction.y);
	if (magnitude == 0)
	{
		SetVelocity(sf::Vector2f(0, 0));
	}
	else
	{
		sf::Vector2f directionNorm = direction / magnitude;

		SetVelocity(directionNorm * moveSpeed);
	}
}

void Ship::Fire()
{
	// Create a bullet
	Bullet* newBullet = new Bullet();

	// set the bullet's position to our 
	//		ship's position + some firing offset (TODO)
	newBullet->SetPosition(GetPosition());

	// set the bullet's velocity based on the 
	//		type of ship
	newBullet->SetVelocity(sf::Vector2f(600, 0));

	// Give the bullet to the game to manage
	myGame->AddBullet(newBullet);
}
