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

    initscr();//creates std screen
    cbreak();//enter raw modal
    noecho();
    curs_set(0);

    int col = 0;
    int row = 0;
    getmaxyx(stdscr, col, row);

    Game *game = new Game(row - 2, col - 2);

    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);

    int c;
	int cnt;
	start_color();
	init_pair(1, COLOR_CYAN, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    refresh();
    while(game->checkEndgame())
    {
        mvprintw(0, 0, "SCORE  %d", game->getScore());
        mvprintw(0, 50, "LIVES  %d", game->getLife());
        if ((c = getch()) != ERR)
            game->getInput(c);
        if (cnt % 5000 == 0)
            game->moveBullets();
        if (cnt % 10000 == 0) {
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
