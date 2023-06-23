// id and name

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
using namespace std;

class Customer {
public:
    Customer();
    Customer(int id, string name);
    ~Customer();
    int getId();
    string getName();

private:
    int id;
    string name;
}; 
#endif 