#pragma once

#include "village.h"


Animation citizenAnimation;

void citizenTalk()
{
	int citizenChoice = rand() % 5;

	int resetInput;
	char ynInput;
	int moneyInput;

	playerStats();

	switch (citizenChoice)
	{
	case 0:
		system("cls");
		citizenAnimation.citizen();

		std::cout << "Marcellus: My name is Marcellus. Are you from here? Y/N\n";


		std::cin >> ynInput;

		if (toupper(ynInput) == 'Y')
		{
			std::cout << "Really... I never saw you before, but I get the sense you are lying. If only you said the truth, I would have given you a fun riddle to play with.\n";
			system("pause");
		}
		else
		{
			std::cout << "I bet you are a traveller. I have a riddle that might help you on your journey...\n\n";
			std::cout << "'Once every beast is killed, a person in the welfare of a town will show themselves as useful...'\n\n";
			std::cout << "I heard this riddle a couple days ago when I was easedropping some peeps... hey, mind your business!\n";
			system("pause");
		}
		break;
	case 1:
		system("cls");
		citizenAnimation.citizen();
		std::cout << "Francio: You an outsider? If you are interested, I have a riddle that you may like... for a price of 5g!\n\n";
		std::cout << "Input 5g:";

		
		std::cin >> moneyInput;

		if (moneyInput >= 5)
		{
			if (Player.money >= 5)
			{
				Player.money -= 5;
				std::cout << "Thank you for the money kind sir, but I actually do not have anything to say. Toddles!\n";
				system("pause");

			}
			else if (Player.money < 5)
			{
				std::cout << "Not enough!\n";
				system("pause");
			}
		}
		else if (moneyInput < 5)
		{
			std::cout << "Sorry, I won't accept your money! Give me the exact amount!\n";
			system("pause");
		}
		break;
	case 2:
		system("cls");
		citizenAnimation.citizen();
		std::cout << "Kassio: I had to retreat to this village after the monsters started to invade Odyssey.\n\n";
		std::cout << "Kassio: And because of that, some of my loot was lost in the area! If only one were to find it...\n";

		system("pause");
		break;
	case 3:
		system("cls");
		citizenAnimation.citizen();
		std::cout << "Malon: You know those monsters out there? They seem to hold these transparent gems that are naked to the eye.\n";
		std::cout << "Malon: I heard that if one were to harness all of the gems, a faint voice will call them out...\n";
		std::cout << "Malon: ...what, I am only a kid!\n";
		system("pause");
		break;
	case 4:
		system("cls");
		citizenAnimation.citizen();
		std::cout << "Issei: My farm outside the village has been destroyed by the monsters! Oh no...\n";
		system("pause");
		break;

	}	
}



