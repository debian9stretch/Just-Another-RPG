#include <iostream>
#include <fstream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "mainmenu.hpp"
#include "hero.hpp"

class Player;

MainMenu::MainMenu() {

}

void MainMenu::openMainMenu() {
	sf::Image image;
	sf::Texture texture;
	image.loadFromFile("test.jpg");
	texture.loadFromImage(image);
}

void MainMenu::start() {

}

void MainMenu::newGame() {

}

void MainMenu::load(Player& player) {
	unsigned long firstNumber;
	std::ifstream saveFile;
	saveFile.open("stats.txt");
	saveFile >> firstNumber;
	player.addXP(firstNumber);
	player.update();
	saveFile.close();
}