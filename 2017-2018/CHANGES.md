# Changes made from the original exercises


## [EN]

### - Worksheet 1
- Exercises `1.1` to `1.5` and `2.1 a)` to `2.1 e)` were isolated in specific functions;
- Function `f` (exercise `2.1 f)`) was renamed to `ex2_1_f`, and its respective `main` function was renamed to `ex2_1_f_main`, which receives 0 arguments `(void)`, instead of an unspecified number of arguments `()`;
- Functions from exercises `1.1` to `2.1 f)` were (excessively) commented on to provide a detailed description;
- Exercises `2` and `3` use `stdio`'s `fputc` instead of `putchar`;
- Exercise `4` was solved in a specific directory, with a respective Makefile;
- Exercise `4` `triangulo` function was renamed to `triangle`, and receives an argument of type `size_t` instead of an `int`.

### - Worksheet 2
- Every occurence of the type `int` was replaced with `signed int`;
- Exercises `1` and `2` were renamed from `multInt` to `integer_float_product_v1` and `integer_float_product_v2`, respectively;
- Exercise `1` return variable was renamed from `r` to `product` (hooray giving your variables *actual, decent* names!);
- Exercises `3`, `4` and `5` were renamed from `mdc` to `gcd_v1`, `gcd_v2`, (...), depending on the exercise number, and receive and return an `unsigned int` instead of an `int`, because the greatest common divsor in negative numbers is the same as in positive ones;
- Exercises `6 a)` and `6 b)` were renamed from `fib` to `fib_recursive_v1` and `fib_iterative`, respectively;
- An alternative, faster recursive fibonacci definition `fib_recursive_v2` was added.

### - Worksheet 3
- Every occurence of the type `int` was replaced with `signed int`;
- Exercise `1 a)` was isolated in function `ex1_a`;
- Exercises `1 a)` and `1 b)` were (excessively) commented on to provide a detailed description;
- Exercise `1 b)` was renamed from `main` to `ex1_b`, and receives 0 arguments `(void)`, instead of an unspecified number of arguments `()`;
- Exercise `2` was renamed from `swapM` to `swap_signed_int`;
- Exercise `3` was renamed from `swap` to `swap_signed_int_elem_v1`;
- Several alternatives to `swap_signed_int_elem_v1` were added (`swap_signed_int_elem_v2`, (...)), along with a generic swap macro;
- `const` qualifier was added to exercises `4` and `5` array argument, because the array isn't modified by these functions (see [const correctness](https://isocpp.org/wiki/faq/const-correctness));
- Exercises `4` to `6` array size argument type was changed from `int` to `size_t`, because negative array sizes make no sense;
- Exercise `4` was renamed from `soma` to `integer_sum_v1`, and returns a `signed long long int` instead of an `int` as to avoid integer overflow;
- Exercise `4` alternatives `integer_sum_v2` and `integer_sum_v3` were added;
- Exercise `5` was renamed from `maximum` to `integer_maximum`, and returns the maximum of the array, instead of a *0 = worked correctly, otherwise failed* value. Doesn't receive a pointer to store the maximum, and assumes the array is valid, i. e., it's size is positve.
- Exercises `6` and `7` return an allocated array instead of filling one, and as such only receive the desired array size as an argument, which is now a `size_t` instead of an `int`;
- Exercies `6` and `7` arrays are now of type `unsigned long long int` instead of `int` as to avoid integer overflow;
- Alternatives to exercises `6` and `7` were added, where the array is passed as an argument and filled, instead of allocated, as the worksheet originally requested;
- Exercises `6` and `7` function call examples were provided, for each exercise's version.

### - Worksheet 4
- Every occurence of the type `int` was replaced with `signed int` (except for the return value of `string`'s `strcmp`);
- Exercise `1` was renamed from `minusculas` to `str_tolower_v1`;
- Exercise `1` returns the resulting string, instead of the number of upper case letters in the string, which is now optionally stored in a pointer;
- Added alternatives `str_tolower_v2` and `count_lines_v2` to exercises `1` and `2` respectively, which do the exact same but with a slightly different syntax;
- Exercises `2` and `3` were renamed from `contalinhas` and `contaPal` to `count_lines_v1` and `count_words_v1` respectively;
- Exercises `2` and `3` return a `size_t` instead of an `int`, and a `const` qualifier was added to the `char*` argument of both exercises;
- Added an alternative algorithm `count_words_v2` to exercise `3`;
- Added `const` qualifiers to the arguments of type `char*` and `char**` of the exercises `4` to `6`;
- Exercises `4` to `6` return a pointer to the needle string if found, or `NULL` otherwise, instead of the needle's possible index in the haystack;
- Exercises `4` to `6` array size argument type was changed from `int` to `size_t`;
- Exercise `4` was renamed from `procura` to `search_str`;
- Exercise `5` was renamed from `procura` to `search_str_ord_v1`, and an alternative `search_str_ord_v2` was added;
- Exercise `6` was renamed from `procura` to `bin_search_str_recursive` and `bin_search_str_iterative`, depending on the version;
- Exercise `7` was renamed from `zeros` to `count_zeros`, and its array size argument and return type were changed from `int` to `size_t`;
- Exercises `8` and `9` return an allocated matrix and array respectively, instead of filling one, and as such do not receive any matrix or array to fill;
- Exercises `8` and `9` matrix and array size argument type was changed from `int` to `size_t`;
- Alternatives to exercises `8` and `9` were added, where the matrix and array are passed as arguments and filled respectively, instead of allocated, as the worksheet originally requested;
- Exercise `8` function call examples were provided, for each version.


## [PT]

### - Ficha 1
- Os exercícios `1.1` a `1.5` e `2.1 a)` a `2.1 e)` foram isolados em funções específicas;
- A função `f` (exercício `2.1 f)`) foi renomeada para `ex2_1_f`, e a sua respetiva função `main` foi renomeada para `ex2_1_f_main`, que recebe 0 argumentos `(void)` em vez de um número não especificado de argumentos `()`;
- As funções dos exercícios `1.1` a `2.1 f)` foram (excessivamente) comentadas para fornecer uma descrição mais detalhada;
- Os exercícios `2` e `3` usam a função `fputc` do `stdio` em vez de `putchar`;
- O exercício `4` foi resolvido numa diretoria específica, com uma Makefile respetiva;
- A função `triangulo` do exercício `4` foi renomeada para `triangle`, e recebe um argumento do tipo `size_t` em vez de um `int`.

### - Ficha 2
- Todas as ocurrências do tipo `int` foram substituídas por `signed int`;
- Os exercícios `1` e `2` foram renomeados de `multInt` para `integer_float_product_v1` e `integer_float_product_v2`, respetivamente;
- A variável de retorno no exercício `1` foi renomeada de `r` para `product` (hooray dar nomes *decentes* a variáveis!);
- Os exercícios `3`, `4` e `5` foram renomeados de `mdc` para `gcd_v1`, `gcd_v2`, (...), dependendo do número do exercício, e recebem e retornam um `unsigned int` em vez de um `int`, porque o maior divisor comum em números negativos é o mesmo que em positivos;
- Os exercícios `6 a)` e `6 b)` foram renomeados de `fib` para `fib_recursive_v1` e `fib_iterative`, respetivamente;
- Foi adicionada uma definição recursiva mais rápida alternativa `fib_recursive_v2`.

### - Ficha 3
- Todas as ocurrências do tipo `int` foram substituídas por `signed int`;
- O exercício `1 a)` foi isolado na função `ex1_a`;
- As funções dos exercícios `1 a)` e `1 b)` foram (excessivamente) comentadas para fornecer uma descrição mais detalhada;
- O exercício `1 b)` foi renomeado de `main` para `ex1_b`, e recebe 0 argumentos `(void)`, em vez de um número não especificado de argumentos `()`;
- O exercício `2` foi renomeado de `swapM` para `swap_signed_int`;
- O exercício `3` foi renomeado de `swap` para `swap_signed_int_elem_v1`;
- Foram adicionadas diversas alternatives (`swap_signed_int_elem_v2`, (...)) à função `swap_signed_int_elem_v1`, assim como uma macro genérica de swap;
- O qualificador `const` foi adicionado ao array passado como argumento aos exercícios `4` e `5`, porque o array não é modificado por estas funções (ver [const correctness](https://isocpp.org/wiki/faq/const-correctness));
- O tipo da variável que guarda o tamanho dos arrays nos exercícios `4` a `6` foi alterado de `int` para `size_t`, porque tamanhos de array negativos não fazem sentido;
- O exercício `4` foi renomeado de `soma` para `integer_sum_v1`, e retorna um `signed long long int` em vez de um `int` para prevenir *integer overflow*;
- Alternativas ao exercício `4` `integer_sum_v2` e `integer_sum_v3` foram adicionadas;
- O exercício `5` foi renomeado de `maximum` para `integer_maximum`, e retorna o máximo do array, em vez de um valor *0 = funcionou corretamente, caso contrário falhou*. Não recebe um apontador para guardar o máximo, e assume que o array é valido, isto é, que o seu tamanho é positivo.
- Os exercícios `6` e `7` retornam um array alocado em vez de preencherem um, e portanto apenas recebem o tamanho do array desejado como argumento, que agora é do tipo `size_t` em vez de `int`;
- Os arrays dos exercícios `6` e `7` são agora do tipo `unsigned long long int` em vez de `int` para prevenir *integer overflow*;
- Foram criadas alternativas aos exercícios `6` e `7`, onde o array é passado por argumento e preenchido, em vez de alocado, como o enunciado originalmente pedia;
- Foram fornecidos exemplos de chamadas das funções dos exercícios `6` e `7`, para cada versão dos exercícios.

### - Ficha 4
- Todas as ocurrências do tipo `int` foram substituídas por `signed int` (exceto no valor de retorno da função `strcmp` do `string`);
- O exercício `1` foi renomeado de `minusculas` para `str_tolower_v1`;
- O exercício `1` retorna a string resultante, em vez de o número de letras maiúsculas na string, que agora é opcionalmente guardado num apontador;
- Foram adicionadas as alternativas `str_tolower_v2` e `count_lines_v2` aos exercícios `1` e `2` respetivamente, que fazem exatamente o mesmo mas com uma sintaxe ligeiramente diferente;
- Os exercícios `2` e `3` foram renomeados de `contalinhas` e `contaPal` para `count_lines_v1` e `count_words_v1` respetivamente;
- Os exercícios `2` e `3` retornam um `size_t` em vez de um `int`, e o qualificador `const` foi adicionado ao argumento do tipo `char*` dos dois exercícios;
- Foi adicionado um algoritmo alternativo `count_words_v2` ao exercício `3`;
- Foram adicionados qualificadores `const` aos argumentos do tipo `char*` e `char**` dos exercícios `4` a `6`;
- Os exercícios `4` a `6` retornam um apontador para a string agulha se esta for encontrada, ou `NULL` caso contrário, em vez do possível índice da agulha no palheiro;
- O tipo da variável que guarda o tamanho dos arrays nos exercícios `4` a `6` foi alterado de `int` para `size_t`;
- O exercício `4` foi renomeado de `procura` para `search_str`;
- O exercício `5` foi renomeado de `procura` para `search_str_ord_v1`, e uma função alternativa `search_str_ord_v2` foi adicionada;
- O exercício `6` foi renomeado de `procura` para `bin_search_str_recursive` e `bin_search_str_iterative`, dependendo da versão;
- O exercício `7` foi renomeado de `zeros` para `count_zeros`, e o tipo da variável que guarda o tamanho do array que lhe é passado e o seu tipo de retorno foram alterados de `int` para `size_t`;
- Os exercícios `8` e `9` retornam uma matriz e um array alocados respetivamente, em vez de preencherem um, e portanto não recebem qualquer matriz ou array para preencher;
- O tipo da variável que guarda o tamanho da matriz e do array passados como argumentos aos exercícios `8` e `9` foi alterado de `int` para `size_t`;
- Foram criadas alternativas aos exercícios `8` e `9`, onde a matriz e o array passados como argumentos são preenchidos, em vez de alocados, como o enunciado originalmente pedia;
- Foram fornecidos exemplos de chamadas das funções do exercício `8`, para cada versão do exercício.
