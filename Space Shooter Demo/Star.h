#pragma once
#include "GameObject.h"
class Star :
    public GameObject
{

public:

    Star(sf::Vector2f newScreenSize);

    // Overridden Functions
    virtual void Update(sf::Time deltaTime) override;

private:

    void Reset();

    static sf::Texture* starTexture;
    sf::Vector2f screenSize;
    float moveSpeed;
};

