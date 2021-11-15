// Bin Nguyen
// HW5



// === Problem 1: Measurements and Conversions
struct measurement {
    double value;
    char* units;
    unsigned int exponent;
};
// exponent allows for the representation of units
// add_measurements simply adds two values
struct measurement add_measurements(struct measurement m1, 
                                    struct measurement m2);

// scale_measurement returns a copy of the measurement
//  with the value scaled by the provided factor.
struct measurement scale_measurement(struct measurement m, 
                                        double lambda);

// multiply_measurements multiplies two measurements
struct measurement multiply_measurements(struct measurement m1, 
                                        struct measurement m2);
 
// measurement_tos should return a string-formatted
// version of the measurement consisting of the
// number, a space, the units, and,
// if the exponent is not 1, a carat (^) and the exponent.
char* measurement_tos(struct measurement m);


struct conversion {
    char *from, *to;
    double mult_by;
};
// takes in a list of known conversion factors 
// and that list's length
//  a particular measurement, and the units
//  returns a properly-converted and labeled value.
struct measurement convert_units(struct conversion* conversions,
                                 unsigned int n_conversions,
                                 struct measurement m, 
                                 char* to);


//Problem 2: Tagged unions: Playing Cards
enum face {
    JACK, QUEEN, KING
};

enum suit {
    SPADES, HEARTS, CLUBS, DIAMONDS
};

enum card_type {
    FACE, PIP, JOKER
};

struct face_card {
    enum face rank;
    enum suit suit;
};

struct pip_card {
    unsigned char rank;
    enum suit suit;
};

union rank_suit {
    struct face_card f;
    struct pip_card p;
};

struct card {
    enum card_type type;
    union rank_suit rs;
};

//Given an array of cards with the specified length
// return a pseudo-boolean int representing true
// if and only if all the cards in the list are red
// Remember that the joker is not considered red
int all_red(struct card* cards, unsigned int ncards);

//Print out to the screen a textual representation 
//of the given card
void card_show(struct card c);

// Return a pseudo-boolean int
// true if and only if both of the cards 
// passed in are identical.
int cards_equal(struct card c1, struct card c2);

//Return the sum of the values of all the cards
// in the given array 
//  the joker will have a value of 0, 
//  face cards will have a value of 10
unsigned int sum_cards(struct card* cards, unsigned int ncards);


//Problem 3: Linked Lists
typedef struct intlist intlist;

struct intlist {
    int val;
    intlist* next;
};

//intlist_nth returns the nth value in the provided list
int intlist_nth(intlist* xs, unsigned int n);

//intlist_set overwrites the value in the list at the nth
//index with the specified new value
void intlist_set(intlist* xs, unsigned int n, int val);

//intlist_append appends the given value
// to the end of the specified list
// returns the head of the resulting list
intlist* intlist_append(intlist* xs, int val);

//intlist_show prints the contents of the list to the screen
void intlist_show(intlist* xs);

//intlist_free reclaims the memory used by the linked list cells.
void intlist_free(intlist* xs);
