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

// upper -> takes in a string, and converts it to upper case *(modifies the original string)*
void upper(char string[]){
	for(int i = 0; i < len(string); i++){
		string[i] = (char)((int)string[i] - 32);
	}
}

// lower -> takes in a string, and converts it to lower case *(modifies the original string)*
void lower(char string[]){
	for(int i = 0; i < len(string); i++){
		string[i] = (char)((int)string[i] + 32);
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
int substr_exists(char string[], char sub_string[]){
	int group_size = len(sub_string);
	int index = 0;
	char buffer_string[len(sub_string)];
	int buffer_string_index = 0;
	int found = 0;
	while(index + group_size < len(string)){
		for(int i = index; i < index + group_size; i++){
			buffer_string[buffer_string_index] = string[i];
			buffer_string_index++;
		}
		if(stringCompare(sub_string, buffer_string)){
			return 1;
		}
		index++;
		buffer_string_index = 0;	
	}
	return 0;
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


