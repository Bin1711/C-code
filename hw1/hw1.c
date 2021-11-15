//Bin Nguyen
//hw1.c
#include "hw1.h"

// Problem 1: Formula
// Return the price we need to pay for the trip 
double transit_cost(unsigned char bus, unsigned char train,
                    unsigned char transfer, double pass_price) {
    double b = 2.25 * bus;
          /* the amount that I need to pay the bus fare */
    double l = 2.50 * train; 
         /* the amount that I need to pay for the 'L' fare */
    double t = 0.25 * transfer;
         /* the amount that I need to pay for the transfer price */
    double total = b + l + t;
         /* total price (not using the pass) */
    if (total > pass_price) {
        return pass_price;
    }
    return total;
}


// Problem 2: Photocopier Supplie   
// takes in the number of students
//and the number of sheets per exam, in that order,
// and returns the number of sheets of paper to buy.
unsigned int reams_for_exam(unsigned int students, unsigned int exam_pages) {
    unsigned int papers = students * exam_pages;
                 /* number of papers we need */
    if (papers % 500 == 0) {
        return papers;
    } 
    return 500 * (papers/500 + 1);
}


// Problem 3: GCD
// Return The greatest common divisor of two natural numbers
unsigned int gcd(unsigned int n, unsigned int m) {
    if (m == 0) {
        return n;
    }
    if (n >= m) {
        return gcd(m, n % m);
    }
    return gcd(m, n);
}
