#include "hw5.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// test for add_measurements
void test1() {
    struct measurement m1 = {20, "cm", 2};
    struct measurement m2 = {13, "cm", 2};
    struct measurement m = add_measurements(m1, m2);
    printf("%.2lf, %s, %u\n", m.value, m.units, m.exponent);
}

//test scale_measurement
void test2() {
    struct measurement m1 = {20, "cm", 2};
    struct measurement m = scale_measurement(m1, 2);
    printf("%.2lf, %s, %u\n", m.value, m.units, m.exponent);
}

//test for multiply_measurements
void test3() {
    struct measurement m1 = {20, "cm", 2};
    struct measurement m2 = {13, "cm", 2};
    struct measurement m = multiply_measurements(m1, m2);
    printf("%.2lf, %s, %u\n", m.value, m.units, m.exponent);
}

//test for measurement_tos
void test4() {
    struct measurement m1 = {20, "cm", 2};
    printf("%s\n", measurement_tos(m1));
}

// test for convert_units
void test5() {
    struct measurement m1 = {200, "cm", 1};
    struct conversion c[2] = {{"cm", "m", 0.01}, {"dm", "cm", 10}};
    struct measurement m = convert_units(c, 2, m1, "m");
    printf("%.2lf, %s, %u\n", m.value, m.units, m.exponent);
}

// test for all_red
void test6() {
    struct card cs[] = {{FACE, {{JACK, CLUBS}}},
                        {JOKER}};
    int a = all_red(cs, 2);
    printf("%d\n", a);
}

//test for card_show
void test7() {
    struct card c = {PIP, {{1, CLUBS}}};
    card_show(c);
    printf("\n");
}

//test for cards_equal
void test8() {
    struct card c1 = {PIP, {{1, CLUBS}}};
    struct card c2 = {PIP, {{1, CLUBS}}};
    int a = cards_equal(c1, c2);
    printf("%d\n", a);
}

//test for sum_cards
void test9() {
    struct card cs[] = {{FACE, {{JACK, CLUBS}}},
                        {JOKER}, {PIP, {{3,DIAMONDS}}}};
    unsigned int a = sum_cards(cs, 3);
    printf("%u\n", a);
}

//cons function
intlist* cons(int first, intlist* rest) {
    intlist* res = (intlist*)malloc(sizeof(intlist));
    if (res == NULL) {
        fprintf(stderr, "error");
        exit(1);
    }
    res->val = first;
    res->next = rest;
    return res;
}

//helper for print list
intlist* helper() {
    struct intlist* a = cons(20, NULL);
    struct intlist* b = cons(30, a);
    struct intlist* c = cons(40,b);
    struct intlist* d = cons(30,c);
    struct intlist* e = cons(35,d);
    return e;
}

// test for intlist_nth
void test10() {
    struct intlist* xs = helper();
    struct intlist* t = xs;
    int a = intlist_nth(xs, 3);
    printf("%d\n", a);
    intlist_free(t);
}

//test for intlist_set
void test11() {
    struct intlist* a = cons(20, NULL);
    struct intlist* b = cons(30, a);
    struct intlist* c = cons(40, b);
    struct intlist* d = c;
    struct intlist* e = intlist_append(c, 50);
    while (e != NULL) {
        printf("%d ", e->val);
        e = e->next;
    }
    printf("\n");
    intlist_free(d);
}

//test for intlist_append
void test12() {
    struct intlist* xs = helper();
    struct intlist* list = intlist_append(xs, 50);
    while (list != NULL) {
        printf("%d ", list->val);
        list = list->next;
    }
    printf("\n\n");
    intlist_free(xs);
}

//test for intlist_show
void test13() {
    struct intlist* xs = helper();
    struct intlist* t = xs;
    intlist_show(xs);
    intlist_free(t);
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
    test10();
    test11();
    test12();
    test13();
    return 1;
}
