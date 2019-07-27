#ifndef _PROCESS_H_
#define _PROCESS_H_
#include<iostream>
#include"character.h"

extern int score, life, line, level;
extern char playername[20], answer[256];

void resizeConsole(int width, int height);
void textcolor(int x);
void GotoXY(int x, int y);
void resetdata();
void encrypt(Word &ch);
bool processpassgame(Word ch, char answer[]);
void start();
void newgame();
void gameover();
#endif
