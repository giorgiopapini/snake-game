#include <iostream>
#include <string>

using namespace std;

class Field {
	public:
		string grid[DIM];
		
		Field() {
			drawBorders();
		}
		
		void drawBorders() {
			drawVerticalBorders();
			addCharToBorder(CORNER_BORDER, BOTH);
			drawHorizontalBorders();
			addCharToBorder(CORNER_BORDER, BOTH);
		}
		
		void printField() {
			system("cls");
			for (int i = 0; i < DIM; i ++) {
				cout << grid[i] << endl;
			}
		}
	
	
	private:
		void drawHorizontalBorders() {

			for (int i = 0; i < (DIM - 2); i ++) {
				grid[0] += HORIZONTAL_BORDER;
				grid[DIM - 1] += HORIZONTAL_BORDER;
			}

		}
		
		void drawVerticalBorders() {
			for (int i = 1; i < (DIM - 1); i ++) {  // for row in field (except first row)
				for (int j = 0; j < DIM; j ++) {  // for char in row
					if (j == 0 || j == (DIM - 1)) {
						grid[i] += VERTICAL_BORDER;	
					}
					else { grid[i] += ' '; }
				}
			}
		}
		
		void addCharToBorder(char _wantedChar, int _position) {
			if (_position == TOP) {
				grid[0] += _wantedChar;
			}
			else if (_position == DOWN) {
				grid[DIM - 1] += _wantedChar;	
			}
			else {
				grid[0] += _wantedChar;
				grid[DIM - 1] += _wantedChar;
			}
		}
	
};

