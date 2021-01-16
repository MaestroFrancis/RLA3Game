#pragma once
#include "animation.h"



Animation battleAnimation;


struct Character { //character stats
    int hp;
    int atk;
    int warpstk;
    int heal;
    int mana;
    int money;
};

struct Enemy { //enemy stats
    int mhp;
    int matk;
    int mwarpstk;
    int mheal;
};

Character Player =
{
    50, //Player.hp
    10, //Player.atk
    18, //Player.warpstk
    12,  //Player.heal
    30, //Player.mana
    50, //Player.money
};



Enemy Goblin =
{
    40, //Goblin.mhp 
    10, //Goblin.matk
    12, //Goblin.mwarpstk
    8, //Goblin.heal
};

Enemy Giant =
{
    60, 
    20,
    5,
    5,
};

Enemy Dragon =
{
    90,
    20,
    20,
    5,
};

int choice, eChoice, cDamage, eDamage;
int randomMoneyGen = rand() % 20;


void goblinMenu()
{
    std::cout << "\n";
    std::cout << "You have " << Player.hp << " health and " << Player.mana << " mana.\nThe Goblin has " << Goblin.mhp << " health.\n\n";
    std::cout << "What do you want to do?\n";
    std::cout << "1: Attack\n"; //regular attack.
    std::cout << "2: Warp Strike (-10 Mana)\n"; //stronger attack, yet risking mana due to the RNG.
    std::cout << "3: Heal\n";
    std::cout << "\n";
}

void giantMenu() 
{
    std::cout << "\n";


    std::cout << "You have " << Player.hp << " health and " << Player.mana << " mana.\nThe Giant has " << Giant.mhp << " health.\n\n";
    std::cout << "What do you want to do?\n";
    std::cout << "1: Attack\n"; //regular attack.
    std::cout << "2: Warp Strike (-10 Mana)\n"; //stronger attack, yet risking mana due to the RNG.
    std::cout << "3: Heal\n";
    std::cout << "\n";
}

void dragonMenu()
{
    std::cout << "\n";
    std::cout << "You have " << Player.hp << " health and " << Player.mana << " mana.\nThe DRAGON has " << Dragon.mhp << " health.\n\n";
    std::cout << "What do you want to do?\n";
    std::cout << "1: Attack\n"; //regular attack.
    std::cout << "2: Warp Strike (-10 Mana)\n"; //stronger attack, yet risking mana due to the RNG.
    std::cout << "3: Heal\n";
    std::cout << "\n";
}

void goblinSequence()
{
    while (Player.hp > 0 && Goblin.mhp > 0)
    {


        goblinMenu();

        std::cin >> choice;

        //The following switch statement allows the player to type out the number corresponding to their choice of action.
        //(see mainMenu(); function to understand each case)
        switch (choice) {
        case 1:
            Player.atk = rand() % 10;
            battleAnimation.attack();
            break;
        case 2:
            battleAnimation.warpattack();
            if (Player.mana < 10) {
                Player.atk = 0;
                std::cout << "You are unable to use warp strike, losing your chance of striking back!\n";
                break;
            }
            else if (Player.mana >= 10) {
                Player.atk = rand() % Player.warpstk;
                Player.mana = Player.mana - 10;
                break;
            }
        case 3:
            battleAnimation.Heal();
            Player.heal = rand() % Player.heal;
            Player.atk = 0;
            Player.hp = Player.heal + Player.hp;
            if (Player.hp > 50) {
                Player.hp = 50;
            }
            std::cout << "You were healed! " << Player.heal << " of your health was given back!\n";
            break;
        default:
            std::cout << "You hesistated, losing your chance of striking back!\n";
            Player.atk = 0;
            std::cin.clear();
            break;
        }

        //The following switch statement allows the computer to randomly pick a number from 1 to 3; that number will thus be the enemy's choice.
        eChoice = rand() % 4;

        switch (eChoice) {
        case 1:
            Goblin.matk = rand() % 10;
            break;
        case 2:
            Goblin.matk = rand() % Goblin.mwarpstk;
            break;
        case 3:
            Goblin.mheal = rand() % 10;
            Goblin.matk = 0;
            Goblin.mhp = Goblin.mheal + Goblin.mhp;
            if (Goblin.mhp > 40) {
                Goblin.mhp = 40;
            }
            std::cout << "The Goblin healed himself! " << Goblin.mheal << " of his health was given back!\n";
            break;
        }

        //The following lines will dictate the outcome of both characters. I defined eDamage and cDamage as the amount of damage that came from the opponent.

        eDamage = Player.atk;

        Goblin.mhp = Goblin.mhp - eDamage;

        if (Goblin.mhp < 1) {
            Goblin.mhp = 0;
            std::cout << ". ";
            Sleep(800);
            std::cout << ". ";
            Sleep(800);
            std::cout << ". ";
            Sleep(800);
            std::cout << "You took " << Goblin.matk << " damage, but...\n";
            std::cout << "you have killed the Goblin. Hurrah! You earned " << randomMoneyGen << " gold.\n";
            Player.money += randomMoneyGen;
            Sleep(1500);
            Player.atk = 10; //to fix any wrongdoings


        }
        else {
            std::cout << "You did " << eDamage << " damage against the Goblin. He now has " << Goblin.mhp << " health.\n";
        }

        cDamage = Goblin.matk;

        Player.hp = Player.hp - cDamage;

        if (Player.hp < 1) {
            std::cout << ". ";
            Sleep(800);
            std::cout << ". ";
            Sleep(800);
            std::cout << ". ";
            Sleep(800);
            std::cout << "The Goblin dealt " << cDamage << " damage. You have been killed.\n";
            Sleep(800);

        }
        else if (Player.hp > 0 && Goblin.mhp > 0) {
            std::cout << "The Goblin dealt " << cDamage << " damage against you! You now have " << Player.hp << " health.\n\n";
            system("pause");
            system("cls");

        }
    }
}

void giantSequence()
{
    while (Player.hp > 0 && Giant.mhp > 0)
    {


        giantMenu();

        std::cin >> choice;

        //The following switch statement allows the player to type out the number corresponding to their choice of action.
        //(see mainMenu(); function to understand each case)
        switch (choice) {
        case 1:
            Player.atk = rand() % 10;
            battleAnimation.attack();
            break;
        case 2:
            battleAnimation.warpattack();
            if (Player.mana < 10) {
                Player.atk = 0;
                std::cout << "You are unable to use warp strike, losing your chance of striking back!\n";
                break;
            }
            else if (Player.mana >= 10) {
                Player.atk = rand() % Player.warpstk;
                Player.mana = Player.mana - 10;
                break;
            }
        case 3:
            battleAnimation.Heal();
            Player.heal = rand() % Player.heal;
            Player.atk = 0;
            Player.hp = Player.heal + Player.hp;
            if (Player.hp > 50) {
                Player.hp = 50;
            }
            std::cout << "You were healed! " << Player.heal << " of your health was given back!\n";
            break;
        default:
            std::cout << "You hesistated, losing your chance of striking back!\n";
            Player.atk = 0;
            std::cin.clear();
            break;
        }

        //The following switch statement allows the computer to randomly pick a number from 1 to 3; that number will thus be the enemy's choice.
        eChoice = rand() % 4;

        switch (eChoice) {
        case 1:
            Giant.matk = rand() % 20;
            break;
        case 2:
            Giant.matk = rand() % Giant.mwarpstk;
            break;
        case 3:
            Giant.mheal = rand() % 5;
            Giant.matk = 0;
            Giant.mhp = Giant.mheal + Giant.mhp;
            if (Giant.mhp > 40) {
                Giant.mhp = 40;
            }
            std::cout << "The Giant healed himself! " << Giant.mheal << " of his health was given back!\n";
            break;
        }

        //The following lines will dictate the outcome of both characters. I defined eDamage and cDamage as the amount of damage that came from the opponent.

        eDamage = Player.atk;

        Giant.mhp = Giant.mhp - eDamage;

        if (Giant.mhp < 1) {
            Giant.mhp = 0;
            std::cout << ". ";
            Sleep(800);
            std::cout << ". ";
            Sleep(800);
            std::cout << ". ";
            Sleep(800);
            std::cout << "You took " << Giant.matk << " damage, but...\n";
            std::cout << "you have killed the Giant. Hurrah! You earned " << randomMoneyGen << " gold.\n";
            Player.money += randomMoneyGen;
            Sleep(1500);
            Player.atk = 10; //to fix any wrongdoings


        }
        else {
            std::cout << "You did " << eDamage << " damage against the Giant. He now has " << Giant.mhp << " health.\n";
        }

        cDamage = Giant.matk;

        Player.hp = Player.hp - cDamage;

        if (Player.hp < 1) {
            std::cout << ". ";
            Sleep(800);
            std::cout << ". ";
            Sleep(800);
            std::cout << ". ";
            Sleep(800);
            std::cout << "The Giant dealt " << cDamage << " damage. You have been killed.\n";
            Sleep(800);

        }
        else if (Player.hp > 0 && Giant.mhp > 0) {
            std::cout << "The Giant dealt " << cDamage << " damage against you! You now have " << Player.hp << " health.\n\n";
            system("pause");
            system("cls");

        }
    }
}

void dragonSequence()
{
    while (Player.hp > 0 && Dragon.mhp > 0)
    {


        dragonMenu();

        std::cin >> choice;

        //The following switch statement allows the player to type out the number corresponding to their choice of action.
        //(see mainMenu(); function to understand each case)
        switch (choice) {
        case 1:
            Player.atk = rand() % 20;
            battleAnimation.attack();
            break;
        case 2:
            battleAnimation.warpattack();
            if (Player.mana < 10) {
                Player.atk = 0;
                std::cout << "You are unable to use warp strike, losing your chance of striking back!\n";
                break;
            }
            else if (Player.mana >= 10) {
                Player.atk = rand() % Player.warpstk;
                Player.mana = Player.mana - 10;
                break;
            }
        case 3:
            battleAnimation.Heal();
            Player.heal = rand() % Player.heal;
            Player.atk = 0;
            Player.hp = Player.heal + Player.hp;
            if (Player.hp > 50) {
                Player.hp = 50;
            }
            std::cout << "You were healed! " << Player.heal << " of your health was given back!\n";
            break;
        default:
            std::cout << "You hesistated, losing your chance of striking back!\n";
            Player.atk = 0;
            std::cin.clear();
            break;
        }

        //The following switch statement allows the computer to randomly pick a number from 1 to 3; that number will thus be the enemy's choice.
        eChoice = rand() % 4;

        switch (eChoice) {
        case 1:
            Dragon.matk = rand() % 25;
            break;
        case 2:
            Dragon.matk = rand() % Dragon.mwarpstk;
            break;
        case 3:
            Dragon.mheal = rand() % 5;
            Dragon.matk = 0;
            Dragon.mhp = Dragon.mheal + Dragon.mhp;
            if (Dragon.mhp > 40) {
                Dragon.mhp = 40;
            }
            std::cout << "The Dragon healed himself! " << Dragon.mheal << " of his health was given back!\n";
            break;
        }

        //The following lines will dictate the outcome of both characters. I defined eDamage and cDamage as the amount of damage that came from the opponent.

        eDamage = Player.atk;

        Dragon.mhp = Dragon.mhp - eDamage;

        if (Dragon.mhp < 1) {
            Dragon.mhp = 0;
            std::cout << ". ";
            Sleep(800);
            std::cout << ". ";
            Sleep(800);
            std::cout << ". ";
            Sleep(800);
            std::cout << "You have killed the DRAGON! HURRAH!\n";
            Sleep(1500);
            Player.atk = 10; //to fix any wrongdoings


        }
        else {
            std::cout << "You did " << eDamage << " damage against the DRAGON. He now has " << Dragon.mhp << " health.\n";
        }

        cDamage = Dragon.matk;

        Player.hp = Player.hp - cDamage;

        if (Player.hp < 1) {
            std::cout << ". ";
            Sleep(800);
            std::cout << ". ";
            Sleep(800);
            std::cout << ". ";
            Sleep(800);
            std::cout << "The DRAGON dealt " << cDamage << " damage. You have been killed.\n";
            Sleep(800);

        }
        else if (Player.hp > 0 && Dragon.mhp > 0) {
            std::cout << "The DRAGON dealt " << cDamage << " damage against you! You now have " << Player.hp << " health.\n\n";
            system("pause");
            system("cls");

        }
    }
}