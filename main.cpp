#include <iostream>
#include "Game.h"
#include "Player.h"
using namespace std;

int main() {

	Player A("Gabriel"), B("Catherine");

	cout << "Welcome to 7 Wonders Duel C++ version" << endl;
	cout << "The players are: " << endl;
	A.print();
	B.print();

	Game game(&A, &B);

}
