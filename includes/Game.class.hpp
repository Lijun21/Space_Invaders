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
		void	spawnEnemy(void);
		void	spawnPlayer(void);
		void	getInput(int i);

		void	moveEnemies(int i);


	private:

		int		_input;
		Alien 	_enemy[10];
		Player	_player;
		int		_endgame;

};

#endif
