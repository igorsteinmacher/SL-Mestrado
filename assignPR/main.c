// Conversion Functions (F1)
// The two functions, characteristic() and mantissa(),
// will break a character array into a characteristic and a mantissa.
// The characteristic for the number 2.351 is 2 and the mantissa is 351 over 1,000.
// The characteristic for the number 0.0125 is 0 and the mantissa is 125 over 10,000.
// The characteristic for the number -4.0 is -4 and the mantissa is 0 over 10.
// These values should be stored in the reference parameters c, numerator and denominator.
// The C string may include leading or trailing spaces, unary plus or minus signs,
// integers, or real numbers. Your functions must handle all of these cases.
// If an invalid string is passed in your function will return false.
// If the passed in string was valid return true.

#include "entrada.h"

#define STYLE_BOLD         "\033[1m"
#define STYLE_NO_BOLD      "\033[22m"

int main( int argc, char *argv[ ] ){

    system("clear");  

    // Caso falte os paramêtros
    if(argc != 2){  
        printf(STYLE_BOLD "use: %s numero\n" STYLE_NO_BOLD, argv[0]);
        exit(1);
    }

    // Caso o valor digitado foi inválido
    if(!numStringEhValido(argv[1])){
        printf(STYLE_BOLD "numero inválido\n" STYLE_NO_BOLD);
        exit(1);
    }

    int c;
    int numerator;
    int denominator;

    // if the conversion from C string to integers can take place
    if(characteristic(argv[1], &c) && mantissa(argv[1], &numerator, &denominator)){
        // do some math with c, n, and d 
        printf("character: %d\n", c);
        printf("numerator: %d\n", numerator);
        printf("demorator: %d\n", denominator);
    } else {
        // handle the error on input
        printf(STYLE_BOLD "erro!" STYLE_NO_BOLD);
    }

    return 0;
}
