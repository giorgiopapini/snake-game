#include <iostream>
#include "constants.cpp"
#include "GameClass.cpp"

using namespace std;


char menu() {
	system("cls");
	char choice;
	cout << " __________________________________________" << endl;
	cout << "|                                          |" << endl;
	cout << "|                Snake Game                |" << endl;
	cout << "|__________________________________________|" << endl;
	cout << endl;
	cout << "- Insert " << EXIT << " to end the program" << endl;
	cout << "- Insert " << FIRST_OPTION << " to start the game" << endl;
	cout << "- Insert " << SECOND_OPTION << " to set your avatar" << endl;
	cout << "- Insert " << THIRD_OPTION << " to view commands" << endl;
	cin >> choice;
	return choice;
}


int main() {
	while(true) {
		srand(time(NULL));
		Game game;
		char choice = menu();
		switch(choice) {
			case FIRST_OPTION:
				game.startGame();
				break;
			case SECOND_OPTION:
				break;
			case THIRD_OPTION:
				break;
			case EXIT:
				system("cls");
				cout << endl << "Thanks for playing!" << endl;
				return 0;
		}
	}
}
