#include "Bank.h"

int main()
{
	Bank bank1;
	int idIvan = bank1.openAccount("Ivan");
    // малко недоуточнение в условието,  openAccount трябва да връща
	// идентификатор на новия акаунт, за да имаме достъп до него
	bank1.Deposit(idIvan, 123);

	int idGeorgi = bank1.openAccount("Georgi");

	bank1.Deposit(idGeorgi, 567);
	// тестваме оператор равно
	Bank bank2;
	bank2 = bank1;
	// тестваме запълването на капацитета
	for (int i = 0; i < 8; i++)
		bank2.openAccount("Asen");

	bank2.Transfer(idGeorgi, idIvan, 100);
	bank2.Withdrawal(idGeorgi, 67);

	bank2.print();
}