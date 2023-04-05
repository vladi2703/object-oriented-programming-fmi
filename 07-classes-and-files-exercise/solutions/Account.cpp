#include <iostream>
#include "Account.h"

Account::Account(std::string new_owner, size_t new_id) :
	owner(new_owner),id(new_id),balance(0)
{

}

int Account::getID()
{
	return id;
}

const std::string& Account::getOwner()
{
	return owner;
}

void Account::printData()
{
	std::cout << "Owner: " << owner << "\nID: " << id << std::endl;
	std::cout << "Balance: " << balance << std::endl;
}
