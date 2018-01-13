/* ************************************************************************** */
/*                                                                            */
/*    Enemy.class.cpp     	 _             _              :::      ::::::::   */
/*    By: mlu               | |           | |           :+:      :+:    :+:   */
/*     ___  __ _  __ _ _ __ | | __ _ _ __ | |_        +:+ +:+         +:+     */
/*    / _ \/ _` |/ _` | '_ \| |/ _` | '_ \| __|     +/+  +:+       +/+        */
/*   |  __/ (_| | (_| | |_) | | (_| | | | | |_    +/+/+/+/+/+   +/+           */
/*    \___|\__, |\__, | .__/|_|\__,_|_| |_|\__|        /+/    /+/             */
/*          __/ | __/ | |                             ///   ////////.fr       */
/*         |___/ |___/|_|                                                     */
/* ************************************************************************** */

#include <iostream>
#include "Enemy.class.hpp"

Enemy::Enemy(void) : _life(1) {}

Enemy::Enemy(int x, int y) : _x(x), _y(y), _life(1) {}

Enemy::Enemy(int x, int y, int life) : _x(x), _y(y), _life(life) {}

Enemy::Enemy(Enemy &obj) { 
	*this = obj;
}

Enemy::~Enemy(void) {}

Enemy &Enemy::operator=(Enemy const &r) {
	this->_x = r._x;
	this->_y = r._y;
	this->_life = r._life;
	return (*this);
}

void		Enemy::setPos(int x, int y) {
	this->_x = x;
	this->_y = y;
}

int			Enemy::getX(void) {
	return (this->_x);
}

int			Enemy::getY(void) {
	return (this->_y);
}

void		Enemy::moveRight(void) {
	this->_x++;
}

void		Enemy::moveLeft(void) {
	this->_x--;
}

int			Enemy::isHit(int x, int y) {
	if (this->_x == x && this->_y == y)
	{
		this->_life = 0;
		return (1);
	}
	return (0);
}