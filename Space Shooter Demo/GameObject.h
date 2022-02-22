#pragma once
#include <SFML/Graphics.hpp>

class GameObject
{
public:

	GameObject();

	void Draw(sf::RenderTarget& target);
	virtual void Update(sf::Time deltaTime);
	void SetVelocity(sf::Vector2f newVelocity);
	void SetPosition(sf::Vector2f newPosition);
	sf::Vector2f GetPosition();
	sf::FloatRect GetCollider();

protected:

	sf::Sprite objectSprite;

private:

	sf::Vector2f position;
	sf::Vector2f velocity;

};

