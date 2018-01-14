/* ************************************************************************** */
/*                                                                            */
/*    Game.class.hpp         _             _              :::      ::::::::   */
/*    By: mlu               | |           | |           :+:      :+:    :+:   */
/*     ___  __ _  __ _ _ __ | | __ _ _ __ | |_        +:+ +:+         +:+     */
/*    / _ \/ _` |/ _` | '_ \| |/ _` | '_ \| __|     +/+  +:+       +/+        */
/*   |  __/ (_| | (_| | |_) | | (_| | | | | |_    +/+/+/+/+/+   +/+           */
/*    \___|\__, |\__, | .__/|_|\__,_|_| |_|\__|        /+/    /+/             */
/*          __/ | __/ | |                             ///   ////////.fr       */
/*         |___/ |___/|_|                                                     */
/* ************************************************************************** */

#ifndef Game_H
# define Game_H

# include <Space.Invaders.hpp>

class	Game {

	public:

		Game(void);
		Game(Game &obj);
		virtual ~Game(void);
		Game &operator=(Game const &r);

		int		checkEndgame(void);
		void	getInput(int c);

		void	spawnEnemy(void);
		void	moveEnemies(void);

		void	spawnPlayer(void);
		void	movePlayer(void);

		void	playerBullet(void);
		void	moveBullets(void);

		void	enemyBullet(void);

		int		getScore(void);
		int		getLife(void);

		void	drawPlayer(void);
		void	drawEnemy(void);

	private:

		int		_checkHit(int x, int y);
		int		_checkPHit(int x, int y);

		int		_death;
		int		_input;
		Alien 	_enemy[10];
		Player	_player;
		int		_endgame;
		Bullet	*_bullet;
		Bullet	*_ebullet;

		int		_score;

		int		_bspd;

};

#endif
