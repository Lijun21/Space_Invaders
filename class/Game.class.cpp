/* ************************************************************************** */
/*                                                                            */
/*    Game.class.cpp         _             _              :::      ::::::::   */
/*    By: mlu               | |           | |           :+:      :+:    :+:   */
/*     ___  __ _  __ _ _ __ | | __ _ _ __ | |_        +:+ +:+         +:+     */
/*    / _ \/ _` |/ _` | '_ \| |/ _` | '_ \| __|     +/+  +:+       +/+        */
/*   |  __/ (_| | (_| | |_) | | (_| | | | | |_    +/+/+/+/+/+   +/+           */
/*    \___|\__, |\__, | .__/|_|\__,_|_| |_|\__|        /+/    /+/             */
/*          __/ | __/ | |                             ///   ////////.fr       */
/*         |___/ |___/|_|                                                     */
/* ************************************************************************** */

#include <Space.Invaders.hpp>

Game::Game(void) : _endgame(1) {}

Game::Game(Game &obj) { 
	*this = obj;
}

Game::~Game(void) {}

Game &Game::operator=(Game const &r) {
	this->_input = r._input;
	for (int i = 0; i < 10; i++) {
		this->_enemy[i] = r._enemy[i];
	}
	this->_player = r._player;
	this->_endgame = r._endgame;
	return (*this);
}

int			Game::checkEndgame(void) {
	return (this->_endgame);
}

void		Game::spawnEnemy(void) {
	for (int i = 0; i < 10; i++) {
		_enemy[i].setPos((rand() % 30 + 3), (rand() % 3 + 1));
		attron(A_STANDOUT | A_UNDERLINE);
		mvprintw(_enemy[i].getY(), _enemy[i].getX(), "@");
		attroff(A_STANDOUT | A_UNDERLINE);
	}
}

void		Game::moveEnemies(int i) {
	(void)i;
	for (int i = 0; i < 10; i++){
			mvprintw(_enemy[i].getY(), _enemy[i].getX(), " ");
		}
	for (int i = 0; i < 10; i++){
		_enemy[i].moveRight();
		attron(A_STANDOUT | A_UNDERLINE);
		mvprintw(_enemy[i].getY(), _enemy[i].getX(), "@");
		attroff(A_STANDOUT | A_UNDERLINE);
    }
}
