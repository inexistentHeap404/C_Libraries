# C_Libraries

You can create, customise and use these functions to ease the workload while using C.
Unlike C++, C does not use classes, but C is still widely used and also donned by hobbyist and nerds. To prevent rewriting the same code again and again I present you certain libraries.

```
Strings.h
Arrays.h (coming soon)
```
# Installation
```
use the classic git clone
```
# Setup
```
navigate to the folder
Strings:
$ gcc -c Strings.c -o Strings.o
$ ar rcs -libStrings.a Strings.o

!impotant -> while adding new functions, update the header file
```
if you wish to make it globally availible make sure you move it to ``` /usr/libs ```
else, have it in your workspace for the main file compilation 
for strings:```$ gcc [filename].c -L. -lStrings -o [outfile].o```
happy hacking!!
