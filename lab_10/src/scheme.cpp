#include "scheme.h"
#include <stdio.h>

Scheme::Scheme(int capacity){
	figures_=new Figure* [capacity];
	size_=0;
} 
Scheme::~Scheme(){
	for(int i=0;i<size_;i++){
		delete figures_[i];			
	}
}

void Scheme::push_back_figure(Figure* fg){
	figures_[size_]=fg;
	size_++;
	
}
void Scheme::remove_figure(int id){
	for(int i=0;i<size_;i++){
		if(figures_[i]->get_id()==id){
			delete figures_[i];
			for(int j=i;j<size_-1;j++)figures_[i]=figures_[i+1];
			size_--;			
			break;
		}
	}
	
}
void Scheme::print_all_figures(){
	for(int i=0;i<size_;i++){
		figures_[i]->print();
 	}
}

void Scheme::zoom_figure(int id, int factor){
	for(int i=0;i<size_;i++){
		if(figures_[i]->get_id()==id){
			figures_[i]->zoom(factor);
			break;
		}
	}
}
Figure* Scheme::is_inside_figure(int x, int y){
	for(int i=0;i<size_;i++){
		if(figures_[i]->is_inside(x,y)){
			return figures_[i];
		}
	}
	printf("%s","chto ty blyat delaesh");
	return figures_[size_-1];
}
void Scheme::move(int id, int new_x, int new_y){
	for(int i=0;i<size_;i++){
		if(figures_[i]->get_id()==id){
			figures_[i]->move(new_x,new_y);
			break;
		}
	}

}
