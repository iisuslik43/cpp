#include "matrix.h"
#include "shared_ptr.h"
#include <iostream>
#include <cassert>
#include <string>
#include <map>
//Matrix m= new Matrix(1,1);
//Matrix *clear=new Matrix(1,1);

shared_ptr::Storage::Storage(Matrix* mtx){
	this->data_=mtx;
	this->ref_count_=1;
}
shared_ptr::Storage::~Storage(){
	delete this->data_;
	
}

void shared_ptr::Storage::incr(){
	this->ref_count_++;

}
void shared_ptr::Storage::decr(){
	this->ref_count_--;
	
}

int shared_ptr::Storage::getCounter() const{
	return this->ref_count_;
}
Matrix* shared_ptr::Storage::getObject() const{

	return this->data_;

}








shared_ptr::shared_ptr(Matrix* obj){
	this->storage_=new Storage(obj);
}
shared_ptr::shared_ptr(const shared_ptr& other){
	this->storage_=other.storage_;
	this->storage_->incr();
}
shared_ptr& shared_ptr::operator=(shared_ptr other){
	this->storage_->decr();
	if(this->storage_->getCounter()<1){
		delete this->storage_;
	}
	this->storage_=other.storage_;
	other.storage_->incr();
	return *this;
}
shared_ptr::~shared_ptr(){
	this->storage_->decr();
	if(this->storage_->getCounter()<1)
		delete this->storage_;

}

Matrix* shared_ptr::ptr() const{
	return this->storage_->getObject();
}
bool shared_ptr::isNull() const{
	Matrix* matr = this->storage_->getObject();
	return matr==NULL;
	
}
void shared_ptr::reset(Matrix* obj){
	//delete this->storage_;
	this->storage_->decr();
	if(this->storage_->getCounter()<1)
		delete this->storage_;
	this->storage_=new Storage(obj);
}

Matrix* shared_ptr::operator->() const{
	return this->storage_->getObject();

}
Matrix& shared_ptr::operator*() const{
	return *this->storage_->getObject();

}