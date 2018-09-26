#include <iostream>
#include <string>
#include "battlesystem.hpp"
#include "enemy.hpp"
#include "hero.hpp"

int main(int argc, char const *argv[]) {

	Player player;
	std::cout << "\nWelcome. You wake up in a place you've never seen before, and this land once unbeknownst to you is filled with strange creatures. \nYou look around, and there is a river to your right filled with the most plump looking fish.\nTo your left is a field with a huge open expanse that stretches on for miles, fairies fluttering in the wind while gracing\nthe land and animals with their magic and presence.\nThere also appear to be dangerous animals such as dragons very far off in the distance.\nIn front of you is mountain range with the purest white snow-capped peaks, and you can\nsee all sorts of flying animals in the sky. It truly is a beautiful sight.\nSo, where would you like to go?\n";
	for (;;) {
		std::cout << "\nNorth, West, East, or South? ";
		std::string direction;
		std::cin >> direction;
		std::cout << "\n";
		if (direction == "West" || direction == "west") {
			std::cout << "\nYou look to your left towards the massive open expanse,\nand realize it's probably a bad idea in your current\ncondition to go that way right now.\n";
			battle(player);
			std::cout << "You have slain the enemy, and now you are tired. You decide to go to sleep. As you fall asleep under the mystic willow tree,\n you feel uneasy. When you come to, there is another enemy standing over you!\n";
			battle(player);
			std::cout << "After defeating the enemy, you are exhausted. 'What was that? Where am I?'\n All these questions race by in your mind as you get lulled to sleep by nature under the \n mystic willow tree. When you come to, you see an enemy charging! Prepare for battle!\n";
			battle(player);
			break;
		}
		else if (direction == "South" || direction == "south") {
			std::cout << "You look behind you and see something you didn't notice before.\nThere's an abandoned looking village hidden under the shroud of a beautiful forest.\nI'd be careful though, because it looks like you could get lost easily.\n";
			break;
		}
		else if (direction == "East" || direction == "east") {
			std::cout << "You walk up to the river to get a drink. Man are you thirsty!\nAfter drinking some water, you remember about the fish and consider catching one. What do you want to do?\n";
			break;
		}
		else if (direction == "North" || direction == "north") {
			std::cout << "Traveling north will take a few days time in your current condition, and although\nthe view is beautiful you're also not up to a fight if anything happens.\nI'd like you to reconsider.";
			break;
		}
		else {
			std::cout << "That's not a direction. Try again.\n";
		}
	}
	return 0;
}

/*

			What I want is to make an area base level (classes and inheritance?) and use that to determine enemy level.
			Something like

				enemyLv = areaBase+rand()%areaBase+1


*/
