#include <iostream>

#ifndef SET_H
#define SET_H

template<typename T>
class Set
{
	int capacity, size;
	T* arr;

	void copy(const Set<T>& other);
	void erase();
	void resize();

public:
	Set();
	Set(const Set<T> &other);
	Set<T>& operator=(const Set<T>& other);
	~Set();

	void add(const T& obj);
	bool isEmpty();
	void print(); 
	bool contains(const T& obj) const; // трябва да е const, иначе оператори + и < няма да работят
									   // защото имат константен аргумент от тип Set
	Set<T> operator+(const Set<T>& b);
	bool operator<(const Set<T>& b);
};

template<typename T>
void Set<T>::copy(const Set<T>& other)
{
	capacity = other.capacity;
	size = other.size;
	arr = new T[capacity];
	for (int i = 0; i < size; i++)
		arr[i] = other.arr[i];
}

template<typename T>
void Set<T>::erase()
{
	delete[] arr;
}

template<typename T>
void Set<T>::resize()
{
	capacity *= 2;
	T* new_arr = new T[capacity];
	for (int i = 0; i < size; i++)
		new_arr[i] = arr[i];
	delete[] arr;
	arr = new_arr;
}

template<typename T>
Set<T>::Set()
{
	const int init_cap = 8;
	arr = new T[init_cap];
	capacity = init_cap;
	size = 0;
}

template<typename T>
Set<T>::Set(const Set<T>& other)
{
	copy(other);
}

template<typename T>
Set<T>& Set<T>::operator=(const Set<T>& other)
{
	if (this != &other)
	{
		erase();
		copy(other);
	}
	return *this;
}

template<typename T>
Set<T>::~Set()
{
	erase();
}

template<typename T>
void Set<T>::add(const T& obj)
{
	if (!contains(obj))
	{
		if (capacity == size)
			resize();

		arr[size] = obj;
		size++;
	}
}

template<typename T>
bool Set<T>::isEmpty()
{
	return size==0;
}

template<typename T>
void Set<T>::print()
{
	for (int i = 0; i < size; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

template<typename T>
bool Set<T>::contains(const T& obj) const
{
	for (int i = 0; i < size; i++)
		if (arr[i] == obj)
			return true;

	return false;
}

template<typename T>
Set<T> Set<T>::operator+(const Set<T> &b)
{
	Set<T> c(b);

	for (int i = 0; i < size; i++)
		c.add(arr[i]);

	return c;
}

template<typename T>
bool Set<T>::operator<(const Set<T>& b)
{
	for (int i = 0; i < size; i++)
		if (!b.contains(arr[i]))
			return false;

	return true;
}

#endif


