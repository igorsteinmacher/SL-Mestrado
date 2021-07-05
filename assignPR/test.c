#include "acutest.h"
#include "entrada.h"

#define TAM_NUMERO 50

void testSomenteNumeroInteiro(void){
    char *numero = (char*) calloc (TAM_NUMERO, sizeof(char));
    strcpy(numero, "342432432343");
    TEST_CHECK(numStringEhValido(numero) == 1);
}

void testSomenteNumeroReal(void){
    char *numero = (char*) calloc (TAM_NUMERO, sizeof(char));
    strcpy(numero, "321321.432432");
    TEST_CHECK(numStringEhValido(numero) == 1);
}

void testSomenteCaracteres(void){
    char *numero = (char*) calloc (TAM_NUMERO, sizeof(char));
    strcpy(numero, "adsuidasiuhdasuiiauds");
    TEST_CHECK(numStringEhValido(numero) != 1);
}

void testCaracteresENumero(void){
    char *numero = (char*) calloc (TAM_NUMERO, sizeof(char));
    strcpy(numero, "adsuidasiuhdasuiiauds132123321321");
    TEST_CHECK(numStringEhValido(numero) != 1);
}

void testNumeroPositivo(void){
    char *numero = (char*) calloc (TAM_NUMERO, sizeof(char));
    strcpy(numero, "+36.432");
    TEST_CHECK(numStringEhValido(numero) == 1);
}

void testNumeroNegativo(void){
    char *numero = (char*) calloc (TAM_NUMERO, sizeof(char));
    strcpy(numero, "-95.432");
    TEST_CHECK(numStringEhValido(numero) == 1);
}

void testNumeroComSinalPositivoNoMeio(void){
    char *numero = (char*) calloc (TAM_NUMERO, sizeof(char));
    strcpy(numero, "423423+36.432");
    TEST_CHECK(numStringEhValido(numero) != 1);
}

void testCharacteristicReal(void){
    int numeroEsperado = 32, numeroRetornado;
    char *numero = (char*) calloc (TAM_NUMERO, sizeof(char));
    strcpy(numero, "32.768");
    characteristic(numero, &numeroRetornado);
    TEST_CHECK(numeroRetornado == numeroEsperado);
}

void testCharacteristicRealNegativo(void){
    int numeroEsperado = -32, numeroRetornado;
    char *numero = (char*) calloc (TAM_NUMERO, sizeof(char));
    strcpy(numero, "-32.768");
    characteristic(numero, &numeroRetornado);
    TEST_CHECK(numeroRetornado == numeroEsperado);
}

void testCharacteristicInteiro(void){
    int numeroEsperado = 32768, numeroRetornado;
    char *numero = (char*) calloc (TAM_NUMERO, sizeof(char));
    strcpy(numero, "32768");
    characteristic(numero, &numeroRetornado);
    TEST_CHECK(numeroRetornado == numeroEsperado);
}

void testCharacteristicInteiroNegativo(void){
    int numeroEsperado = -100, numeroRetornado;
    char *numero = (char*) calloc (TAM_NUMERO, sizeof(char));
    strcpy(numero, "-100");
    characteristic(numero, &numeroRetornado);
    TEST_CHECK(numeroRetornado == numeroEsperado);
}

void testExemploCaracteristicaNumeratorDenominatorUm(void){
    int numeroCaracteristicaEsperado = 2, numeroCaracteristicaRetornado;
    int numeroNumeratorEsperado = 351, numeroNumeratorRetornado;
    // 1001 por causa do teto
    int numeroDenominatorEsperado = 1001, numeroDenominatorRetornado;
    char *numero = (char*) calloc (TAM_NUMERO, sizeof(char));
    strcpy(numero, "2.351");
    characteristic(numero, &numeroCaracteristicaRetornado);
    mantissa(numero, &numeroNumeratorRetornado, &numeroDenominatorRetornado);
    TEST_CHECK(numeroCaracteristicaRetornado == numeroCaracteristicaEsperado);
    TEST_CHECK(numeroNumeratorRetornado == numeroNumeratorEsperado);
    TEST_CHECK(numeroDenominatorRetornado == numeroDenominatorEsperado);
}

void testExemploCaracteristicaNumeratorDenominatorDois(void){
    int numeroCaracteristicaEsperado = -4, numeroCaracteristicaRetornado;
    int numeroNumeratorEsperado = -4, numeroNumeratorRetornado;
    int numeroDenominatorEsperado = 10, numeroDenominatorRetornado;
    char *numero = (char*) calloc (TAM_NUMERO, sizeof(char));
    strcpy(numero, "-4");
    characteristic(numero, &numeroCaracteristicaRetornado);
    mantissa(numero, &numeroNumeratorRetornado, &numeroDenominatorRetornado);
    TEST_CHECK(numeroCaracteristicaRetornado == numeroCaracteristicaEsperado);
    TEST_CHECK(numeroNumeratorRetornado == numeroNumeratorEsperado);
    TEST_CHECK(numeroDenominatorRetornado == numeroDenominatorEsperado);
}

void testExemploCaracteristicaNumeratorDenominatorTres(void){
    int numeroCaracteristicaEsperado = 0, numeroCaracteristicaRetornado;
    int numeroNumeratorEsperado = 125, numeroNumeratorRetornado;
    int numeroDenominatorEsperado = 10000, numeroDenominatorRetornado;
    char *numero = (char*) calloc (TAM_NUMERO, sizeof(char));
    strcpy(numero, "0.0125");
    characteristic(numero, &numeroCaracteristicaRetornado);
    mantissa(numero, &numeroNumeratorRetornado, &numeroDenominatorRetornado);
    TEST_CHECK(numeroCaracteristicaRetornado == numeroCaracteristicaEsperado);
    TEST_CHECK(numeroNumeratorRetornado == numeroNumeratorEsperado);
    TEST_CHECK(numeroDenominatorRetornado == numeroDenominatorEsperado);
}

TEST_LIST = {
    {"testSomenteNumeroInteiro", testSomenteNumeroInteiro},
    {"testSomenteNumeroReal", testSomenteNumeroReal},
    {"testSomenteCaracteres", testSomenteCaracteres},
    {"testCaracteresENumero", testCaracteresENumero},
    {"testNumeroPositivo", testNumeroPositivo},
    {"testNumeroNegativo", testNumeroNegativo},
    {"testNumeroComSinalPositivoNoMeio", testNumeroComSinalPositivoNoMeio},
    {"testCharacteristicReal", testCharacteristicReal},
    {"testCharacteristicRealNegativo", testCharacteristicRealNegativo},
    {"testCharacteristicInteiro", testCharacteristicInteiro},
    {"testCharacteristicInteiroNegativo", testCharacteristicInteiroNegativo},
    {"testExemploCaracteristicaNumeratorDenominatorUm", testExemploCaracteristicaNumeratorDenominatorUm},
    {"testExemploCaracteristicaNumeratorDenominatorDois", testExemploCaracteristicaNumeratorDenominatorDois},
    {"testExemploCaracteristicaNumeratorDenominatorTres", testExemploCaracteristicaNumeratorDenominatorTres},
    {0}	
};