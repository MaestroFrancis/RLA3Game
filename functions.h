#pragma once

#include <string>
#include "battle.h"


std::string name;

void titleScreen()
{
	std::cout << "   OOO      DDD      YYY      YYY     SSSSS    SSSSS    EEEEEEEEEEEE     YYY      YYY\n";
	std::cout << "  OO OO     D  DDD    YYY    YYY     SSSS     SSSS      EEEEEEEEEEEE      YYY    YYY\n";
	std::cout << " OOO OOO    D    DD    YYY  YYY     SSSS     SSSS       EEE                YYY  YYY\n";
	std::cout << "OOO   OOO   D    DD     YYYYYY        SSSS     SSSS     EEEEEEEEEE          YYYYYY\n";
	std::cout << " OOO OOO    D    DD      YYYY         SSSS     SSSS     EEE                  YYYY\n";
	std::cout << "  OO OO     D  DDD       YYYY          SSSS     SSSS    EEEEEEEEEEEE         YYYY\n";
	std::cout << "   OOO      DDD          YYYY      SSSS       SSSS      EEEEEEEEEEEE         YYYY\n";

	std::cout << "Odyssey Main Menu\n";
	std::cout << "___________________\n";
	std::cout << "1: Start Game\n";

	int titleInput;
	std::cin >> titleInput;
	std::cout << "What is your name, traveller?\n";
	std::cin >> name;
	std::cout << name << ", a traveller from farlands, had come from far lands to look for the secret treasure known by the locals ";
	std::cout << "as the Trident of Odysseus,\n";
	std::cout << "a weapon held by the legend himself.\n";
	std::cout << "As " << name << " continued his search, he discovered the land of Odyssey, a country filled with myths and legends ";
	std::cout << "that continue to define the world.\n";
	std::cout << "Despite his readiness, " << name << " was not ready for what was about to unravel...'\n\n";

	std::cout << "Welcome to the world of Odyssey...\n\n";
	
	system("pause");

	
}

void playerStats()
{
	std::cout << "Name: " << name << "\n";
	std::cout << "HP: " << Player.hp << "/50\n";
	std::cout << "Atk: " << Player.atk << "\n";
	std::cout << "Heal: " << Player.heal << "\n";
	std::cout << "Mana: " << Player.mana << "\n";
	std::cout << "Money: " << Player.money << "g\n";
	std::cout << "__________________________________\n\n";
}

void secretVoice()
{
	std::cout << name << "... " << name << "...\n";
	std::cout << "I am a voice of myth and legends. I am a voice of treasure. I am the voice of the rich and poor...\n";
	std::cout << "Because of the monsters you killed, you were able to prove your soul...\n";
	std::cout << "If you wish to claim the trident of mine, you must talk to a person in the villages for guidance...\n";
	std::cout << "I only wish you luck, and may your strength be more powerful...\n";

	system("pause");
	system("cls");
}

void ending()
{
	std::cout << "With the death of the dragon, " << name << " was able to claim the trident of Odysseus.\n";
	std::cout << "The people of Odyssey was now in eternal happiness due to the loss of monsters!\n";
	std::cout << "You are achieved peace! Hurray! Hurray!\n\n";

	std::cout << "'Thanks for playing my game! - Francis'";
}