#include "mathlib.h"
#include "messages.h"
#include "operators.h"
#include "stack.h"

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv) {
    (void) argc;
    (void) argv;
    bool selected_m = false;
    int opt;

    (void) selected_m;
    while ((opt = getopt(argc, argv, "-mh")) != -1) {
        switch (opt) {
        case 'h': printf(USAGE, argv[0]); return 0;

        case 'm': selected_m = true; break;
        case '?': printf(USAGE, argv[0]); return 1;
        }
    }

    for (;;) {
        fprintf(stderr, "> ");
        char str[1024];
        if (fgets(str, 1024, stdin) == NULL)
            break;
        char *saveptr;
        str[strlen(str) - 1] = 0;
        bool no_error = true;
        const char *token = strtok_r(str, " ", &saveptr);
        bool calc_passed;
        (void) calc_passed;

        while (token != NULL && no_error) {
            double token_double;
            if (parse_double(token, &token_double)) {
                no_error = stack_push(token_double);
            } else {
                if (strcmp(token, "+") == 0) {
                    calc_passed = apply_binary_operator(operator_add);
                } else if (strcmp(token, "-") == 0) {
                    calc_passed = apply_binary_operator(operator_sub);
                } else if (strcmp(token, "*") == 0) {
                    calc_passed = apply_binary_operator(operator_mul);
                } else if (strcmp(token, "/") == 0) {
                    calc_passed = apply_binary_operator(operator_div);
                } else if (strcmp(token, "%") == 0) {
                    calc_passed = apply_binary_operator(fmod);
                } else if (strcmp(token, "s") == 0) {
                    if (selected_m) {
                        calc_passed = apply_unary_operator(sin);
                        //printf("using math library");
                    } else {
                        calc_passed = apply_unary_operator(Sin);
                    }
                } else if (strcmp(token, "c") == 0) {
                    if (selected_m) {
                        calc_passed = apply_unary_operator(cos);
                    } else {
                        calc_passed = apply_unary_operator(Cos);
                    }
                } else if (strcmp(token, "t") == 0) {
                    if (selected_m) {
                        calc_passed = apply_unary_operator(tan);
                    } else {
                        calc_passed = apply_unary_operator(Tan);
                    }
                } else if (strcmp(token, "a") == 0) {
                    if (selected_m) {
                        calc_passed = apply_unary_operator(fabs);
                    } else {
                        calc_passed = apply_unary_operator(Abs);
                    }
                } else if (strcmp(token, "r") == 0) {
                    if (strcmp(token, "r") == 0) {
                        calc_passed = apply_unary_operator(sqrt);
                    } else {
                        calc_passed = apply_unary_operator(Sqrt);
                    }
                } else {
                    if (strlen(token) == 1) {
                        char token_c = token[0];
                        fprintf(stderr, ERROR_BAD_CHAR, token_c);
                        calc_passed = false;
                    } else {
                        fprintf(stderr, ERROR_BAD_STRING, token);
                        calc_passed = false;
                    }
                }
            }
            token = strtok_r(NULL, " ", &saveptr);
        }
        if (calc_passed && no_error) {
            stack_print();
        }
        stack_clear();
    }
    return 0;
}
