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
int main(){
        char str[] = "aBcDeFe";
        int string_length = len(str);
        printf("%d", string_length);
        return 0;
}
returns -> 7
```

# find
Params and types: string(char[]) and to_find
Returns: -1 if not found else the index of the first occurence of the character in the string
exameple:
```
int main(){
        char str[] = "aBcDeFe";
        int index  = find(str, 'a');
        printf("%d", index);
        return 0;
}
retunrs -> 0 
```
