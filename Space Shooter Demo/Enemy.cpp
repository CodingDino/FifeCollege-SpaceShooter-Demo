#include "Enemy.h"

Enemy::Enemy(Game* newGame, sf::Vector2f newScreenSize)
	: Ship				(newGame)
	, movementTarget	(0,0)
	, arrivalDistance	(10)
	, arrivedAtTarget	(true)
{
	// randomly position
	sf::Vector2f newPosition(0, 0);
	float screenGap = 100;
	float estimateSpriteHeight = 100;
	float lowerBound = screenGap;
	float upperBound = newScreenSize.y - screenGap - estimateSpriteHeight;

	// randomNumber = lower + rand() % (upper - lower)
	newPosition.x = (int)newScreenSize.x - 150;
	newPosition.y = lowerBound + rand() % (int)(upperBound - lowerBound);
	SetPosition(newPosition);

	// Set up our move speed
	moveSpeed = 100;

	// TEMP
	SetTarget(sf::Vector2f(0, 0));
}

void Enemy::Update(sf::Time deltaTime)
{
	AI(); // Process the AI and choose a location to move to

	if (!arrivedAtTarget)
	{
		sf::Vector2f direction = movementTarget - GetPosition();
		Move(direction); // set our velocity
	}
	else // already at target, do not move anymore
	{
		SetVelocity(sf::Vector2f(0, 0));
	}

	Ship::Update(deltaTime); // process game physics etc

	// Check if we have now arrived at target

	// get the distance vector using subtraction
	sf::Vector2f distanceVector = movementTarget - GetPosition();
	// Get the magnitude using the pythagorean theorem
	float distance = sqrtf(  distanceVector.x * distanceVector.x 
						   + distanceVector.y * distanceVector.y); 

	if (distance <= arrivalDistance)
	{
		// We have arrived!
		arrivedAtTarget = true;
	}

}

void Enemy::SetTarget(sf::Vector2f newTarget)
{
	movementTarget = newTarget;
	arrivedAtTarget = false;
}

void Enemy::AI()
{
}
