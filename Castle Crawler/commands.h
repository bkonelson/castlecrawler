#include <iostream>
#include <string>
#include <algorithm>
#include "character.h"
using namespace std;

int commands(character* player1, Room* curRoom) {
	string first;
	string second;
	string fullString;
	getline(cin, fullString);
	int space = fullString.find(' ');
	if (space != -1) {
		first = fullString.substr(0, space);
		second = fullString.substr(space + 1);
	}
	else {
		first = fullString;
		second = "";
	}
	transform(first.begin(), first.end(), first.begin(), tolower);
	transform(second.begin(), second.end(), second.begin(), tolower);

	//go
	if (first == "go") {
		if (second == "south" || second == "north" || second == "east" || second == "west") {
			return curRoom->go(second);
		}
		else {
			cout << second << " is not an accepted direction. (Use north, south, east, or west)" << endl;
			return 0;
		}
	}

	//open
	else if (first == "open") {
		if (second == "door") {
			cout << "Open door in which direction?" << endl;
			string option;
			getline(cin, option);
			if (option == "south" || option == "north" || option == "east" || option == "west") {
				return curRoom->go(option);
			}
			else {
				cout << option << " is not an accepted direction. (Use north, south, east, or west)" << endl;
				return 0;
			}
		}
		else if (second == "south door" || second == "north door" || second == "east door" || second == "west door") {
			return curRoom->go(second);
		}
		else {
			curRoom->openContainer(second);
			return 0;
		}
	}

	//unlock
	else if (first == "unlock") {
		if (second == "door") {
			cout << "Open door in which direction?" << endl;
			string option;
			getline(cin, option);
			if (option == "south" || option == "north" || option == "east" || option == "west") {
				option += " door";
				if (!curRoom->getDoor(option)) {
					return 0;
				}
				if (!curRoom->getDoor(option)->key) {
					cout << "This door doesn't require a key." << endl;
					return 0;
				}
				if (player1->hasKey(curRoom->getDoor(option)->key)) {
					curRoom->unlockDoor(option);
					return 0;
				}
				else {
					cout << "You do not have the key for this door." << endl;
					return 0;
				}
			}
			else {
				cout << option << " is not an accepted direction. (Use north, south, east, or west)" << endl;
				return 0;
			}
		}
		else if (second == "south door" || second == "north door" || second == "east door" || second == "west door") {
			if (!curRoom->getDoor(second)) {
				cout << "Not a door there" << endl;
				return 0;
			}
			if (!curRoom->getDoor(second)->key) {
				cout << "This door doesn't require a key." << endl;
				return 0;
			}
			if (player1->hasKey(curRoom->getDoor(second)->key)) {
				curRoom->unlockDoor(second);
				return 0;
			}
			else {
				cout << "You do not have the key for this door." << endl;
				return 0;
			}
		}
		else {
			if (!curRoom->getChestKey(second)) {
				cout << second << " doesn't require a key." << endl;
				return 0;
			}
			if (player1->hasKey(curRoom->getChestKey(second))) {
				curRoom->unlockChest(second);
				return 0;
			}
		}
	}

	//attack
	else if (first == "attack" || first == "fight") {
		if (second == "door") {
			cout << "Attack door in which direction?" << endl;
			string option;
			getline(cin, option);
			if (option == "south" || option == "north" || option == "east" || option == "west") {
				curRoom->attack(option, player1);
				return 0;
			}
			else {
				cout << option << " is not an accepted direction. (Use north, south, east, or west)" << endl;
				return 0;
			}
		}
		else {
			curRoom->attack(second, player1);
			return 0;
		}
	}

	//get
	else if (first == "get") {
		curRoom->getItemFromChest(second, player1);
		return 0;
	}

	//potion
	else if (first == "potion") {
		player1->usePotion(second);
		return 0;
	}

	//equip 
	else if (first == "equip") {
		player1->equipItem(second);
		return 0;
	}

	//search
	else if (first == "search") {
		if (second == "room" || second == "" || second == curRoom->getName()) {
			curRoom->displaySearch();
			return 0;
		}
		else if (second == "") {
			cout << "What to search?  ";
			string option;
			getline(cin, option);
			if (second == "room" || second == "" || second == curRoom->getName()) {
				curRoom->displaySearch();
				return 0;
			}
			else {
				curRoom->openContainer(second);
				return 0;
			}
		}
		else {
			curRoom->openContainer(second);
			return 0;
		}
	}

	//bag
	else if (first == "bag") {
		if (second == "") {
			player1->lookinbag();
			return 0;
		}
	}

	//character stats
	else if (first == "cs") {
		if (second == "") {
			player1->getStats();
			return 0;
		}
	}

	//help
	else if (first == "help") {
		player1->help();
		return 0;
	}

	//inspect
	else if (first == "inspect") {
		if (curRoom->inspect(second)) {
			return 0;
		}
		player1->inspectItem(second);
		return 0;
	}

	else {
		cout << "Unrecognized command. Try again." << endl;
		return 0;
	}
}

