#include"character.h"
#include<iostream>
#include<string.h>
#include<time.h>

using namespace std;

Word::Word() :m_content(NULL), m_encrypt(NULL) {}

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
			memmove(m_content, str1, len);

			//Trường hợp hàm fgets nhận ký tự xuống dòng//
			//Ví dụ len=6 nghĩa là str1 có 1 ký tự xuống dòng cuối chuỗi và 5 ký tự khác//
			//Trên bộ nhớ thì str1 trỏ tới vùng nhớ 7 byte = 5 byte ký tự + 1 byte '\n' + 1 byte '\0' //
			if (*(m_content + (len - 1)) == '\n') {
				*(m_content + (len - 1)) = '\0'; //Ghi đè ký tự kết thúc chuỗi lên ký tự xuống dòng. Khi đó m_content trỏ vào vùng nhớ 6 byte, 5 byte cho ký tự, 1 byte cho ký tự kết thúc chuỗi //
				break;
			}
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

	if (mode == 1) {
		memmove(m_encrypt, b, bi * sizeof(char));
		memmove(m_encrypt + bi, a, ai);
		/*strcpy(m_encrypt, b);
		strcpy(m_encrypt + bi, a);*/
	}

	else if(mode==2){
		memmove(m_encrypt, a, ai * sizeof(char));
		memmove(m_encrypt + ai, b, bi);
		/*strcpy(m_encrypt, a);
		strcpy(m_encrypt + ai, b);*/
	}

	delete[]a;
	delete[]b;
}

void Word::shift(int deviation) {
	int len = strlen(m_content);

	if (len < 4)	//Nếu m_content có ít hơn 4 ký tự thì không làm//
		return;

	if (m_encrypt == NULL) {
		m_encrypt = (char*)malloc(len * sizeof(char));
		strcpy(m_encrypt, m_content);
	}

	while (deviation > len)
		deviation = deviation - len;

	char* str1 = (char*)malloc(len + 1);
	//Dịch các phần tử sang trái theo độ lệch (mảng quay vòng)//
	for (int i = 0; i < len; i++) {
		if (i - deviation < 0)
			*(str1 + (i - deviation + len)) = *(m_encrypt + i);
		else
			*(str1 + (i - deviation)) = *(m_encrypt + i);
	}
	memmove(m_encrypt, str1, len * sizeof(char));
	delete[]str1;
	return;
}

bool Word::compare(char* str) {
	if (_stricmp(m_content, str) == 0)
		return true;
	return false;
}

int Word::lenght() {
	return strlen(m_content);
}

char* Word::getcontent() const {
	return m_content;
}

char* Word::getencrypt() const {
	return m_encrypt;
}








