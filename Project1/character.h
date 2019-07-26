#ifndef _CHARACTER_H_
#define _CHARACTER_H_

class Word
{
public:
	void readfile(const char* filename, int line);	//Đọc dòng thứ n trong file//
	void copycontent(char* str);	//Copy nội dung của str vào m_content//
	void encrypt(int mode);			//Mã hóa m_content thành m_encryt//
	void shift(int deviation);		//Dịch chuyển các ký tự sang trái n vị trí (mảng quay vòng)//
	bool compare(char* str);		//So sánh str có giống với m_content không//
	int lenght();
	char* getcontent() const;	//Trả về nội dung của m_content//
	char* getencrypt() const;	//Trả về nội dung của m_encrypt//
	Word();

private:
	char* m_content;
	char* m_encrypt;
};

#endif
