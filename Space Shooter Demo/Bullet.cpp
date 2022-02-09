#include "Bullet.h"

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
