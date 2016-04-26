// Brendan O'Connor	
// 3/21/16
// Lab 8
#include "Account.h"
#include "CertificateOfDeposit.h"

// Constructor
CertificateOfDeposit::CertificateOfDeposit(int newAccountNum) : Account()
{
	accountNum = newAccountNum;
	type = "Certificate of Deposit";
	hasWithdrawn = false;

}

// Applies an interest rate to the balance
void CertificateOfDeposit::accrueInterest()
{
	if (!hasWithdrawn) {
		balance *= 1.10;
	}
	else {
		balance *= 1.01;
	}
}

// Removes money from the bank account
void CertificateOfDeposit::withdrawal(double amount)
{
	balance -= amount;
	hasWithdrawn = true;
}