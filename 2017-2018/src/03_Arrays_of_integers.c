/*
 * Description : University of Minho Imperative Programming 2017/2018 worksheet
 *               3 solved exercises.
 *               Resolução da ficha 3 de Programação Imperativa 2017/2018 da
 *               Universidade do Minho.
 * Copyright   : © Oracle, 2019
 * License     : MIT
 * Maintainer  : oracle.uminho@gmail.com
 * The code written in exercise 1 doesn't serve as an example of good coding
 * practices, nor do the comments.
 * O código escrito no exercício 1 não serve como exemplo de boas práticas de
 * programação. O mesmo se aplica aos comentários.
 */

#include <stdio.h>
#include <stdlib.h>

/* Exercise 1 a) */
void ex1_a(void) {
    int x[15] = {
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15
    }; /* define a 15 element signed integer array variable x
          assign specific values to each and every element */

    int *y, *z, i; /* define 2 signed integer pointer variables: y, z
                      define a signed integer variable i */

    y = x;     /* assign the memory adress of *x to y (*y = 1)       */
    z = x + 3; /* assign the memory adress of *(x + 3) to z (*z = 4) */

    for (i = 0; i < 5; i++) /* execute body of the for loop 5 times */
    {
        printf("%d %d %d\n", x[i], *y, *z); /* format print the integer values
                                               stored in the memory addresses
                                               <x + i>,
                                               <y>,
                                               <z>
                                               to stdout */

        y = y + 1; /* increment y by 1 */
        z = z + 2; /* increment z by 2 */
    }
    /* at the end of the cycle the following characters will have been written
       to stdout */
    /*
    "1 1 4"
    "2 2 6"
    "3 3 8"
    "4 4 10"
    "5 5 12
    "
     */
}

/* Exercise 1 b) main */
int ex1_b(void) {
    int i, j, *a, *b; /* define 2 signed integer variables: i, j
                         define two signed integer pointer variables: a, b */

    i = 3;  /* assign the integer variable <3> to i */
    j = 5;  /* assign the integer variable <5> to j */
    a = &i; /* assign the memory address of i to a (*a = i = 3) */
    b = &j; /* assign the memory address of j to b (*b = j = 5) */
    i++;    /* increment i by 1 <4> */

    j = i + *b; /* read i <4>
                   read *b <5>
                   calculate i + *b (4 + 5 = 9)
                   assign the integer value <9> to j */

    b = a;      /* assign the memory address stored of a to b (*b = *a = 4) */
    j = j + *b; /* increment j by *b (9 + 4 = 13) */

    printf("%d\n", j); /* format print
                          j <13>
                          <newline>
                          to stdout */
    /* Expected output:
    "13
    "
     */
    return 0; /* return success exit code */
}

/* Exercise 2 */

/* May evaluate left and right more than once */
#define SWAP(T, left, right)                 \
    do {                                     \
        const T __SWAP_tmp__ = left;         \
        left                 = right;        \
        right                = __SWAP_tmp__; \
    } while (0)

void swap_signed_int(signed int *left, signed int *right) {
    const signed int tmp = *left;
    *left  = *right;
    *right = tmp;
}

/* Exercise 3 */
void swap_signed_int_elem_v1(signed int a[], signed int i, signed int j) {
    swap_signed_int(a + i, a + j);
}

void swap_signed_int_elem_v2(signed int a[], signed int i, signed int j) {
    const signed int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

void swap_signed_int_elem_v3(signed int a[], signed int i, signed int j) {
    const signed int tmp = i[a];
    i[a] = j[a];
    j[a] = tmp;
}

void swap_signed_int_elem_v4(signed int a[], signed int i, signed int j) {
    const signed int tmp = *(a + i);
    *(a + i) = *(a + j);
    *(a + j) = tmp;
}

/* Exercise 4 */
signed long long int integer_sum_v1(const signed int a[], size_t n) {
    signed long long int sum = 0;
    for ( ; n > 0; sum += a[--n]) {}
    return sum;
}

signed long long int integer_sum_v2(const signed int a[], size_t n) {
    signed long long int sum = 0;

    for (size_t i = 0; i < n; sum += a[i++]) {
        continue;
    }

    return sum;
}

signed long long int integer_sum_v3(const signed int a[], size_t n) {
    signed long long int sum = 0;

    for (size_t i = 0; i < n; ++i) {
        sum += a[i];
    }

    return sum;
}

/* Exercise 5 */
signed int integer_maximum(const signed int a[], size_t n) {
    signed int maximum = a[--n];

    while (n--) {
        if (a[n] > maximum) {
            maximum = a[n];
        }
    }

    return maximum;
}

/* Exercise 6 */
unsigned long long int *squares_array(size_t n) {
    unsigned long long int *const squares_array =
        calloc(n, sizeof(unsigned long long int));

    while (n--) {
        squares_array[n] = n * n;
    }

    return squares_array;
}

unsigned long long int *
fill_with_squares_array(unsigned long long int squares_array[], size_t n) {
    while (n--) {
        squares_array[n] = n * n;
    }
    return squares_array;
}

static void squares_array_example(void) {
    const size_t n = 10;
    unsigned long long int *const squares = squares_array(n);
    free(squares);
}

static void fill_with_squares_array_example(void) {
    const size_t n = 10;
    unsigned long long int squares[n]; /* uninitialized, careful */
    fill_with_squares_array(squares, n);
}

/* Exercise 7 */
unsigned long long int *pascal_array(size_t n) {
    unsigned long long int *const pascal_array =
        calloc(n, sizeof(unsigned long long int));

    pascal_array[0] = 1;

    for (size_t i = 1; i < n; ++i) {
        pascal_array[i] = 1;

        for (size_t j = i - 1; j > 0; --j) {
            pascal_array[j] += pascal_array[j - 1];
        }
    }

    return pascal_array;
}

unsigned long long int *
fill_with_pascal_array(unsigned long long int pascal_array[], size_t n) {
    pascal_array[0] = 1;

    for (size_t i = 1; i < n; ++i) {
        pascal_array[i] = 1;

        for (size_t j = i - 1; j > 0; --j) {
            pascal_array[j] += pascal_array[j - 1];
        }
    }

    return pascal_array;
}

static void pascal_array_example(void) {
    const size_t n = 10;
    unsigned long long int *const pascal = pascal_array(n);
    free(pascal);
}

static void fill_with_pascal_array_example(void) {
    const size_t n = 10;
    unsigned long long int pascal[n]; /* uninitialized, careful */
    fill_with_pascal_array(pascal, n);
}
