#include <iostream>
#include <cstdlib>
#include <cmath>
#include "hero.hpp"
#include "enemy.hpp"

Enemy enemy;

	//	constructors

Player::Player(unsigned long l, unsigned long h, unsigned long a, unsigned long d, unsigned long m, unsigned long s){
	playerLv = l;
	playerHP = h;
	playerATK = a;
	playerDEF = d;
	playerMana = m;
	playerSP = s;
}

Player::Player(){
	playerLv = 1;
	playerHP = 15;
	maxHP = playerHP;
	playerATK = 5;
	playerDEF = 4;
	playerMana = 10;
	playerExp = 0;
	playerSP = 7;
}


	//battle functions


void Player::takeDamage(unsigned long x){
	playerHP -= x;
}

unsigned long Player::Heal(){
	heal = ((pow(playerLv,1.9)+rand()%(playerLv*10)-1)+(playerMana))/2;
	playerHP+=heal;
	return heal;
}

void Player::attack(Enemy enemy){
	damage = ((playerATK*2)+(rand()%(playerLv*10)-1))+1;
	enemy.takeDamage(Damage());
}

unsigned long Player::magic(){
	magicDMG = ((pow((playerLv/1.3),1.9)+rand()%(playerLv*10)-1)+(playerMana))/2;
	enemy.takeDamage(magicDMG);	
	return magicDMG;
}

void Player::hpCheck(){
	playerHP=getMaxHP();
}


	//stat mutators  (setters)


void Player::setLv(){
	playerLv=pow((playerExp+1)/5, 0.4)+1;
}

long Player::setMaxHP(){
	maxHP = pow((playerLv/1.2),2)+15;
	return maxHP;
}

void Player::setATK(){
	playerATK = (((pow((playerLv/1.5),2))-(playerLv/1.5))+6)/2;
}

void Player::setDEF(){
	playerDEF = ((pow((playerLv/1.6),2)-(playerLv/1.6))+6)/2;
}

void Player::setSP(){
	playerSP = ((pow((playerLv/1.1),2)-(playerLv/1.2))+6)/2;
}

void Player::setMana(){
	playerMana = ((pow((playerLv/1.1),2)-(playerLv/1.2))+6)/2;
}

void Player::setXP(unsigned long x){
	playerExp+=x;
}


	//stat accessors  (getters)


long Player::Damage(){
	return damage;
}

unsigned long Player::getLv(){
	return playerLv;
}

long Player::getMaxHP(){
	return maxHP;
}

long Player::getHP(){
	return playerHP;
}

unsigned long Player::getATK(){
	return playerATK;
}

unsigned long Player::getDEF(){
	return playerDEF;
}

unsigned long Player::getSP(){
	return playerSP;
}

unsigned long Player::getMana(){
	return playerMana;
}

void Player::update(){
	setXP(enemy.xpToDrop());
	playerLv = pow((playerExp+1)/5,0.4)+1;
	maxHP = pow((playerLv/1.2),2)+15;
	playerATK = ((pow((playerLv/1.5),2)-(playerLv/1.5))+6)/2;
	playerDEF = ((pow((playerLv/1.6),2)-(playerLv/1.6))+6)/2;
	playerSP = ((pow((playerLv/1.1),2)-(playerLv/1.2))+6)/2;
	playerMana = ((pow((playerLv/1.1),2)-(playerLv/1.2))+6)/2;
} 

/*

		//STAT DECLARATIONS DON'T LOSE

		playerLv=pow((playerExp+1)/5, 0.4)+1;
		maxHP = pow((playerLv/1.2),2)+15;
		playerATK = ((pow((playerLv/1.5),2)-(playerLv/1.5))+6)/2;
		playerDEF = ((pow((playerLv/1.6),2)-(playerLv/1.6))+6)/2;
		playerSP = ((pow((playerLv/1.1),2)-(playerLv/1.2))+6)/2;
		playerMana = ((pow((playerLv/1.1),2)-(playerLv/1.2))+6)/2;

		//DON'T LOSE
*/