#include "figure.h"

Figure::Figure(int id, int x, int y){
this->id=id;
this->x=x;
this->y=y;

}

Figure::~Figure(){

}
/*
virtual void Figure::print() const = 0;
virtual bool Figure::is_inside(int x, int y) const = 0;
virtual void Figure::zoom(int factor) = 0;
*/
void Figure::move(int new_x, int new_y){
x=new_x;
y=new_y;
}
int Figure::get_id() const{
	return id;
}
