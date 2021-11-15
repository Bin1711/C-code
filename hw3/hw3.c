#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "hw3.h"


// Problem 1: Array Basics
//
//returns a pseudo-boolean int representing true
//if and only if all elements of the array a with 
//length alen are positive.
int all_positive(int a[], unsigned int alen) {
    int i;
    int s;    
    for(i = 0; (a[i] > 0) && (i < alen); i++) {
        s = 1;
    }
    if (i < alen) {
        s = 0;
    }
    return s;
}

//returns a pseudo-boolean int representing true
// if and only if at least one element 
// of the array is positive
int exists_positive(int a[], unsigned int alen) {
    int i;
    int s;
    for(i = 0; (a[i] <= 0) && (i < alen); i++) {
        s = 0;
    }
    if (i < alen) {
        s = 1;
    }
    return s;
} 

//that returns the index of the first
//element in the array that is positive. 
//If no element is positive, return -1.
int first_positive(int a[], unsigned int alen) {
    int i;
    int s;
    for(i = 0; (a[i] <= 0) && (i < alen); i++);
    if (i == alen) {
        s = -1;
    } else {
        s = a[i];
    }
    return s;
}

//returns the number of positive numbers in the array.
unsigned int number_positives(int a[], unsigned int alen) {
    int i;
    int s = 0;
    for(i = 0; i < alen; i++) {
        if (a[i] > 0) {
            s++;
        }
    }
    return s;
}

//changes every element in the array 
//to be its absolute value
void array_abs(int a[], unsigned int alen) {
    int i;
    for(i = 0; i < alen; i++) {
        if (a[i] < 0) {
            a[i] = -a[i];
        }
    }
}

//returns a new array containing partial sums 
//over the provided array
int* partial_sums(int a[], unsigned int alen) {
    int i;
    int* b = (int*)malloc(sizeof(int) * (alen + 1));
    for(i = 0; i < alen + 1; i++) {
        if (i == 0) {
            b[i] = 0;
        } else {
            b[i] = b[i - 1] + a[i - 1];
        }
    }
    return b;
}

//modifies the passed-in array
//such that each value appears, in the updated array
//one more spot to the "right" than before
//The last element must "wrap around"
//to become the new first element
void rotate_right(int a[], unsigned int alen) {
    int i;
    int s = a[alen - 1];
    for (i = alen - 1; i > 0; i--) {
        a[i] = a[i - 1];
    }
    a[0] = s;
}


//  Problem 2: Merging Lists
//  given two lists and their corresponding lengths
//  produces a merged list
//  the overall list sorted in ascending order
int* merge(int* a, unsigned int alen, int* b, unsigned int blen) {
    int i;
    int j;
    int* c = (int*)malloc(sizeof(int) * (alen + blen));
    for(i = 0; i < blen; i++) {
        for(j = 0; (a[j] < b[i]) && (j < alen); j++);
        c[i + j] = b[i];
    }
    for(i = 0; i< alen; i++) {
        for(j = 0; (b[j] < a[i]) && (j < blen); j++);
        c[i + j] = a[i];
    }
    return c;
}


// Problem 3: Changing Fractions, in a List
// give information about all the changed fractions, 
// in ascending order of denominator from 2 to max_denom
// only identify those fractions that have changed
// return them in a list.
unsigned short* changed_fractions(unsigned short num, 
                                  unsigned short denom,
                                  unsigned short increment,
                                  unsigned short max_denom, 
                                  unsigned short* outlen) {
    int i;
    unsigned short l;
    int s = 0;
    unsigned short j;
    unsigned short k;
    for(i = 2; i <= max_denom; i++) {
        j = num * i / denom;
        k = (num + increment) * i / denom;
        if (j < k) {
            s++;
        }
    }
    s = 2 * s;
    *outlen = s;
    unsigned short* r = 
        (unsigned short*)malloc(sizeof(unsigned short) * s);   
    for(i = 0; i < s/2; i++) {
        int t = -1;
        for(l = 2; (t < i) && (l <= max_denom); l++) {
            j = num * l / denom;
            k = (num + increment) * l / denom;
            if (j < k) {
                t++;
            }
        }
        r[2 * i] = k;
        r[2 * i + 1] = l - 1;
    }
    return r;
} 
