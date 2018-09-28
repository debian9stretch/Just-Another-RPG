#pragma once

class Player;

class Enemy {
public:

		//	constructors

	Enemy(unsigned long l, unsigned long h, unsigned long a, unsigned long d, unsigned long s);
	Enemy();

		//battle functions

	unsigned long Damage();
	void attack(Player& player);
	void takeDamage(unsigned long x);

	//	mutators/setters

	unsigned long calcEnemyLv();
	unsigned long calcEnemySP();
	unsigned long calcEnemyATK();
	unsigned long calcEnemyDEF();
	unsigned long calcEnemyMaxHP();

	//	accessors/getters


	long getLv();
	long getMaxHP();
	long getHealth();
	long getATK();
	long getDEF();
	long getSP();
	unsigned long xpToDrop();
	void update(Player& player);

private:

	unsigned long health;

	unsigned long enemySP;

	unsigned long enemyATK;
	
	unsigned long enemyDMG;
	
	unsigned long enemyDEF;

	unsigned long enemyLv;

	unsigned long expToDrop;

	unsigned long maxEnemyHP;

	unsigned long currentEnemyHP;
};
