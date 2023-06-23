#include <iostream>
#include <string>
#include "Account.h"
#include "Branch.h"
#include "Customer.h"
using namespace std;


Account::Account(){
    
}

Account::Account(Branch branch, Customer customer, double amount, int id){
    this->branchAc = branch;
    this->customerAc = customer;
    this->amount = amount;
    this->idAccount = id;
}

Account::~Account(){
    
}

Branch Account::getBranch(){
    return branchAc;
}

Customer Account::getCustomer(){
    return customerAc;
}

double Account::getAmount(){
    return amount;
}

int Account::getIdAccount() {
    return idAccount;
}
