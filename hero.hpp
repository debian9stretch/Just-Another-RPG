#pragma once

class Enemy;

class Item;

class Player {
public:

		//constructors

	Player();
	Player(unsigned long level, unsigned long health, unsigned long attack, unsigned long defense, unsigned long mana, unsigned long specialPower);
	
		//	battle functions

	long Damage();
	unsigned long Heal();
	void attack(Enemy& enemy);
	void magicAttack(Enemy& enemy);
	void takeDamage(unsigned long exp);

		//	mutators/setters

	void setHP();
	void update();
	void useItem(Item* item);
	void addXP(unsigned long x);
	unsigned long calcPlayerLv();
	unsigned long calcPlayerMaxHP();
	unsigned long calcPlayerATK();
	unsigned long calcPlayerDEF();
	unsigned long calcPlayerSP();
	unsigned long calcPlayerMP();

		//	accessors/getters

	long getHP();
	unsigned long getMaxHP();
	unsigned long getLv();
	unsigned long getDEF();
	unsigned long getMana();
	unsigned long getATK();
	unsigned long getSP();
	unsigned long getXP();

private:
	int baseXP=10;
	unsigned long playerExp = 0;
	unsigned long playerLv;
	unsigned long playerMaxMP;
	unsigned long playerMana;
	unsigned long heal;
	unsigned long damage;
	unsigned long playerATK;
	unsigned long maxHP;
	unsigned long playerHP;
	unsigned long magicDMG;
	unsigned long playerSP;
	unsigned long playerDEF;
};
