#include <iostream>
#include "constants.cpp"
#include "GameClass.cpp"
#include "MenuClass.cpp"

using namespace std;

int main() {
	Menu menu;
	while(true) {
		srand(time(NULL));
		Game game;
		char choice = menu.mainMenu();
		switch(choice) {
			case FIRST_OPTION:
				menu.startLevel(game);
				break;
			case SECOND_OPTION:
				menu.customization();
				break;
			case THIRD_OPTION:
				menu.showCommands();
				break;
			case EXIT:
				menu.closeGame();
				return 0;
		}
	}
}
