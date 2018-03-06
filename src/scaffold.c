#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "stringArray.h"
#include "ioHandler.h"

int main(int args, char** argv){
	
	//var
	StringArray* stringArray;
	char* in;
	
	
	stringArray = createStringArray();
	
	//main loop
	while(strcmp((in = softenStringInput()), "q") != 0){
		
		printf("%s\n", in);
		addString(stringArray, in);
		
	}

	

	deleteStringArray(stringArray);
	//free(stringArray);
	
	return 0;
	
}
