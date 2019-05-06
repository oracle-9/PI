# Changes made from the original exercises

## [EN]

### - Worksheet 1
- Exercises `1.1` to `1.5` and `2.1 a)` to `2.1 e)` were isolated in specific functions;
- Function `f` (exercise `2.1 f)`) was renamed to `ex2_1_f`, and its respective `main` function was renamed to `ex2_1_f_main`;
- Functions from exercises `1.1` to `2.1 f)` were (excessively) commented on to provide a detailed description;
- Exercises `2` and `3` use `stdio`'s `fputc` instead of `putchar`;
- Exercise `4` was solved in a specific directory, with a respective Makefile;
- Exercise `4` `triangulo` function was renamed to `triangle`, and receives an argument of type `size_t` instead of an `int`.

### - Worksheet 2
- Every occurence of the type `int` was replaced with `signed int`;
- Exercises `3`, `4` and `5` were renamed from `mdc` to `gcd_v1`, `gcd_v2`, (...), depending on the exercise number, and receive and return an `unsigned int` instead of an `int`, because the greatest common divsor in negative numbers is the same as in positive ones;
- Exercises `6 a)` and `6 b)` were renamed from `fib` to `fib_recursive_v1` and `fib_iterative`, respectively;
- An alternative, faster recursive fibonacci definition `fib_recursive_v2` was added.


## [PT]

### - Ficha 1
- A função `f` (exercício `2.1 f)`) foi renomeada para `ex2_1_f`, e a sua respetiva função `main` foi renomeada para `ex2_1_f_main`;
- As funções dos exercícios `1.1` a `2.1 f)` foram (excessivamente) comentadas para fornecer uma descrição mais detalhada;
- Os exercícios `2` e `3` usam a função `fputc` do `stdio` em vez de `putchar`;
- O exercício `4` foi resolvido numa diretoria específica, com uma Makefile respetiva;
- A função `triangulo` do exercício `4` foi renomeada para `triangle`, e recebe um argumento do tipo `size_t` em vez de um `int`.

### - Ficha 2
- Todas as ocurrências do tipo `int` foram substituídas por `signed int`;
- Os exercícios `1` e `2` foram renomeados de `multInt` para `integer_float_product_v1` e `integer_float_product_v2`, respetivamente;
- A variável de retorno no exercício `1` foi renomeada de `r` para `product` (hooray dar nomes decentes a variáveis!);
- Os exercícios `3`, `4` e `5` foram renomeados de `mdc` para `gcd_v1`, `gcd_v2`, (...), dependendo do número do exercício, e recebem e retornam um `unsigned int` em vez de um `int`, porque o maior divisor comum em números negativos é o mesmo que em positivos;
- Os exercícios `6 a)` e `6 b)` foram renomeados de `fib` para `fib_recursive_v1` e `fib_iterative`, respetivamente;
- Foi adicionada uma definição recursiva e mais rápida alternativa `fib_recursive_v2`.
