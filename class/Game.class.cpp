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

Game::Game(int x, int y) : _mapx(x), _mapy(y), _endgame(2), _menu(1) {
	this->_bullet = new Bullet[16];
	this->_ebullet = new Bullet[10];
	this->_score = 0;
	this->_bspd = 34;
	this->_death = 0;
	spawnEnemy();
	spawnPlayer();
	this->_player.setLife(5);
}

Game::Game(Game &obj) { 
	*this = obj;
}

Game::~Game(void) {
	delete [] this->_bullet;
	delete [] this->_ebullet;
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
	clear();
	if (this->_bspd > 4)
		this->_bspd -= 4;
	for (int i = 0; i < 10; i++) {
		_enemy[i].setPos(1 + (rand() % _mapx + 3), (rand() % 3 + 1));
		_enemy[i].setLife(1);
	}
}

void		Game::moveEnemies(void) {
	_death = 0;

	for (int i = 0; i < 10; i++){
			mvprintw(_enemy[i].getY(), _enemy[i].getX(), " ");
		}
	for (int i = 0; i < 10; i++){
		if (_enemy[i].checkLife()) {
			if(_enemy[i].movement(_mapy, _mapx)) {
				if(_player.loseLife())
					_endgame = 0;
			}
			init_pair(2, COLOR_RED, COLOR_BLACK);
			attron(COLOR_PAIR(2));
			mvprintw(_enemy[i].getY(), _enemy[i].getX(), "@");
			attroff(COLOR_PAIR(2));
		}
		if (!_enemy[i].checkLife())
			_death++;
    }
    if (_death == 10)
    	spawnEnemy();
    drawPlayer();
}

void		Game::spawnPlayer(void) {
	_player = Player(25, _mapy);
	drawPlayer();
}

void		Game::drawPlayer(void) {
	attron(COLOR_PAIR(1));
	mvaddch(_player.getY(), _player.getX(), '^');
	attroff(COLOR_PAIR(1));
	drawEnemy();
	box(stdscr, 0, 0);
	refresh();
}

void		Game::drawEnemy(void) {
	for (int i = 0; i < 10; i++){
		if (_enemy[i].checkLife()) {
			attron(COLOR_PAIR(2));
			mvprintw(_enemy[i].getY(), _enemy[i].getX(), "@");
			attroff(COLOR_PAIR(2));
		}
    }
}

void		Game::getInput(int c) {
	int a = 0;

	if (c == ' ')
		playerBullet();
	if (c == KEY_RIGHT || c == KEY_LEFT || c == '6' || c == '4'
		|| c == '1' || c == '3')
		mvaddch(_player.getY(), _player.getX(), ' ');
	if ((c == KEY_RIGHT || c == '6') && _player.getX() < _mapx)
		_player.moveRight();
	if ((c == KEY_LEFT || c == '4' ) && _player.getX() > 1)
		_player.moveLeft();
	if ((c == '3') && _player.getX() < _mapx)
	{
		playerBullet();
		_player.moveRight();
	}
	if ((c == '1') && _player.getX() > 1)
	{
		playerBullet();
		_player.moveLeft();
	}
	drawPlayer();
}

int		Game::_checkHit(int x, int y) {
	for (int i = 0; i < 10; i++){
		if (_enemy[i].checkLife() && _enemy[i].isHit(x, y)) {
			_score = _score + 1;
			return (1);
		}
	};
	return (0);
}

int		Game::_checkPHit(int x, int y) {
	if (_player.isHit(x, y)) {
		if(_player.bulletHit()) {
			_endgame = 0;
		}
		return (1);
	}
	return (0);
}

void		Game::moveBullets(void) {
	for (int i = 0; i < 16; i++) {
		if (this->_bullet[i].checkLife()) {
			this->_bullet[i].clearBullet();
			this->_bullet[i].moveUp();
			this->_bullet[i].shootBullet();
			if (this->_bullet[i].getY() == -1) {
				this->_bullet[i].setLife(0);
				this->_bullet[i].clearBullet();
			}
			if (_checkHit(this->_bullet[i].getX(), this->_bullet[i].getY())) {
				this->_bullet[i].setLife(0);
				this->_bullet[i].clearBullet();
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		if (this->_ebullet[i].checkLife()) {
			this->_ebullet[i].clearBullet();
			this->_ebullet[i].moveDown();
			this->_ebullet[i].shootEBullet();
			if (this->_ebullet[i].getY() >= (_mapy + 1)) {
				this->_ebullet[i].setLife(0);
				this->_ebullet[i].clearBullet();
			}
			if (_checkPHit(this->_ebullet[i].getX(), this->_ebullet[i].getY())) {
				this->_ebullet[i].setLife(0);
				this->_ebullet[i].clearBullet();
			}
		}
	}	
	drawPlayer();
}

void		Game::playerBullet(void) {
	for (int i = 0; i < 16; i++) {
		if (!this->_bullet[i].checkLife()) {
			this->_bullet[i].setInfo(_player.getX(), _player.getY(), 1);
			return;
		}
	}
}

void		Game::enemyBullet(void) {
	int rd = 0;

	for (int i = 0; i < 10; i++) {
		rd = rand();
		if ((rd % _bspd == 0) && !_ebullet[i].checkLife() && _enemy[i].checkLife()) {
			_ebullet[i].setInfo(_enemy[i].getX(), _enemy[i].getY(), 1);
			_ebullet[i].shootEBullet();
			return;
		}
	}
}

void		Game::moveMenu(int i) {
	if (i == 1)
	{
		this->_menu += 2;
		if (this->_menu > 5)
			this->_menu = 1;
	}
	else if (i == 2)
	{
		this->_menu -= 2;
		if (this->_menu < 1)
			this->_menu = 5;
	}

}

void		Game::menuInput(int c) {
	if (_menu == 1 && c == ' ')
		_endgame = 1;
	if (_menu == 5 && c == ' ')
		_endgame = -1;
	if (c == KEY_DOWN)
		moveMenu(1);
	if (c == KEY_UP)
		moveMenu(2);
}

int			Game::getScore(void) {
	return (this->_score);
}

int			Game::getLife(void) {
	return (this->_player.checkLife());
}

int			Game::getMenu(void) {
	return (this->_menu);
}

void		Game::setEndgame(int i) {
	this->_endgame = i;
}
