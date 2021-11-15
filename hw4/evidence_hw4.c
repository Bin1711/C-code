#include "hw4.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test1() {
    unsigned int a[] = {1, 0, 3, 4};
    char* c = decode(a, 4);
    printf("%s\n", c);
    free(c);
    }

void test2() {
    char e[9];
    char d[12];
    char f[17];
    find_replace("foofoofoo", "foo", "bar", e);
    find_replace("hello world", "hallo", "hi", d);
    find_replace("the thing is there, then?", "the", "", f);
    printf("%s\n", d);
    printf("%s\n",f);
    printf("%s\n", e);
}

void test3() {
    char* a[] = {"Hi", "hello"};
    char* c = concat_strings(a, 2);
    printf("%s\n", c);
    free(c);
}

int main(int argc, char *argv[]) {
    test1();
    test2();
    test3();
    return 1;
}
