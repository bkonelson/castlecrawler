#include <iostream>
#include <string>
#include "Furnishing.h"

using namespace std;


void Furnishing::damageItem(Weapon* w) {
	w->condition -= 1;
	if (w->condition > 0) {
		cout << w->getName() << " condition is " << w->condition << endl;
	}
	if (w->condition == 0) {
		cout << w->getName() << " has been broken. (1/2 damage)" << endl;
		w->damage /= 2;
	}
}

void Furnishing::takeDamage(int damage) {
	if (this->invulnerable) {
		cout << this->name << " is invulnerable to damage." << endl;
	}
	else if(this->destroyed) {
		cout << this->name << " has been destroyed." << endl;
	}
	else {
		this->hp -= damage;
		cout << name << " took " << damage << " damage." << endl;
		if (this->hp <= 0) {
			cout << name << " has been destroyed." << endl;
			this->destroyed = true;
		}
	}
}


void Furnishing::inspection() {
	cout << name << ":\n";
	(isinv()) ? cout << "invulnerable to damage" : cout << "HP: " << gethp() << endl;
}



