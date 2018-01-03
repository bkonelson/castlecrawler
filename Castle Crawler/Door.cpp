#include <iostream>
#include <string>
#include "Door.h"

using namespace std;

void Door::unlock() {
	if (!this->locked) {
		cout << this->location << " door is already unlocked." << endl;
	}
	else {
		this->locked = false;
		cout << "(unlocking click noise)" << endl;
	}
}

void Door::damageItem(Weapon* w) {
	w->condition -= 1;
	if (w->condition > 0) {
		cout << w->getName() << " condition is " << w->condition << endl;
	}
	if (w->condition == 0) {
		cout << w->getName() << " has been broken. (1/2 damage)"  << endl;
		w->damage /= 2;
	}
}

void Door::takeDamage(int damage) {
	if (this->invulnerable) {
		cout << this->location << " door is invulnerable to damage." << endl;
	}
	else {
		if (hp <= 0) {
			cout << "Door has 0 HP." << endl;
			return;
		}
		this->hp -= (damage-1);
		cout << location << " door took " << (damage-1) << " damage." << endl;
		if (this->locked && this->hp <= 0) {
			cout << this->location << " door lock has been destroyed." << endl;
			this->locked = false;
		}
	}
}

void Door::inspection() {
	(invulnerable) ? cout << "invulnerable to damage" : cout << "HP: " << hp;
	cout << "\nlocked:  ";
	(locked) ? cout << "yes" << endl : cout << "No" << endl;
	if (key) {
		cout << key->getName() << " required to unlock" << endl;
	}
	if (puz) {
		cout << "Door has a puzzle:" << endl;
		puz->displayPuzzle();
		cout << "Your Answer:  ";
		string ans;
		getline(cin, ans);
		if (puz->compareAnswer(ans)) {
			unlock();

		}
	}
}
