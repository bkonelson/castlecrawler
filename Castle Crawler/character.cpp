#include <iostream>
#include <string>
#include <iomanip>
#include "character.h"
using namespace std;

void character::help() {
	cout << string(60, '-') << endl;
	cout << "Commands are 1 word followed by an object, seperated by a space" << endl;
	cout << "Available commands are:\n"; 
	cout << setw(20) << left << "go" << setw(20) << "attack" << setw(20) << "search" << endl; 
	cout << setw(20) << "inspect" << setw(20) << "get" << setw(20) << "equip" << endl;
	cout << setw(20) << "potion" << setw(20) << "open" << setw(20) << "unlock" << endl;
	cout << "To view your character sheet/look at stats type:   cs" << endl;
	cout << "To view your current inventory type:   bag" << endl;
	cout << "To use a potion type:  potion  (follewed by the name of the potion)" << endl;
	cout << "Monsters will only attack you if you attack them, some of them have interesting or necessary items though" << endl;
	cout << string(60, '-') << endl;
}

void character::defend(int dam, int fDam, int pDam) {
	hp -= (dam - armorRating > 0) ? dam-armorRating : 0;
	if (!fireImmune) {
		hp -= fDam;
	}
	if (!poisonImmune) {
		hp -= pDam;
	}
}

void character::getStats() {
	string fire = (fireImmune) ? "Yes" : "No";
	string poison = (poisonImmune) ? "Yes" : "No";
	cout << name << "\nHP: " << hp << "\nArmorRating: " << armorRating << "\nDamage: " << damage;
	cout << "\nFire Immunity: " << fire;
	cout << "\nPoison Immunity: " << poison << endl;
	if (myArmor) {
		cout << "Armor: " << myArmor->getName() << endl;
	}
	if (myWeapon) {
		cout << "Weapon: " << myWeapon->getName() << endl;
	}
	if (myRing) {
		cout << "Ring: " << myRing->getName() << endl;
	}
}

void character::lookinbag() {
	cout << "Bag contains: " << endl;
	for (auto item : bag) {
		cout << item->getName() << endl;
	}
}

void character::inspectItem(string s) {
	for (auto item : bag) {
		if (s == item->getName()) {
			item->inspection();
			return;
		}
	}
	if (myWeapon && s == myWeapon->getName()) {
		myWeapon->inspection();
		return;
	}
	if (myArmor && s == myArmor->getName()) {
		myArmor->inspection();
		return;
	}
	if (myRing && s == myRing->getName()) {
		myRing->inspection();
		return;
	}
	cout << s << " doesn't seem to be an object or item here." << endl;
}

bool character::hasKey(Item* i) {
	for (auto item : bag) {
		if (i == item) {
			return true;
		}
	}
	return false;
}

void character::addItemtoBag(Item* i) {
	for (auto item : bag) {
		if (item == i) {
			cout << "You already have " << i->getName() << endl;
			return;
		}
	}
	bag.push_back(i);
}

void character::equipItem(string s) {
	if ((myWeapon && s == myWeapon->getName()) || (myArmor && s == myArmor->getName()) || (myRing && s == myRing->getName())) {
		cout << s << " is already equipped.";
		return;
	}
	for (auto item : bag) {
		if (item->getName() == s) {
			if (item->getType() == 'a') {
				if (!myArmor) {
					myArmor = (Armor*)item;
				}
				else if (myArmor == item) {}
				else {
					addItemtoBag(myArmor);
					myArmor = (Armor*)item;
				}
				cout << item->getName() << " equipped!." << endl;
			}
			else if (item->getType() == 'r') {
				if (!myRing) {
					myRing = (Ring*)item;
				}
				else if (myRing == item) {}
				else {
					addItemtoBag(myRing);
					myRing = (Ring*)item;
				}
				cout << item->getName() << " equipped!." << endl;
			}
			else if (item->getType() == 'w') {
				if (!myWeapon) {
					myWeapon = (Weapon*)item;
				}
				else if (myWeapon == item) {}
				else {
					addItemtoBag(myWeapon);
					myWeapon = (Weapon*)item;
				}
				cout << item->getName() << " equipped!." << endl;
			}
			else {
				cout << item->getName() << " cannot be equipped." << endl;
				return;
			}
			bag.remove(item);
			updateStats();
			return;
		}
	}
	cout << "You don't have a " << s << " ...whatever it is." << endl;
}

void character::updateStats() {
	if (myArmor) {
		armorRating = myArmor->armorRating;
	}
	if (myWeapon) {
		damage = 1 + myWeapon->damage;
	}
	if (myRing) {
		armorRating = myRing->armorRating;
		poisonImmune = myRing->poisonImmune;
		fireImmune = myRing->fireImmune;
	}
	if (myArmor && myRing) {
		armorRating = myArmor->armorRating + myRing->armorRating;
	}
}

void character::usePotion(string s) {
	for (auto item : bag) {
		if (item->getName() == s) {
			if (item->getType() == 'p') {
				Potion* potion = (Potion*)item;
				if (potion->qhp() > 0) {
					hp += potion->qhp();
					cout << "Potion restored " << potion->qhp() << " HP." << endl;
					if (hp >= maxHP) {
						hp = maxHP;
						cout << "You are at Maximum HP" << endl;
					}
				}
				if (potion->qc() > 0) {
					if (myWeapon->condition > 0) {
						myWeapon->condition += potion->qc();
						cout << "Potion restored " << potion->qc() << " conditon to " << myWeapon->getName() << endl;
					}
					else {
						cout << "Cannot restore broken weapons." << endl;
						return;
					}
				}
				bag.remove(item);
				return;
			}
			cout << s << " is not a potion." << endl;
			return;
		}
	}
	cout << "You do not have " << s << endl;
}