#include "mergesort.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
void prisv(char *to,char *from,size_t size){
for(size_t i=0;i<size;i++){
	*(to+i)=*(from+i);
}
}




char *merge_sort(char* st,char* buf,size_t l,size_t r, size_t size,int (*compare)(void*, void*)){
if(l==r){
	prisv(buf+l*size, st+l*size, size);
	return buf;
}
size_t middle=(l+r)/2;
char *l_buf=merge_sort(st,buf,l,middle,size,compare);
char *r_buf=merge_sort(st,buf,middle,r,size,compare);
char *res=buf+l*size;
size_t li=l,ri=r,n=r-l;
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
char* buf=malloc(size*num);
size_t left=0;
size_t right=num-1;
char* res=merge_sort(st,buf,left,right,size,compare);
if(res==st){
free(buf);
}
else{
free(st);
base=res;
}
return 0;
}


