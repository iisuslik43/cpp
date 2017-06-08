#include "../include/product.h"
#include <cstring>
#include <iostream>
using namespace std;
Product::Product(){
        name_ = NULL;
        quantity_ = 0;
        price_ = 0;
}
void Product::copy(const Product& p){
        if(p.name_){
                name_ = new char [strlen(p.name_) + 1];
                strcpy(name_, p.name_);
        }
        quantity_ = p.quantity_;
        price_ = p.price_;
}
Product::Product(const char* name, int quantity, double price){
        if(name){
                name_ = new char [strlen(name) + 1];
                strcpy(name_, name);
        }
        quantity_ = quantity;
        price_ = price;
}
Product::Product(const Product& p){
        copy(p);
}
Product& Product::operator=(const Product& p){
        if(name_)
                delete [] name_;
        copy(p);
        return *this;
}
Product::~Product(){
        delete [] name_;
}
ostream& operator<<(ostream& os, const Product& p){
        os << p.name_ << " " << p.quantity_ << " " << p.price_ << " ";
        return os;
}
