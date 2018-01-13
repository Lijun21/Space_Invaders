/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 20:27:08 by lwang             #+#    #+#             */
/*   Updated: 2018/01/12 21:55:26 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include "Enemy.class.hpp"
#include "Alien.class.hpp"

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

    bool endgame = false;
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
    
    /*
    ** michael change
    */
    Alien enemy[10];

    // mvprintw(5, 5, "Movement");
    // mvaddch(6, 5, '@');

    for (int i = 0; i < 10; i++){
        enemy[i].setPos((rand() % 30 + 3), (rand() % 3 + 1));
        attron(A_STANDOUT | A_UNDERLINE);
        mvprintw(enemy[i].getY(), enemy[i].getX(), "@");
        attroff(A_STANDOUT | A_UNDERLINE);
    }

    int p_x = 25;
    int p_y = 20;
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);

    int c;
	int cnt;

    start_color();
    init_pair(1, COLOR_BLUE, COLOR_GREEN);
    while(endgame == false)
    {
        if ((c = getch()) != ERR)
        {
            mvaddch(p_y, p_x, ' ');
            player_move(c, &p_x, &p_y);
            attron(COLOR_PAIR(1));
            mvaddch(p_y, p_x, 'P');
            attroff(COLOR_PAIR(1));
            refresh();
        }
        else if (cnt % 60000 == 0)
        {
            for (int i = 0; i < 10; i++){
                mvprintw(enemy[i].getY(), enemy[i].getX(), " ");
            }
              for (int i = 0; i < 10; i++){
                // if (int c = getch())
                //     player_move(c, &p_x, &p_y);
                enemy[i].moveRight();
                attron(A_STANDOUT | A_UNDERLINE);
                mvprintw(enemy[i].getY(), enemy[i].getX(), "@");
                attroff(A_STANDOUT | A_UNDERLINE);
            }
            //sleep(1);
            refresh();
        }
		cnt++;
		if (cnt > 100000000)
			cnt = 0;
        // sleep(1);
        // refresh();
    }
    endwin();

    return 0;
}
