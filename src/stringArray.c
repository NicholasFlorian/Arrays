#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "stringArray.h"

StringArray *createStringArray(){
    
    StringArray *stringArray = malloc(sizeof(StringArray));
    
    //set defualt values
    stringArray->array = malloc(sizeof(char));
    stringArray->count = 0;
    stringArray->size = 0;
    
    return stringArray;
    
}

void readCharArray(char *url, StringArray* stringArray){
 
    //var
    
    //handle each word, allow up to 81 chars
    char* word = malloc(sizeof(char) * 81);
    
    //create connection to file
    FILE *file = fopen(url, "r");
    
    
    //if file doesnt exist let the calling method know
    if(!file){
        
        stringArray = NULL;
        
    }
    
    //check for end of file
    while(!feof(file)){
        
        //strclr(word); forgot dont have stackoverflow rn to check
        
        //get the word
        fgets(word, 80, file);
 
        addString(stringArray, word);
        
    }
    
    free(word);
    
}

void addString(StringArray* stringArray, char* stringToAdd){
    
    //var
    int length = 0;
    
    //increase the amount of chars
    length = strlenX(stringToAdd) + 1; //1 for trailing end /0
    stringArray->size+= length;
    
    //printf("Current size of charArray: %d\n", stringArray->size);
    
    //printf("A, ");
    
    //increase the memory of the array
    stringArray->array = realloc(
        stringArray->array,
        sizeof(char*) * (stringArray->count + 1) );
   
    //printf("B\n");
    
    //add word to stringArray
    
    stringArray->array[stringArray->count] = malloc(sizeof(char) * length);
    strncpy(stringArray->array[stringArray->count], stringToAdd, length - 1);
	
    //printf("array at index <%d>, <%s>\n", stringArray->count, stringArray->array[stringArray->count]);
	
    stringArray->count++;
    
}

void deleteStringArray(StringArray* stringArray){

    //TODO
    
}

int strlenX(char *stringToIndex){
    
    int length = strlen(stringToIndex);
    
    //ignore getting the length of the word if the \n is within
    if(stringToIndex[length - 1] == '\n'){
        
        return length -1;
        
    }
    
    return length;
    
}

