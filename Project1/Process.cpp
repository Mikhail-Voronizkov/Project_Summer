#include"Process.h"
#include"character.h"
#include <Windows.h>
#include<iostream>
#include <time.h>
#include <conio.h>

using namespace std;

//Global
int score, life, line, level;
char playername[20], answer[256];

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
	line = 1;
	score = 0;
	strcpy(answer, "");
}

void encrypt(Word &ch) {
	int len = ch.lenght();
	srand(time(NULL));
	int mode = rand() % 2 + 1;
	int deviation = rand() % (len - 1);
	ch.encrypt(mode);
	ch.shift(deviation);
}

bool processpassgame(Word ch, char answer[]) {
	if (ch.compare(answer))
		return true;
	else
	{
		life = life - 1;
		return false;
	}
}

void start() {
	Word ch;
	while (true) {
		//Check gameover//
		if (life <= 0)
			gameover();
		//Print quest//
		ch.readfile("STRING.txt", line);
		encrypt(ch);
		cout << ch.getencrypt() << endl;
		//Recieve answer
		do {
			cout << "life: "<< life << endl;
			cout << "YOUR ANSWER: ";
			gets_s(answer, 256);
			cout << endl;
		} while (!processpassgame(ch, answer) && life > 0);
		//next word
		line++;
	}
}

void newgame() {
	resetdata();
	start();
}


void gameover() {
	system("cls");
	cout << "GAME OVER" << endl;
	Sleep(4000);
	exit(0);
	/*cout << "Press 1 to play again" << endl;
	cout << "Press 2 to exit" << endl;
	int choose = 0;
	cin >> choose;
	if (_kbhit()) {
		if (choose == 1)
			newgame();
		else if (choose == 2)
			exit(0);
	}*/
}

