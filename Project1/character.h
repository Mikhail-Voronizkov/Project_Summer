#pragma pack(1)
#ifndef _CHARACTER_H_
#define _CHARACTER_H_
#include<iostream>

class word
{
public:
	void readword(char* filename);
	void enscript(int mode);
	bool compare(char* charac);
	char* getcontent() const;
	char* getenscript() const;

private:
	char* m_content;
	char* m_enscript;
	char* m_token;
};


#endif
