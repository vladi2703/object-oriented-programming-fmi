#include <iostream>
#include <string>

template <typename T>
void swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

int main()
{
	std::string c1("asd"), c2("qwert");
	swap(c1, c2);
	std::cout << c1 << " " << c2 << std::endl;
} 