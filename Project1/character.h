#ifndef _CHARACTER_H_
#define _CHARACTER_H_
#include<iostream>

class word
{
public:
	void readword(char* filename);
	void copycontent(char* str);
	void enscript(int mode);
	bool compare(char* charac);
	int lenght();
	char* getcontent() const;
	char* getenscript() const;
	word();

private:
	char* m_content;
	char* m_enscript;
	char* m_token;
};

static int score, life;
static char* playername;

char* shift(char* str);

#endif