#ifndef BANKING_SYSTEM_H
#define BANKING_SYSTEM_H

#include <string>
#include <iostream>
#include "Account.h"
#include "Branch.h"
#include "Customer.h"

using namespace std;

class BankingSystem {

public: 

BankingSystem();
~BankingSystem();
void addBranch( const int branchId, const string branchName );
void deleteBranch( const int branchId );
void addCustomer( const int customerId, const string customerName );
void deleteCustomer( const int customerId );
int addAccount( const int branchId , const int customerId , const double amount );
void deleteAccount( const int accountId );
void showAllAccounts();
void showBranch( const int branchId ); 
void showCustomer( const int customerId );
private:
Branch* branchArray;
Customer* customerArray;
Account* accountArray;
int branchNum;
int customerNum;
int accountNum;
int accountNumId;
};

#endif
       