#include"character.h"
#include<iostream>
#include<string.h>
#include<time.h>

using namespace std;

void Word::readfile(const char* filename, int line) {
	char str1[256];
	FILE* fin;
	int i = 0;
	fin = fopen(filename, "r");
	if (fin==NULL) {
		fclose(fin);
		return;
	}
	rewind(fin);
	while (!feof(fin)) {
		fgets(str1, 256, fin);
		i++;
		if (i == line) {
			int len = strlen(str1);
			m_content = (char*)malloc(len);
			strcpy(m_content, str1);
			break;
		}
	}
	fclose(fin);
}

void Word::copycontent(char* str) {
	int len = strlen(str);
	m_content = (char*)malloc(len * sizeof(char));
	strcpy(m_content, str);
}

void Word::encrypt(int mode) {
	int len = strlen(m_content);
	m_encrypt = (char*)malloc(len * sizeof(char));
	strcpy(m_encrypt, m_content);
	if (len < 2)
		return;
	if (len == 2) {
		char c = m_encrypt[1];
		m_encrypt[1]= m_encrypt[0];
		m_encrypt[0] = c;
		return;
	}
	int ai = 0;
	int bi = 0;
	char* a = (char*)malloc(len - (len / 2)* sizeof(char));
	char* b = (char*)malloc((len / 2) * sizeof(char));
	for (int i = 0; i < len; i++) {
		if (i % 2 == 0) {
			*(a + ai) = *(m_content + i);
			ai++;
		}
		else {
			*(b + bi) = *(m_content + i);
			bi++;
		}
	}
	a[ai] = '\0';
	b[bi] = '\0';
	if (mode == 1) {
		strcpy(m_encrypt, b);
		strcpy(m_encrypt + bi, a);
	}
	else if(mode==2){
		strcpy(m_encrypt, a);
		strcpy(m_encrypt + ai, b);
	}
}

bool Word::compare(char* str) {
	if (_stricmp(m_content, str) == 0)
		return true;
	return false;
}

int Word::lenght() {
	int len = 0;
	while (*m_content++)
		len++;
	return len;
}

char* Word::getcontent() const {
	return m_content;
}

char* Word::getencrypt() const {
	return m_encrypt;
}

Word::Word():m_content(NULL), m_encrypt(NULL), m_token(NULL){}

char* shift(char* str) {
	int len = strlen(str);
	if (len < 4)
		return str;
	else {
		srand(time(NULL));
		int deviation = rand() % (len-4);				
		if (deviation > len)
			deviation = deviation - len;
		char* str1 = (char*)malloc(len + 1);
		char* str2 = (char*)malloc(len + 1);
		strcpy(str1, str);
		for (int i = 0; i < len; i++) {
			if (i - deviation < 0)
				*(str2 + (i - deviation + len)) = *(str1 + i);
			else
				*(str2 + (i - deviation)) = *(str1 + i);
		}
		strcpy(str1, str2);
		str1[len] = '\0';
		return str1;
		delete[]str1;
		delete[]str2;
	}
}

