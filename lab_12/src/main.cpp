#include <iostream>
#include "../include/product.h"
#include "../include/my_vector.h"
#include "cassert"

using namespace std;

template<typename T>
void test_my_vector(const T& a, const T& b){
        my_vector<T> v;
        my_vector<T> v2(2);
        my_vector<T> v3(v);
        my_vector<T> victor(43);
        victor = v2;
        assert(v2.size() == 2 && v2.capacity() == 4);
        assert(v3.size() == v.size() && v3.capacity() == v.capacity());
        assert(v2.size() == victor.size() && v2.capacity() == victor.capacity());
        assert(v.size() == 0 && v.capacity() == 0);
        v.push_back(a);
        v.push_back(b);
        //T temp = v[0];
        //temp = b;
        v[0] = b;
        v.pop_back();
        assert(v.size() == 1 && v.capacity() == 2);
        v.clear();
        assert(v.empty());
        v.push_back(a);
        v.push_back(a);
        v.reserve(5);
        assert(v.size() == 2 && v.capacity() == 8);
        v.resize(5);
        assert(v.size() == 5 && v.capacity() == 8);
}

int main() {
    test_my_vector<int>(5, 10);
    test_my_vector<Product>(Product("asdf", 4, 12.0), Product("qwe", -1, 7.5));
    return 0;
}
