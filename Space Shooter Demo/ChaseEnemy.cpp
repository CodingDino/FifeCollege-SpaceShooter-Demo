#include "ChaseEnemy.h"
#include "Player.h"

// Initialise static variable
sf::Texture* ChaseEnemy::chaseEnemyTexture = nullptr;

ChaseEnemy::ChaseEnemy(Game* newGame, sf::Vector2f newScreenSize, Player* newPlayer)
	: Enemy				(newGame, newScreenSize)
	, playerPointer		(newPlayer)
{

	if (chaseEnemyTexture == nullptr)
	{
		chaseEnemyTexture = new sf::Texture();
		chaseEnemyTexture->loadFromFile("Assets/Graphics/enemyChase.png");
	}

	objectSprite.setTexture(*chaseEnemyTexture);

}

void ChaseEnemy::AI()
{
	SetTarget(playerPointer->GetPosition());
}
