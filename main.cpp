#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <string>
#include <vector>

#include "battle.h" //contains stats, battle sequences, etc
#include "map.h" //renders map and character/enemy placement
#include "village.h" //village functions

#include "functions.h" //general functions
#include "animation.h" //animation functions
 


int main()
{
	Animation animation;

	srand(time(NULL));

    Grid grid;
    grid.totalX = 20;
    grid.totalY = 10;

    GridObject player;
    player.x = rand() % grid.totalX;
    player.y = rand() % grid.totalY;

    GridObject goblin;
    goblin.x = rand() % grid.totalX;
    goblin.y = rand() % grid.totalY;

	GridObject giant;
	giant.x = rand() % grid.totalX;
	giant.y = rand() % grid.totalY;

    GridObject village;
    village.x = rand() % grid.totalX;
    village.y = rand() % grid.totalY;


	GridObject dragon;
	dragon.x = 60;
	dragon.y = 60;
	

	std::vector<int> gem = {};
	

   
    titleScreen(); 


    Sleep(2000);
    system("cls");



	PlayerInput playerInput;

	char input = '0';

	while (input != 'q')
	{
		if (gem.size() == 2)
		{
			secretVoice();
			gem.push_back(1);

			hiddenVillager = true;
		}
		if (dragonSpawn == true)
		{
			dragon.x = 19;
			dragon.y = 9;
		}

		playerStats();

		
		grid.RenderMap(player, goblin, giant, village, dragon);

		
		input = playerInput.GetInput();

		system("cls");

		switch (input)
		{
		case 'w':
			player.y -= 1;
			break;
		case 'd':
			player.x += 1;
			break;
		case 's':
			player.y += 1;
			break;
		case 'a':
			player.x -= 1;
			break;
		case '0':
			std::cout << "Shutting down..."; 
			return 0;
		}

		if (player.x <= -1)
		{
			player.x += 1;
		}

		if (player.x >= grid.totalX)
		{
			player.x = grid.totalX - 1;
		}

		if (player.y <= -1)
		{
			player.y += 1;
		}

		if (player.y >= grid.totalY)
		{
			player.y = grid.totalY - 1;
		}

		
		if (player.x == goblin.x && player.y == goblin.y)
		{
			system("cls"); 

			animation.enteringBattle();
			goblinSequence();

			if (Goblin.mhp < 1)
			{
				gem.push_back(1);

				goblin.x = 25;
				goblin.y = 25;
				system("cls");
			}
		}	

		if (player.x == giant.x && player.y == giant.y)
		{
			system("cls"); 

			animation.enteringBattle();
			giantSequence();

			if (Giant.mhp < 1)
			{
				gem.push_back(2);
				giant.x = 26;
				giant.y = 26;
				system("cls");
			}
		}
		
		if (player.x == dragon.x && player.y == dragon.y)
		{
			system("cls");

			animation.dragonBattle();
			dragonSequence();

			if (Dragon.mhp < 1)
			{
				ending();
				return 0;

			}
		}


        
		if (Player.hp < 1)
		{
			system("cls");
			std::cout << "You were killed. Try again!\n";
			return 0;
		}
        if (player.x == village.x && player.y == village.y)
        {
            system("cls");
            villageSequence();
            
        }
	}
}