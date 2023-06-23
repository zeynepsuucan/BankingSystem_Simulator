// has a branch and a customer
// id
// same customer can have multiple accounts in the same branch but id s are unique

#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "Branch.h"
#include "Customer.h"

class Account{

public:
    Account();
    Account(Branch branch, Customer customer, double amount, int id);
    ~Account();
    Branch getBranch();
    Customer getCustomer();
    double getAmount();
    int getIdAccount();

private:
    Branch branchAc;
    Customer customerAc;
    double amount;
    int idAccount;

}; 
#endif 