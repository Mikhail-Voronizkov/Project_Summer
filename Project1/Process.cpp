#include"Process.h"
#include"character.h"
#include <Windows.h>
#include<iostream>
#include <time.h>
#include <conio.h>

using namespace std;

void resizeConsole(int width, int height)
{
	_COORD coord;
	coord.X = width;
	coord.Y = height;
	HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);      // Get Handle 
	SetConsoleScreenBufferSize(Handle, coord);
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}

void GotoXY(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void resetdata() {
	level = 1;
	life = 3;
	line = 0;
	score = 0;
	strcpy(playername,"Player_1");
}

void encrypt(Word &ch) {
	int len = ch.lenght();
	srand(time(NULL));
	int mode = rand() % 2 + 1;
	int deviation = rand() % (len - 1);
	ch.encrypt(mode);
	ch.shift(deviation);
}

