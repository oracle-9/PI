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

extern void fputcn(char c, FILE *stream, size_t n);

void triangle(size_t n) {
    for (size_t i = 1; i < n; ++i) {
        fputcn('#', stdout, i);
        fputc('\n', stdout);
    }

    for (size_t i = n; i > 0; --i) {
        fputcn('#', stdout, i);
        fputc('\n', stdout);
    }
}
