#include "matrix.h"

std::size_t Matrix::get_rows() const{ 
	return this->_rows; 
}

std::size_t Matrix::get_cols()const { 
	return this->_cols; 
}



Matrix::Matrix(const Matrix &copy ){
	std::size_t r=this->get_rows();
	std::size_t c=this->get_cols();
	for(std::size_t i=0;i<r;i++){
		for(int j=0;j<c;j++)this->_data[i][j]=copy._data[i][j];
	}
}

Matrix::~Matrix(){
	for(std::size_t i=0;i<this->get_rows();i++)
		delete [] this->_data[i];
	delete [] this->_data;
}

Matrix::Matrix(std::size_t r, std::size_t c) {
	this->_data=new int* [r];
	
	for(std::size_t i=0;i<r;i++){
		this->_data[i]=new int [c];
		for(std::size_t j=0;j<c;j++)this->_data[i][j]=0;
	}
}

Matrix Matrix:: operator=(const Matrix& m){
	for(std::size_t i=0;i<this->get_rows();i++)
		delete [] this->_data[i];
	delete [] this->_data;
	this->_data=new int* [m._cols];
	for(std::size_t i=0;i<m._rows;i++){
		this->_data[i]=new int [m._cols];
		for(std::size_t j=0;j<m._cols;j++)this->_data[i][j]=m._data[i][j];
	}
	_rows=m._rows;
	_cols=m._cols;
	return *this;
}

void Matrix::set(std::size_t i, std::size_t j, int val) {
	if(i<this->get_cols()&&j<this->get_rows())
		this->_data[i][j]=val;
	else printf("%s","Don't do it again plz");
}

int Matrix::get(std::size_t i, std::size_t j)const {
	if(i<this->get_rows()&&j<this->get_cols())
		return this->_data[i][j];
	else printf("%s","Don't do it again plz");
	return NULL;
}

void Matrix::print(FILE* f) const{
	for(std::size_t i=0;i<this->_rows;i++){
		for(std::size_t j=0;j<this->_cols;j++)fprintf(f,"%d ",this->_data[i][j]);
	fprintf(f,"\n");
	}

}

bool Matrix::operator==(const Matrix& m) const{
	for(std::size_t i=0;i<this->get_rows();i++){
		for(std::size_t j=0;j<this->get_cols();j++)
			if(m._data[i][j]!=this->_data[i][j]){
				return false;
			}
	}
	return true;
}

bool Matrix::operator!=(const Matrix& m) const{
	return !(*this==m);
}

Matrix& Matrix::operator+=(const Matrix& m) {
	for(std::size_t i=0;i<this->get_rows();i++){
		for(std::size_t j=0;j<this->get_cols();j++)
			this->_data[i][j]+=m._data[i][j];
	}
	return *this;
}

Matrix& Matrix::operator-=(const Matrix& m) {
	for(std::size_t i=0;i<this->get_rows();i++){
		for(std::size_t j=0;j<this->get_cols();j++)
			this->_data[i][j]-=m._data[i][j];
	}
	return *this;
}

Matrix& Matrix::operator*=(const Matrix& m) {
	Matrix c(this->get_rows(),m._cols);
	for(std::size_t i=0;i<this->get_rows();i++){
		for(std::size_t j=0;j<m._cols;j++)
			for(std::size_t k=0;k<m._cols;k++)
				c.set(i,j,this->_data[i][k]*m._data[k][j]);
	}
	*this=c;
	return *this;
}

Matrix Matrix::operator+(const Matrix& m)const {
	Matrix res(this->get_rows(),this->get_cols());
	res=m;
	res+= *this;
	return res;
}

Matrix Matrix::operator-(const Matrix& m) const{
	Matrix res(this->get_rows(),this->get_cols());
	res=m;
	res-= *this;
	return res;
}


Matrix Matrix::operator*(const Matrix& m) const{
	Matrix res(this->get_rows(),this->get_cols());
	res=m;
	res*= *this;
	return res;
}



