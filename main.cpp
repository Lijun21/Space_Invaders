#include <ncurses.h>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


int main(){
    srand(time(NULL));
    bool endgame = false;
    int gamespeed = 400;
    int score = 0;
    int lives = 5;
    int randam_enemies_x;
    int randam_enemies_y;

    initscr();//creates std screen
    raw();//enter raw modal
    printw("SCORE  %d", score);
    move(0, 50);
    printw("LIVES  %d", lives);

    // addch('a');
    move(0, 0);

    // mvprintw(5, 5, "Movement");
    // mvaddch(6, 5, '@');

    for (int i = 0; i < 10; i++){
        randam_enemies_x = rand() % 30 + 3;
        randam_enemies_y = rand() % 3 + 1;
        attron(A_STANDOUT | A_UNDERLINE);
        mvprintw(randam_enemies_y, randam_enemies_x, "@");
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