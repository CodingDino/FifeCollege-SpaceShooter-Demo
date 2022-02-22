#include "Bullet.h"
#include "Ship.h"
#include <iostream>

// Initialise static variable
sf::Texture* Bullet::bulletTexture = nullptr;

Bullet::Bullet()
	: GameObject ()
{
	if (bulletTexture == nullptr)
	{
		bulletTexture = new sf::Texture();
		bulletTexture->loadFromFile("Assets/Graphics/playerBullet.png");
	}
	objectSprite.setTexture(*bulletTexture);
}

void Bullet::HandleCollision(Ship* target)
{
	sf::FloatRect bulletCollider = GetCollider();
	sf::FloatRect shipCollider = target->GetCollider();

	if (bulletCollider.intersects(shipCollider))
	{
		target->TakeDamage(100);
	}
}
