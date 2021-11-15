#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "hw2.h"

// Problem 1: switch, Spelling Digits
// Takes in a single digit, represented as an unsigned char,
// and returns the number of unique letters
// in its English word, also an unsigned char
// If anything other than a single digit number is passed in,
// raise an error
unsigned char digit_letters(unsigned char digit) {
    switch(digit) {
        case 0:
        case 3:
        case 4:
        case 5:
        case 7:
            return 4;
        
        case 1:
        case 2:
        case 6:
        case 9:
            return 3;

        case 8:
            return 5;

        default:
            if (digit > 9) {
                fprintf(stderr, "digit_letters: invalid digit %u\n", digit);
                exit(1);
            }
    }
}

// Problem 2: Tracking progress
//Representing the progress as fractions 
//with the denominators 2-20, print out which of 
//those fractions have changed and which have stayed the same
void changed_fractions(unsigned short num, unsigned short denom,
                       unsigned short increment) {
    int i = 2;
    for(; i <= 20; i++) {
        unsigned short j = num * i / denom;
        unsigned short k = (num + increment) * i / denom;
        if (j == k) {
            printf("still %hu/%d\n", j ,i);
        } else {
            printf("was %hu/%d, now %hu/%d\n", j, i, k, i);
        }
    }
}
          

// Problem 3: Legal keys
//  for a lock with four cuts, 
//  and some specified number of possible depths 
//  and a specified MACS restriction limiting 
//  how far apart the depths can be 
//  for any adjacent pair of cuts
//   returns the number of legal keys for that lock.
unsigned int legal_keys(unsigned char depths, unsigned char macs)
{
    unsigned char i = 1;
    unsigned int s = 0; 
    for (; i <= depths; i++) {
        int t = i + macs;
        int u = i - macs;
        int j;
        int m;
        int n;
        int k = 2 * macs + 1;
        if ((i <= macs) && (t <= depths)) {
            for(j = 1; j <= i + macs; j++) {
                if ((j <= macs) && (j + macs <= depths)) {
                    s += (j + macs) * t;
                } else if ((j <= macs) && (j + macs > depths)) {
                    s += depths * t;
                } else if ((j > macs) && (j + macs <= depths)) {
                    s += k * t;
                } else { 
                    s += (depths + 1 + macs - j) * t;
                }
            }
        } else if ((i <= macs) && (t > depths)) {
            for(j = 1; j <= depths; j++) {
                if (j + macs <= depths) {
                    s += depths * (j + macs);
                } else if (j > macs) {
                    s += (depths + 1 + macs - j) * depths;
                } else {
                    s += depths * depths;
                }
            }
        } else if ((i > macs) && (t <= depths)) {
            for (j = u; j <= t; j++) {
                m = j - macs;
                n = j + macs;
                if (m <= 0) {
                    s += n * k;
                } else if (n > depths) {
                    s += (depths + 1 - m) * k;
                } else {
                    s += k * k;
                }
            }
        } else {
            for (j = u; j <= depths; j++) {
                m = j - macs;
                n = j + macs;
                if ((m <= 0) && (n < depths)) {
                    s += n * (depths + 1 + macs - i);
                } else if ((m <= 0) && (n >= depths)) {
                    s += depths * (depths + 1 + macs -i);
                } else {
                    if (n <= depths) {
                        s += (depths + 1 + macs - i) * 
                                k;
                    } else {
                        s += (depths + 1 + macs - i) *
                                (depths - m + 1);
                    }
                }
            }
        }
    }
    return s;
}  
        

//Problem 4: Finding Roots
//Finding the roots of sin function
//a new guess x_n based on the previous two guesses
double secant_root(double epsilon, double x0, double x1) {
    double s1 = x0;
    double s2 = x1;
    while ((fabs(sin(s2))) > epsilon) {
        double t = s2;
        s2 = fabs(s2 - sin(s2) * (s2 - s1) / (sin(s2) - sin(s1)));
        s1 = t;
    }
    return s2;
}


//Problem 5: Integrating Parabolas
//use Riemann sums, and iteration
//to compute integrate
double integrate_parabola(double a, double b, double c, double left,
                          double right, unsigned int n) {
    double s = (right - left) / n;
    double r = 0;
    double x;
    double y;
    int i; 
    for (i = 0; i < n; i++) {
        x = s * i + left; 
        y = a * x * x + b * x + c;
        r += y * s;
    }
    return r;
}

//use an antiderivative to compare 
double antiderivative_parabola(double a, double b, double c, double x) {
    return a * x * x * x / 3 + b * x * x / 2 + c * x;
}
 
 



