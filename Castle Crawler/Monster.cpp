#include <iostream>
#include <string>
#include "Monster.h"
using namespace std;

void Monster::defend(int dam, int arpen, int pDam, int fDam) {
	armorRating -= arpen;
	hp -= (dam - armorRating > 0) ? dam - armorRating : 0;
	if (!fireImmune) {
		hp -= fDam;
	}
	if (!poisonImmune) {
		hp -= pDam;
	}
}

void Monster::inspection() {
	string fire = (fireImmune) ? "Yes" : "No";
	string poison = (poisonImmune) ? "Yes" : "No";
	cout << name << "\nHP: " << hp << "\nArmor: " << armorRating;
	cout << "\nDamage: " << damage << "  fire: " << fireDamage << "  poison: " << poisonDamage;
	cout << "\nFire Immunity: " << fire;
	cout << "\nPoison Immunity: " << poison << endl;
}

void Monster::addItem(Item* i1, Item* i2, Item* i3, Item* i4, Item* i5) {
	items.push_back(i1);
	if (i2) items.push_back(i2);
	if (i3) items.push_back(i3);
	if (i4) items.push_back(i4);
	if (i5) items.push_back(i5);
}