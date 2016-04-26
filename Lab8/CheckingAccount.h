// Brendan O'Connor	
// 3/21/16
// Lab 8

#include "Account.h"

// Prevent multiple includes of this class
#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

class CheckingAccount : public Account
{
public:
	// Constructor
	CheckingAccount(int newAccountNum);

	// Applies an interest rate to the balance
	void virtual accrueInterest();
};

#endif
