#include <iostream>
#include <string>
#include "battlesystem.hpp"
#include "enemy.hpp"
#include "hero.hpp"

int Battle::battle(){
	//make an object for player and enemy alike
	Player player;
	Enemy enemy;

	//introduce and start the battle loop
	std::cout << "\nIt seems you've encountered an enemy! Its level is " << enemy.getLv() << " and it has " << enemy.getHealth() << " health!\n";

	//have it loop infinitely for obvious reasons
	for (;;){
		std::string choice;
		//loop battle options with cin so there's no infinite loop here
		for(;;){
			std::cout << "\nWhat do you do? Attack or Heal? ";
			std::cin >> choice;	
			std::cout << "\n";

			//provide options for battle
			if(choice=="Attack"||choice=="attack"){
				player.attack(enemy);
				std::cout << "You attacked the enemy! " << "The enemy has " << enemy.getHealth() << " health left!\n";
				break;
			}
			else if(choice=="Heal"||choice=="heal"){
				player.Heal();
				std::cout << "You healed and are feeling reinvigorated! You now have " << player.getHP() << " health!\n";
				if (player.getHP()>player.getMaxHP())
				{
					player.hpCheck();
				}
				break;
			}
			else if (choice=="Magic"||choice=="magic")
			{
				player.magic();
				std::cout << "Your magic dealt " << player.magic() << " damage to the enemy! The enemy has " << enemy.getHealth() << " left!\n";
				break;
			}
			else{
				std::cout << "That's not a command. Re-enter your choice.\n";
			}
		}	

		if (player.getHP()<=0||enemy.getHealth()<=0){
			if (enemy.getHealth()<=0){
				player.update();
				enemy.update();
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
			if (player.getHP()<=0){
				std::cout << "You have been defeated...\n";
				break;
			}
		}
		enemy.attack(player);
		std::cout << "The enemy has attacked you!\n";
		std::cout << "You have " << player.getHP() << " HP left!\n";
	}
	return 0;
}
//playerXP doesn't carry over between battles because it's a different scope. Need to either save between fight and game
//or make playerExp persistent otherwise