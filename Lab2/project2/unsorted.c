/*File: unsorted.c
 *
 * Name: Khondakar Marzouq Mujtaba
 *
 * This program provides many ways to create, search, and manipulate a set datastructure */




#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
// defining the set data type
typedef struct set{
	char** data;
	int length;
	int count;
}SET;

//search function. It sequentially searches the set by taking in the set pointer and the target string
static int search(SET *sp, char *tar){ 
	assert(sp!=NULL);
	int ser = sp->count;
	int x; 
	for (x=0;x<ser;x++){ 
		if (strcmp(sp->data[x],tar)==0){ 
			return x; 
		}
		}
	return (-1); 
}

// this function creates an empty set and then allocates memory for it. It takes in the arguement maxElts
SET *createSet(int maxElts){ 
	SET* sp;
	sp = malloc(sizeof(SET));
	assert(sp!=NULL); 
	sp->count =0; 
	sp->length = maxElts;  
	sp->data= malloc(sizeof(char*)*sp->length); 
	assert(sp->data!=NULL); 
	return (sp); 
	
}


//this function destorys a set and deallocates its memory. It takes the arguement sp which is the pointer to the set
void destroySet(SET *sp){ 
	assert(sp!=NULL);
	int i;
	for (i=0; i< sp->count; i++){ 
		free(sp->data[i]); 
	}
	free(sp->data); 
	free(sp);
	
}

//this function returns the number of elemnt in a set given by pointer sp
int numElements(SET *sp){
	assert (sp!=NULL);
	return sp->count;
}

//this function takes in an element elt and the set pointer sp and adds the element to sp. It checks beforehand if the element is already in the array or if there is no space to add an element and then terminates the program.
void addElement(SET *sp, char *elt){ 
	if (sp->length==sp->count){ 
		printf("array full");
		exit(1);
		}
	int sind = search(sp,elt); 
	if (sind!=(-1)){ 
		return;
	}
	else{ 
		sp->data[sp->count]=strdup(elt); 
		assert(sp->data[sp->count]!=NULL);
		sp->count++; 
	}
}

// this function takes in a pointer to a set and an element elt and searches the set for elt. If it finds elt, it removes it and deallocates its memory
void removeElement(SET *sp, char *elt){
	assert(sp!=NULL);
	int ind = search(sp, elt); 
	if (ind != -1){
		free(sp->data[ind]);
		sp->count--;
		sp->data[ind]=sp->data[sp->count];
		}
}

//this function takes in a set pointer and an element. the function searches the element and if it finds said element, it will return the element
char *findElement(SET *sp, char *elt){ 
	assert(sp!=NULL);
	int ind = search(sp, elt); 
	if (ind!=(-1)){ 
		return sp->data[ind];
	}
	else{ 
		return NULL; 
	}
}

//this function takes in the set pointer sp. It will then create a an array and allocate memory for it. It will then copy all the strings in the set into the new array and return it
char **getElements(SET *sp){
	assert(sp!=NULL);
	char** arrstr; 
	int totnum = numElements(sp); 
	arrstr = malloc(sizeof(char*)*totnum); 
	int i;
	memcpy(arrstr,sp->data, sizeof(char*)*sp->count);
	return arrstr; 	
}
