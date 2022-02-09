#pragma once
#include "Ship.h"

class Game;

class Enemy :
    public Ship
{

public:

    Enemy(Game* newGame, sf::Vector2f newScreenSize);

    // Overridden Functions
    virtual void Update(sf::Time deltaTime) override;

protected:

    void SetTarget(sf::Vector2f newTarget);

    virtual void AI();

private:

    sf::Vector2f movementTarget;
    float arrivalDistance;
    bool arrivedAtTarget;

};

