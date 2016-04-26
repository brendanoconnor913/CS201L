// Brendan O'Connor	
// 3/21/16
// Lab 8

#include "Account.h"
#include "CertificateOfDeposit.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include <fstream>
#include <string>
using namespace std;

int main() 
{
	// File I/O
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	// Stores up to 30 accounts
	Account* accounts[30];
	// Number of accounts that have been opened
	int numAccounts = 0;

	// For file input processing
	string command, acctType;
	int acctNum1, acctNum2;
	double amount;

	// Do the input and math
	while(fin >> command)
	{
		if(command == "NEW")
		{
			// Create a new account
			fin >> acctType;
			fin >> acctNum1;
			if (acctType == "CHECKING") {
				accounts[numAccounts] = new CheckingAccount(acctNum1);
			}
			else if (acctType == "SAVINGS"){
				accounts[numAccounts] = new SavingsAccount(acctNum1);
			}
			else if (acctType == "CERTIFICATE") {
				accounts[numAccounts] = new CertificateOfDeposit(acctNum1);
			}
			numAccounts++;
        }
		else if (command == "WITHDRAWAL")
		{
			// Remove money from an account
			fin >> acctNum1;
			fin >> amount;
			for (int i = 0; i < numAccounts; i++) {
				if (acctNum1 == accounts[i]->getAccountNum()) {
					accounts[i]->withdrawal(amount);
				}
			}

        }
		else if (command == "DEPOSIT")
		{
			// Add money to an account
			fin >> acctNum1;
			fin >> amount;
			for (int i = 0; i < numAccounts; i++) {
				if (acctNum1 == accounts[i]->getAccountNum()) {
					accounts[i]->deposit(amount);
				}
			}
            
		}
		else if (command == "TRANSFER")
		{
			// Move money from one account to another
			fin >> acctNum1;
			fin >> acctNum2;
			fin >> amount;
			for (int i = 0; i < numAccounts; i++) {
				if (acctNum1 == accounts[i]->getAccountNum()) {
					// Withdrawl money from the first
					accounts[i]->withdrawal(amount);
				}
			}

			for (int j = 0; j < numAccounts; j++) {
				if (acctNum2 == accounts[j]->getAccountNum()) {
					// Deposit the same ammount into the second account
					accounts[j]->deposit(amount);
				}
			}

        }
		else if (command == "INTEREST")
		{
			// Calculate interest on all accounts
			for (int i = 0; i < numAccounts; i++) {
				accounts[i]->accrueInterest();
			}

        }
    }
	// Print output
	fout << "BANK STATEMENT" << endl << endl;

	for(int i = 0; i < numAccounts; i++)
	{
		fout << "Account number: " << accounts[i]->getAccountNum() << endl;
		fout << "Type of account: " << accounts[i]->getAccountType() << endl;
		fout << "Balance: $" << accounts[i]->getBalance() << endl;
		fout << endl;
	}
    
    // Delete accounts
	for (int i = 0; i < numAccounts; i++)
		delete accounts[i];

    // Close files
    fin.close();
    fout.close();
    return 0;
}