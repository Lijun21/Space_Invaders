/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 20:27:08 by lwang             #+#    #+#             */
/*   Updated: 2018/01/12 20:27:12 by lwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Enemy.class.hpp"
#include "Alien.class.hpp"

using namespace std;


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
    raw();//enter raw modal
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
        // enemies[i][0] = rand() % 30 + 3;
        // enemies[i][1] = rand() % 3 + 1;
        enemy[i].setPos((rand() % 30 + 3), (rand() % 3 + 1));
        attron(A_STANDOUT | A_UNDERLINE);
        // mvprintw(randam_enemies_y, randam_enemies_x, "@");
        mvprintw(enemy[i].getY(), enemy[i].getX(), "@");
        attroff(A_STANDOUT | A_UNDERLINE);
    }

    


    // move(60, 50);

    start_color();
    init_pair(1, COLOR_BLUE, COLOR_GREEN);

    attron(COLOR_PAIR(1));
    mvaddch(20, 25, 'P');
    attroff(COLOR_PAIR(1));

    getch();
    endwin();

    return 0;
}
