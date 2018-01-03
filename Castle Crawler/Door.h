#pragma once
#include <iostream>
#include <string>
#include "puzzle.h"
#include "Item.h"

using namespace std;

class Door {
public:
	string location;
	Item* key;
	puzzle* puz;
	bool invulnerable;
	int hp;
	bool locked;
	Door(string loc, bool inv, int hp, bool locked, Item* key = nullptr, puzzle* puzzle = nullptr) 
		: location(loc), invulnerable(inv), hp(hp), locked(locked), key(key), puz(puzzle) {}
	void unlock();
	void damageItem(Weapon* w);
	void takeDamage(int damage);
	string getLoc() { return location; }
	void inspection();
};