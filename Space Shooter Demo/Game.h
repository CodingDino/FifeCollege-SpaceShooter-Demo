#pragma once
#include <SFML/Graphics.hpp>



class Game
{
public:

	Game();

	void Run();
	void Draw();
	void Update();


private:

	sf::RenderWindow window;

};

