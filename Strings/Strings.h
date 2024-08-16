#include<stdbool.h>
#ifndef STRINGS_H
#define STRINGS_H

int len(char string[]);
int find(char string[], char to_find);
void substr(char string[], int start, int end, char sub[]);
int getCount(char string[], char toCount);
char** split(char string[], char delim);
void upper(char string[]);
void lower(char string[]);
bool stringCompare(char string1[], char string2[]);
int substr_exists(char string[], char sub_string[]);
char* stringCopy(char string[]);
#endif
