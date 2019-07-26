#ifndef _PROCESS_H_
#define _PROCESS_H_
#include<iostream>
#include"character.h"

static int score, life, line, level;
static char playername[20], answer[256];

void resizeConsole(int width, int height);
void textcolor(int x);
void GotoXY(int x, int y);
void resetdata();
void encrypt(Word &ch);
#endif
