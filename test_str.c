#include "str.h"
#include "test_str.h"
#include <cstdio>
using namespace std;
void test_str(){


cout<<"cpy"<<endl;
char s1[10]="gossamer";
char s2[20];
strcpy(s2,s1);
cout<<s2<<endl;


cout<<"cmp"<<endl;
char s3[10]="sempiternal";
char s4[20]="sempiternal";
int c=strcmp(s2,s1);
cout<<c<<endl;


cout<<"cat"<<endl;
char s5[8]="gossamer";
char s6[20]="ethereal";
strcat(s2,s1);
cout<<s2<<endl;


cout<<"len"<<endl;
char s7[10]="halcyon";
size_t l=strlen(s1);
cout<<l<<endl;

}
