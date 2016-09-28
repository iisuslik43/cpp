#include "str.h"
char * strcat(char * destination, const char * source){
 while (*destination)
{
destination++;
}
while(*source)
{
*destination = *source;
destination++;
source++;
}
*destination = '\0';
}

int strlen(const char * str){
int s;
while(*str){
  s++;
}
return s;
}

char * strcpy(char * destination, const char * source){
	while(*source){
	  *destination=*source;
	  source++;
	  destination++;
	}
        *destination='\0';
		
		
}

int strcmp(const char * str1, const char * str2){
    while(*str1&&*str2&&str1==str2){
	str1++;
	str2++;
}
return *str2-*str1;
}
