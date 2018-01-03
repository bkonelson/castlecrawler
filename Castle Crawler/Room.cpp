#include <iostream>
#include <string>
#include <iomanip>
#include "Room.h"
using namespace std;
	
void Room::addFurn(Furnishing* F1, Furnishing* F2, Furnishing* F3, Furnishing* F4, Furnishing* F5, Furnishing* F6, Furnishing* F7) {
	stuff.push_back(F1);
	if (F2) stuff.push_back(F2);
	if (F3) stuff.push_back(F3);
	if (F4) stuff.push_back(F4);
	if (F5) stuff.push_back(F5);
	if (F6) stuff.push_back(F6);
	if (F7) stuff.push_back(F7);
}

void Room::addDoor(Door* D1, Door* D2, Door* D3, Door* D4) {
	doors.push_back(D1);
	if (D2) doors.push_back(D2);
	if (D3) doors.push_back(D3);
	if (D4) doors.push_back(D4);
}

void Room::addMonster(Monster* M1, Monster* M2, Monster* M3, Monster* M4, Monster* M5, Monster* M6, Monster* M7) {
	monsters.push_back(M1);
	if (M2) monsters.push_back(M2);
	if (M3) monsters.push_back(M3);
	if (M4) monsters.push_back(M4);
	if (M5) monsters.push_back(M5);
	if (M6) monsters.push_back(M6);
	if (M7) monsters.push_back(M7);
}

int Room::go(string s) {
	for (int i = 0; i < doors.size(); i++) {
		if (doors[i]->location == s || doors[i]->location + " door" == s) {
			if (doors[i]->locked != true) {
				if (s == "north door" || s == "north") {
					return north;
				}
				else if (s == "south door" || s == "south") {
					return south;
				}
				else if (s == "east door" || s=="east") {
					return east;
				}
				else {
					return west;
				}
			}
			else {
				cout << "The " << s << " door is locked" << endl;
				return 0;
			}
		}
	}
	cout << "There is not a door in that direction." << endl;
	return 0;
}

void Room::attack(string s, character* P1) {
	for (int i = 0; i < monsters.size(); i++) {
		if (monsters[i]->name == s) {
			int damage = P1->damage;
			int arpen = 0, fire = 0, poison = 0;
			if (P1->myWeapon) {
				arpen = P1->myWeapon->armorPen;
				fire = P1->myWeapon->fDamage;
				poison = P1->myWeapon->pDamage;
			}
			monsters[i]->defend(damage, arpen, poison, fire);
			if (P1->myWeapon && P1->myWeapon->condition > 0) {
				P1->myWeapon->condition -= 1;
				cout << P1->myWeapon->getName() << " conditon is " << P1->myWeapon->condition << endl;
				if (P1->myWeapon->condition == 0) {
					cout << P1->myWeapon->getName() << " broke. (1/2 damage)" << endl;
					P1->myWeapon->damage /= 2;
					P1->updateStats();
				}
			}
			if (monsters[i]->hp <= 0) {
				cout << monsters[i]->name << " has been defeated!" << endl;
				for (auto item : monsters[i]->items) {
					item->allowPickUp();
					P1->bag.push_back(item);
					cout << "You have aquired - " << item->getName() << endl;
				}
				monsters.erase(monsters.begin() + i);
			}
			else {
				cout << "Your attack leaves " << monsters[i]->name << " with " << monsters[i]->hp << " HP." << endl;
				monsterAttack(monsters[i], P1);
			}
			return;
		}
	}
	for (int i = 0; i < doors.size(); i++) {
		if (doors[i]->location == s || doors[i]->location + " door" == s) {
			doors[i]->takeDamage(P1->damage);
			if (P1->myWeapon) {
				doors[i]->damageItem(P1->myWeapon);
				P1->updateStats();
			}
			return;
		}
	}
	for (int i = 0; i < stuff.size(); i++) {
		if (stuff[i]->getName() == s) {
			stuff[i]->takeDamage(P1->damage);
			if (P1->myWeapon) {
				stuff[i]->damageItem(P1->myWeapon);
				P1->updateStats();
			}
			return;
		}
	}
	cout << "Cannot attack " << s << ". That does not exist in this room." << endl;
}

void Room::monsterAttack(Monster* M, character* P1) {
	P1->defend(M->damage,M->fireDamage, M->poisonDamage);
	if (P1->hp <= 0) {
		cout << M->name << " has prevailed :(   You have died." << endl;
		cout << "Game Over" << endl;
		string something;
		cin.ignore();
		getline(cin,something);
		exit(0);
	}
	cout << M->name << " attacks leaving you with " << P1->hp << " HP." << endl;
}

void Room::displaySearch() {
	cout << "The " << name << " contains: " << endl;
	cout << "Doors:  ";
	bool secLoop = false;
	for (auto door : doors) {
		if (secLoop)
			cout << ", ";
		cout << door->location << " door";
		secLoop = true;
	}
	secLoop = false;
	cout << "\nFurnishings:  ";
	for (auto things : stuff) {
		if (secLoop)
			cout << ", ";
		cout << things->getName();
		secLoop = true;
	}
	secLoop = false;
	cout << "\nMonsters:  ";
	for (auto enemies : monsters) {
		if (secLoop)
			cout << ", ";
		cout  << enemies->name;
		secLoop = true;
	}
	cout << endl;
}



void Room::unlockDoor(string s) {
	for (int i = 0; i < doors.size(); i++) {
		if (doors[i]->location + " door" == s) {
			doors[i]->unlock();
			cout << s << " has been unlocked" << endl;
			return;
		}
	}
}

Door* Room::getDoor(string s) {
	for (auto door : doors) {
		if (s == door->location + " door") {
			return door;
		}
	}
	cout << "There is not a door in that direction" << endl;
	return nullptr;
}

Item* Room::getChestKey(string s) {
	for (auto chest : stuff) {
		if (s == chest->getName()) {
			return chest->getKey();
		}
	}
	return nullptr;
}

void Room::unlockChest(string s) {
	for (auto chest : stuff) {
		if (s == chest->getName()) {
			return chest->unlockChest();
		}
	}
}

Furnishing* Room::getFurn(string s) {
	for (auto item : stuff) {
		if (s == item->getName()) {
			return item;
		}
	}
	return nullptr;
}

void Room::openContainer(string s) {
	for (auto item : stuff) {
		if (s == item->getName()) {
			item->showContents();
			return;
		}
	}
	cout << s << " cannot be searched or doesn't exist." << endl;
}

void Room::getItemFromChest(string s, character* p1) {
	for (auto chest : stuff) {
		if (chest->isItem(s)) {
			p1->addItemtoBag(chest->getItem(s));
			return;
		}
	}
	cout << s << " doesn't exist here." << endl;
}

bool Room::inspect(string s) {
	for (auto door : doors) {
		if (s == door->location + " door") {
			door->inspection();
			return true;
		}
	}
	for (auto things : stuff) {
		if (s == things->getName()) {
			things->inspection();
			return true;
		}
	}
	for (auto enemies : monsters) {
		if (s == enemies->name) {
			enemies->inspection();
			return true;
		}
	}
	return false;
}
