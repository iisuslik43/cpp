#include "rectangle.h"
#include "figure.h"
#include <stdio.h>
Rectangle::Rectangle(int id, int x, int y, int width, int height):Figure(id,x,y){
	w_=width;
	h_=height;
    }
//Rectangle::~Rectangle();
void Rectangle::print() const{
	printf("Rectangle %d: x = %d y = %d width = %d height = %d",id,x,y,w_,h_);
}
bool Rectangle::is_inside(int x, int y) const{
	return x<=this->x+w_/2&&x>=this->x-w_/2&&y<=this->y+h_/2&&y>=this->y-h_/2;
}
void Rectangle::zoom(int factor){
	h_*=factor;
	w_*=factor;
}
void Rectangle::move(int new_x, int new_y){
	x=new_x;
	y=new_y;
}
int Rectangle:: get_id() const{
	return id;
}
