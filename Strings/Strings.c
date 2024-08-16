#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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

// split -> takes in a string, a delimiter and a target char[][] and redirects the split output to the char[][] (NOT YET IMPLEMENTED SOME ERROR WITH THE MALLOC)

char** split(char string[], char delim){
	int delim_count = getCount(string, delim);
	char** out = (char**)malloc(sizeof(char*) * delim_count);
	char buffer_string[255];
	int buffer_string_index = 0;
	int out_index = 0;
	for(int i = 0; i < len(string); i++){	
		if(delim == string[i]){
			for(int j = 0; j < len(buffer_string); j++){
				out[out_index][j] = buffer_string[j];
			}
			out_index++;
			buffer_string_index = 0;
		}
		else{
			buffer_string[buffer_string_index] = string[i];
		}
		buffer_string_index++;
	}
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

//
