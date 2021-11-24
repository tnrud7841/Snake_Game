#include <ncurses.h>
#include <iostream>
#include <fstream>
#define JUST 0
#define WALL 1
#define IW 2
#define HEAD 3
#define BODY 4

using namespace std;
int s = 0;
int arr[21][21]={{2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2},
                {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                {1,0,0,0,0,0,3,4,4,0,0,0,0,0,0,0,0,0,0,0,1},
                {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                {2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2}};

void go(int y, int x){
  x = 2*x;
  move(y,x);
}
void map(WINDOW * win){
  wrefresh(win);
  int c;
  for(int i=0;i<21;i++){
    for(int j=0;j<21;j++){
      int c = arr[i][j];
      switch(c){
        case 0:
          go(i,j);
          printw("");
          break;
        case 1:
          go(i,j);
          printw("*");
          break;
        case 2:
          go(i,j);
          printw("*");
          break;
        case 3:
          go(i,j);
          printw("0");
          break;
        case 4:
          go(i,j);
          printw("-");
          break;
      }
    }printw("\n");
  }
    wrefresh(win);
}


int head_x = 6;
int head_y = 6;
extern int result;
void key(WINDOW * win){
  curs_set(0);
  keypad(stdscr, TRUE);
  int key;
  key = getch();
  switch(key){
    case KEY_UP:
      arr[head_x][head_y] = BODY;
      arr[head_x+2][head_y] = 0;
      head_x-=1;
      go(head_x, head_y);
      arr[head_x][head_y] = HEAD;
      map(win);
      break;

    case KEY_DOWN:
      arr[head_x][head_y] = BODY;
      head_x+=1;
      go(head_x+1, head_y);
      arr[head_x][head_y] = HEAD;
      map(win);
      break;
    case KEY_LEFT:
      arr[head_x][head_y] = BODY;
      head_y-=1;
      go(head_x, head_y);
      arr[head_x][head_y] = HEAD;
      map(win);
      break;
    case KEY_RIGHT:
      arr[head_x][head_y] = BODY;
      head_y+=1;
      go(head_x, head_y+1);
      arr[head_x][head_y] = HEAD;
      map(win);
      break;
  }
  noecho();
  getch();
  refresh();
}
bool fail(){
  if(head_x == 0 || head_x == 20 || head_y == 0 || head_y == 20) return false;
  else return true;
}
