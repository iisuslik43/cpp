#include "circle.h"
#include "figure.h"
#include "math.h"
#include <stdio.h>
#include <string.h>
Circle::Circle(int id, int x, int y, int radius, const char* label):Figure(id,x,y){
	r_=radius;
	label_ = new char[strlen(label) + 1];
        strcpy(label_, label);

}
Circle::~Circle(){
	delete [] label_;
}
    
void Circle::print() const{
	printf("Circle %d: x = %d y = %d radius = %d label = %s",id,x,y,r_,label_);
}
bool Circle::is_inside(int x, int y) const{
	return sqrt((x-this->x)*(x-this->x)+(y-this->y)*(y-this->y))<=r_;
}
void Circle::zoom(int factor){
	r_*=factor;
}
