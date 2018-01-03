#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "character.h"
#include "Door.h"
#include "Furnishing.h"
#include "Monster.h"

using namespace std;

class Room {
private:
	string name;
	int north;
	int south;
	int east;
	int west;
	vector<Door*> doors;
	vector<Furnishing*> stuff;
	vector<Monster*> monsters;
public:
	bool cleared;
	Room(string name, int n, int s, int e, int w): name(name), north(n),south(s),east(e), west(w) {}
	void addDoor(Door* D1, Door* D2 = nullptr, Door* D3 = nullptr, Door* D4 = nullptr);
	string getName() { return name; }
	void addFurn(Furnishing* F1, Furnishing* F2 = nullptr, Furnishing* F3 = nullptr, Furnishing* F4 = nullptr, Furnishing* F5 = nullptr, Furnishing* F6 = nullptr, Furnishing* F7 = nullptr);
	void addMonster(Monster* M1, Monster* M2 = nullptr, Monster* M3 = nullptr, Monster* M4 = nullptr, Monster* M5 = nullptr, Monster* M6 = nullptr, Monster* M7 = nullptr);
	int go(string s);
	void openContainer(string s);
	void displaySearch();	
	void attack(string s, character* P1);
	void monsterAttack(Monster* M, character* P1);
	void unlockDoor(string s);
	Door* getDoor(string s);
	Furnishing* getFurn(string s);
	Item* getChestKey(string s);
	void unlockChest(string s);
	bool inspect(string s);
	void getItemFromChest(string s, character* p1);
	int getMonsterCount() { return monsters.size(); }
};