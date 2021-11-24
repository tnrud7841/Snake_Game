#define _CRT_SECURE_NO_WARNINGS
#include <ncurses.h>
#include <iostream>
#include <fstream>
#include "map.h"
#include "score.h"

using namespace std;

extern int s;
int result;
int main(){
  initscr();
  resize_term(200, 200);
  init_pair(1, COLOR_WHITE, COLOR_BLACK);
  WINDOW * win1;
  curs_set(0);
  win1 = newwin(50,50,3,3);
  wbkgd(win1, COLOR_PAIR(1));
  wattron(win1, COLOR_PAIR(1));
  map(win1);
  score_box();
  while(1){
    key(win1);
    if(fail()==false) break;
    else continue;
  }
  map(win1);
  mvwprintw(win1, 2, 2,"!THE END!");
  delwin(win1);
  endwin();
}
