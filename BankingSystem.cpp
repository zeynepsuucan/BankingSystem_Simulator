#include <iostream>
#include <string>
#include "BankingSystem.h"
using namespace std;
#include <iomanip>

BankingSystem::BankingSystem()
{
    branchArray = nullptr;
    customerArray = nullptr;
    accountArray = nullptr;
    branchNum = 0;
    customerNum = 0;
    accountNum = 0;
    accountNumId = 0;
}

BankingSystem::~BankingSystem()
{
    delete[] branchArray;
    delete[] customerArray;
    delete[] accountArray;
}

void BankingSystem::addBranch(const int branchId, const string branchName)
{
    for (int i = 0; i < branchNum; i++)
    {
        if (branchArray[i].getId() == branchId)
        {
            cout << "Branch " << branchId << " already exists" << endl;
            return;
        }
    }
    Branch *resized = new Branch[branchNum + 1];
    for (int i = 0; i < branchNum; i++)
    {
        resized[i] = Branch(branchArray[i].getId(), branchArray[i].getName());
    }
    Branch newBranch = Branch(branchId, branchName);
    resized[branchNum] = newBranch;
    delete[] branchArray;
    branchArray = resized;
    branchNum++;
    cout << "Branch " << branchId << " has been added" << endl;
}

void BankingSystem::deleteBranch(const int branchId)
{
    int n1 = accountNum;
    int ind = -1;
    bool found = false;
    for (int i = 0; i < branchNum; i++)
    {
        if (branchArray[i].getId() == branchId)
        {
            found = true;
            ind = i;
        }
    }
    if (!found)
    {
        cout << "Branch " << branchId << " does not exist" << endl;
        return;
    }
    Branch *resized = new Branch[branchNum - 1];
    for (int i = 0; i < ind; i++)
    {
        resized[i] = Branch(branchArray[i].getId(), branchArray[i].getName());
    }
    for (int i = ind; i < branchNum - 1; i++)
    {
        resized[i] = Branch(branchArray[i + 1].getId(), branchArray[i + 1].getName());
    }
    int k=0;
    for (int i = 0; i < n1; i++)
    {
        if (accountArray[k].getBranch().getId() == branchId)
        {
            Account *resized2 = new Account[accountNum - 1];
            for (int j = 0; j < k; j++)
            {
                resized2[j] = Account(accountArray[j].getBranch(), accountArray[j].getCustomer(), accountArray[j].getAmount(),
                                      accountArray[j].getIdAccount());
            }
            for (int j = k; j < accountNum - 1; j++)
            {
                resized2[j] = Account(accountArray[j+ 1].getBranch(), accountArray[j + 1].getCustomer(), accountArray[j + 1].getAmount(),
                                      accountArray[j + 1].getIdAccount());
            }
            delete[] accountArray;
            accountArray = resized2;
            accountNum--;
        }
        else{
            k++;
        }
    }
    delete[] branchArray;
    branchArray = resized;
    branchNum--;
    cout << "Branch " << branchId << " has been deleted" << endl;
}

void BankingSystem::addCustomer(const int customerId, const string customerName)
{
    for (int i = 0; i < customerNum; i++)
    {
        if (customerArray[i].getId() == customerId)
        {
            cout << "Customer " << customerId << " already exists" << endl;
            return;
        }
    }
    Customer *resized = new Customer[customerNum + 1];
    for (int i = 0; i < customerNum; i++)
    {
        resized[i] = Customer(customerArray[i].getId(), customerArray[i].getName());
    }
    Customer newCustomer = Customer(customerId, customerName);
    resized[customerNum] = newCustomer;
    delete[] customerArray;
    customerArray = resized;
    customerNum++;
    cout << "Customer " << customerId << " has been added" << endl;
}

void BankingSystem::deleteCustomer(const int customerId)
{
    int n1 = accountNum;
    int ind = -1;
    bool found = false;
    for (int i = 0; i < customerNum; i++)
    {
        if (customerArray[i].getId() == customerId)
        {
            found = true;
            ind = i;
        }
    }
    if (!found)
    {
        cout << "Customer " << customerId << " does not exist" << endl;
        return;
    }
    Customer *resized = new Customer[customerNum - 1];
    for (int i = 0; i < ind; i++)
    {
        resized[i] = Customer(customerArray[i].getId(), customerArray[i].getName());
    }
    for (int i = ind; i < customerNum - 1; i++)
    {
        resized[i] = Customer(customerArray[i + 1].getId(), customerArray[i + 1].getName());
    }
    int k=0;
    for (int i = 0; i < n1; i++)
    {
        if (accountArray[k].getCustomer().getId() == customerId)
        {
            Account *resized2 = new Account[accountNum - 1];
            for (int j = 0; j < k; j++)
            {
                resized2[j] = Account(accountArray[j].getBranch(), accountArray[j].getCustomer(), accountArray[j].getAmount(),
                                      accountArray[j].getIdAccount());
            }
            for (int j = k; j < accountNum - 1; j++)
            {
                resized2[j] = Account(accountArray[j+ 1].getBranch(), accountArray[j + 1].getCustomer(), accountArray[j + 1].getAmount(),
                                      accountArray[j + 1].getIdAccount());
            }
            delete[] accountArray;
            accountArray = resized2;
            accountNum--;
        }
        else{
            k++;
        }
    }
    delete[] customerArray;
    customerArray = resized;
    customerNum--;
    cout << "Customer " << customerId << " has been deleted" << endl;
}

int BankingSystem::addAccount(const int branchId, const int customerId, const double amount)
{
    Branch branchAc;
    Customer customerAc;
    bool branchFound = false;
    bool customerFound = false;

    for (int i = 0; i < branchNum; i++)
    {
        if (branchId == branchArray[i].getId())
        {
            branchAc = branchArray[i];
            branchFound = true;
        }
    }
    for (int i = 0; i < customerNum; i++)
    {
        if (customerId == customerArray[i].getId())
        {
            customerAc = customerArray[i];
            customerFound = true;
        }
    }
    if (!branchFound)
    {
        cout << "Branch " << branchId << " does not exist" << endl;
        return -1;
    }

    if (!customerFound)
    {
        cout << "Customer " << customerId << " does not exist" << endl;
        return -1;
    }
    Account *resized = new Account[accountNum + 1];
    for (int i = 0; i < accountNum; i++)
    {
        resized[i] = Account(accountArray[i].getBranch(), accountArray[i].getCustomer(), accountArray[i].getAmount(), accountArray[i].getIdAccount());
    }
    Account newAccount = Account(branchAc, customerAc, amount, accountNumId + 1);
    resized[accountNum] = newAccount;
    delete[] accountArray;
    accountArray = resized;
    accountNum++;
    accountNumId++;
    cout << "Account " << accountNumId << " added for customer " << customerId << " at branch " << branchId << endl;
    return accountNumId;
}

void BankingSystem::deleteAccount(const int accountId)
{
    int ind = -1;
    bool found = false;
    for (int i = 0; i < accountNum; i++)
    {
        if (accountArray[i].getIdAccount() == accountId)
        {
            found = true;
            ind = i;
        }
    }
    if (!found)
    {
        cout << "Account " << accountId << " does not exist" << endl;
        return;
    }
    Account *resized = new Account[accountNum - 1];
    for (int i = 0; i < ind; i++)
    {
        resized[i] = Account(accountArray[i].getBranch(), accountArray[i].getCustomer(), accountArray[i].getAmount(),
                             accountArray[i].getIdAccount());
    }
    for (int i = ind; i < accountNum - 1; i++)
    {
        resized[i] = Account(accountArray[i + 1].getBranch(), accountArray[i + 1].getCustomer(), accountArray[i + 1].getAmount(),
                             accountArray[i + 1].getIdAccount());
    }
    delete[] accountArray;
    accountArray = resized;
    accountNum--;
    cout << "Account " << accountId << " has been deleted" << endl;
}

void BankingSystem::showAllAccounts()
{
    cout << "Account id Branch id Branch name Customer id Customer name Balance" << endl;
    for (int i = 0; i < accountNum; i++)
    {
        cout << accountArray[i].getIdAccount() << " " << accountArray[i].getBranch().getId()
             << " " << accountArray[i].getBranch().getName() << " " << accountArray[i].getCustomer().getId() << " "
             << accountArray[i].getCustomer().getName() << " " ;

        cout << fixed << setprecision(2) << accountArray[i].getAmount() << endl;
    }
}

void BankingSystem::showBranch(const int branchId)
{
    int noAccounts = 0;
    Branch branchP;
    Account *branchAccounts = new Account[1];
    bool found = false;

    for (int i = 0; i < branchNum; i++)
    {
        if (branchArray[i].getId() == branchId)
        {
            branchP = branchArray[i];
            found = true;
        }
    }

    if (!found)
    {
        cout << "Branch " << branchId << " does not exist" << endl;
        delete[] branchAccounts;
        return;
    }

    for (int i = 0; i < accountNum; i++)
    {
        if (accountArray[i].getBranch().getId() == branchId)
        {
            noAccounts++;
            Account *resized = new Account[noAccounts];
            for (int j = 0; j < noAccounts - 1; j++)
            {
                resized[j] = Account(branchAccounts[j].getBranch(), branchAccounts[j].getCustomer(), branchAccounts[j].getAmount(), branchAccounts[j].getIdAccount());
            }
            resized[noAccounts - 1] = Account(accountArray[i].getBranch(), accountArray[i].getCustomer(), accountArray[i].getAmount(), accountArray[i].getIdAccount());
            delete[] branchAccounts;
            branchAccounts = resized;
        }
    }

    cout << "Branch id: " << branchP.getId() << " Branch name: " << branchP.getName() << " Number of accounts: " << noAccounts << endl;
    if (noAccounts > 0)
    {
        cout << "Accounts at this branch:" << endl;
        cout << "Account id Customer id Customer name Balance" << endl;
        for (int i = 0; i < noAccounts; i++)
        {
            cout << branchAccounts[i].getIdAccount() << " " << branchAccounts[i].getCustomer().getId()
                 << " " << branchAccounts[i].getCustomer().getName() << " ";
                 std::cout << std::fixed << std::setprecision(2) << branchAccounts[i].getAmount() << std::endl;
        }
    }
    delete[] branchAccounts;
}

void BankingSystem::showCustomer(const int customerId)
{

    int noAccounts = 0;
    Customer customerP;
    Account *customerAccounts = new Account[1];
    bool found = false;

    for (int i = 0; i < customerNum; i++)
    {
        if (customerArray[i].getId() == customerId)
        {
            customerP = customerArray[i];
            found = true;
        }
    }

    if (!found)
    {
        cout << "Customer " << customerId << " does not exist" << endl;
        delete[] customerAccounts;
        return;
    }

    for (int i = 0; i < accountNum; i++)
    {
        if (accountArray[i].getCustomer().getId() == customerId)
        {
            noAccounts++;
            Account *resized = new Account[noAccounts];
            for (int j = 0; j < noAccounts - 1; j++)
            {
                resized[j] = Account(customerAccounts[j].getBranch(), customerAccounts[j].getCustomer(), customerAccounts[j].getAmount(), customerAccounts[j].getIdAccount());
            }
            resized[noAccounts - 1] = Account(accountArray[i].getBranch(), accountArray[i].getCustomer(), accountArray[i].getAmount(), accountArray[i].getIdAccount());
            delete[] customerAccounts;
            customerAccounts = resized;
        }
    }

    cout << "Customer id: " << customerP.getId() << " Customer name: " << customerP.getName() << " Number of accounts: " << noAccounts << endl;
    if (noAccounts > 0)
    {
        cout << "Accounts of this customer:" << endl;
        cout << "Account id Branch id Branch name Balance" << endl;
        for (int i = 0; i < noAccounts; i++)
        {
            cout << customerAccounts[i].getIdAccount() << " " << customerAccounts[i].getBranch().getId()
                 << " " << customerAccounts[i].getBranch().getName() << " ";
            std::cout << std::fixed << std::setprecision(2) << customerAccounts[i].getAmount() << std::endl;
        }
    }
    delete[] customerAccounts;
}