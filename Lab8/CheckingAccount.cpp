// Brendan O'Connor	
// 3/21/16
// Lab 8

#include "Account.h"
#include "CheckingAccount.h"

// Constructor
CheckingAccount::CheckingAccount(int newAccountNum) : Account()
{
	accountNum = newAccountNum;
	type = "Checking";
}

// Applies an interest rate to the balance
void CheckingAccount::accrueInterest()
{
	// Checking accounts don't accrue interest
}
