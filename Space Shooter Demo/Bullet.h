#pragma once
#include "GameObject.h"

class Ship;

class Bullet :
    public GameObject
{

public:

    Bullet();

    void HandleCollision(Ship* target);

private:

    static sf::Texture* bulletTexture;

};

