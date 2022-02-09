#include "Game.h"

Game::Game()
	: window			(sf::VideoMode::getDesktopMode(), "Space Shooter", sf::Style::Titlebar | sf::Style::Close)
	, gameClock			()
	, playerInstance	(this)
	, starVector		()
	, enemyVector		()
	, timeSinceEnemy	()
	, bulletVector		()
{

	AddBullet(new Bullet());

}

void Game::Run()
{
	SetupGame();

	while (window.isOpen())
	{
		// Poll and handle window events
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		// Close the game if escape is pressed
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			// if so, call the close function on the window
			window.close();
		}

		// Update
		Update();

		// Draw
		Draw();
	}

}

void Game::Draw()
{
	window.clear();

	// TODO: Draw everything
	for (int i = 0; i < starVector.size(); ++i)
	{
		starVector[i]->Draw(window);
	}

	playerInstance.Draw(window);

	for (int i = 0; i < enemyVector.size(); ++i)
	{
		enemyVector[i]->Draw(window);
	}

	for (int i = 0; i < bulletVector.size(); ++i)
	{
		bulletVector[i]->Draw(window);
	}

	window.display();
}

void Game::Update()
{
	// Get the time passed since last frame
	sf::Time deltaTime = gameClock.restart();

	// TODO: Update everything
	playerInstance.Update(deltaTime);

	for (int i = 0; i < starVector.size(); ++i)
	{
		starVector[i]->Update(deltaTime);
	}

	for (int i = 0; i < enemyVector.size(); ++i)
	{
		enemyVector[i]->Update(deltaTime);
	}

	// Spawn enemies every few second
	float enemyFrequency = 2.0f; // in seconds
	timeSinceEnemy += deltaTime;
	if (timeSinceEnemy.asSeconds() >= enemyFrequency)
	{
		// Time to spawn an enemy!
		SpawnEnemy();
		timeSinceEnemy = sf::Time();
	}

	for (int i = 0; i < bulletVector.size(); ++i)
	{
		bulletVector[i]->Update(deltaTime);
	}
}

void Game::AddBullet(Bullet* bulletToAdd)
{

	bulletVector.push_back(bulletToAdd);

}

void Game::SetupGame()
{
	sf::Vector2f screenSize(window.getSize());

	//Put our player in the center of the screen vertically, and near the left side
	playerInstance.SetPosition(sf::Vector2f(100, screenSize.y / 2 - 50));

	// Create stars
	int numStars = 20;
	for (int i = 0; i < numStars; ++i)
	{
		starVector.push_back(new Star(screenSize));
	}
}

void Game::SpawnEnemy()
{
	// Special Pointer EVERY class has
	//   "this" (like saying "THIS OBJECT" or "THIS INSTANCE"

	// TODO: Randomly choose between Chase and Pattern Enemy
	enemyVector.push_back(new ChaseEnemy(this, sf::Vector2f(window.getSize()), &playerInstance));
}
