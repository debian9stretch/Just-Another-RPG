#pragma once

class Player;

class Enemy {
public:

		//	constructors

	Enemy(unsigned long l, unsigned long h, unsigned long a, unsigned long d, unsigned long s);
	Enemy();

		//battle functions

	unsigned long Damage();
	void attack(Player player);
	void takeDamage(unsigned long x);

	//	mutators/setters

	void setLv();
	void setSP();
	void setATK();
	void setDEF();
	void setMaxHP();

	//	accessors/getters


	long getLv();
	long getMaxHP();
	long getHealth();
	long Health();
	long getATK();
	long getDEF();
	long getSP();
	unsigned long xpToDrop();
	void update();

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