#include <iostream>
#include "Bank.h"

void Bank::copy(const Bank& other)
{
	capacity = other.capacity;
	count = other.count;
	current_id = other.current_id;
	
	accounts = new Account*[capacity];
	for (int i = 0; i < count; i++)
		accounts[i] = new Account(*(other.accounts[i]));
		// тук ползваме копи конструктора на Account,
	    // който е автоматично генериран от компилатора
}

void Bank::erase()
{
	for (int i = 0; i < count; i++)
		delete accounts[i];

	delete[] accounts;
}

void Bank::resize()
{
	Account** temp = new Account*[capacity * 2];
	for (int i = 0; i < count; i++)
		temp[i] = accounts[i];
		// прехвърляме адресите на обектите

	capacity *= 2;
	delete[] accounts;
	accounts = temp;
}

int Bank::findIndex(size_t id)
{
	for (int i = 0; i < count; i++)
		if (accounts[i]->getID() == id)
			return i;
	// accounts[i]->getID() е равносилно на (*(accounts[i])).getID()
	return -1;
}

void Bank::sortArr(Account** arr, int size)
{// bubble sort
	for(int i=0; i<size-1; i++)
		for (int j = size - 2; j >= i; j--)
			if (arr[j]->getOwner() > arr[j + 1]->getOwner())
			{
				Account* temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
}

Bank::Bank()
{
	const size_t default_capacity = 8;
	const size_t default_id = 1000;
	// създаваме положителен капацитет по подразбиране и масив с такава големина, за да 
	// не се налага да разглеждаме частния случай, когато масива е празен
	accounts = new Account*[default_capacity];
	capacity = default_capacity;
	count = 0;
	current_id = default_id;
}

Bank::Bank(const Bank& other)
{
	copy(other);
}

Bank& Bank::operator=(const Bank& other)
{
	if (this != &other)
	{
		erase();
		copy(other);
	}
	return *this;
}

Bank::~Bank()
{
	erase();
}

int Bank::openAccount(std::string new_owner)
{
	if (capacity == count)
		resize();

	accounts[count] = new Account(new_owner, current_id);
	count++;
	current_id++;

	return current_id - 1;
}

void Bank::Withdrawal(size_t id, double amount)
{
	int index = findIndex(id);
	if (index == -1 || amount < 0)
		throw std::exception("Owner not found or invalid amount");

	if(accounts[index]->balance < amount)
		throw std::exception("Insufficient balance");


	// равносилно на (*(accounts[index])).balance
	accounts[index]->balance -= amount;

}

void Bank::Deposit(size_t id, double amount)
{
	int index = findIndex(id);
	if (index == -1 || amount < 0)
		throw std::exception("owner not found or invalid amount");
	
	// равносилно на (*(accounts[index])).balance
	accounts[index]->balance += amount;
}

void Bank::Transfer(size_t from_id, size_t to_id, double amount)
{
	int index1 = findIndex(from_id);
	int index2 = findIndex(to_id);
	if (index1 == -1 || index2==-1 || amount < 0)
		throw std::exception("Owner not found or invalid amount");

	if (accounts[index1]->balance < amount)
		throw std::exception("Insufficient balance");

	accounts[index1]->balance -= amount;
	accounts[index2]->balance += amount;
}

void Bank::print()
{
	Account** sorted_arr = new Account*[count];
	for (int i = 0; i < count; i++)
		sorted_arr[i] = accounts[i];
	// копираме адресите в другия масив и ги сортираме
	// спрямо това, което е сочено от тях, без да
	// се засяга оригиналния масив и без да копираме Account обекти

	sortArr(sorted_arr, count);

	std::cout << "There are " << count << " accounts:\n";
	for (int i = 0; i < count; i++)
	{
		sorted_arr[i]->printData();
		std::cout << std::endl;
	}
}
