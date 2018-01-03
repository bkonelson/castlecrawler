#pragma once
#include <iostream>
#include <string>

using namespace std;

class Item {
private:
	string name;
	char type;
	bool pickUp;
public:
	Item(string name, char type = 'i', bool pickUp = false) : name(name), type(type), pickUp(pickUp) {}
	void allowPickUp() { pickUp = true; }
	bool canPickUp() { return pickUp; }
	string getName(){ return name; }
	char getType() { return type; }
	virtual void inspection() {
		cout << name << endl;
	}
};

class Armor : public Item {
public:
	int armorRating;
	Armor(string name, int armor, bool pickUp = false, char type='a') : Item(name,type,pickUp), armorRating(armor) {}
	void inspection() {
		Item::inspection();
		cout << "Armor: " << armorRating << endl;
	}
};

class Ring : public Item {
public:
	int armorRating;
	bool fireImmune;
	bool poisonImmune;
	Ring(string name, int armor = 0, bool poison = false, bool fire = false, bool pickUp = false, char type = 'r')
		: Item(name,type,pickUp), armorRating(armor), poisonImmune(poison), fireImmune(fire) {}
	void inspection() {
		Item::inspection();
		if (armorRating != 0) {
			cout << "Armor: " << armorRating << endl;
		}
		if (poisonImmune) {
			cout << "Immunity to Poison" << endl;
		}
		if (fireImmune) {
			cout << "Immunity to Fire" << endl;
		}
	}
};

class Weapon : public Item {
public:
	int damage;
	int armorPen;
	int pDamage;
	int fDamage;
	int condition;
	Weapon(string name, int damage, int armp = 0, int pDam = 0, int fDam = 0, int cond = 5, bool pickUp = false, char type = 'w')
		: Item(name,type,pickUp), damage(damage), armorPen(armp), pDamage(pDam), fDamage(fDam), condition(cond) {}
	void inspection() {
		Item::inspection();
		cout << "Damage: " << damage << endl;
		cout << "Condition: " << condition << endl;
		if (armorPen != 0) {
			cout << "Armor Damage: " << armorPen << endl;
		}
		if (pDamage != 0) {
			cout << "Poison Damage: " << pDamage << endl;
		}
		if (fDamage != 0) {
			cout << "Fire Damage: " << fDamage << endl;
		}
	}
};

class Potion : public Item {
private:
	int fixHP;
	int fixCondition;
public:
	Potion(string name, int fixHP, int fixCond = 0, char type = 'p', bool pickUp = false) : 
		Item(name,type,pickUp), fixHP(fixHP), fixCondition(fixCond) {}
	int qhp() { return fixHP; }
	int qc() { return fixCondition; }
	void inspection() {
		Item::inspection();
		if (fixHP > 0) {
			cout << "Restores " << fixHP << " HP when used." << endl;
		}
		if (fixCondition > 0) {
			cout << "Restores " << fixCondition << " condition to equipped weapon." << endl;
		}
	}
};