#include "MyString.h"
#include <cstring>
#include <iostream>

void MyString::copy(const MyString& other)
{
	size = other.size;
	
	if (other.empty())
		arr = nullptr;
	else
	{
		arr = new char[size];
		for (int i = 0; i < size; i++)
			arr[i] = other.arr[i];
	}
}

void MyString::erase()
{
	delete[] arr;
}

MyString::MyString() : arr(nullptr),size(0)
{
//	arr = nullptr;
//	size = 0;
}

MyString::MyString(const char* str)
{
	size = strlen(str);
	if (size == 0)
		arr = nullptr;
	else
	{
		arr = new char[size];
		for (int i = 0; i < size; i++)
			arr[i] = str[i];
	}
}

MyString::MyString(const MyString& other)
{
	copy(other);
}

MyString& MyString::operator=(const MyString& other)
{
	if (this != &other)
	{
		erase();
		copy(other);
	}
	return *this;
}

MyString::~MyString()
{
	erase();
}

int MyString::length()
{
	return size;
}

char& MyString::at(unsigned indx)
{
	if (indx >= size)
		throw std::exception("Invalid index");

	return arr[indx];
}

int MyString::find(char c, unsigned startPos)
{
	for (int i = startPos; i < size; i++)
		if (arr[i] == c)
			return i;

	return -1;
}

bool MyString::empty() const
{
	return size==0;
}

MyString MyString::substr(unsigned pos, unsigned n)
{
	if(pos >= size)
		throw std::exception("Invalid index");

	if (n == 0)
		return MyString(); // създаваме и връщаме празен низ

	MyString ans;
	if (pos + n > size)
		ans.size = size - pos;
	else
		ans.size = n;

	ans.arr = new char[ans.size];
	
	for (int i = pos; i < pos + n && i < size; i++)
		ans.arr[i-pos] = arr[i];

	return ans;
}

void MyString::append(const MyString& str)
{
	// текущия обект е обекта, от който е извикан метода append
	if (empty())
	{
		// на текущия обект присвояваме str
		*this = str;
		return;
	}
	MyString temp; // временен обект, където записваме резултата
	temp.size = size + str.size;
	temp.arr = new char[ temp.size ];

	for (int i = 0; i < size; i++)
		temp.arr[i] = arr[i]; // копираме масива

	for (int i = 0; i < str.size; i++)
		temp.arr[i + size] = str.arr[i]; // копираме и масива на str

	*this = temp; // записваме резултата в текущия обект
}

void MyString::print()
{
	for (int i = 0; i < size; i++)
		std::cout << arr[i];
}
