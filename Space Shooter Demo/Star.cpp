#include "Star.h"

// Initialise static variable
sf::Texture* Star::starTexture = nullptr;


Star::Star(sf::Vector2f newScreenSize)
	: GameObject	()
	, screenSize	(newScreenSize)
	, moveSpeed		(500)
{
	if (starTexture == nullptr)
	{
		starTexture = new sf::Texture();
		starTexture->loadFromFile("Assets/Graphics/star.png");
	}

	objectSprite.setTexture(*starTexture);

	// randomly position
	sf::Vector2f newPosition(0, 0);
	// randomNumber = lower + rand() % (upper - lower)
	newPosition.x = rand() % (int)screenSize.x;
	newPosition.y = rand() % (int)screenSize.y;
	SetPosition(newPosition);

	// set initial velocity
	sf::Vector2f moveDirection(-1.0f, 0.0f); // Unit vector in the left direction
	SetVelocity(moveDirection * moveSpeed);
}

void Star::Update(sf::Time deltaTime)
{
	GameObject::Update(deltaTime); // This actually moves the star

	float starRight = GetPosition().x + objectSprite.getGlobalBounds().width;
	if (starRight < 0)
	{
		Reset();
	}
}

void Star::Reset()
{
	// randomly position
	sf::Vector2f newPosition(0, 0);
	// randomNumber = lower + rand() % (upper - lower)
	newPosition.x = (int)screenSize.x; // just off screen right
	newPosition.y = rand() % (int)screenSize.y;
	SetPosition(newPosition);

}
