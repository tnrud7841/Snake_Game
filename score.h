#include <ncurses.h>
#include <iostream>
#include <fstream>
using namespace std;
void score_box(){
  initscr();
  mvprintw(2,52,"snake game\n");
  mvprintw(4,48,"<snake game score>\n");
  mvprintw(6,50,"score: %d",s);
  mvprintw(8,48,"<snake game mission>");
  mvprintw(10,50,"mission: ");
  refresh();
}
