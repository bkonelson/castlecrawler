#pragma once
#include <iostream>
#include <string>
#include <list>
#include "Item.h"

using namespace std;

class character {
public:
	string name;
	int hp = 10;
	int maxHP = hp;
	int armorRating = 0;
	int damage = 1;
	Weapon* myWeapon;
	Armor* myArmor;
	Ring* myRing;
	list<Item*> bag;
	bool fireImmune = false;
	bool poisonImmune = false;
	character(string name) : name(name) {}
	void help();
	void addItemtoBag(Item* i);
	void lookinbag();
	void defend(int dam, int fDam, int pDam);
	void getStats();
	void updateStats();
	void inspectItem(string s);
	bool hasKey(Item* i);
	void equipItem(string s);
	void usePotion(string s);
};
