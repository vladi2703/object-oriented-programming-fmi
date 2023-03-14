#include <iostream>
#include "MyString.h"

int main()
{
	// тестваме
	MyString str1, str2("test string!"), str3, str4("other str");
	str2.print();
	std::cout << std::endl;

	str3 = str4;
	
	str3.print();

	str3 = str1;
	std::cout << std::endl << str3.empty() << std::endl;

	std::cout << std::endl << str2.length() << std::endl;

	for (int i = 0; i < str2.length(); i++)
		if (str2.at(i) == 't')
			str2.at(i) = '.';

	str2.print(); std::cout << std::endl;

	// тук се извиква копи конструктор реално за sub1 и sub2 - те се инициализират с върнатото от методите
	MyString sub1 = str4.substr(2,6), sub2 = str4.substr(2,100);
	sub1.print(); std::cout << std::endl;
	sub2.print(); std::cout << std::endl;

	MyString str5(str2); // създаваме str5 да е копие на str2
	str5.append(str4);
	str5.print(); std::cout << std::endl;

	std::cout << str5.find('!') << " " << str5.find('!', 14) << std::endl;
}