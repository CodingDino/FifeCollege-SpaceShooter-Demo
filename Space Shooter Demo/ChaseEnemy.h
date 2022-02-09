#pragma once
#include "Enemy.h"

class Player;

class ChaseEnemy :
    public Enemy
{
public:

    // Constructors / Destructors
    ChaseEnemy(Game* newGame, sf::Vector2f newScreenSize, 
               Player* newPlayer);

protected:

    virtual void AI() override;

private:

    static sf::Texture* chaseEnemyTexture;
    Player* playerPointer;
};

