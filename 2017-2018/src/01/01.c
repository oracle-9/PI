/*
 * Description : University of Minho Imperative Programming 2017/2018 worksheet
 *               1 solved exercises.
 *               Resolução da ficha 1 de Programação Imperativa 2017/2018 da
 *               Universidade do Minho.
 * Copyright   : © Oracle, 2019
 * License     : MIT
 * Maintainer  : oracle.uminho@gmail.com
 * The code written from exercises 1.1 up to and including 2.1 doesn't serve as
 * an example of good coding practices, nor do the comments.
 * O código escrito dos exercícios 1.1 a 2.1, inclusive, não serve como exemplo
 * de boas práticas de programação. O mesmo se aplica aos comentários.
 */

#include <stdio.h>

/* *****************************************************************************
                              STATE AND ASSIGNMENT
                              ESTADO E ATRIBUIÇÃO
*******************************************************************************/

/* Exercise 1.1 */
void ex1_1(void) {
    int x, y; /* define two signed integer variables: x, y */

    x = 3; /* assign the value <3> to x */

    y = x + 1; /* read x (3)
                  calculate x + 1 (3 + 1 = 4)
                  assign the integer value <4> to y */

    x = x * y; /* read x <3>
                  read y <4>
                  calculate x * y (3 * 4 = 12)
                  assign the integer value <12> to x */

    y = x + y; /* read x <12>
                  read y <4>
                  calculate x + y (12 + 4 = 16)
                  assign the integer value <16> to y */

    printf("%d %d\n", x, y); /* format print x <12>, <space>, y <16>, <newline>
                                to stdout */
    /* Expected output:
     "12 16
     "
     */
}

/* Exercise 1.2 */
void ex1_2(void) {
    int x, y; /* define two signed integer variables: x, y */

    x = 0; /*  assign the integer value <0> to x */

    printf("%d %d\n", x, y); /* format print
                                x <0>, <space>, y <uninitialized>, <newline>
                                to stdout*/
    /* Expected output:
    "0 ind
    "
    where ind is an indeterminate value caused by undeﬁned behavior (printing an
    uninitialized variable)
     */
}

/* Exercise 1.3 */
void ex1_3(void) {
    char a, b, c; /* define three character variables: a, b, c */
    a = 'A';      /* assign the character value <'A'> to a     */
    b = ' ';      /* assign the character value <' '> to b     */
    c = '0';      /* assign the character value <'0'> to c     */

    printf("%c %d\n", a, a); /* format print
                                a <'A'>,
                                <space>,
                                ASCII value of a <65>,
                                <newline>
                                to stdout */
    /* Expected output:
    "A 65
    "
     */

    a = a + 1; /* increment a by 1 ('A' + 1 = 65 + 1 = 66 = 'B') */
    c = c + 2; /* increment c by 2 ('0' + '2' = 48 + 2 = 50 = '2') */

    printf("%c %d %c %d\n", a, a, c, c); /* format print
                                            a <'B'>,
                                            <space>,
                                            ASCII value of a <66>,
                                            <space>,
                                            c <'2'>
                                            <space>,
                                            ASCII value of c <50>
                                            <newline>
                                            to stdout */
    /* Expected output:
    "B 66 2 50
    "
     */

    c = a + b; /* read a <'B'>
                  read b <' '>
                  calculate a + b ('B' + ' ' = 66 + 32 = 98 = 'b')
                  assign character value <'b'> to c */

    printf("%c %d\n", c, c); /* format print
                                c <'b'>,
                                <space>,
                                ASCII value of c <98>
                                <newline>
                                to stdout */
    /* Expected output
    "b 98
    "
     */
}

/* Exercise 1.4 */
void ex1_4(void) {
    int x, y;  /* define two signed integer variables: x, y */
    x = 200;   /* assign the integer value <200> to x       */
    y = 100;   /* assign the integer value <100> to y       */
    x = x + y; /* increment x by y (200 + 100 = 300)        */

    y = x - y; /* read x <300>
                  read y <100>
                  calculate x - y (300 - 100 = 200)
                  assign the integer value <200> to y */

    x = x - y; /* decrement x by y (300 - 200 = 100) */

    printf("%d %d\n", x, y); /* format print
                                x <100>
                                <space>
                                y <200>
                                <newline>
                                to stdout */
    /* Expected output
    "100 200
    "
     */
}

/* Exercise 1.5 */
void ex1_5(void) {
    int x, y; /* define two signed integer variables: x, y */
    x = 100;  /* assign the integer value <100> to x       */
    y = 28;   /* assign the integer value <28> to y        */
    x += y;   /* increment x by y (100 + 28 = 128)         */
    y -= x;   /* decrement y by x (28 - 128 = -100)        */

    printf("%d %d\n", x++, ++y); /* increment y by 1 (-100 + 1 = -99)
                                    format print
                                    x <128>
                                    <space>
                                    y <-99>
                                    <newline>
                                    to stdout
                                    increment x by 1 (128 + 1 = 129) */
    /* Expected output:
    "128 -99
    "
     */

    printf("%d %d\n ", x, y); /* format print
                                 x <129>
                                 <space>
                                 y <-99>
                                 <newline>
                                 to stdout */
    /* Expected output:
    "129 -99
    "
    */
}

/* *****************************************************************************
                               CONTROL STRUCTURES
                             ESTRUTURAS DE CONTROLO
*******************************************************************************/

/* Exercise 2.1 a) */
void ex2_1_a(void) {
    int x, y; /* define two signed integer variables: x, y */
    x = 3;    /* assign the integer value <3> to x         */
    y = 5;    /* assign the integer value <5> to y         */

    if (x > y) /* check whether x is greater than y
                  if the condition is true, execute the body of the if block
                  (3 > 5 -> false) */
    {
        y = 6; /* not executed */
    }

    printf("%d %d\n", x, y); /* format print
                                x <3>
                                <space>
                                y <5>
                                <newline>
                                to stdout */
    /* Expected output: 
    "3 5
    "
     */
}

/* Exercise 2.1 b) */
void ex2_1_b(void) {
    int x, y; /* define two signed integer variables: x, y */

    x = y = 0; /* assign the integer value <0> to y
                  read y <0>
                  assign the integer value <0> to x */

    while (x != 11) /* check whether x is different than <11>
                       while the condition is true, execute the body of the
                       while loop */
    {
        x = x + 1; /* increment x by <1> */
        y += x;    /* increment y by x */
    }
    /* at the end of the cycle, x = <11> and y = <66> */

    printf("%d %d\n", x, y); /* format print
                                x <11>
                                <space>
                                y <66>
                                <newline>
                                to stdout */
    /*
    "11 66
    "
     */
}

/* Exercise 2.1 c) */
void ex2_1_c(void) {
    int x, y;  /* define two signed integer variables: x, y */
    x = y = 0; /* assign the integer value <0> to y
                  read y <0>
                  assign the integer value <0> to x */

    while (x != 11) /* check whether x is different than <11>
                       while the condition is true, execute the body of the
                       while loop */
    {
        x = x + 2; /* increment x by <2> */
        y += x;    /* increment y by x */
    }
    /* since x will always be even, the condition wil always be satisfied, which
       will cause an endless loop */

    printf("%d %d\n", x, y); /* not executed */
}

/* Exercise 2.1 d) */
void ex2_1_d(void) {
    int i; /* define a signed integer variable i */

    for (i = 0; i < 20; i++) /* assign the integer value <0> to i
                                check whether i is lesser than <20>
                                while the condition is true, execute the body of
                                the while loop, then increment i by <1> */
    {
        if (i % 2 == 0) /* check whether i is even
                           if the condition is true, execute the body of
                           the if block */
        {
            putchar('_'); /* write the character <'_'> to stdout */
        }

        else /* if the condition is false (i is odd), execute the body of the
                else block */
        {
            putchar('#'); /* write the character <'#'> to stdout */
        }
        /* at the end of the cycle, the characters "_#_#_#_#_#_#_#_#_#_#" will
           have been written to stdout */
    }
}

/* Exercise 2.1 e) */
void ex2_1_e(void) {
    char i, j; /* define two character variables: i, j */

    for (i = 'a'; i != 'h'; i++) /* assign the character value <'a'> to i
                                    check whether i is different than <'h'>
                                    while the condition is true, execute the
                                    body of the while loop, then increment i by
                                    <1> */
    {
        for (j = i; j != 'h'; j++) /* assign the character value in i to j
                                    check whether j is different than <'h'>
                                    while the condition is true, execute the
                                    body of the while loop, then increment j by
                                    <1> */
        {
            putchar(j); /* write the character in j to stdout */
        }

        putchar('\n'); /* write <newline> to stdout */
    }
    /* at the end of the cycle the following characters will have been written
       to stdout:
      "abcdefg
       bcdefg
       cdefg
       defg
       efg
       fg
       g
       "
       */
}

/* Exercise 2.1 f) */
void ex2_1_f(int n) {
    while (n > 0) /* check whether n is greater than 0
                     while the condition is true, execute the body of the while
                     the loop */
    {
        if (n % 2 == 0) /* check whether i is even
                           if the condition is true, execute the body of
                           the if block */
        {
            putchar('0'); /* write the character value <'0'> to stdout */
        }

        else /* if the condition is false (n is odd), execute the body of the
                else block */
        {
            putchar('1'); /* write the character value <'1'> to stdout */
        }

        n = n / 2; /* halve n */
    }

    putchar('\n'); /* write <newline> to stdout */
}

/* Exercise 2.1 f) main */
int ex2_1_f_main(void) {
    int i; /* define a signed integer variable i */

    for (i = 0; i < 16; i++) /* execute body of the for loop 16 times */
    {
        ex2_1_f(i); /* call ex2_1_f with the argument i; */
    }
    /* at the end of the cycle the following characters will have been written
       to stdout: */
    /*
    "
    1
    01
    11
    001
    101
    011
    111
    0001
    1001
    0101
    1101
    0011
    1011
    0111
    1111
    "
     */
    return 0; /* return success exit code */
}

/* Exercise 2.2 */
static void fputcn(char c, FILE *stream, size_t n) {
    while (n--) {
        fputc(c, stream);
    }
}

void print_square(size_t n) {
    for (size_t i = 0; i < n; ++i) {
        fputcn('#', stdout, n);
        fputc('\n', stdout);
    }
}

/* Exercise 2.3 */
void print_chess_board(size_t n) {
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            fputc(((i + j) % 2 == 0) ? ('#') : ('_'), stdout);
        }
        fputc('\n', stdout);
    }
}
