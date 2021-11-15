// CS15200
// HW2
// Bin Nguyen


// Problem 1: switch, Spelling Digits
unsigned char digit_letters(unsigned char digit);

//Problem 2: Tracking progress 
void changed_fractions(unsigned short num, unsigned short denom,
                       unsigned short increment);

//Problem 3: Legal keys
unsigned int legal_keys(unsigned char depths, unsigned char macs);

//Problem 4: Finding Roots
double secant_root(double epsilon, double x0, double x1);

//Problem 5: Integrating Parabolas
double integrate_parabola(double a, double b, double c, double left,
                          double right, unsigned int n);
double antiderivative_parabola(double a, double b, double c, double x);
