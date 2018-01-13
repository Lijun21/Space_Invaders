/* ************************************************************************** */
/*                                                                            */
/*    Bullet.class.cpp     	 _             _              :::      ::::::::   */
/*    By: mlu               | |           | |           :+:      :+:    :+:   */
/*     ___  __ _  __ _ _ __ | | __ _ _ __ | |_        +:+ +:+         +:+     */
/*    / _ \/ _` |/ _` | '_ \| |/ _` | '_ \| __|     +/+  +:+       +/+        */
/*   |  __/ (_| | (_| | |_) | | (_| | | | | |_    +/+/+/+/+/+   +/+           */
/*    \___|\__, |\__, | .__/|_|\__,_|_| |_|\__|        /+/    /+/             */
/*          __/ | __/ | |                             ///   ////////.fr       */
/*         |___/ |___/|_|                                                     */
/* ************************************************************************** */

#include <iostream>
#include "Bullet.class.hpp"

Bullet::Bullet(void) : Bullet() {}

Bullet::Bullet(int x, int y) : Bullet(x, y) {}

Bullet::Bullet(Bullet &obj) { 
	*this = obj;
}

Bullet::~Bullet(void) {}

Bullet &Bullet::operator=(Bullet const &r) {
	this->_x = r._x;
	this->_y = r._y;
	this->_life = r._life;
	return (*this);
}

int			Bullet::getX(void) {
	return (this->_x);
}

int			Bullet::getY(void) {
	return (this->_y);
}

void		Alien::moveDown(void) {
	this->_y++;
}

void		Alien::moveUp(void) {
	this->_y--;
}