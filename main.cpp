#include <iostream>
#include <array>
#include <vector>
#include "Game.h"
#include "Player.h"
#include "Wonder.h"
using namespace std;


int main() {

	vector<Wonder> wonders;
	wonders.emplace_back( Wonder("The Appian Way", array<int, 5> {1, 1, 1, 0, 2}, vector<Impact>()) );
	wonders.emplace_back( Wonder("Circus Maximus", array<int, 5> {1, 1, 1, 0, 2}, vector<Impact>()) );
	wonders.emplace_back( Wonder("The Collossus", array<int, 5> {1, 1, 1, 0, 2}, vector<Impact>()) );
	wonders.emplace_back( Wonder("The Great Library", array<int, 5> {1, 1, 1, 0, 2}, vector<Impact>()) );
	wonders.emplace_back( Wonder("The Great Lightouse", array<int, 5> {1, 1, 1, 0, 2}, vector<Impact>()) );
	wonders.emplace_back( Wonder("The Hanging Gardens", array<int, 5> {1, 1, 1, 0, 2}, vector<Impact>()) );
	wonders.emplace_back( Wonder("The Mausoleum", array<int, 5> {1, 1, 1, 0, 2}, vector<Impact>()) );
	wonders.emplace_back( Wonder("Piraeus", array<int, 5> {1, 1, 1, 0, 2}, vector<Impact>()) );
	wonders.emplace_back( Wonder("The Pyramids", array<int, 5> {1, 1, 1, 0, 2}, vector<Impact>()) );
	wonders.emplace_back( Wonder("The Sphinx", array<int, 5> {1, 1, 1, 0, 2}, vector<Impact>()) );
	wonders.emplace_back( Wonder("The Statue Of Zeus", array<int, 5> {1, 1, 1, 0, 2}, vector<Impact>()) );
	wonders.emplace_back( Wonder("The Temple of Artemis", array<int, 5> {1, 1, 1, 0, 2}, vector<Impact>()) );
	cout << "The number of wonders is:" << wonders.size() << endl;

	Player A("Gabriel"), B("Catherine");

	cout << "Welcome to 7 Wonders Duel C++ version" << endl;
	cout << "The players are: " << endl;
	A.print();
	B.print();

	Game game(&A, &B);

	return 0;
}
