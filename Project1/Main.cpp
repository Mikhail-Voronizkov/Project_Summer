#include <iostream>
#include<string.h>
#include"character.h"
#include"Process.h"

using namespace std;

int main() {
	Word ch;
	ch.readfile("STRING.txt", 2);
	cout << ch.getcontent() << endl;
	return 0;
}