#include <iostream>
#include <string>
#include "Branch.h"
using namespace std;

Branch::Branch(){}
Branch::Branch(int id, string name){
    this->id=id;
    this->name=name;
}
Branch::~Branch(){

}
int Branch::getId(){
    return id;
}

string Branch::getName(){
    return name;
}

