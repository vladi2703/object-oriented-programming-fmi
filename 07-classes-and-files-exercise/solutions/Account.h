#include <string>

#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account
{
	std::string owner;
	size_t id;

public:
	double balance;

	Account(std::string new_owner, size_t new_id);
	int getID();
	const std::string& getOwner();
	void printData();
};

#endif