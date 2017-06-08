#ifndef H_MY_VECTOR
#define H_MY_VECTOR
#include <cstddef>
#include <iostream>




template<typename T>
class my_vector{
public:
    my_vector<T>(){
            array_ = NULL;
            size_ = 0;
            capacity_ = 0;
    }
    my_vector<T>(const std::size_t n){
            std::size_t t = closest_2(2 * n);

            array_ = (T*) new char [t * sizeof(T)];
            size_ = n;
            capacity_ = t;
            for(std::size_t i = 0; i < size_; i++){
                    new (array_ + i) T();
            }
    }
    my_vector<T>(const my_vector<T>& other){
            array_ = (T*) new char [other.capacity_ * sizeof(T)];

            for(std::size_t i = 0; i < other.size_; i++){
                    new (array_ + i) T();
                    array_[i] = other.array_[i];
            }

            size_ = other.size_;
            capacity_ = other.capacity_;
    }
    my_vector<T>& operator=(const my_vector<T>& other){
            for(std::size_t i = 0; i < size_; i++){
                    array_[i].~T();
            }
            delete [] (char*)array_;
            array_ = (T*) new char [other.capacity_ * sizeof(T)];
            for(std::size_t i = 0; i < other.size_; i++){
                    new (array_ + i) T();
                    array_[i] = other.array_[i];
            }
            size_ = other.size_;
            capacity_ = other.capacity_;
            return *this;
    }
    ~my_vector<T>(){
            for(std::size_t i = 0; i < size_; i++){
                    array_[i].~T();
            }
            delete [] (char*)array_;
    }

    size_t size() const{
            return size_;
    }
    size_t capacity() const{
            return capacity_;
    }
    bool empty() const{
            return size_ == 0;
    }

    void resize(const std::size_t n){
            if(n > size_){
                if(n > capacity_)
                        reserve(n);
                for(std::size_t i = size_; i < n; i++){
                        new (array_ + i) T();
                }
            }
            if(n < size_){
                    for(std::size_t i = n; i < size_; i++){
                            array_[i].~T();
                    }
            }
            size_ = n;
    }
    void reserve(std::size_t n){
            if (n <= capacity_)
                    return;
            if(n == 0)
                    n = 1;
            capacity_ = closest_2(n);
            T* temp = (T*) new char [capacity_ * sizeof(T)];
            for(std::size_t i = 0; i < size_; i++){
                    new (temp + i) T();
                    temp[i] = array_[i];
            }
            for(std::size_t i = 0; i < size_; i++){
                    array_[i].~T();
            }
            delete [] (char*)array_;
            array_ = temp;
    }

    const T& operator[](const size_t index) const{
            return array_[index];
    }
    T& operator[](const size_t index){
            return array_[index];
    }

    void push_back(const T& t){
            if(capacity_ == 0){
                    reserve(1);
            }
            if(size_ == capacity_){
                    reserve(capacity_ * 2);
            }
            new (array_ + size_) T(t);
            size_++;
    }
    void pop_back(){
            array_[size_ - 1].~T();
            size_--;
    }
    void clear(){
            for(std::size_t i = 0; i < size_; i++){
                    array_[i].~T();
            }
            size_ = 0;
    }

private:
    size_t capacity_;
    size_t size_;
    T* array_;
    std::size_t static closest_2(std::size_t n){
            std::size_t t = 1;
            while(t < n){
                    t *= 2;
            }
            return t;
    }
};
template <typename T>
std::ostream& operator<<(std::ostream& os, const my_vector<T>& v){
        for(std::size_t i = 0; i < v.size(); i++){
                os << v[i];
        }
        return os;
}
#endif
