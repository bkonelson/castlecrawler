#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Item.h"
using namespace std;

class Monster {
public:
	string name;
	int hp;
	int armorRating;
	int damage;
	int fireDamage;
	int poisonDamage;
	bool fireImmune;
	bool poisonImmune;
	vector<Item*> items;
	Monster(string name, int hp, int armor, int damage, int fDam = 0, int pDam = 0, bool fire = false, bool poison = false) 
		: name(name), hp(hp), armorRating(armor), damage(damage), fireDamage(fDam), poisonDamage(pDam), fireImmune(fire), poisonImmune(poison) {}
	void defend(int dam, int arpen, int pDam, int fDam);
	void inspection();
	void addItem(Item* i1, Item* i2 = nullptr, Item* i3 = nullptr, Item* i4 = nullptr, Item* i5 = nullptr);
};