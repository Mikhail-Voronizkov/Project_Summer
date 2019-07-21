#include <iostream>
#include<string.h>
#include"character.h"

using namespace std;

int main() {
	char str[]="UNDERSTAND";
	char* m=shift(str);
	cout << m;
	return 0;
}