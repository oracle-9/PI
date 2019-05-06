/*
 * Description : University of Minho Imperative Programming 2017/2018 worksheet
 *               1 solved exercise 4.
 *               Resolução do exercício 4 da ficha 1 de Programação Imperativa
 *               2017/2018 da Universidade do Minho.
 * Copyright   : © Oracle, 2019
 * License     : MIT
 * Maintainer  : oracle.uminho@gmail.com
 */

#include <stdlib.h>

#define DEFAULT_TRIANGLE_SIZE 10

extern void triangle(size_t n);

int main(int argc, const char *argv[]) {
    triangle((argc > 1) ? (strtoul(argv[1], NULL, 10))
                        : (DEFAULT_TRIANGLE_SIZE));
}
