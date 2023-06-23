#include <iostream>
#include <string>
#include "Customer.h"
using namespace std;

Customer::Customer(){}

Customer::Customer(int id, string name){
    this->id=id;
    this->name=name;
}
Customer::~Customer(){
}

int Customer::getId(){
    return id;
}
string Customer::getName(){
    return name;
}