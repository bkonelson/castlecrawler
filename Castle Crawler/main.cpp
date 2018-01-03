#include <iostream>
#include <string>
#include "Room.h"
#include "commands.h"
using namespace std;

int main() {
	string playername;
	cout << "Enter a name for your character: ";
	cin >> playername;
	character* player1 = new character(playername);
	int curChoice;
	cout << "\nWelcome to Castle Crawler 1.0 " << player1->name << ", choose what you will do!" << endl;
	cout << "   1.  Enter the small castle and prepare to meet uncertain death" << endl;
	cout << "   2.  Enter the bigger castle and prepare to meet certain death" << endl;
	cout << "   3.  Flee like a patsy" << endl;
	cin >> curChoice;
	if (curChoice == 1) {
		cout << "Stage Info \nName: Castle Basic Bro\nHidden Rooms: 0\nArtifacts: 0" << endl;

		//Rooms
		Room* room1 = new Room("entry hall",0,0,2,0);
		Room* room2 = new Room("training ground", 4, 0, 3, 1);
		Room* room3 = new Room("armory", 0, 0, 0, 2);
		Room* room4 = new Room("throne room", 99, 2, 0, 0);
		
		//Items and puzzles
		Item* key1 = new Item("brass key");
		Item* key2 = new Item("Silver key");
		Item* key3 = new Item("golden key");
		Weapon* sword1 = new Weapon("basic sword", 3,0,0,0,8);
		Weapon* axe1 = new Weapon("goblin axe", 4);
		Armor* armor1 = new Armor("basic chainmail", 2);
		Ring* ring1 = new Ring("fire brand", 1, false, true);
		Potion* potion1 = new Potion("hpot", 5);
		Potion* potion2 = new Potion("health+", 7);
		puzzle* puzzle1 = new puzzle("(1,2,3,5,8,13,__", "21");
		puzzle* puzzle2 = new puzzle("You go at red and stop at green. (hint: one word)", "watermelon");
		
		//Doors
		Door* e1door = new Door("east",true,1,false);
		Door* e2door = new Door("east", true, 1, true,key1);
		Door* w2door = new Door("west", true, 1, false);
		Door* n2door = new Door("north", true, 1, true, key2);
		Door* w3door = new Door("west", true, 1, false);
		Door* s4door = new Door("south", true, 1, false);
		Door* n4door = new Door("north", true, 1, true, key3);

		//Furnishings
		Furnishing* table = new Furnishing("table", true, 1);
		Chest* chest1 = new Chest("wooden chest",true,1,nullptr,puzzle1);
		Chest* chest2 = new Chest("ornate chest",true,1,nullptr,puzzle2);
		Painting* paint1 = new Painting("painting", true, 1, "A painting of some fruit.", "Rhind A. Meet");
		Chest* armorRack = new Chest("armor cabinet",false,10,nullptr,nullptr,false,false);
		Furnishing* chair = new Furnishing("plain chair", false, 5);
		Furnishing* dummy = new Furnishing("practice dummy", true, 1);
		Furnishing* archery = new Furnishing("archery target", true, 1);
		Furnishing* throne = new Furnishing("throne", true, 1);

		//Monsters
		Monster* m1 = new Monster("goblin1", 5, 0, 2);
		Monster* m2 = new Monster("goblin2", 5, 0, 2);
		Monster* m3 = new Monster("large goblin", 8, 1, 3);
		Monster* m4 = new Monster("goblin armorer", 6, 2, 2);
		Monster* m5 = new Monster("goblin king", 12, 2, 3,3);

		//Adding doors to rooms
		room1->addDoor(e1door);
		room2->addDoor(e2door,w2door,n2door);
		room3->addDoor(w3door);
		room4->addDoor(s4door,n4door);

		//Adding Furnishings to rooms
		room1->addFurn(table,chest1);
		room2->addFurn(archery,dummy,chair);
		room3->addFurn(chest2,armorRack,paint1);
		room4->addFurn(throne);

		//Add Monsters to rooms
		room2->addMonster(m1,m2,m3);
		room3->addMonster(m4);
		room4->addMonster(m5);

		//Add items to containers and monsters
		chest1->addItem(sword1,potion1);
		chest2->addItem(ring1,potion2);
		armorRack->addItem(armor1);
		m1->addItem(axe1);
		m3->addItem(key1);
		m4->addItem(key2);
		m5->addItem(key3);

		//Main Loop
		cin.ignore();
		cout << "You enter the " << room1->getName() << ".  [type 'help' for a list of commands and info]" << endl;
		Room* curRoom = room1;
		int move = 0;
		bool end = false;
		while (!end) {
			int move = commands(player1,curRoom);
			switch (move) {
				case 0:
					break;
				case 1:
					curRoom = room1;
					break;
				case 2:
					curRoom = room2;
					break;
				case 3:
					curRoom = room3;
					break;
				case 4:
					curRoom = room4;
					break;
				case 99:
					end = true;
					break;
			}
			if (move != 0) {
				cout << "You enter the " << curRoom->getName() << endl;
			}
		}
		cout << "You have defeated the goblin king and won the heart of the princess" << endl;
		cout << "Just kidding.......there was no princess, you got a pretty nice ring though right?" << endl;
		string something;
		getline(cin, something);

	}

	else if (curChoice == 2) {
		cout << "Stage Info \nName: Mysterious Queen Lady\nHidden Rooms: 1\nArtifacts: 2" << endl;

		//Rooms
		Room* room1 = new Room("entry hall", 2, 0, 3, 0);
		Room* room2 = new Room("guard room", 0, 1, 0, 0);
		Room* room3 = new Room("hall extension", 0, 0, 4, 1);
		Room* room4 = new Room("antechamber", 7, 5, 6, 3);
		Room* room5 = new Room("kings bedroom", 4, 0, 0, 0);
		Room* room6 = new Room("throne room", 0, 0, 99, 4);
		Room* room7 = new Room("queens hall", 10, 4, 8, 0);
		Room* room8 = new Room("queens bedroom", 0, 0, 0, 7);
		Room* room9 = new Room("lair", 0, 0, 10, 0);
		Room* room10 = new Room("instruction room", 0, 7, 11, 9);
		Room* room11 = new Room("hidden closet", 0, 0, 0, 10);
		

		//Items and puzzles
		Item* key1 = new Item("simple key");
		Item* key2 = new Item("large key");
		Item* key3 = new Item("diamond key");
		Item* key4 = new Item("queens key");
		Item* key5 = new Item("lair key");
		Item* secret = new Item("queen shyvanna's diary");
		Weapon* w1 = new Weapon("staff", 2); //1
		Weapon* w2 = new Weapon("soldiers sword", 4); //2
		Weapon* w3 = new Weapon("heavy sword", 2,2); //2
		Weapon* w4 = new Weapon("captains sword", 4, 0,0,2,8); //3
		Weapon* w5 = new Weapon("heavy mace", 5, 2, 0, 0, 8); //10
		Weapon* w6 = new Weapon("dragon slayer", 7, 3, 3); //11
		Armor* armor1 = new Armor("chainmail", 1); //2
		Armor* armor2 = new Armor("captains chainmail", 3); //8
		Armor* armor3 = new Armor("champions armor", 5); //11
		Ring* ring1 = new Ring("queens signet",2,true);
		Ring* ring2 = new Ring("ruby ring", 0, false,true);
		Potion* potion1 = new Potion("hpotion", 5);
		Potion* potion2 = new Potion("hpotion+", 7);
		Potion* potion3 = new Potion("hpotion++", 10);
		Potion* potion4 = new Potion("cpotion", 0,5);
		Potion* potion5 = new Potion("cpotion+", 0,7);
		Potion* potion6 = new Potion("cpotion++", 0,10);

		puzzle* puzzle1 = new puzzle("The maker doesn't want it, the buyer doesn't use it, the user doesn't know it. (one word)", "coffin");
		puzzle* puzzle2 = new puzzle("Enter the name of the queen:  ", "shyvanna");
		puzzle* puzzle3 = new puzzle("How many days are there in 4 years? (type number, don't spell)", "1461");
		puzzle* puzzle4 = new puzzle("A snickers and a gumball cost a dollar and a dime.  If the snickers costs 1 dollar more than the gumball, how many cents was the gumball? (type number, don't spell)", "5");
		puzzle* puzzle5 = new puzzle("307,311,313,317,331,337,347,349,___", "353");
		puzzle* puzzle6 = new puzzle("Passphrase: ", "roasting");

		//Doors
		Door* e1door = new Door("east",true,1,false);
		Door* n1door = new Door("north", false, 6, true);
		Door* s2door = new Door("south", true, 1, false);
		Door* e3door = new Door("east", true, 1, true, key1);
		Door* w3door = new Door("west", true, 1, false);
		Door* n4door = new Door("north", false, 30, true,key2);
		Door* s4door = new Door("south", true, 1, true, nullptr,puzzle1);
		Door* e4door = new Door("east", true, 1, true,nullptr,puzzle2);
		Door* w4door = new Door("west", true, 1, false);
		Door* n5door = new Door("north", true, 1, false);
		Door* e6door = new Door("east", true, 1, true, key3);
		Door* w6door = new Door("west", true, 1, false);
		Door* n7door = new Door("north", true, 1, false);
		Door* s7door = new Door("south", true, 1, false);
		Door* e7door = new Door("east", true, 1, true, key4);
		Door* w8door = new Door("west", true, 1, false);
		Door* e9door = new Door("east", true, 1, false);
		Door* s10door = new Door("south", true, 1, false);
		Door* e10door = new Door("east", true, 1, true,nullptr,puzzle3); //hidden door
		Door* w10door = new Door("west", true, 1, true,key5);
		Door* w11door = new Door("west", true, 1, false);

		//Furnishings

		Chest* chest1 = new Chest("armor chest", true, 1, nullptr, puzzle4);
		Chest* chest2 = new Chest("kings chest", true, 1, nullptr, puzzle5);
		Chest* chest3 = new Chest("jewelry box", true,1,nullptr,puzzle6);
		Chest* chest4 = new Chest("iron chest",true,1,nullptr,nullptr,false,false);
		Chest* chest5 = new Chest("iron chest", true, 1, nullptr, nullptr, false, false);
		Chest* chest6 = new Chest("fancy chest", true, 1, nullptr, nullptr, false, false);
		Chest* vase1 = new Chest("vase", true, 1, nullptr, nullptr, false, false);
		Chest* vase2 = new Chest("vase", true, 1, nullptr, nullptr, false, false);
		Chest* chamber = new Chest("chamber pot", true, 1, nullptr, nullptr, false, false);
		Chest* book = new Chest("boring book", true, 1, nullptr, nullptr, false, false);
		Painting* paint1 = new Painting("mountain painting",false,3,"Some happy looking trees on some mountains","Bob Ross");
		Painting* paint2 = new Painting("subaru painting", false, 2, "Some guy going really slow around around a semi.", "Rhodes H. Rage");
		Painting* paint3 = new Painting("christmas painting", true, 1, "chestnuts **roasting** on an open fire", "Saint Nicholas");
		Painting* paint4 = new Painting("battle painting", false, 1, "Looks like the battle of Helms Deep, but different", "LotrFan87");
		Painting* paint5 = new Painting("dragon painting", false, 10, "A giant dragon spitting fire into the sky, really old", "The Queen");
		Furnishing* table = new Furnishing("table", true, 1);
		Furnishing* fchair = new Furnishing("fancy chair", true, 1);
		Furnishing* chair = new Furnishing("plain chair", true, 1);
		Furnishing* candle = new Furnishing("candlestick", true, 1);
		Furnishing* bed = new Furnishing("bed", true, 1);
		Furnishing* throne = new Furnishing("throne", true, 1);
		Furnishing* desk = new Furnishing("desk", true, 1);

		//Monsters
		Monster* m1 = new Monster("guard1", 5, 0, 2);
		Monster* m2 = new Monster("guard2", 6, 0, 2);
		Monster* m3 = new Monster("armored guard", 6, 1, 3);
		Monster* m3copy = new Monster("armored guard", 7, 2, 3);
		Monster* m4 = new Monster("archer", 5, 0, 4);
		Monster* m4copy = new Monster("archer", 5, 0, 4);
		Monster* m5 = new Monster("guard captain", 10, 2, 3,2);
		Monster* m6 = new Monster("castle steward", 10,1,3);
		Monster* m7 = new Monster("knight protector", 12, 2, 6,3,0,true);
		Monster* m8 = new Monster("heavyarmor guard", 8, 4, 5);
		Monster* m9 = new Monster("secret keeper", 15, 3, 5, 0, 2);
		Monster* m10 = new Monster("minion1", 8, 2, 3,0,3);
		Monster* m11 = new Monster("minion2", 8, 2, 3, 0, 2);
		Monster* m12 = new Monster("minion3", 8, 2, 3, 0, 2);
		Monster* m13 = new Monster("minion4", 8, 2, 3, 0, 2);
		Monster* m14 = new Monster("minion5", 8, 2, 3, 0, 2);
		Monster* m15 = new Monster("dragon queen", 25, 6, 6,10,0,true);

		//Adding doors to rooms
		room1->addDoor(e1door, n1door);
		room2->addDoor(s2door);
		room3->addDoor(e3door,w3door);
		room4->addDoor(n4door,s4door,e4door,w4door);
		room5->addDoor(n5door);
		room6->addDoor(e6door,w6door);
		room7->addDoor(n7door,s7door,e7door);
		room8->addDoor(w8door);
		room9->addDoor(e9door);
		room10->addDoor(s10door,w10door);
		room11->addDoor(w11door);

		//Adding Furnishings to rooms
		room1->addFurn(chest4, paint4, candle);
		room2->addFurn(chair, chest1, bed, table);
		room3->addFurn(vase1, table);
		room4->addFurn(paint1);
		room5->addFurn(desk, bed, book, chest2);
		room6->addFurn(throne);
		room7->addFurn(paint2, chair);
		room8->addFurn(paint3, fchair, desk, chest3, bed,chest6,chamber);
		room9->addFurn(fchair);
		room10->addFurn(paint5, table, vase2);
		room11->addFurn(chest5);
		//Add Monsters to rooms
		room2->addMonster(m1, m2, m3);
		room3->addMonster(m4, m5, m3copy);
		room6->addMonster(m15);
		room7->addMonster(m6);
		room9->addMonster(m9, m10, m11, m12, m13, m14);
		room10->addMonster(m7, m8, m4copy);

		//Add items to containers and monsters
		chest1->addItem(armor1,potion4);
		chest2->addItem(ring2,potion1,key4);
		chest3->addItem(ring1,potion5);
		chest4->addItem(w1, potion1);
		chest5->addItem(armor3,w6);
		chest6->addItem(armor2);
		vase1->addItem(potion2);
		book->addItem(key2);
		chamber->addItem(potion3);
		m1->addItem(potion1);
		m2->addItem(w2);
		m3->addItem(w3);
		m5->addItem(key1,w4);
		m7->addItem(key5);
		m8->addItem(w5);
		m9->addItem(secret);
		m15->addItem(key3);
		

		//Main Loop (make sure to set cases equal to rooms)
		cin.ignore();
		cout << "You enter the " << room1->getName() << ".  [type 'help' for a list of commands and info]" << endl;
		bool showmsg1 = true;
		Room* curRoom = room1;
		int move = 0;
		bool end = false;
		while (!end) {
			int move = commands(player1, curRoom);
			switch (move) {
			case 0:
				break;
			case 1:
				curRoom = room1;
				break;
			case 2:
				curRoom = room2;
				break;
			case 3:
				curRoom = room3;
				break;
			case 4:
				curRoom = room4;
				break;
			case 5:
				curRoom = room5;
				break;
			case 6:
				curRoom = room6;
				break;
			case 7:
				curRoom = room7;
				break;
			case 8:
				curRoom = room8;
				break;
			case 9:
				curRoom = room9;
				break;
			case 10:
				curRoom = room10;
				break;
			case 11:
				curRoom = room11;
				break;
			case 99:
				end = true;
				break;
			}
			if (move != 0) {
				cout << "You enter the " << curRoom->getName() << endl;
			}
			//special for this dungeon
			if (showmsg1 && room10->getFurn("dragon painting")->isDest()) {
				room10->addDoor(e10door);
				cout << "You hear a thud and look around, a door has appeared." << endl;
				showmsg1 = false;
			}
			m9->hp += room9->getMonsterCount();
			if (m9->hp > 15) m9->hp = 15;
		}
		cout << "Ah yes the classic 'This boss is actually a league of legends character the whole time'.  ";
		cout << "Mixed in with a 'Was the capatin of the guard hooking up with the queen who was actually a dragon?'" << endl;
		cout << "Anyway, good job making it to the end" << endl;
		string something;
		getline(cin, something);
	}

	else {
		cout << "Really? Fine....you flee and remain an indetured servant the rest of your life";
		cout << " interestingly without any dentures, very poor dental hygiene." << endl;
		cin.ignore();
		string something;
		getline(cin, something);
	}
	return 0;
}