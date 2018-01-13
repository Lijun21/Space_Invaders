/* ************************************************************************** */
/*                                                                            */
/*    Bullet.class.cpp       _             _              :::      ::::::::   */
/*    By: mlu               | |           | |           :+:      :+:    :+:   */
/*     ___  __ _  __ _ _ __ | | __ _ _ __ | |_        +:+ +:+         +:+     */
/*    / _ \/ _` |/ _` | '_ \| |/ _` | '_ \| __|     +/+  +:+       +/+        */
/*   |  __/ (_| | (_| | |_) | | (_| | | | | |_    +/+/+/+/+/+   +/+           */
/*    \___|\__, |\__, | .__/|_|\__,_|_| |_|\__|        /+/    /+/             */
/*          __/ | __/ | |                             ///   ////////.fr       */
/*         |___/ |___/|_|                                                     */
/* ************************************************************************** */

#include <Space.Invaders.hpp>

Bullet::Bullet(void) {}

Bullet::Bullet(int x, int y) : _x(x), _y(y) {}

Bullet::Bullet(Bullet &obj) { 
	*this = obj;
}

Bullet::~Bullet(void) {}

Bullet &Bullet::operator=(Bullet const &r) {
	this->_x = r._x;
	this->_y = r._y;
	return (*this);
}

int			Bullet::getX(void) {
	return (this->_x);
}

int			Bullet::getY(void) {
	return (this->_y);
}

void		Bullet::moveDown(void) {
	this->_y++;
}

void		Bullet::moveUp(void) {
	this->_y--;
}
