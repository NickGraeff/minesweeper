/*
* To change this license header, choose License Headers in Project Properties.
* To change this template file, choose Tools | Templates
* and open the template in the editor.
*/

/*
* File:   main.cpp
* Author: Nick
*
* Created on August 23, 2017, 5:32 PM
*/

#include <cstdlib>
#include <iostream>
#include <time.h>
#include <SFML/Graphics.hpp>
#include "boardClass.h"


using namespace sf;

/*
*
*/
int main(int argc, char** argv) {
	board *mineSweeper;
	int boardSize;

	std::cout << "Please enter the board size you would like: " << std::endl;
	std::cin >> boardSize;

	mineSweeper = new board(boardSize);

	srand(time(0));

	RenderWindow *app = new RenderWindow(VideoMode(boardSize * 32, boardSize * 32), "MineSweeper!");

	Texture t;
	t.loadFromFile("./tiles.jpg");
	Sprite s(t);

	while (app->isOpen() && !mineSweeper->didTheyWin()) {
		Vector2i pos = Mouse::getPosition((*app));
		int x = pos.x / 32;
		int y = pos.y / 32;
		Event e;

		while (app->pollEvent(e)) {
			if (e.type == Event::Closed) {
				app->close();
			}
			if (e.type == Event::MouseButtonPressed)
				if (e.key.code == Mouse::Left) {
					if (!mineSweeper->isThereAMine(x, y)) {
						mineSweeper->markItUsed(x, y);
					} else {
						return 0;
					}
				} 
		}

		app->clear(Color::White);
		for (int i = 0; i < boardSize; i++) {
			for (int j = 0; j < boardSize; j++) {
				if (mineSweeper->didTheyPickIt(i, j)) {
					s.setTextureRect(IntRect(mineSweeper->whatsItsNumber(i, j) * 32, 0, 32, 32));
				} else {
					s.setTextureRect(IntRect(10 * 32, 0, 32, 32));
				}
				s.setPosition(i * 32, j * 32);
				app->draw(s);
			}
		}
		app->display();

	}

	return 0;
}
