#include <iostream>

using namespace std;

class Menu {
	public:
		
		int levelCount = 0;
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
			cout << " ______________________ " << levelCount + 1 << char(248) << " Level ____________________" << endl;
			cout << endl;
			cout << "- Total score: " << totalScore << endl;
			cout << "- Average score per level: " << getAverageScore() << endl << endl;
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
		
		void closeGame() {
			system("cls");	
			cout << " __________________________________________" << endl;
			cout << "|                                          |" << endl;
			cout << "|            Thanks for playing!           |" << endl;
			cout << "|__________________________________________|" << endl;
			cout << endl;
			cout << "- Level reached: " << levelCount << endl;
			cout << "- Total score: " << totalScore << endl;
			cout << "- Average score per level: " << getAverageScore() << endl;
		}
		
		
		private:
			float getAverageScore() {
				float averageScore = (float)totalScore / levelCount;
				if (averageScore != averageScore) {  // check if averageScore is NaN (divided by 0)
					averageScore = 0; 
				}
				return averageScore;
			}
};
