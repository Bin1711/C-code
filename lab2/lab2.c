#include "lab2.h"
/* expt : linear time recursive exponentiation */
long long int expt(int a, unsigned int n) {
    if (n == 0) {
        return 1;
    } else {
        return a * expt(a, n-1);
    }
}

/* ss : exponentiation by successive squaring */
long long int ss(int a, unsigned int n) {
    if (n == 0) {
        return 1;
    } else if (n % 2 == 0) {
        long long int b = ss(a, n/2);
        return b * b;
    } else {
        return a * ss(a, n-1);
    }
}

/* ssm : exponentiation modulo m by successive squaring */
int ssm(int a, unsigned int n, unsigned int m) {
    if (n == 0) {
        return 1;
    } else if (n % 2 == 0) {
        long long int b = ssm(a, n/2, m);
        return (b * b) % m;
    } else {
        return (a * ssm(a, n-1, m)) % m;
    }
}

