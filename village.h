#pragma once
#include "battle.h"
#include "functions.h"
#include "citizens.h"

Animation villageAnimation;

int villageInput;
bool hiddenVillager = false;
bool dragonSpawn = false;
void villageSequence()
{

	bool exitVillage = false;

	while (!exitVillage)
	{
		std::cin.clear();

		playerStats();

		std::cout << "Welcome to Templeton! Pick your destination:\n";
		std::cout << "1: Inn (restore full health with 20g)\n";
		std::cout << "2: Witch Hut (restore full mana with 15g)\n";
		std::cout << "3: Talk with citizens\n";
		std::cout << "4: ...\n";
		std::cout << "0: Leave Village\n";

		std::cin >> villageInput; 

		

		switch (villageInput) 
		{
		case 0:
			exitVillage = true;
			break;
		case 1:
			system("cls");
			
			playerStats();
			std::cout << "\n";

			villageAnimation.inn();

			std::cout << "Inn Manager: Hello, would you like to rest? (20g) Y/N\n";

			char innInput;
			std::cin >> innInput;
			
			if (toupper(innInput) == 'Y')
			{
				if (Player.money >= 20)
				{
					std::cout << "Inn Manager: Payment received! Enjoy your stay.\n\n";
					Player.hp = 50;
					Player.money -= 20;
					std::cout << "...health fully recovered!\n\n";
					system("pause");
				}
				else if (Player.money < 20)
				{
					std::cout << "Inn Manager: Payment declined. You are short of money.\n";
					system("pause");
				}
			}
			system("cls");
			break;
		case 2:
			system("cls");

			playerStats();

			villageAnimation.witch();
			

			std::cout << "Witch: Hello young traveller, would you like me to restore your mana? (15g) Y/N\n";

			char witchInput;
			std::cin >> witchInput;

			if (toupper(witchInput) == 'Y')
			{
				if (Player.money >= 15)
				{
					std::cout << "Witch: Very nice... here you go!\n";
					Player.mana = 30;
					Player.money -= 15;
					std::cout << "...mana fully recovered!";
					system("pause");
				}
				else if (Player.money < 15)
				{
					std::cout << "You don't even have enough money! Nice try, trickster.\n";
					system("pause");
				}
			}
			system("cls");
			break;
		case 3:
			system("cls");

			citizenTalk();

			system("cls");
			break;
		case 4:
			system("cls");

			if (hiddenVillager == false)
			{
				std::cout << "...\n";
			}

			if (hiddenVillager == true)
			{
				std::cout << "...the one who killed the monsters of Odyssey...\n";
				Sleep(200);
				std::cout << "You were able to prove your soul, thus showing us your strength.\n";
				std::cout << "If you go out in the world, you will see a monster like no other.\n";
				std::cout << "Destroy it, and receive the Trident of Odysseus...\n";
				dragonSpawn = true;
			}

			system("pause");
			system("cls");
		default:
			exitVillage = true;
			break;
		}
	}
}