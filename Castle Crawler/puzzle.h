#pragma once
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class puzzle {
private:
	string question;
	string answer;
public:
	puzzle(string q, string a) : question(q), answer(a) {}
	void displayPuzzle() { cout << question << endl; }
	bool compareAnswer(string s) {
		if (s == answer) {
			cout << "That is correct!" << endl;
			return true;
		}
		cout << "That is not correct..." << endl;
		return false;
	}
};