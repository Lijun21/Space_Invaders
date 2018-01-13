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

Game::Game(void) : _endgame(1) {
	this->_bullet = new Bullet[16];
	spawnEnemy();
	spawnPlayer();
}

Game::Game(Game &obj) { 
	*this = obj;
}

Game::~Game(void) {
	delete [] this->_bullet;
}

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

void		Game::moveEnemies(void) {
	for (int i = 0; i < 10; i++){
			mvprintw(_enemy[i].getY(), _enemy[i].getX(), " ");
		}
	for (int i = 0; i < 10; i++){
		if (_enemy[i].checkLife()) {
			_enemy[i].moveRight();
			attron(A_STANDOUT | A_UNDERLINE);
			mvprintw(_enemy[i].getY(), _enemy[i].getX(), "@");
			attroff(A_STANDOUT | A_UNDERLINE);
		}
    }
    refresh();
}

void		Game::spawnPlayer(void) {
	_player = Player(25, 20);
	attron(COLOR_PAIR(1));
	mvaddch(_player.getY(), _player.getX(), 'P');
	attroff(COLOR_PAIR(1));
	refresh();
}

void		Game::getInput(int c) {
	if (c == ' ') {
		playerBullet();
		return;
	}
	if (c == KEY_RIGHT || c == KEY_LEFT)
		mvaddch(_player.getY(), _player.getX(), ' ');
	if (c == KEY_RIGHT)
		_player.moveRight();
	if (c == KEY_LEFT)
		_player.moveLeft();
	attron(COLOR_PAIR(1));
	mvaddch(_player.getY(), _player.getX(), 'P');
	attroff(COLOR_PAIR(1));
	refresh();
}

int		Game::_checkHit(int x, int y) {
	for (int i = 0; i < 10; i++){
		if (_enemy[i].isHit(x, y)) {
			return (1);
		}
    }
    return (0);
}

void		Game::moveBullets(void) {
	for (int i = 0; i < 16; i++) {
		if (this->_bullet[i].checkLife()) {
			this->_bullet[i].clearBullet();
			this->_bullet[i].moveUp();
			this->_bullet[i].shootBullet();
			if (_checkHit(this->_bullet[i].getX(), this->_bullet[i].getY())) {
				this->_bullet[i].setLife(0);
			}
		}
	}
	refresh();
}

void		Game::playerBullet(void) {
	for (int i = 0; i < 16; i++) {
		if (!this->_bullet[i].checkLife()) {
			this->_bullet[i].setInfo(_player.getX(), _player.getY(), 1);
			return;
		}
	}
}




