#pragma once
#include "GameObject.h"

class Bullet :
    public GameObject
{

public:

    Bullet();

private:

    static sf::Texture* bulletTexture;

};

