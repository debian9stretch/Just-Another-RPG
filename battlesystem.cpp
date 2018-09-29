#include <iostream>
#include <string>
#include <fstream>
#include <random>
#include <ctime>
#include "enemy.hpp"
#include "hero.hpp"

int battle(Player& player){

	//make an object of enemy to fight
	Enemy enemy;

	//update enemy so it'll appear a random level
	
	//	uniform_int_distribution didn't *quite* work. Ask Jack later
	enemy.update(player);

	//introduce and start the battle loop
	std::cout << "\nIt seems you've encountered an enemy! Its level is " << enemy.getLv() << " and it has " << enemy.getHealth() 
	<< " health!\n Your level is " << player.getLv() << ".\n";

	//have it loop infinitely for obvious reasons
	for (;;) {
		std::string choice;
		//loop battle options with cin so there's no infinite loop here
		for(;;) {
			std::cout << "\nWhat do you do? Attack or Heal? ";
			std::cin >> choice;
			std::cout << "\n";

			//provide options for battle
			if(choice=="Attack"||choice=="attack") {
				player.attack(enemy);
				std::cout << "You attacked the enemy! " << "The enemy has " << enemy.getHealth() << " health left!\n";
				break;
			}
			else if(choice=="Heal"||choice=="heal") {
				player.Heal();
				if (player.getHP()>player.getMaxHP()){
					player.setHP();
					std::cout << "You healed and are feeling reinvigorated! You now have " << player.getHP() << " health!\n";
				}
				break;
			}
			else if (choice=="Magic"||choice=="magic") {
				player.magicAttack(enemy);
				std::cout << "Your magic dealt significant damage to the enemy! The enemy has " << enemy.getHealth() << " left!\n";
				break;
			}
			else if (choice == "exit") {
				return 0;
			}
			else {
				std::cout << "That's not a command. Re-enter your choice.\n";
			}
		}

		if (player.getHP()<=0||enemy.getHealth()<=0) {
			if (enemy.getHealth()<=0){
				player.addXP(enemy.xpToDrop());
				player.update();
				enemy.update(player);
				std::cout << "You have slain the enemy! Congratulations!\n";
				std::cout << "You have gained " << enemy.xpToDrop() << " experience!\n";
				std::cout << "You are now level " << player.getLv() << "\n";


				std::cout << "Your stats are as follows. \nHealth: " << player.getHP() << "\nAttack: " << player.getATK()
				<< "\nDefense: " << player.getDEF() << "\nMana: " << player.getMana()
				<< "\nAverage damage dealt per hit: " << player.Damage();
				std::cout << "\n";

				std::cout << "Your enemy's stats are as follows. \nLevel: " << enemy.getLv()
				<< "\nHealth: " << enemy.getHealth() << "\nAttack: " << enemy.getATK()
				<< "\nDefense: " << enemy.getDEF() << "\nAverage damage dealt per hit: " << enemy.Damage();
				std::cout << "\n";
				break;
			}
			if (player.getHP()<=0) {
				std::cout << "You have been defeated...\n";
				break;
			}
		}
		enemy.attack(player);
		std::cout << "The enemy has attacked you!\n";
		std::cout << "You have " << player.getHP() << " HP left!\n";
	}
	std::ofstream saveFile;
	saveFile.open("stats.txt");

		saveFile << player.getXP() << "\n" << player.getLv()
		<< player.getMaxHP() << "\n" << player.getATK()
		<< player.getDEF() << "\n" << player.getSP()
		<< "\n" << player.getMana() << "\n";
	
	saveFile.close();

	return 0;
}

/*
	Instantiate multiple enemy class objects using:
	std::vector<T> v(objCount);
	
*/