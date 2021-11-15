#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "hw4.h"

// Problem 1: CRYP 10100
// takes in an array of code numbers
// and its length and returns a string
// with the decoded message
//If a code number is zero,
//place a space at that location in the string
//code number is greater than 26,
//print an error and exit.
char* decode(unsigned int a[], unsigned int alen) {
    char* c = (char*)malloc(sizeof(char) * (alen + 1));
    if (c == NULL) {
        fprintf(stderr, "invalid string\n");
        exit(1);
    }
    int i;
    for(i = 0; i < alen; i++) {
        if (a[i] > 26) {
            fprintf(stderr, "invalid input %u\n", a[i]);
            exit(1);
        }
        if (a[i] == 0) {
            c[i] = 32;
        } else {
            c[i] = a[i] + 64;
        }
    }
    c[i] = '\0';
    return c;
}


// Problem 2: Find and Replace
// takes in a string
// a string to search for within that string
// a string to replace it with
// and a string in which to store the result.
void find_replace(char* src, char* from, char* to, char* dest) {
    int i = 0;
    int j;
    int l;
    int x = 0;
    char* t = src;
    while (src[i]) {
        j = 0;
        while ((*(t + j) == from[j]) && (from[j])) {
            j++;
        }
        if (from[j]) {
            dest[x] = src[i];
            x++;
            t++;
        } else {
            for(l = 0; (to[l]); l++) {
                dest[x] = to[l];
                x++;
            }
            for(j = 0; (from[j]); j++) {
            t++;
            }
        }
        i = t - src;
    }
    dest[x] = '\0';
}


// Problem 3: String Concatenation
// takes in a list (array) of strings
// and concatenates them into one larger string
// Between each pair of strings,
// it should insert a space character
// but not before the first string or
// after the last string
char* concat_strings(char** strings,
                        unsigned int num_strings) {
    int i;
    int j;
    int s = 0;
    int t = 0;
    for(i = 0; i < num_strings; i++) {
        for(j = 0; (strings[i][j]); j++) {
            s++;
        }
        s++;
    }
    char* c = (char*)malloc(sizeof(char) * s);
    for(i = 0; i < num_strings; i++) {
        for(j = 0; (strings[i][j]); j++) {
            c[t] = strings[i][j];
            t++;
        }
        if(i < num_strings - 1) {
            c[t] = 32;
            t++;
        }
    }
    c[t] = '\0';
    return c;
}
