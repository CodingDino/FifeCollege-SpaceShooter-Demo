#include "Ship.h"
#include "Bullet.h"
#include "Game.h"

Ship::Ship(Game* newGame)
	: GameObject		()
	, moveSpeed			(0)
	, fireCooldown		(3)
	, firingOffset		(0, 0)
	, maxHealth			(100)
	, currentHealth		(100)
	, myGame			(newGame)
	, timeSinceFire		()
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
	if (timeSinceFire.asSeconds() >= fireCooldown)
	{
		// Create a bullet
		Bullet* newBullet = new Bullet();

		// set the bullet's position to our 
		//		ship's position + some firing offset
		newBullet->SetPosition(GetPosition()+ firingOffset);

		// set the bullet's velocity based on the 
		//		type of ship
		newBullet->SetVelocity(sf::Vector2f(600, 0));

		// Give the bullet to the game to manage
		myGame->AddBullet(newBullet);

		// We just fired, so set our time to 0
		timeSinceFire = sf::Time();
	}
}

void Ship::Update(sf::Time deltaTime)
{

	GameObject::Update(deltaTime);

	timeSinceFire += deltaTime;
}

void Ship::TakeDamage(int damage)
{
	currentHealth -= damage;

	// Check if we died, if so, play 
	// explosions sound and image?
}

bool Ship::IsAlive()
{
	return currentHealth > 0;
}


