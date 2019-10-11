#pragma once
#include "enemy.hpp"

class Dragon : public Enemy {
public:

	Dragon();

	//new type of attack, will use for testing purposes
	void fireAttack(Player& player);
	unsigned long calcDragonLv();
	unsigned long calcDragonHP();
	unsigned long calcDragonATK();
	unsigned long calcDragonDEF();
	unsigned long calcDragonSP();

private:
	int dragonLv;
	int dragonHP;
	int dragonATK;
	int dragonSP;
	int specialDMG;
	int physicalDMG;
	int expToDrop;
};