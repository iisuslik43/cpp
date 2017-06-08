#ifndef H_PRODUCT
#define H_PRODUCT
#include <iostream>

class Product {
public:
    Product();

    Product(const char* name, int quantity, double price);
    Product(const Product& p);
    Product& operator=(const Product& p);
    ~Product();
    friend std::ostream& operator<<(std::ostream& os, const Product& p);
private:
    void copy(const Product& p);
    char *name_;
    int quantity_;
    double price_;
};
#endif
