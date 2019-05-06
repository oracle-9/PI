/*
 * Description : University of Minho Imperative Programming 2017/2018 worksheet
 *               4 solved exercises.
 *               Resolução da ficha 4 de Programação Imperativa 2017/2018 da
 *               Universidade do Minho.
 * Copyright   : © Oracle, 2019
 * License     : MIT
 * Maintainer  : oracle.uminho@gmail.com
 */

#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

/* Exercise 1 */
char *str_tolower_v1(char *s, size_t *count) {
    if (count) {
        *count = 0;

        for ( ; *s; ++s) {
            if (isupper(*s)) {
                *s = tolower(*s);
                ++(*count);
            }
        }
    } else {
        for ( ; *s; ++s) {
            *s = tolower(*s);
        }
    }

    return s;
}

char *str_tolower_v2(char s[], size_t *count) {
    if (count) {
        *count = 0;

        for (size_t i = 0; '\0' != s[i]; ++i) {
            if (isupper(s[i])) {
                s[i] = tolower(s[i]);
                ++(*count);
            }
        }
    } else {
        for (size_t i = 0; '\0' != s[i]; ++i) {
            s[i] = tolower(s[i]);
        }
    }

    return s;
}

/* Exercise 2 */
size_t count_lines_v1(const char *s) {
    size_t count = 1;

    for ( ; *s; ++s) {
        if ('\n' == *s) {
            ++count;
        }
    }

    return count;
}

size_t count_lines_v2(const char s[]) {
    size_t count = 1;

    for (size_t i = 0; s[i]; ++i) {
        if ('\n' == s[i]) {
            ++count;
        }
    }

    return count;
}

/* Exercise 3 */
size_t count_words_v1(const char *s) {
    size_t count = 0;

    for (size_t i = 0; s[i];) {
        for ( ; isspace(s[i]); ++i) {
        }

        if (s[i]) {
            ++count;
            for ( ; s[i] && !isspace(s[i]); ++i) {
            }
        }
    }

    return count;
}

size_t count_words_v2(const char *s) {
    size_t count = 0;

    for (size_t i = 0; s[i]; ++i) {
        if (!isspace(s[i]) && (i == 0 || isspace(s[i - 1]))) {
            ++count;
        }
    }

    return count;
}

/* Exercise 4 */
char *search_str(const char needle[], const char *const haystack[], size_t n) {
    while (n--) {
        if (strcmp(needle, haystack[n]) == 0) {
            return (char *)haystack[n];
        }
    }
    return NULL;
}

/* Exercise 5 */
char *search_str_ord_v1(const char needle[],
                        const char *const haystack[],
                        size_t n) {
    int cmp = 0;
    while (n-- && ((cmp = strcmp(needle, haystack[n])) < 0)) {}
    return (0 == cmp) ? ((char *)haystack[n]) : (NULL);
}

char *search_str_ord_v2(const char needle[],
                        const char *const haystack[],
                        size_t n) {
    for (size_t i = 0; i < n; ++i) {
        const int cmp = strcmp(needle, haystack[i]);

        if (cmp > 0) {
            continue;
        } else if (0 == cmp) {
            return (char *)haystack[i];
        } else {
            break;
        }
    }

    return NULL;
}

/* Exercise 6 */
static char *bin_search_str_recursive_aux(const char needle[],
                                          const char *const haystack[],
                                          ssize_t l,
                                          ssize_t r) {
    if (l > r) {
        return NULL;
    }

    const int mid = (l + r) / 2;
    const int cmp = strcmp(needle, haystack[mid]);

    if (cmp < 0) {
        return bin_search_str_recursive_aux(needle, haystack, l, mid - 1);
    } else if (0 == cmp) {
        return (char *)haystack[mid];
    } else {
        return bin_search_str_recursive_aux(needle, haystack, mid + 1, r);
    }
}

char *bin_search_str_recursive(const char needle[],
                               const char *const haystack[],
                               size_t n) {
    return bin_search_str_recursive_aux(needle, haystack, 0, n - 1);
}

char *bin_search_str_iterative(const char needle[],
                               const char *const haystack[],
                               size_t n) {
    ssize_t l = 0;
    ssize_t r = n - 1;

    while (l <= r) {
        const size_t mid = (l + r) / 2;
        const int cmp = strcmp(needle, haystack[mid]);

        if (cmp < 0) {
            r = mid - 1;
        } else if (0 == cmp) {
            return (char *)haystack[mid];
        } else {
            l = mid + 1;
        }
    }

    return NULL;
}

/* Exercise 7 */
size_t count_zeros(size_t r, size_t c, signed int m[r][c]) {
    size_t count = 0;

    for (size_t i = 0; i < r; ++i) {
        for (size_t j = 0; j < c; ++j) {
            if (0 == m[i][j]) {
                ++count;
            }
        }
    }

    return count;
}

/* Exercise 8 */
signed int **identity_matrix_v1(size_t n) {
    signed int (*const identity)[n] = calloc(n * n, sizeof(signed int));

    for (size_t i = 0; i < n; ++i) {
        identity[i][i] = 1;
    }

    return (signed int **)identity;
}

signed int **identity_matrix_v2(size_t n) {
    signed int *const inner_array = calloc(n * n, sizeof(signed int));
    signed int **const identity   = calloc(n, sizeof(signed int *));

    for (size_t i = 0; i < n; ++i) {
        inner_array[i * n + i] = 1;
        identity[i] = inner_array + n * i;
    }

    return identity;
}

void fill_with_identity_matrix_v1(size_t n, signed int m[n][n]) {
    memset(m, 0, n * n * sizeof(signed int));
    for (size_t i = 0; i < n; ++i) {
        m[i][i] = 1;
    }
}

void fill_with_identity_matrix_v2(size_t n, signed int m[n][n]) {
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < i; ++j) {
            m[i][j] = 0;
        }

        m[i][i] = 1;

        for (size_t j = i + 1; j < n; ++j) {
            m[i][j] = 0;
        }
    }
}

static void identity_matrix_v1_example(void) {
    const size_t n = 10;
    signed int(*const identity)[n] =
        (signed int(*const)[n])identity_matrix_v1(n);
    free(identity);
}

static void identity_matrix_v2_example(void) {
    const size_t n = 10;
    signed int **const identity = identity_matrix_v2(n);
    free(*identity);
    free(identity);
}

void fill_with_identity_matrix_example(void) {
    const size_t n = 10;
    signed int my_matrix[n][n]; /* uninitialized, careful */
    fill_with_identity_matrix_v1(n, my_matrix);
}

/* Exercise 9 */
float *float_2d_matrix_prod(size_t n, const float m[n][n], const float vec[n]) {
    float *const product = calloc(n * n, sizeof(float));

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j)
            product[i] += m[i][j] * vec[j];
    }

    return product;
}

void fill_with_float_2d_matrix_prod(size_t n,
                                    const float m[n][n],
                                    const float vec[n],
                                    float product[n]) {
    for (size_t i = 0; i < n; ++i) {
        product[i] = 0;
        for (size_t j = 0; j < n; ++j)
            product[i] += m[i][j] * vec[j];
    }
}
