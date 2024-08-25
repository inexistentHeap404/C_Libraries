# Strings.h implementation

# Global Req
```
#inlcude<stdio.h>
#include<stdbool.h>
#include "Strings.h"
```

# len
Params and type: stirng(char[])
Returns: length of the string (int)
example:
```
char str[] = "aBcDeFe";
int string_length = len(str);
printf("%d", string_length);
returns -> 7
```

# find
Params and types: string(char[]) and to_find\
Returns: -1 if not found else the index of the first occurence of the character in the string\
exameple:\
```
char str[] = "aBcDeFe";
int index  = find(str, 'a');
printf("%d", index);
retunrs -> 0 
```

# findLast
Params and type: stirng(char[]) and to_find\
Returns: -1 if not found else the index of the last occurence of the character in the string\
example:\
```
char str[] = "aBcDeFe";
int index = findLast(str, 'e');
printf("%d", index);
returns -> 6
```

# substr
Params and type: string(char[]), start index(int) end index(int), sub (cha[])\
Returns : void\
example:\
```
char str[] = "aBcDeFe";
char sub[100];
substr(str, 2, 4, sub);
printf("%s", sub);
prints -> "cDe"
```

# getCount
Params and type: string (char[]), toCount (char)\
Returns: number of occurences of the toCount char in string (int)\
example:\
```
char str[] = "aBcDeFe";
int a = getCount(str, 'e');
returns -> 2
```
NOTE: The counter is case sensitive.

# split
Params and type: string (char[]), delim (char)
Returns: a double pointer **char** to the split string


# upper
Params and type: string (char[])\
Returns: void\

