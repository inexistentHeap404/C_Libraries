#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
// len -> finds the length of the input string (forms the basis for this lib)
int len(char string[]){
	int length = 0;
	char *ptr = &string[0];
	while(*ptr != '\0'){
		length++;
		ptr++;
	}
	return length;
}

// find -> return the index of where a character was first found in a string
int find(char string[], char to_find){
	int find_index = 0;
	char *ptr = &string[0];
	while(*ptr != to_find){
		find_index++;
		ptr++;
	}
	if(find_index > len(string))
		return -1;
	else
		return find_index;
}

// findLast -> returns the last index of where a char was found
int findLast(char string[], char to_find){
	int i = len(string);
	int find_index = len(string);
	while(string[i] != to_find){
		if(string[i] == to_find){
			find_index = i;
		}
		i--;
	}
	return find_index;
}

// substr -> extracts the substring from a string from start to end both inclusive and redirects the substring to a string which is already definded in the function the function is used (it does not modify the original string)
void substr(char string[], int start, int end, char out_string[]){
	if(len(string) > 0 && start < len(string) && end < len(string) && end - start > 0){
		int index = 0;
		for(int i = start; i < end + 1; i++){
			out_string[index] = string[i];
			index++;
		}
	}
	else{
		out_string[0] = '\0';
	}
}

// getCount -> Gets the number of occurences of a character in a given string
int getCount(char string[], char toCount){
	int count = 0;
	for(int i = 0; i < len(string); i++){
		if(string[i] == toCount){
			count++;
		}
	}
	return count;
}

// split -> takes in a string, a delimiter and a target char[][] and returns 2s char array char**

char** split(char string[], char delim){
	int delim_count = getCount(string, delim);
	char buffer_string[10];
	char** ret = (char**) malloc(delim_count + 1);
	int buffer_string_index = 0;
	int ret_index = 0;
	if(delim_count != 0){
		for(int i = 0; i < len(string); i++){
			if(string[i] == delim || string[i + 1] == '\0'){
				ret[ret_index] = (char*) malloc(len(buffer_string) + 1);
				buffer_string[buffer_string_index + 1] = '\0';
				for(int j = 0; j < len(buffer_string); j++){
					ret[ret_index][j] = buffer_string[j];
				}
				ret[ret_index][len(ret[ret_index])] = '\0';
				buffer_string_index = 0;
				ret_index++;
				continue;
			}
			buffer_string[buffer_string_index] = string[i];
			buffer_string_index++;
		}
		return ret;
	}
	else{
		return &string;
	}
}	

// upper -> takes in a string, and converts it to upper case *(modifies the original string)*
void upper(char string[]){
	for(int i = 0; i < len(string); i++){
		if((int)string[i] >= 97 && (int)string[i] <= 122){
			string[i] = (char)((int)string[i] - 32);
		}
		else{
			continue;
		}
	}
}

// lower -> takes in a string, and converts it to lower case *(modifies the original string)*
void lower(char string[]){
	for(int i = 0; i < len(string); i++){
		if((int)string[i] >= 65 && (int)string[i] <= 90){
			string[i] = (char)((int)string[i] + 32);
		}
		else{
			continue;
		}
	}
}

// stringCompare -> takes in two strings and checks character wise returns 1 if same else 0
bool stringCompare(char string1[], char string2[]){
	for(int i = 0; i < len(string1); i++){
		if((int)string1[i] != (int)string2[i]){
			return false;
		}
	}
	return true;
}

// substr_exists -> takes in a string and a substring and checks if the substring exists in the string(return 1 or -1)
int substr_exits(char string[], char substr[]){
	int group_size = len(substr);
	int index = 0;
	int string_length = len(string);
	char buffer_string[len(substr)];
	int buffer_string_index = 0;
	while(group_size + index < string_length){
		for(int i = index; i < index + group_size; i++){
			buffer_string[buffer_string_index] = string[i];
			buffer_string_index++;
		}
		if(stringCompare(buffer_string, substr)){
			return 1;
		}
		
		index++;
	}
}
// stringCopy -> takes in a string and copies it to another string, returns a char* to the copied string
char* stringCopy(char string[]){
	char* ret = (char*) malloc(len(string));
	for(int i = 0; i < len(string); i++){
		ret[i] = string[i];
	}
	return &ret[0];
}

/* strJoin -> takes in a string and a delimiter as inputs and returns a char* to the joined string 
 * example :
 * str = "abcd"
 * delim = ' ';
 * join(str, delim) will give an output like -> a b c d
 */
char* stringJoin(char string[], char delim){
	int delim_count = len(string) - 1;
	char* ret = malloc(len(string) + delim_count + 1);
	int string_index = 0;
	for(int i = 0; i < len(string) + delim_count; i++){
		if(i % 2 == 0){
			ret[i] = string[string_index];
			string_index++;
		}
		else{
			ret[i] = delim;
		}
	}
	ret[len(string) + delim_count + 1] = '\0';
	return ret;
}

// stringAppend -> takes in two strings appends the second to the first returns a char*
/*
 * example:
 * str = "ab"
 * str2 = "cd"
 * stringAppend(str, str2) -> "abcd"
 */
char* stringAppend(char string1[], char string2[]){
	int total_length = len(string1) + len(string2);
	char* ret = (char*) malloc(total_length + 1);
	int str1_len = len(string1);
	int str2_len = len(string2);
	int str2_index = 0;
	for(int i = 0; i < str1_len; i++){
		ret[i] = string1[i];
	}
	for(int i = str1_len; i < total_length; i++){
		ret[i] = string2[str2_index];
		str2_index++;
	}
	return ret;
}

//stringCharInsert -> takes in a string, a char, and an index. inserts the character at the specified 0-based index. (modifies the original string)
void stringCharInsert(char string[], char insertChar, int insertIndex){
	int string_length = len(string);
	for(int i = string_length; i > insertIndex - 1; i--){
		string[i + 1] = string[i];
	}
	string[insertIndex] = insertChar;
}

//stringInsert -> takes in two strings and an index, inserts the second string in the specified index of the first string
void stringInsert(char string[], char insertString[],  int insertIndex){
	int insertString_length = len(insertString);
	for(int i = 0; i < insertString_length; i++){
		stringCharInsert(string, insertString[i], insertIndex);
		insertIndex++;
	}
}

//stringRevrse -> takes in a string and reverses the string (modifies the original string)
void stringReverse(char string[]){
	char temp;
	int string_length = len(string);
	for(int i = 0; i < string_length / 2; i++){
		temp = string[i];
		string[i] = string[string_length - i - 1];	
		string[string_length - i - 1] = temp;
	}
}
