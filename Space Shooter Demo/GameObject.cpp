#include "GameObject.h"

GameObject::GameObject()
	: objectSprite	()
	, position		(0,0)
	, velocity		(0,0)
{
}

void GameObject::Draw(sf::RenderTarget& target)
{
	target.draw(objectSprite);
}

void GameObject::Update(sf::Time deltaTime)
{
	SetPosition(position + velocity * deltaTime.asSeconds());
}

void GameObject::SetVelocity(sf::Vector2f newVelocity)
{
	velocity = newVelocity;
}

void GameObject::SetPosition(sf::Vector2f newPosition)
{
	position = newPosition;
	objectSprite.setPosition(position);
}

sf::Vector2f GameObject::GetPosition()
{
	return position;
}
