//CMSC 15200
//HW1
//BIN NGUYEN
//File name: hw1.h

//Problem 1: 
//Determine the price when paying for each trip, and compare to the pass price.
//Return the best (smallest) price you need to pay for the trip
double transit_cost(unsigned char bus, unsigned char train,
                    unsigned char transfer, double pass_price);

//Problem 2
//takes in the number of students and the number of sheets per exam,
//in that order, and returns the number of sheets of paper to buy.
unsigned int reams_for_exam(unsigned int students, unsigned int exam_pages);

//Problem 3
//Return The greatest common divisor of two natural numbers
//is given by Euclid's algorithm
unsigned int gcd(unsigned int n, unsigned int m);
