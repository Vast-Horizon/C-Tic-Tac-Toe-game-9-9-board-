/*
********************************
C++ Tic-Tac-Toe game (9*9 board)
********************************
Developer: Fiavi Y.
Data: 12/18/2020
********************************
Players: 2.  X v.s. O
Playing time: ~5 minutes

This is a Tic-tac-toe "ish" game.
On a 9*9 playing board, the player who succeeds in placing *four* of their marks (X or O) 
in a diagonal, horizontal, or vertical row is the winner.

The program is able to:
 Implement the game
 Detect the winner 
 Check whether a coordinate is already occupied
 track the numbers of X and O on the borad
**/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>


using namespace std;
//matrix size constants
int const ROWS = 9;
int const COLS = 9;
//function prototype
bool testMatrix(char m[][COLS]);
bool checkIfUcanPutItHere(int m[][2], int x, int y);

int main() {

	//define a 9*9 matrix for the playing board
	char matrix[9][9];

	//initialize the board matrix
	string enter;
	for (int i = 0; i < ROWS; i++) {

		for (int j = 0; j < COLS; j++) {
			matrix[i][j] = '.';
		}

	}
	cout << "This is a 9*9 board\n";
	for (int i = 0; i < ROWS; i++) {

		for (int j = 0; j < COLS; j++) {
			cout << matrix[i][j] << "    ";
		}
		cout << endl<<endl;
	}

	system("pause");

	cout << "Each coordinate of the board is shown below\n";
	for (int i = 0; i < ROWS; i++) {

		for (int j = 0; j < COLS; j++) {
			cout <<"("<< i<<" "<<j<< ") ";
		}
		cout << endl<<endl;
	}

	cout << "During the game, enter the coordinate in two number form. ex: 2 3" << endl;
	cout << "The playing pieces are X and O\n";
	
	
	system("pause");

	//start the game
	cout << "\n-----Game Starts-----\n";
	//define a  matrix to store coordinates
	int xyMatrix[81][2];
	int m_X = 0, m_Y = 0;
	int counter = 1;


	for (int i = 0; i < 81; i++) {

	
			xyMatrix[i][0] = 9;
			xyMatrix[i][1] = 9;

	}

	cout << endl;

	while (1) {
		char piece;
		int x, y;
		do {
			cout << "X or O\n";
			cin >> piece;
		} while (piece != 'X' && piece != 'O');

		do {
			//clear the previous input
			cin.clear();
			cin.ignore(10, '\n');

			cout << "Where?\n";
			
		} while (!(cin >> x >> y)||x>8 || y>8 || x<0 || y < 0);
		
		bool putFlag = checkIfUcanPutItHere(xyMatrix, x, y);

		if (putFlag) {
			matrix[x][y] = piece;

			xyMatrix[m_X][0] = x;
			xyMatrix[m_X][1] = y;
			cout << xyMatrix[m_X][0] << xyMatrix[m_X][1] << endl;

			m_X++;
		}
		
		int countX = 0, countO = 0;

		for (int i = 0; i < ROWS; i++) {

			for (int j = 0; j < COLS; j++) {
				cout << matrix[i][j] << "  ";
				if (matrix[i][j] == 'X') {
					countX++;
				}
				else if(matrix[i][j] == 'O') {
					countO++;
				}
			}
			cout << endl;
		}
		cout << "\t*counter*" << endl;
		cout << "\t  X " <<" "<< "O" << endl;
		cout <<"\t  "<<countX << "  " << countO<< endl;
		cout << "\t*********" << endl;

		if (testMatrix(matrix)) {
			cout << "\n------Game Over------\n";
			break;
			
		}
	}


	

	return 0;
}

bool checkIfUcanPutItHere(int m[][2], int x, int y) {
	for (int i = 0; i < 81; i++) {

		if (m[i][0] == x && m[i][1] == y) {
			cout << "You can't put it here\n";
			return false;
		}

	}

	return true;

}
bool testMatrix(char m[][COLS]) {


	// check rows
	for (int i = 0; i < ROWS; i++) {
		//start test from the first element of a row, which always has a index number(i,0)
		char currentXO = m[i][0];
		//initialize a counter
		int counter = 0;

		for (int j = 0; j < COLS; j++) {
			//check if the second value equals the first one
			if (m[i][j] == currentXO&& m[i][j]!='.') {

				//if true, the counter plus one
				counter++;

				//if there are 3 consecutive numbers, return true
				if (counter == 4) {
					cout << "\nThe winner is: " << m[i][j] << endl;
					return true;
				}
			}
			else {
				//if false, then let currentXO equal to the current number
				//check next value
				currentXO = m[i][j];
				counter = 1;
			}

		}
	}

	// check columns
	for (int j = 0; j < COLS; j++) {
		//start test from the first element of a column, which always has a index number(0,j)
		int counter = 0;
		char currentOX = m[0][j];

		for (int i = 0; i < ROWS; i++) {

			if (m[i][j] == currentOX && m[i][j] != '.') {
				counter++;

				if (counter == 4) {
					cout << "The winner is: " << m[i][j] << endl;
					return true;
				}
			}
			else {
				currentOX = m[i][j];
				counter = 1;
			}

		}
	}


	//check diagonal, from bottom left to top lift
	for (int i = 8; i > 0; i--) {
		int x = i;
		int y = 0;
		int consecutive = 0;
		char currentXO = m[x][y];

		while (x >= 0) {
			if (m[x][y] == currentXO && m[x][y] != '.') {
				consecutive++;
				if (consecutive == 4) {
					cout << "The winner is: " << m[x][y] << endl;
					return true;
				}
			}
			else {
				consecutive = 1;
				currentXO = m[x][y];
			}
			x--;
			y++;
		}
	}

	//check diagonal, from bottom right to top right
	for (int i = 8; i > 0; i--) {
		int x = 8;
		int y = i;
		int consecutive = 0;
		char currentXO = m[x][y];

		while (x >= 0) {
			if (m[x][y] == currentXO && m[x][y] != '.') {
				consecutive++;
				if (consecutive == 4) {
					cout << "The winner is: " << m[x][y] << endl;
					return true;
				}
			}
			else {
				consecutive = 1;
				currentXO = m[x][y];
			}
			x--;
			y++;
		}
	}

	//check diagonal, from top left to top right
	for (int i = 0; i < 9; i++) {
		int x = 0;
		int y = i;
		int consecutive = 0;
		char currentXO = m[x][y];

		while (x < 9) {
			if (m[x][y] == currentXO && m[x][y] != '.') {
				consecutive++;
				if (consecutive == 4) {
					cout << "The winner is: " << m[x][y] << endl;
					return true;
				}
			}
			else {
				consecutive = 1;
				currentXO = m[x][y];
			}
			x++;
			y++;
		}
	}

	//check diagonal,from top left to bottom left
	for (int i = 0; i < 9; i++) {
		int x = i;
		int y = 0;
		int consecutive = 0;
		char currentXO = m[x][y];

		while (x < 9) {
			if (m[x][y] == currentXO && m[x][y] != '.') {
				consecutive++;
				if (consecutive == 4) { 
					cout << "The winner is: " << m[x][y] << endl;
					return true; }

			}
			else {
				consecutive = 1;
				currentXO = m[x][y];
			}
			x++;
			y++;
		}
	}

	//return false by default
	return false;


}
