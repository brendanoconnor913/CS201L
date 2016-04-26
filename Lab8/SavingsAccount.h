// Brendan O'Connor	
// 3/21/16
// Lab 8

#include "Account.h"

// Prevent multiple includes of this class
#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

class SavingsAccount : public Account
{
public:
	// Constructor
	SavingsAccount(int newAccountNum);
	
	// Applies an interest rate to the balance
	void virtual accrueInterest();
};

#endif
