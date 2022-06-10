#include <iostream>
#include <string>
#include <time.h>  
#include <conio.h>
#include <algorithm>
#include <iterator>
#include <thread>
#include <chrono>
#include <Windows.h>
#include "FieldClass.cpp"
#include "SnakeClass.cpp"

using namespace std;

class Game {
	public:
		Field field;
		Snake snake;
		bool gameEnded = false;
		int currentDirection = 0;
		
		void startGame() {
			spawnSnake();
			spawnApple();
			while(gameEnded == false) {
				field.printField();
				changeDirection();
				move();
				this_thread::sleep_for(chrono::milliseconds(100));
			}
			endGame();
		}
		
		void endGame() {
			system("cls");
			cout << " __________________________________________" << endl;
			cout << "|                                          |" << endl;
			cout << "|                GAME OVER!                |" << endl;
			cout << "|__________________________________________|" << endl;
			cout << endl;
			cout << "- Total score: " << snake.length - 1 << endl << endl;
			system("pause");
		}
		
		void spawnSnake() {
			int randX = rand() % (DIM - 2) + 1;
			int randY = rand() % (DIM - 2) + 1;
			snake.pos[0][0] = randX;
			snake.pos[0][1] = randY;
			field.grid[randY][randX] = snake.symbol;
		}
		
		void spawnApple() {
			while (true) {
				int randX = rand() % (DIM - 2) + 1;
				int randY = rand() % (DIM - 2) + 1;
				if (field.grid[randY][randX] == ' ') {
					field.grid[randY][randX] = APPLE_CHAR;
					break;
				}
			}
		}
		
		void changeDirection() {
			if (GetKeyState(VK_UP) & 0x8000) {  // It changes snake direction when arrow key is pressed
				if (currentDirection != DIR_DOWN) {
					currentDirection = DIR_UP;	
				}
			}
			else if (GetKeyState(VK_DOWN) & 0x8000) {
				if (currentDirection != DIR_UP) {
					currentDirection = DIR_DOWN;	
				}
			}
			else if (GetKeyState(VK_LEFT) & 0x8000) {
				if (currentDirection != DIR_RIGHT) {
					currentDirection = DIR_LEFT;	
				}
			}
			else if (GetKeyState(VK_RIGHT) & 0x8000) {
				if (currentDirection != DIR_LEFT) {
					currentDirection = DIR_RIGHT;	
				}
			}
		}
		
		void move() {
			int nextX;
			int nextY;
			switch(currentDirection) {
				case DIR_UP: 
					nextX = snake.pos[0][0];
					nextY = snake.pos[0][1] - 1;
					if (snake.prevDir != DIR_DOWN && isNextPosValid(nextX, nextY)) {
						if (appleEaten(nextX, nextY)) {
							snake.grow();
						}
						field.grid[nextY][nextX] = snake.symbol;
						moveSnake(nextX, nextY);
						snake.prevDir = DIR_UP;	
					}
					break;
				case DIR_DOWN:
					nextX = snake.pos[0][0];
					nextY = snake.pos[0][1] + 1;
					if (snake.prevDir != DIR_UP && isNextPosValid(nextX, nextY)) {
						if (appleEaten(nextX, nextY)) {
							snake.grow();
						}
						field.grid[nextY][nextX] = snake.symbol;
						moveSnake(nextX, nextY);
						snake.prevDir = DIR_DOWN;	
					}
					break;
				case DIR_LEFT:
					nextX = snake.pos[0][0] - 1;
					nextY = snake.pos[0][1];
					if (snake.prevDir != DIR_RIGHT && isNextPosValid(nextX, nextY)) {
						if (appleEaten(nextX, nextY)) {
							snake.grow();
						}
						field.grid[nextY][nextX] = snake.symbol;
						moveSnake(nextX, nextY);
						snake.prevDir = DIR_LEFT;	
					}
					break;
				case DIR_RIGHT:
					nextX = snake.pos[0][0] + 1;
					nextY = snake.pos[0][1];
					if (snake.prevDir != DIR_LEFT && isNextPosValid(nextX, nextY)) {
						if (appleEaten(nextX, nextY)) {
							snake.grow();
						}
						field.grid[nextY][nextX] = snake.symbol;
						moveSnake(nextX, nextY);
						snake.prevDir = DIR_RIGHT;	
					}
					break;
			}
		}
		
		void moveSnake(int _nextX, int _nextY) {
			eraseSnake();  // the snake is erased. Inside field.grid now there is no snake
			snake.updatePosition(_nextX, _nextY);
			printSnake();  // the snake is again inserted inside field.grid (after position update)
		}
		
		void eraseSnake() {
			for (int i = 0; i < snake.length; i ++) {
				field.grid[snake.pos[i][1]][snake.pos[i][0]] = ' ';
			}
		}
		
		void printSnake() {
			for (int i = 1; i < snake.length; i ++) {
				field.grid[snake.pos[i][1]][snake.pos[i][0]] = snake.symbol;
			}
		}


	private:
		bool isNextPosValid(int _nextX, int _nextY) {
			if (field.grid[_nextY][_nextX] == VERTICAL_BORDER || field.grid[_nextY][_nextX] == HORIZONTAL_BORDER || field.grid[_nextY][_nextX] == snake.symbol) {
				gameEnded = true;
				return false;
			}
			return true;
		}
		
		bool appleEaten(int _nextX, int _nextY) {
			if (field.grid[_nextY][_nextX] == APPLE_CHAR) {
				spawnApple(); // a new apple appears inside the field
				return true;
			}
			return false;
		}
};
