#include <iostream>
#include<string.h>
#include"character.h"

using namespace std;

int main() {
	word str;
	char s[] = "Hello";
	str.copystr(s);
	str.enscript(1);
	cout << str.getenscript() << endl;
	return 0;
}