# Strings Library Implementation:

# function len
Params: (char[])string
Return: (int) length of the stirng which was passed
example:
```
int main(){
        char str[] = "aBcDeFe";
        int string_length = len(str);
        printf("%d", string_length);
        return 0;
}
returns -> 7
```
# function find
Params: (char[]) string, (char) character to find
Return: (int) The first index of where a character was found : If not found returns -1
```
#include<stdio.h>
#include "Strings.h"
int main(){
        char str[] = "aBcDeFe";
        int index  = find(str, 'a');
        printf("%d", index);
        return 0;
}
returns -> 0
```
