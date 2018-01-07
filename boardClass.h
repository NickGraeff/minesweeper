/*
* To change this license header, choose License Headers in Project Properties.
* To change this template file, choose Tools | Templates
* and open the template in the editor.
*/

/*
* File:   boardClass.h
* Author: nicksnacs
*
* Created on August 19, 2017, 6:47 AM
*/

#ifndef BOARDCLASS_H
#define BOARDCLASS_H

class board {
public:
	board(int userSize);
	board();
	~board();
	bool isThereAMine(int row, int column);
	void markItUsed(int row, int column);
	int whatsItsNumber(int row, int column);
	bool didTheyPickIt(int row, int column);
	void printBoard();
	bool didTheyWin();

private:
	int howManyMinesAroundIt(int row, int column);
	int ** boardArray;
	bool ** userPickedPositions;
	int numberOfMines;
	int boardSize;
	int pickedCorrectly;
};

#endif /* BOARDCLASS_H */