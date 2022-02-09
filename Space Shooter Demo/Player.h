#pragma once
#include "Ship.h"

class Game;

class Player :
    public Ship
{

public:

    // Constructors / Destructors
    Player(Game* newGame);

    // Overridden Functions
    virtual void Update(sf::Time deltaTime) override;

private:

    // Private functions
    void Input();

    // Data members
    sf::Texture playerTexture;

};

