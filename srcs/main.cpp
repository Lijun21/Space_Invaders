/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 20:27:08 by lwang             #+#    #+#             */
/*   Updated: 2018/01/13 16:01:21 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Space.Invaders.hpp>

using namespace std;

int main(){
    srand(time(NULL));

    Game *game = new Game();

    int gamespeed = 400;

    int score = 0;
    int lives = 5;
    int randam_enemies_x;
    int randam_enemies_y;

    char enemies[10][2];

    initscr();//creates std screen
    cbreak();//enter raw modal
    noecho();
    curs_set(0);

    // addch('a');

    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);

    int c;
	int cnt;

    start_color();
    init_pair(1, COLOR_BLUE, COLOR_GREEN);
    refresh();
    while(game->checkEndgame())
    {
        mvprintw(0, 0, "SCORE  %d", game->getScore());
        mvprintw(0, 50, "LIVES  %d", game->getLife());
        if ((c = getch()) != ERR)
            game->getInput(c);
        if (cnt % 3000 == 0)
            game->moveBullets();
        if (cnt % 6000 == 0) {
            game->moveEnemies();
            game->enemyBullet();
        }
		cnt++;
		if (cnt > 100000000)
			cnt = 0;
    }
    endwin();

    return 0;
}
