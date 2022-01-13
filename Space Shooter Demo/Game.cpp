#include "Game.h"

Game::Game()
	: window (sf::VideoMode::getDesktopMode(), "Space Shooter", sf::Style::Titlebar | sf::Style::Close)
{
}

void Game::Run()
{
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

	window.display();
}

void Game::Update()
{

	// TODO: Update everything
}
