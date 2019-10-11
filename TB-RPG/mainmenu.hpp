#pragma once

class Player;

class MainMenu {
public:

	//constructor
	MainMenu();

	//hard to do in the construtor because I'm dumb
	void openMainMenu();
	
	void start();

	void newGame();

	//methods for handling game startup
	void load(Player& player);
};