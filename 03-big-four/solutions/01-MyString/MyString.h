#ifndef MYSTRING_H
#define MYSTRING_H

class MyString
{
private:
	unsigned size;
	char * arr;

	void copy(const MyString&);
	void erase();

public:
	MyString();
	MyString(const char* str); 
	
	MyString(const MyString&);
	MyString& operator=(const MyString&);
	~MyString();

	int length(); 
	char& at(unsigned indx);
	int find(char c, unsigned startPos = 0);
	bool empty() const;
	MyString substr(unsigned pos = 0, unsigned n = 0); 
	void append(const MyString& str); 
	void print();
};


#endif
