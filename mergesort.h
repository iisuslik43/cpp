#include <stddef.h>
int mergesort (void* base, size_t num, size_t size, int (*compare)(void*,void*));
int compare_int(void* a, void* b);
int compare_char(void* a, void* b);
int compare_str(void * s1, void * s2);
