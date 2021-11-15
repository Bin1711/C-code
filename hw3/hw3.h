// Bin Nguyen
// HW3

//Problem 1: Array Basics
//
// returns a pseudo-boolean int representing true
// if and only if all elements of the array 
// a with length alen are positive
int all_positive(int a[], unsigned int alen);

//returns a pseudo-boolean int representing true
//if and only if at least one element
//of the array is positive  
int exists_positive(int a[], unsigned int alen);

// returns the index of the first 
//  element in the array that is positive
//   If no element is positive, return -1.
int first_positive(int a[], unsigned int alen);

//returns the number of positive numbers in the array
unsigned int number_positives(int a[], unsigned int alen);

//changes every element in the array to be its absolute value.
void array_abs(int a[], unsigned int alen);

//returns a new array containing partial 
//sums over the provided array
int* partial_sums(int a[], unsigned int alen);

//modifies the passed-in array 
//each value appears, in the updated array,
//one more spot to the "right" than before
void rotate_right(int a[], unsigned int alen);


//Problem 2: Merging Lists
//
//given two lists and their corresponding lengths, 
//produces a merged list
int* merge(int* a, unsigned int alen, int* b, unsigned int blen);


// Problem 3: Changing Fractions, in a List
//
// give information about all the changed fractions, 
// in ascending order of denominator from 2 to max_denom 
unsigned short* changed_fractions(unsigned short num, 
                                  unsigned short denom,
                                  unsigned short increment,
                                  unsigned short max_denom, 
                                  unsigned short* outlen);
