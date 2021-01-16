#pragma once
#include "battle.h"

struct GridObject
{
	int x;
	int y;
};

struct Grid
{
	int totalX;
	int totalY;

	void RenderMap(GridObject player, GridObject goblin, GridObject giant, GridObject village, GridObject dragon)
	{
		for (int col = 0; col < totalY; col++)
		{
			for (int row = 0; row < totalX; row++)
			{
				if (player.x == row && player.y == col)
				{
					std::cout << "P";
				}
				else if (goblin.x == row && goblin.y == col)
				{
					std::cout << "o";
				}
				else if (giant.x == row && giant.y == col)
				{
					std::cout << "O";
				}
				else if (village.x == row && village.y == col)
				{
					std::cout << "V";
				}
				else if (dragon.x == row && dragon.y == col)
				{
					std::cout << "D";	
				}
				else
				{
					std::cout << ".";
				}
			}


			std::cout << "\n";
		}
		std::cout << "__________________________________\n\n";
		std::cout << "Legend:\n";
		std::cout << "P = Player\n";
		std::cout << "o = Goblin\n";
		std::cout << "O = Giant\n";
		std::cout << "V = Village\n";
	}
};


struct PlayerInput
{
	std::string direction;

	char GetInput()
	{
		std::cout << "Input direction! (W A S D):\n";
		std::cin >> direction;

		if (direction.length() != 1)
		{
			std::cout << "You are unable to travel that far!\n";
			Sleep(1000);
		}
		else
		{
			return direction[0];
		}



	}
};


