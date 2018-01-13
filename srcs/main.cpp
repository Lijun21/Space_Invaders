/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 20:27:08 by lwang             #+#    #+#             */
/*   Updated: 2018/01/12 23:59:23 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Space.Invaders.hpp>

using namespace std;


void       player_move(int c, int *x, int *y)
{
    if (c == KEY_RIGHT)
        *x = *x + 1;
    if (c == KEY_LEFT)
        *x = *x - 1;
}

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
    printw("SCORE  %d", score);
    move(0, 50);
    printw("LIVES  %d", lives);

    // addch('a');
    move(0, 0);

    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);

    int c;
	int cnt;

    start_color();
    init_pair(1, COLOR_BLUE, COLOR_GREEN);
    refresh();
    while(game->checkEndgame())
    {
        if ((c = getch()) != ERR)
            game->getInput(c);
        if (cnt % 30000 == 0)
            game->moveBullets();
        if (cnt % 60000 == 0)
            game->moveEnemies();
		cnt++;
		if (cnt > 100000000)
			cnt = 0;
    }
    endwin();

    return 0;
}
