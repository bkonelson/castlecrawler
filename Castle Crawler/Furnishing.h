#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "puzzle.h"
#include "Item.h"
using namespace std;

class Furnishing {
private:
	string name;
	bool invulnerable;
	int hp;
	bool destroyed;
public:
	Furnishing(string name, bool inv, int hp, bool dest = false) : name(name), invulnerable(inv), hp(hp), destroyed(dest) {}
	void damageItem(Weapon* w);
	void takeDamage(int damage);
	virtual void showContents() { cout << name << " contains nothing." << endl; }
	virtual void inspection();
	string getName() { return name; }
	int gethp() { return hp; }
	bool isDest() { return destroyed; }
	bool isinv() { return invulnerable; }
	virtual Item* getKey() { return nullptr; }
	virtual void unlockChest() {}
	virtual Item* getItem(string s) { return nullptr; }
	virtual bool isItem(string s) { return false; }
};

class Chest : public Furnishing {
public:
	bool locked;
	puzzle* puz;
	Item* key;
	vector<Item*> contents;
	Chest(string name, bool inv, int hp, Item* key = nullptr, puzzle* puzzle = nullptr, bool dest = false, bool locked = true)
		: Furnishing(name, inv, hp, dest), key(key), puz(puzzle), locked(locked) {}
	void addItem(Item* i1, Item* i2=nullptr, Item* i3=nullptr, Item* i4=nullptr, Item* i5=nullptr) {
		contents.push_back(i1);
		if (i2) contents.push_back(i2);
		if (i3) contents.push_back(i3);
		if (i4) contents.push_back(i4);
		if (i5) contents.push_back(i5);
	}
	bool isItem(string s) {
		for (auto item : contents) {
			if (s == item->getName()) {
				return true;
			}
		}
		return false;
	}
	Item* getItem(string s) {
		for (int i = 0; i < contents.size(); i++) {
			if (contents[i]->getName() == s && contents[i]->canPickUp()) {
				Item* temp = contents[i];
				cout << "You aquire " << s << endl;
				contents.erase(contents.begin() + i);
				return temp;
			}
		}
		cout << "Can't pick up " << s << endl;
		return nullptr;
	}
	Item* getKey(){ return key; }
	void unlockChest() {
		if (!this->locked) {
			cout << this->getName() << " is already unlocked." << endl;
		}
		else {
			this->locked = false;
			cout << "(unlocking click noise)" << endl;
		}
	}
	void showContents() {
		if (!this->locked || this->isDest()) {
			cout << this->getName() << " contains: " << endl;
			for (auto item : contents) {
				item->allowPickUp();
				cout << item->getName() << endl;
			}
		}
		else {
			cout << this->getName() << " is locked." << endl;
		}
	}
	void inspection() {
		cout << this->getName() << endl;
		(isinv()) ? cout << "invulnerable to damage" : cout << "HP: " << gethp();
		cout << "\nlocked:  ";
		(locked) ? cout << "yes" << endl : cout << "No" << endl;
		if (this->puz) {
			cout << "There is a puzzle inscribed on the " << getName() << endl;
			puz->displayPuzzle();
			cout << "Your Answer:  ";
			string ans;
			getline(cin, ans);
			if (puz->compareAnswer(ans)) {
				unlockChest();
			}
		}
	}
};

class Painting : public Furnishing {
public:
	string desc;
	string artist;
	bool hidden;
	Painting(string name, bool inv, int hp, string desc, string artist, bool hidden = false, bool dest = false)
		: Furnishing(name, inv, hp, dest), desc(desc), artist(artist), hidden(hidden) {}
	void showContents() {
		cout << "The painting contains nothing unusual." << endl;
	}
	void inspection() {
		cout << this->getName();
		(isinv()) ? cout << "invulnerable to damage" : cout << "HP: " << gethp();
		cout << "\nArtist: " << artist << "\nDescription: " << desc << endl;
	}
	Item* getKey() { return nullptr; }
	void unlockChest() {}
	Item* getItem(string s) { return nullptr; }
    bool isItem(string s) { return false; }
};