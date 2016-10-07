#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "mergesort.h"
void prisv(char *to,char *from,size_t size){
for(size_t i=0;i<size;i++){
	*(to+i)=*(from+i);
}
}

int compare_int(void* a, void* b){
	int* a1=a;
	int* b1=b;
	return *a1-*b1;
}


int compare_char(void* a, void* b){
	char* a1=a;
	char* b1=b;
	int c=*a1-*b1;
	
	return c;
}


int compare_str(void * s1, void * s2){
	return strcmp(*(char **)s1, *(char **)s2);
}




char *merge_sort(char* st,char* buf,size_t l,size_t r, size_t size,int (*compare)(void*, void*)){
if(l==r){
	prisv(buf+l*size, st+l*size, size);
	return buf;
}
size_t middle=(l+r)/2;

char *l_buf=merge_sort(st,buf,l,middle,size,compare);
char *r_buf=merge_sort(st,buf,middle+1,r,size,compare);
char *res = l_buf == st ? buf : st;
size_t li=l,ri=middle+1,n=r-l;
for (size_t i = l; i <= r; i++){
if (li <= middle && ri <= r){
            
	if ((*compare)(l_buf+ size*li,r_buf+ size*ri)<0){
                prisv(res+i*size, l_buf+ size*li,size);
                li++;
            }
        else{
                prisv(res+ size*i, r_buf+ size*ri, size);
                ri++;
            }
        }
else if (li <= middle){
            prisv(res+ size*i, l_buf+ size*li, size);
            li++;
        }
        else{
            prisv(res+ size*i, r_buf+ size*ri, size);
            ri++;
        }
}
return res;
}


int mergesort (void* base, size_t num, size_t size, int (*compare)(void*, void*)){
char* st=base;
char *buf=malloc(num*size);
size_t left=0;
size_t right=num-1;
char* res=merge_sort(st,buf,left,right,size,compare);
if(res==st){

free(buf);
}
else {

for(size_t i=0;i<num;i++){
	for(size_t j=0;j<size;j++){
		*(st+i+j)=*(buf+i+j);
}
}

free(buf);
}

return 0;
}


