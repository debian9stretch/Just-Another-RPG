#include <cstdlib>
#include <cmath>
#include "enemy.hpp"
#include "hero.hpp"

Player player;


	//constructors

Enemy::Enemy(unsigned long l, unsigned long h, unsigned long a, unsigned long d, unsigned long s){
	enemyLv = l;
	currentEnemyHP = h;
	maxEnemyHP = currentEnemyHP;
	enemyATK = a;
	enemyDEF = d;
	enemySP = s;
}

Enemy::Enemy(){
	enemyLv = 2;
	maxEnemyHP = 20;
	currentEnemyHP = maxEnemyHP;
	enemyATK = 7;
	enemyDEF = 6;
	enemySP = 7;
}


	//functions for operational fight


void Enemy::attack(Player& player){
	player.takeDamage(Damage());
}

unsigned long Enemy::Damage(){
	enemyDMG = (1 + pow((enemyATK / 9) , 1.5) + rand()%10);
	return enemyDMG;
}

void Enemy::takeDamage(unsigned long x){
	currentEnemyHP-=x;
}


	//stats getters


void Enemy::setLv(Player& player){
	enemyLv=player.getLv()*1.5;
}

void Enemy::setMaxHP(){
	maxEnemyHP = 1+pow((enemyLv/1.9),3);
}

void Enemy::setATK(){
	enemyATK = 1+pow((enemyLv/4.9),2);
}

void Enemy::setDEF(){
	enemyDEF = 1+pow((enemyLv/4.5),1.9);
}

void Enemy::setSP(){
	enemySP = 1+pow((enemyLv/5),2);
}

unsigned long Enemy::xpToDrop(){
	expToDrop = (1 + pow( ( (enemyLv / 2) + ( rand() % (player.getLv() * 10) ) ), 2.6) * 4);
	return expToDrop;
}


	//stat getters


long Enemy::getLv(){
	return enemyLv;
}

long Enemy::getMaxHP(){
	return maxEnemyHP;
}

long Enemy::getHealth(){
	return currentEnemyHP;
}

long Enemy::getATK(){
	return enemyATK;
}

long Enemy::getDEF(){
	return enemyDEF;
}

long Enemy::getSP(){
	return enemySP;
}

void Enemy::update() {
	enemyLv=enemyLv*1.5;
	setMaxHP();
	setATK();
	setDEF();
	setSP();
	xpToDrop();
}
