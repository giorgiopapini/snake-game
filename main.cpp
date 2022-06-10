#include <iostream>
#include "constants.cpp"
#include "GameClass.cpp"

using namespace std;

class Menu {
	public:
		
		int levelCount = 1;
		int totalScore = 0;
		
		char mainMenu() {
			system("cls");
			char choice;
			cout << " __________________________________________" << endl;
			cout << "|                                          |" << endl;
			cout << "|                Snake Game                |" << endl;
			cout << "|__________________________________________|" << endl;
			cout << endl;
			cout << "- Insert " << EXIT << " to end the program" << endl;
			cout << "- Insert " << FIRST_OPTION << " to start the game" << endl;
			cout << "- Insert " << SECOND_OPTION << " change the aesthetics of the game" << endl;
			cout << "- Insert " << THIRD_OPTION << " to view commands" << endl;
			cin >> choice;
			return choice;
		}
		
		void startLevel(Game game) {
			system("cls");
			cout << " ______________________ " << levelCount << char(248) << " Level ____________________" << endl;
			cout << endl;
			cout << "- Total score: " << totalScore << endl;
			float averageScore = (float)totalScore / (levelCount - 1);
			if (averageScore != averageScore) { averageScore = 0; }  // check if averageScore is NaN (divided by 0)
			cout << "- Average score per level: " << averageScore << endl << endl;
			system("pause");
			game.startGame();
			levelCount ++;
			totalScore += game.snake.length - 1;
		}
		
		void customization() {
			system("cls");
			char choice;
			cout << " __________________________________________" << endl;
			cout << "|                                          |" << endl;
			cout << "|               Customization              |" << endl;
			cout << "|__________________________________________|" << endl;
			cout << endl;
			cout << "- Insert " << FIRST_OPTION << " to change snake symbol (default is 'O', current is '" << SNAKE_CHAR << "')" << endl;
			cout << "- Insert " << SECOND_OPTION << " to change apple symbol (defautl is '@', current is '" << APPLE_CHAR << "')" << endl;
			cin >> choice;
			char symbol;
			switch(choice) {
				case FIRST_OPTION:
					cout << endl << "- New snake symbol: ";
					cin >> symbol;
					if (symbol != APPLE_CHAR && symbol != HORIZONTAL_BORDER && symbol != VERTICAL_BORDER) {
						SNAKE_CHAR = symbol;
					}
					else {
						cout << "- [ERROR] => The snake symbol must be different from the apple symbol and must be different from the field border!" << endl << endl;
						system("pause");
						customization();
					}
					break;
				case SECOND_OPTION:
					cout << endl << "- New apple symbol: ";
					cin >> symbol; 
					if (symbol != SNAKE_CHAR && symbol != HORIZONTAL_BORDER && symbol != VERTICAL_BORDER) {
						APPLE_CHAR = symbol;
					}
					else {
						cout << "- [ERROR] => The apple symbol must be different from the snake symbol and must be different from the field border!" << endl << endl;
						system("pause");
						customization();
					}
					break;
				default:
					customization();
			}
		}
		
		void showCommands() {
			system("cls");
			cout << " __________________________________________" << endl;
			cout << "|                                          |" << endl;
			cout << "|                 Commands                 |" << endl;
			cout << "|__________________________________________|" << endl;
			cout << endl;
			cout << "- ARROW UP     =>  Move the snake to the top" << endl;
			cout << "- ARROW DOWN   =>  Move the snake to the bottom" << endl;
			cout << "- ARROW LEFT   =>  Move the snake to the left" << endl;
			cout << "- ARROW RIGHT  =>  Move the snake to the right" << endl << endl;
			system("pause");
		}
};


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
				system("cls");
				cout << endl << "Thanks for playing!" << endl;
				return 0;
		}
	}
}
