// id and name
#ifndef BRANCH_H
#define BRANCH_H

#include <iostream>
#include <string>
using namespace std;

class Branch {
public:
    Branch();
    Branch(int id, string name);
    ~Branch();
    int getId();
    string getName();
    
private:
    int id;
    string name;
}; 

#endif 