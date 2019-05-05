/*
 * Description : University of Minho Imperative Programming 2017/2018 worksheet
 *               1 solved exercise 4.
 *               Resolução do exercício 4 da ficha 1 de Programação Imperativa
 *               2017/2018 da Universidade do Minho.
 * Copyright   : © Oracle, 2019
 * License     : MIT
 * Maintainer  : oracle.uminho@gmail.com
 */

#include <stdio.h>

void fputcn(char c, FILE *stream, size_t n) {
    while (n--) {
        fputc(c, stream);
    }
}
