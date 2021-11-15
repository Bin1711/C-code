#include "hw5.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Problem 1: Measurements and Conversions
//
// represent a measurement that consists 
// of a numeric value and a unit
//struct measurement {
//    double value;
//    char* units;
//    unsigned int exponent;
//};

//add_measurements simply adds two values
// If they do not have the same units or exponents
//  they cannot be meaningfully added; 
//  print an error and exit.
struct measurement add_measurements(struct measurement m1, 
                                    struct measurement m2) { 
    if (strcmp(m1.units, m2.units) != 0) {
        fprintf(stderr, "Cannot add\n");
        exit(1);
    }
    if (m1.exponent - m2.exponent) {
        fprintf(stderr, "Cannot add\n");
        exit(1);
    }
    struct measurement res;
    res.value = m1.value + m2.value;
    res.units = m1.units;
    res.exponent = m1.exponent;
    return res;
}

//scale_measurement returns a copy of the measurement,
//with the value scaled by the provided factor.
struct measurement scale_measurement(struct measurement m, 
                                        double lambda) {
    struct measurement res;
    res.value = m.value * lambda;
    res.units = m.units;
    res.exponent = m.exponent;
    return res;
}

//multiply_measurements multiplies two measurements.
//Their units must match, though their exponents need not.
struct measurement multiply_measurements(
                            struct measurement m1, 
                            struct measurement m2) {
    struct measurement res;
    if (strcmp(m1.units, m2.units) != 0) {
        fprintf(stderr, "cannot multiply");
        exit(1);
    }
    res.value = m1.value * m2.value;
    res.units = m1.units;
    res.exponent = m1.exponent + m2.exponent;
    return res;
}


//measurement_tos should return a string-formatted
//version of the measurement consisting of
//the number, a space, the units, and
//if the exponent is not 1, a carat (^) 
//and the exponent.
char* measurement_tos(struct measurement m) {
    char result[100];
    if (m.exponent == 1) {
        sprintf(result,"%.2lf %s", m.value, m.units);
    } else {
        sprintf(result,"%.2lf %s^%u", m.value, m.units, m.exponent);
    }
    char* res = strdup(result);
    return res;
}


//represents a unit conversion factor.
//The two strings represent units we might want to convert
//rom and to, and the value of mult_by
//is the constant by which to multiply in order to convert 
//from the from units to the to units
//struct conversion {
//    char *from, *to;
//    double mult_by;
//};

//takes in a list of known conversion factors
//and that list's length, a particular measurement,
//and the units to which we want it converted
//returns a properly-converted and labeled value.
struct measurement convert_units(struct conversion* conversions,
                                 unsigned int n_conversions,
                                 struct measurement m, 
                                 char* to) {
    int i;
    int j = m.exponent;
    int x = 0;
    struct measurement res;
    for(i = 0; i < n_conversions; i++) {
        if ((strcmp(m.units, conversions[i].from) == 0) &&
           (strcmp(to, conversions[i].to) == 0)) {
             double value = m.value;
             double multby = conversions[i].mult_by;
             for(; j > 0; j--) {
                value *= multby;
             }
             res.value = value;
             res.units = to;
             res.exponent = m.exponent;
        } else {
            x++;
        }
    }
    if (x == n_conversions) {
        fprintf(stderr,"no direct conversion matched\n");
    }
    return res;
}


//Problem 2: Tagged unions: Playing Cards
//
//Given an array of cards with the specified length
//return a pseudo-boolean int representing true
//if and only if all the cards in the list are red.
//the joker is not considered red.
int all_red(struct card* cards, unsigned int ncards) {
    int i;
    int t = 0;
    for(i = 0; (t < 1) && (i < ncards); i++) {
        if (cards[i].type == JOKER) {
            t++;
        }
        switch(cards[i].rs.f.suit) {
            case HEARTS:
            case DIAMONDS:
                break;
            case CLUBS:
            case SPADES:
                t++;
                break;
        }
        switch(cards[i].rs.p.suit) {
            case HEARTS:
            case DIAMONDS:
                break;
            case CLUBS:
            case SPADES:
                t++;
                break;
        }
    }
    if (t) {
        return 0;
    } else {
        return 1;
    }
}

//Print out to the screen a textual 
//representation of the given card
void card_show(struct card c) {
    if (c.type == JOKER) {
        printf("Joker");
    } else if (c.type == FACE) { 
        switch(c.rs.f.rank) {
            case JACK:
                printf("Jack ");
                break;
            case QUEEN:
                printf("Queen ");
                break;
            case KING:
                printf("King ");
                break;
        }
        printf("of ");
        switch(c.rs.f.suit) {
            case SPADES:
                printf("Spades ");
                break;
            case HEARTS:
                printf("Hearts ");
                break;
            case CLUBS:
                printf("Clubs ");
                break;
            case DIAMONDS:
                printf("Diamonds ");
                break;
        }
    } else {
        switch(c.rs.p.rank) {
            case 1:
                printf("Ace ");
                break;
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
            case 10:
                printf("%u ", c.rs.p.rank);
                break;
        }
        printf("of ");
        switch(c.rs.p.suit) {
            case SPADES:
                printf("Spades ");
                break;
            case HEARTS:
                printf("Hearts ");
                break;
            case CLUBS:
                printf("Clubs ");
                break;
            case DIAMONDS:
                printf("Diamonds ");
                break;
        }
    }
}


//Return a pseudo-boolean int 
//true if and only if both of the cards 
//passed in are identical.
int cards_equal(struct card c1, struct card c2) {
    if (c1.type != c2.type) {
        return 0;
    } else if (c1.type == FACE) {
        if ((c1.rs.f.rank != c2.rs.f.rank) ||
            (c1.rs.f.suit != c2.rs.f.suit)) {
            return 0;
        } else {
            return 1;
        }
    } else if (c1.type == JOKER) {
        return 1;
    } else {
        if ((c1.rs.p.rank != c2.rs.p.rank) ||
            (c1.rs.p.suit != c2.rs.p.suit)) {
            return 0;
        } else {
            return 1;
        }
    }
}


// Return the sum of the values of all the cards
// the joker will have a value of 0 
// face cards will have a value of 10
// pip cards will have the value shown on them
unsigned int sum_cards(struct card* cards, unsigned int ncards) {
    int i;
    int res = 0;
    for(i = 0; i < ncards; i++) {
        if(cards[i].type == FACE) {
            res = res + 10;
        } else if (cards[i].type == JOKER) {
            res = res + 0;
        } else {
            res = res + cards[i].rs.p.rank;
        }
    }
    return res;
}


//Problem 3: Linked Lists
//
//returns the nth value in the provided list
//using zero-based indexing.
//If the list is not sufficiently long, raise an error
int intlist_nth(intlist* xs, unsigned int n) {
    int i;
    intlist* t = xs;
    for(i = 1; i < n; i++) {
         if (t == NULL) {
            fprintf(stderr,"the list is not sufficiently long");
            exit(1);
        } else {
            t = t->next;
        }
    }
    return t->val; 
}


//overwrites the value in the list at the nth
//index with the specified new value
void intlist_set(intlist* xs, unsigned int n, int val) {
    int i;
    intlist* t = xs;
    for(i = 1; i < n; i++) {
        if (t == NULL) {
            fprintf(stderr,"the list is not sufficiently long");
            exit(1);
        } else {
            t = t->next;
        }
    }
    t->val = val;
}


//appends the given value to the end of the specified list
//returns the head of the resulting list 
intlist* intlist_append(intlist* xs, int val) {
    intlist* t = xs;
    intlist* end = (intlist*)malloc(sizeof(intlist));
    if (end == NULL) {
        fprintf(stderr, "error");
        exit(1);
    }
    end->val = val;
    end->next = NULL;
    if (t == NULL) {
        return end;
    }
    while (t->next != NULL) {
        t = t->next;
    }
    t->next = end;
    return xs;
}


// prints the contents of the list to the screen.
void intlist_show(intlist* xs){
    if (xs == NULL) {
        printf("");
    }
    while (xs->next != NULL) {
        printf("%d ", xs->val);
        xs = xs->next;
    }
    printf("%d", xs->val);
}


//reclaims the memory used by the linked list cells
void intlist_free(intlist* xs) {
    while (xs) {
        intlist* m = xs->next;
        free(xs);
        xs = m;
    }
}      
