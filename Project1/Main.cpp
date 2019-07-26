#include <iostream>
#include<string.h>
#include<time.h>
#include"character.h"
#include"Process.h"

using namespace std;

int main() {
	Word ch;
	char* str1;
	char s[] = "HELLO";
	resetdata();
	ch.readfile("STRING.txt", 2);
	encrypt(ch);
	cout << ch.getencrypt();
}