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

void		Alien::moveDown(void) {
	this->_y++;
}

int			Alien::isAlive(void) {
	return (this->_life);
}
