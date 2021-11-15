#include <stdlib.h>
#include <stdio.h>
#include "lab2.h"


/* evidence_expt: test expt */
void evidence_expt()
{
    printf("*** testing expt\n");
    printf("- expecting 1: %lld\n", expt(2,0));
    printf("- expecting 8: %lld\n", expt(2,3));
    printf("- expecting 243: %lld\n", expt(3,5));
    printf("- expecting 2048: %lld\n", expt(2,11));  
}


/* evidence_ss: test ss */
void evidence_ss()
{
    printf("*** testing ss\n");
    printf("- expecting 1: %lld\n", ss(5,0));
    printf("- expecting 32: %lld\n", ss(2,5));
    printf("- expecting 81: %lld\n", ss(3,4));
    printf("- expecting 16: %lld\n", ss(4,2));
}


void evidence_ssm()
{
    printf("*** testing ssm\n");
    printf("- expecting 1: %lld\n", ssm(2,0,13));
    printf("- expecting 0: %lld\n", ssm(2,3,8));
    printf("- expecting 4: %lld\n", ssm(3,10,5));
    printf("- expecting 1: %lld\n", ssm(2,16,5));
    printf("- expecting 6: %lld\n", ssm(6,11,7));
}


/* main: run the evidence functions above */
int main(int argc, char *argv[])
{
    evidence_expt();
    evidence_ss();
    evidence_ssm();
    return 0;
}

