// Brendan O'Connor	
// 3/21/16
// Lab 8

#include "Account.h"

// Prevent multiple includes of this class
#ifndef CERTIFICATEOFDEPOSIT_H
#define CERTIFICATEOFDEPOSIT_H

class CertificateOfDeposit : public Account
{
private:
	bool hasWithdrawn;
public:
	// Constructor
	CertificateOfDeposit(int newAccountNum);
	
	// Applies an interest rate to the balance
	void virtual accrueInterest();
	// Removes money from the bank account
	void virtual withdrawal(double amount);
};

#endif
