// Bin Nguyen
// evidence_hw1.c: test functions


#include <stdlib.h>
#include <stdio.h>
#include "hw1.h"

/* evidence_transit_cost: test transit_cost */
void evidence_transit_cost() {
    printf("*** testing transit_cost\n");
    printf("- expecting 5.15: %.2lf\n", transit_cost(2,3,7,5.15));
    printf("- expecting 6.25: %.2lf\n", transit_cost(1,1,6,6.75));
    printf("- expecting 7.35: %.2lf\n", transit_cost(3,1,2,7.35));
    printf("- expecting 2.25: %.2lf\n", transit_cost(1,0,0,4.10));
}


/* evidence_reams_for_exam: test reams_for_exam */
void evidence_reams_for_exam() {
    printf("*** testing reams_for_exam\n");
    printf("- expecting 1000: %u\n", reams_for_exam(200,5));
    printf("- expecting 1000: %u\n", reams_for_exam(99,8));
    printf("- expecting 500: %u\n", reams_for_exam(10,5));
    printf("- expecting 1000: %u\n", reams_for_exam(100,6));
    printf("- expecting 16000: %u\n", reams_for_exam(2000,8));
}


/* evidence_gcd: test gcd */
void evidence_gcd() {
    printf("*** testing gcd\n");
    printf("- expecting 4: %u\n", gcd(8,28));
    printf("- expecting 1: %u\n", gcd(120,49));
    printf("- expecting 10: %u\n", gcd(10,0));
    printf("- expecting 23: %u\n", gcd(23,69));
    printf("- expecting 9: %u\n", gcd(18,45));
}


/* main: run the evidence functions above */
int main(int argc, char *argv[]) {
    evidence_transit_cost();
    evidence_reams_for_exam();
    evidence_gcd();
    return 0;
}     
