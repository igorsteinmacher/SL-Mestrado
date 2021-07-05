#include "entrada.h"

/**
 * A função posicaoDoPonto(char[]) retorna a posição do ponto (número real)
 * caso não encontre retorna -1.
 * 
 * @param numString, string que será verificado aonde está o ponto (do decimal).
 * @return i ou -1, i quando achou o ponto e -1 quando não encontra.
*/
int posicaoDoPonto(char numString[]){
    int i = 0;
    while(numString[i] != '\0'){
        if(numString[i] == '.')
            return i;
        i++;
    }
    return -1;
}


/**
 * A função posicaoSinalCorreta(char[]) verifica se na primeira posição
 * da cadeia de caracteres tem um sinal. Caso tenha retorne true,
 * caso contrário retorna false.
 * 
 * @param numString, string que será verificado se tem o sinal ou não na posição correta.
 * @return true ou false, true caso encontre, caso contrário false.
*/
bool posicaoSinalCorreta(char numString[]){
    return numString[0] == '+' || numString[0] == '-' ? true : false;
}

/**
 * A função temMaisDeUmSinal(char[]) verifica se tem mais de um sinal na
 * cadeia de caracteres, caso encontre retorne true ou caso contrário false.
 * 
 * @param numString, string que será verificado se tem mais de um sinal.
 * @return true ou false, true caso encontre mais de um sinal, caso contrário false.
*/
bool temMaisDeUmSinal(char numString[]){
    int i = 0, contador = 0;
    while (numString[i] != '\0'){
        if(contador > 1)
            return true;

        if(numString[i] == '+' || numString[i] == '-')
            contador++;

        i++;
    }
    return false;
}

/**
 * A função temMaisDeUmPonto(char[]) verifica se tem mais de um ponto na
 * cadeia de caracteres, caso encontre retorne true ou caso contrário false.
 * 
 * @param numString, string que será verificado se tem mais de um ponto.
 * @return true ou false, true caso encontre mais de um ponto, caso contrário false.
*/
bool temMaisDeUmPonto(char numString[]){
    int i = 0, contador = 0;
    while (numString[i] != '\0'){
        if(contador > 1)
            return true;

        if(numString[i] == '.')
            contador++;
        
        i++;
    }
    return false;
}

/**
 * A função numStringEhValido(char[]) verifica se a cadeia
 * de caracteres é um número válido.
 * 
 * @param numString, string que será verificado se tem mais de um sinal.
 * @return true ou false, true caso seja válido, caso contrário false.
*/
bool numStringEhValido(char numString[]){

    if (!posicaoSinalCorreta(numString) && (temMaisDeUmPonto(numString) || temMaisDeUmSinal(numString)))
        return false;

    int i = 0;
    while(numString[i] != '\0'){
        if(!isdigit(numString[i]) && numString[i] != '.' && (numString[i] != '-' || i != 0) && (numString[i] != '+' || i != 0))
            return false;
        i++;
    }
    
    return true;
}