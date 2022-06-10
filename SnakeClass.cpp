#include <iostream>
#include <string>

using namespace std;

class Snake {
	public:
		char symbol = SNAKE_CHAR;
		int length = 1;
		int pos[SNAKE_MAX_LENGTH][2];  // this array should be dinamic (no fixed size)
		int prevDir = 0;
		
		void updatePosition(int _nextX, int _nextY) {
			for (int i = 0; i < length; i ++) {
				int tempX = pos[i][0];
				int tempY = pos[i][1];
				pos[i][0] = _nextX;
				pos[i][1] = _nextY;
				_nextX = tempX;
				_nextY = tempY;
			}
		}
		
		void grow() {
			length += 1;
			pos[length - 1][0] = pos[length - 2][0];  // It copies the last position and inserts it inside new empty space inside pos array
			pos[length - 1][1] = pos[length - 2][1];
		}
};
