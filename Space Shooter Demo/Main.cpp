#include "Game.h"

int main()
{
	// Seeding random number generator
	srand(time(NULL));

	Game ourGame;

	ourGame.Run();

	return 0;
}