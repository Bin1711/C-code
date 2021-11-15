#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "hw2.h"

/* P1: evidence_digit_letters: test digit_letters*/

void evidence_digit_letters()

{

    printf("*** testing digit_letters\n");
    printf("- expecting 3: %u\n", digit_letters(1));
    printf("- expecting 3: %u\n", digit_letters(0));
    printf("- expecting 5: %u\n", digit_letters(8));
    printf("- expecting 4: %u\n", digit_letters(5));

}

/* P2: evidence_changed_fractions: test changed_fractions */

void evidence_changed_fractions()

{

    printf("*** testing changed_fractions\n");
    changed_fractions(0, 365, 31);

}


/* P3: evidence_legal_keys: test legal_keys */

void evidence_legal_keys()

{
    printf("*** testing legal_keys\n");
    printf("- expecting 793: %u\n", legal_keys(9,2));
    printf("- expecting 6561: %u\n", legal_keys(9,8));
}


/* P4: evidence_secant_root: test secant_root */

void evidence_secant_root()
{
    printf("*** testing expt\n");
    printf("secant_root(0.0001,2,1): %.3lf\n", 
                        secant_root(0.0001, 2, 1));
    printf("secant_root(0.0001,0.5,1): %.3lf\n", 
                        secant_root(0.0001, 0.5, 1));
}


/* P5: evidence_integrating: test integrate_parabola
 *                           and antiderivative_parabola */

void evidence_integrating()

{
    printf("*** testing integrate_parabola\n");
    printf("%.4lf\n", integrate_parabola(1, 1, 0, 0, 5, 30));
    printf("*** testing antiderivative_parabola\n");
    printf("%.4lf\n", antiderivative_parabola(1, 1, 0, 5));
}

int main(int argc, char *argv[])

{
    evidence_digit_letters();
    evidence_changed_fractions();
    evidence_legal_keys();
    evidence_secant_root();
    evidence_integrating();
    return 0;

}
