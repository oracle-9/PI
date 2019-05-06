/*
 * Description : University of Minho Imperative Programming 2017/2018 worksheet
 *               2 solved exercises.
 *               Resolução da ficha 2 de Programação Imperativa 2017/2018 da
 *               Universidade do Minho.
 * Copyright   : © Oracle, 2019
 * License     : MIT
 * Maintainer  : oracle.uminho@gmail.com
 */

/* Exercise 1 */
float integer_float_product_v1(signed int n, float m) {
    float product = 0;

    for ( ; n > 0; --n) {
        product += m;
    }
    for ( ; n < 0; ++n) {
        product -= m;
    }

    return product;
}

/* Exercise 2 */
float integer_float_product_v2(signed int n, float m) {
    float product = 0;

    for ( ; n; m *= 2, n /= 2) {
        if (n % 2 == 0) {
            product += ( (n > 0) ? (m) : (-m) );
        }
    }

    return product;
}

/* Exercise 3 */
#define MIN(x, y) ( ((x) < (y)) ? (x) : (y) )

unsigned int gcd_v1(unsigned int a, unsigned int b) {
    unsigned int gcd = MIN(a, b);

    while (gcd && (a % gcd || b % gcd)) {
        --gcd;
    }

    return gcd;
}

/* Exercise 4 */
unsigned int gcd_v2(unsigned int a, unsigned int b) {
    while (a && b) {
        ((a > b) ? (a -= b)
                 : (b -= a));
    }
    return a + b;
}

/* Exercise 5 */
unsigned int gcd_v3(unsigned int a, unsigned int b) {
    while (b) {
        const unsigned int c = a % b;
        a = b;
        b = c;
    }
    return a;
}

/* Exericse 6 a) */
unsigned long long int fib_recursive_v1(unsigned int n) {
    return ((0 == n || 1 == n)
        ? (n)
        : (fib_recursive_v1(n - 1) + fib_recursive_v1(n - 2)));
}

static unsigned long long int fib_recursive_v2_acc_lambda(
    unsigned int n, unsigned long long int f0, unsigned long long int f1) {
    return ((0 == n) ? (f0)
                     : (fib_recursive_v2_acc_lambda(n - 1, f1, f0 + f1)));
}

unsigned long long int fib_recursive_v2(unsigned int n) {
    return fib_recursive_v2_acc_lambda(n, 0, 1);
}

/* Exericse 6 b) */
unsigned long long int fib_iterative(unsigned int n) {
    unsigned long long int f0 = 0;
    unsigned long long int f1 = 1;

    while (n--) {
        const unsigned long long int fnext = f0 + f1;
        f0 = f1;
        f1 = fnext;
    }

    return f0;
}
