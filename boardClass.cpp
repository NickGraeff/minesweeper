/*
* To change this license header, choose License Headers in Project Properties.
* To change this template file, choose Tools | Templates
* and open the template in the editor.
*/

/*
* File:   boardClass.cpp
* Author: nicksnacs
*
* Created on August 19, 2017, 6:47 AM
*/
#include<cstdlib>
#include<ctime>
#include<iostream>
#include "boardClass.h"

using namespace std;


board::board(int userSize) {
	numberOfMines = userSize * userSize * .1;
	boardSize = userSize;
	pickedCorrectly = 0;
	srand(time(NULL));

	boardArray = new int *[boardSize];
	userPickedPositions = new bool *[boardSize];
	for (int i = 0; i < boardSize; i++) {
		boardArray[i] = new int[boardSize];
		userPickedPositions[i] = new bool[boardSize];
	}

	for (int i = 0; i < numberOfMines; i++) {
		int randRow = rand() % boardSize;
		int randCol = rand() % boardSize;
		for (;;) {
			if (boardArray[randRow][randCol] != 9) {
				boardArray[randRow][randCol] = 9;
				break;
			}
			randRow = rand() % boardSize;
			randCol = rand() % boardSize;
		}
	}

	for (int i = 0; i < boardSize; i++) {
		for (int j = 0; j < boardSize; j++) {
			if (boardArray[i][j] != 9) {
				boardArray[i][j] = howManyMinesAroundIt(i, j);
			}
			userPickedPositions[i][j] = false;
		}
	}
}

board::board() : board(10) {

}

board::~board() {
	for (int i = 0; i < boardSize; i++) {
		delete[] boardArray[i];
		delete[] userPickedPositions[i];
	}
	delete[] boardArray;
	delete[] userPickedPositions;
}


bool board::isThereAMine(int row, int column) {
	if (boardArray[row][column] == 9) {
		return true;
	}
	return false;
}


void board::markItUsed(int row, int column) {
	if (!userPickedPositions[row][column]) {
		pickedCorrectly++;
		userPickedPositions[row][column] = true;
		if (boardArray[row][column] == 0) {
			for (int i = -1; i < 2; i++) {
				for (int j = -1; j < 2; j++) {
					if (!((row == 0 && i == 1) ||
						(row == boardSize - 1 && i == -1) ||
						(column == 0 && j == 1) ||
						(column == boardSize - 1 && j == -1))) {
						if (!userPickedPositions[row - i][column - j]) {
							markItUsed(row - i, column - j);
						}
					}
				}
			}
		}
	}
}

int board::whatsItsNumber(int row, int column) {
	return boardArray[row][column];
}

bool board::didTheyPickIt(int row, int column) {
	return userPickedPositions[row][column];
}


int board::howManyMinesAroundIt(int row, int column) {
	int surroundingMines = 0;

	for (int i = -1; i < 2; i++) {
		for (int j = -1; j < 2; j++) {
			if (!((row == 0 && i == 1) ||
				(row == boardSize - 1 && i == -1) ||
				(column == 0 && j == 1) ||
				(column == boardSize - 1 && j == -1))) {
				if (boardArray[row - i][column - j] == 9) {
					surroundingMines++;
				}
			}
		}
	}
	return surroundingMines;
}


void board::printBoard() {
	for (int i = 0; i < boardSize; i++) {
		for (int j = 0; j < boardSize; j++) {
			if (!userPickedPositions[i][j]) {
				cout << "x ";
			}
			else {
				cout << boardArray[i][j] << " ";
			}
		}
		cout << endl;
	}
	//    
	//    cout << endl << endl << "CHEAT SHEET" << endl;
	//    for (int i = 0; i < boardSize; i++) {
	//        for (int j = 0; j < boardSize; j++) {
	//                cout << boardArray[i][j] << " ";
	//        }
	//        cout << endl;
	//    }
}


bool board::didTheyWin() {
	if (pickedCorrectly >= boardSize*boardSize - numberOfMines) {
		return true;
	}
	return false;
}