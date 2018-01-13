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

#include <iostream>
#include "Alien.class.hpp"

Alien::Alien(int x, int y) : Enemy(x, y) {}

Alien::Alien(Alien &obj) { 
	*this = obj;
}

Alien::~Alien(void) {}

Alien &Alien::operator=(Alien const &r) {
	this->_x = r._x;
	this->_y = r._y;
	return (*this);
}

int			Alien::isHit(int x, int y) {
	if (this->_x == x && this->_y == y)
	{
		this->_life = 0;
		return (1);
	}
	return (0);
}

void		Alien::moveRight() {
	this->_x++;
}

void		Alien::moveLeft() {
	this->_x--;
}

void		Alien::moveDown() {
	this->_y++;
}

int			Alien::isAlive() {
	return (this->_life);
}