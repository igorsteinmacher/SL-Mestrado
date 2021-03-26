#include "featureMantissa.h"

/**
 * A função characteristic(char[], int*) aloca uma string que receberá
 * a parte que é characteristic. No final converte essa string para inteiro.
 * 
 * @param numString, string que contém o número que será convertido.
 * @param c, irá receber o valor que é convertido pela string.
 * @return true, caso consiga converter.
*/
bool characteristic(char numString[], int *c){
    char *characteristic = malloc(sizeof(char) * TAM_NUMERO);

    int i = 0;
    while(numString[i] != '\0' && numString[i] != '.'){
        characteristic[i] = numString[i];
        i++;
    }

    characteristic[i] = '\0';
    
    *c = atoi(characteristic);
    
    return true;
}

/**
 * A função characteristic(char[], int*) aloca uma string que receberá
 * a parte que é characteristic. No final converte essa string para inteiro.
 * 
 * @param numString, string que contém o número que será convertido.
 * @param numerator,  irá receber o valor que é convertido pela string.
 * @param denominator, irá receber o valor que é calculado.
 * @return true, caso consiga converter e calcular o denominador.
*/
bool mantissa(char numString[], int *numerator, int *denominator){
    char *mantissa = malloc(sizeof(char) * TAM_NUMERO);
    int valueCharacteristic;
    int i = posicaoDoPonto(numString), j = 0;
    
    if(i == -1){
        *numerator = atoi(numString);
        *denominator = 10;
        return true;
    }

    i = i + 1;
    while(numString[i] != '\0')
        mantissa[j++] = numString[i++];
    mantissa[j] = '\0';

    *numerator = atoi(mantissa);
    characteristic(numString, &valueCharacteristic);
    *denominator = ceil((*numerator / (atof(numString) - valueCharacteristic)));
    
    return true;
}