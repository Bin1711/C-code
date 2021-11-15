#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "hw3.h"

// Test for all_positive
void test1() {
    int a[] = {1, 3, 2};
    int b[] = {1, -1, 0};
    printf("expect 1: %d\n", all_positive(a, 3));
    printf("expect 0: %d\n\n", all_positive(b, 3));
}

// Test for exists_positive
void test2() {
    int a[] = {-6, -5, 0};
    int b[] = {1, -1, 0};
    printf("expect 0: %d\n", exists_positive(a, 3));
    printf("expect 1: %d\n\n", exists_positive(b, 3));
}

//Test for first_positive
void test3() {
    int a[] = {-6, -5, 0};
    int b[] = {1, -1, 5};
    printf("expect -1: %d\n", first_positive(a, 3));
    printf("expect 1: %d\n\n", first_positive(b, 3));
}

//Test for number_positives
void test4() {
    int a[] = {-6, -5, 0, 5, 7, 4};
    int b[] = {6, 5, 0, 2, 4, 9};
    int c[] = {-6, -5, 0};
    printf("expect 3: %d\n", number_positives(a, 6));
    printf("expect 5: %d\n", number_positives(b, 6));
    printf("expect 0: %d\n\n", number_positives(c, 3));
}

//Test for array_abs
void test5() {
    int a[] = {-6, -5, 0, 5, 7, 4};
    array_abs(a, 6);
    printf("expect 6 5 7: %d %d %d", a[0], a[3], a[4]);
    printf("\n\n");
}

// Test for partial_sums
void test6() {
    int a[] = {-6, -5, 0, 5, 7, 4};
    int* c = partial_sums(a, 6);
    printf("expect 0 -11 5: %d %d %d", c[0], c[2], c[6]);
    printf("\n\n");
    free(c);
}

//Test for rotate_right
void test7() {
    int a[] = {-6, -5, 0, 5, 7, 4};
    rotate_right(a, 6);
    printf("expect 4 0 7: %d %d %d", a[0], a[3], a[5]);
    printf("\n\n");
}

//Test for merge
void test8() {
    int a[] = {1, 3, 6};
    int b[] = {0, 5};
    int* c = merge(a, 3, b, 2);
    printf("expect 0 3 5: %d %d %d", c[0], c[2], c[3]);
    printf("\n\n");
    free(c);
}

//Test for changed_fractions
void test9() {
    unsigned short c;
    unsigned short* d = changed_fractions(1, 365, 31, 20, &c);
    printf("expect 1 15 20: %hu %hu %hu", d[4], d[7], d[17]);
    printf("\n");
    printf("expected length of d is 18: %hu\n", c);
    free(d);
}

int main(int argc, char *argv[]) {
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
}
