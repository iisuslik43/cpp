#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "mergesort.h"

int main(int argc,char *argv[]){

int (*in)(void *, void *);
int (*ch)(void *, void *);
int (*str)(void *, void *);
str=&compare_str;
in=&compare_int;
ch=&compare_char;
if (argc > 2){

if(strcmp("int",argv[1])==0){

size_t n=argc-2;
int *arr=malloc(n*sizeof(int));
for(size_t i=2;i<n+2;i++){
	sscanf(argv[i],"%d",&arr[i-2]);
}

mergesort (arr, n,sizeof(int), in);
for(size_t i=0;i<n;i++){
printf("%i ",arr[i]);
}

}


if(strcmp("char",argv[1])==0){
size_t n=argc-2;
char* arr=malloc(n*sizeof(char));
for(size_t i=2;i<n+2;i++){
	sscanf(argv[i],"%c",&arr[i-2]);
}
mergesort (arr, n,sizeof(char), ch);
for(size_t i=0;i<n;i++){
printf("%c ",arr[i]);

}

}


if(strcmp(argv[1],"str")==0){
size_t n=argc-2;
char **arr=malloc(n*sizeof(char*));
for(size_t i=2;i<n+2;i++){
	arr[i-2]=argv[i];
}
mergesort (arr, n,sizeof(char*), str);
for(size_t i=0;i<n;i++){
	printf("%s ",arr[i]);	
	}		

}
}
}


