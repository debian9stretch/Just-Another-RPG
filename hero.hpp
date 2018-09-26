#pragma once

class Enemy;

class Player {
public:

		//constructors

	Player();
	Player(unsigned long l, unsigned long h, unsigned long a, unsigned long d, unsigned long m, unsigned long s);
	
		//battle functions

	void run();
	long Damage();
	unsigned long Heal();
	void attack(Enemy& enemy);
	void magicAttack(Enemy& enemy);
	void takeDamage(unsigned long x);
	void hpCheck();

		//	mutators/setters

	void setLv();
	long setMaxHP();
	void setATK();
	void setDEF();
	void setSP();
	void setMana();
	void update(Enemy& enemy);
	void setXP(unsigned long x);

		//	accessors/getters

	unsigned long getLv();
	unsigned long getDEF();
	unsigned long getMana();
	unsigned long getATK();
	unsigned long getSP();
	long getMaxHP();
	long getHP();

private:
	int baseXP=10;
	unsigned long playerLv;
	unsigned long playerExp=0;
	unsigned long playerMana;
	unsigned long heal;
	unsigned long damage;
	unsigned long playerATK;
	unsigned long health;
	unsigned long maxHP;
	unsigned long playerHP;
	unsigned long magicDMG;
	unsigned long playerSP;
	unsigned long playerDEF;
};