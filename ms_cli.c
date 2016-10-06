#include "mergesort.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

int compare_int(void* a, void* b){
	int* a1=a;
	int* b1=b;
	return *a1-*b1;
}


int compare_char(void* a, void* b){
	char* a1=a;
	char* b1=b;
	return *a1-*b1;
}


int compare_str(void * s1, void * s2){
	char* str1=s1;
	char* str2=s2;
	while(*str1&&*str2&&str1==str2){
		str1++;
		str2++;
	}
	return *str2-*str1;
}


int main(){

int (*in)(void *, void *);
int (*ch)(void *, void *);
int (*str)(void *, void *);
str=compare_str;
in=compare_int;
ch=compare_char;


char type[5];
for(int i=0;i<5;i++){
	char x;
	scanf("%c",&x);
	if(x!='\0')type[i]=x;
	else break;
}

char intt[5]={'i','n','t','\0'};
char charr[5]={'c','h','a','r','\0'};
char strr[5]={'s','t','r','\0'};


if(compare_str(intt,type)==0){
size_t n;
scanf("%lu",&n);
printf("%lu",n);
int *arr=malloc(n*sizeof(int));
for(size_t i=0;i<n;i++){
	int a;
	scanf("%d",&a);
	arr[i]=a;
}
printf("%lu",n);
int c=mergesort (arr, n,sizeof(int), in);
for(size_t i=0;i<n;i++){
printf("%d",arr[i]);
printf("%c",' ');
}
free(arr);
}


if(compare_str(type,charr)==0){
size_t n;
scanf("%lu",&n);
char *arr=malloc(n*sizeof(char));

for(size_t i=0;i<n;i++){
	char a;
	scanf("%c",&a);
	arr[i]=a;
}
mergesort (arr, n,sizeof(char), ch);
for(size_t i=0;i<n;i++){
printf("%c",arr[i]);
printf("%c",' ');
}
free(arr);
}


if(compare_str(type,strr)==0){
size_t n;
scanf("%lu",&n);
char *arr=malloc(n*sizeof(char)*20);

for(size_t i=0;i<n;i++){
	for(size_t j=0;j<20;j++){
	char c=scanf("%c",&c);		
	if(c=='\0')break;
	
	*(arr+i+j)=c;
}
}
mergesort (arr, n,sizeof(char)*20, str);
for(size_t i=0;i<n;i++){
	size_t j;
	while(*(arr+i+j)!='\0'){
		printf("%c",arr[i]);
		j++;		
	}		
printf("\n");

}
free(arr);
}



}


