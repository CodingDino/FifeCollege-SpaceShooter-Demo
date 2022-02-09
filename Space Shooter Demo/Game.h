#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Star.h"
#include "ChaseEnemy.h"
#include "Bullet.h"

class Game
{
public:

	Game();

	void Run();
	void Draw();
	void Update();

	void AddBullet(Bullet* bulletToAdd);

private:


	void SetupGame();
	void SpawnEnemy();

	
	sf::RenderWindow window;
	sf::Clock gameClock;
	Player playerInstance;
	std::vector<Star*> starVector;
	std::vector<Enemy*> enemyVector;
	sf::Time timeSinceEnemy;
	std::vector<Bullet*> bulletVector;
};

