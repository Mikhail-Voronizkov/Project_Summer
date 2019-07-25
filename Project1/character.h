#ifndef _CHARACTER_H_
#define _CHARACTER_H_

class Word
{
public:
	void readfile(const char* filename, int line);	//Đọc dòng thứ n trong file//
	void copycontent(char* str);	//Copy nội dung của str vào m_content//
	void encrypt(int mode);			//Mã hóa m_content thành m_encryt//
	bool compare(char* str);		//So sánh str có giống với m_content không//
	int lenght();
	char* getcontent() const;
	char* getencrypt() const;
	Word();

private:
	char* m_content;
	char* m_encrypt;
	char* m_token;
};

static int score, life;
static char* playername;

char* shift(char* str);		//Dịch chuyển các ký tự của str sang trái ngẫu nhiên n vị trí//


#endif
