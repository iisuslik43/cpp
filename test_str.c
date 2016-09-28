#include "str.h"
#include "test_str.h"

void test_str(){

printf("%s", "cpy");
char s1[10]="gossamer";
char s2[20];
strcpy(s2,s1);
printf("%s", s2);


printf("%s", "cmp");
char s3[10]="sempiternal";
char s4[20]="sempiternal";
int c=strcmp(s2,s1);
printf("%d", c);


printf("%s", "cat");
char s5[8]="gossamer";
char s6[20]="ethereal";
strcat(s2,s1);
printf("%s", s2);


printf("%s", "len");
char s7[10]="halcyon";
int l=strlen(s1);
printf("%s", "cpy");

}
