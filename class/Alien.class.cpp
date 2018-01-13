/* ************************************************************************** */
/*                                                                            */
/*    Alien.class.cpp     	 _             _              :::      ::::::::   */
/*    By: mlu               | |           | |           :+:      :+:    :+:   */
/*     ___  __ _  __ _ _ __ | | __ _ _ __ | |_        +:+ +:+         +:+     */
/*    / _ \/ _` |/ _` | '_ \| |/ _` | '_ \| __|     +/+  +:+       +/+        */
/*   |  __/ (_| | (_| | |_) | | (_| | | | | |_    +/+/+/+/+/+   +/+           */
/*    \___|\__, |\__, | .__/|_|\__,_|_| |_|\__|        /+/    /+/             */
/*          __/ | __/ | |                             ///   ////////.fr       */
/*         |___/ |___/|_|                                                     */
/* ************************************************************************** */

#include <Space.Invaders.hpp>

Alien::Alien(void) : Enemy() {}

Alien::Alien(int x, int y) : Enemy(x, y) {}

Alien::Alien(Alien &obj) { 
	*this = obj;
}

Alien::~Alien(void) {}

Alien &Alien::operator=(Alien const &r) {
	this->_x = r._x;
	this->_y = r._y;
	this->_life = r._life;
	return (*this);
}

int			Alien::movement(void) {
	float prob = 1.0 * rand() / RAND_MAX;

	if (prob < 0.45) {
		if (this->_x > 0)	moveLeft();
		else				moveRight();
	}
	else if (prob < 0.9) {
		if (this->_x < 50)	moveRight();
		else				moveLeft();
	}
	else {
		if (this->_y < 20)	moveDown();
		else				{ this->_life = 0; return (1); }
	}
	return (0);
}

int			Alien::isAlive(void) {
	return (this->_life);
}
