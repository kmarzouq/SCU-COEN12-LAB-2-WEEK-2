/*File: sorted.c
 *
 * Name: Khondakar Marzouq Mujtaba
 *
 * This program provides many ways to create, search, and manipulate a set datastructure */




#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
// creating the set data structure
typedef struct set{
	char** data; 
	int length; 
	int count;
}SET;
//creating the boolean variable found
bool found;
//creating a function to search the set given its pointer sp and a target tar. It conducts a binary search and if it find the element, it will set found to true and return the index value, else found will be set to false and will return the minimum boundary last set by the search. 
static int search(SET *sp, char *tar, bool *found){ 
	assert(sp!=NULL);
	int max = sp->count-1;
	int min=0;
	int mid;
	while (min<=max){
		mid = (min+max)/2;
		if (strcmp(sp->data[mid],tar)<0){
			min = mid+1;
		}
		else if (strcmp(sp->data[mid],tar)>0){
			max = mid-1;
		}
		else {
			*found=true;
			return mid;
		}
	}
	*found=false;
	return min; 
}
// creates a set data structure and allocates memory for it by taking in the value of maxElts. It returns the pointer to the structure
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
// takes in the pointer sp to the set. It then deletes the set and frees up the memory it used to fill
void destroySet(SET *sp){ 
	assert(sp!=NULL);
	int i;
	for (i=0; i< sp->count; i++){ 
		free(sp->data[i]); 
	}
	free(sp->data); 
	free(sp);
	
}
// returns the number of elements in the the set data structure sp
int numElements(SET *sp){
	assert (sp!=NULL);
	return sp->count;
}
// takes in arguements pointer sp the the data structure and an element elt. I will first see if the element is already in the function and will exit the function if so. If not, it will shift the data after it up away from the target index and then add the element to the target index
void addElement(SET *sp, char *elt){ 
	assert(elt!=NULL&sp!=NULL& sp->count<=sp->length);
	int sind = search(sp,elt, &found); 
	if (found==true){ 
		return;
	}
	else{
		int x; 
		for (x=sp->count;x>sind; x--){
			sp->data[x] = sp->data[x-1];
		}
		elt = strdup(elt);
		assert(elt!=NULL);
		sp->data[sind] = elt;
		sp->count++; 
		
	}
}
// takes in arguements of pointer sp and the element elt. It will then find the target element and deallocate its memory. It will then shift all the points after it down to fill up the missing index.
void removeElement(SET *sp, char *elt){ 
	assert(sp!=NULL);
	int ind = search(sp, elt, &found); 
	if (found==true){
		free(sp->data[ind]);
		
		int x;
		for (x=ind;x<sp->count-1;x++){
			sp->data[x]=sp->data[x+1];
			}
		
		sp->count--;}
}
// takes in arguements of pointer sp and element elt. It will then search the set sp to find elt. If it does it returns the element, if not it returns NULL
char *findElement(SET *sp, char *elt){ 
	assert(sp!=NULL);
	int ind = search(sp, elt, &found); 
	found ? sp->data[ind] : NULL;
}
// this funciton takes in arguement of pointer sp. It will then create an array and allocate memory for it. The array will be the same size as sp->count to cover all the data. It will then add each element in sp into the array and return it 
char **getElements(SET *sp){ 
	assert(sp!=NULL);
	char** arrstr; 
	int totnum = numElements(sp); 
	arrstr = malloc(sizeof(char*)*totnum); 
	int i;
	memcpy(arrstr,sp->data, sizeof(char*)*sp->count);
	return arrstr; 	
}
