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

int main(void) {
    double unary_op_arg = -1.7;
    double test_functions;
    double binary_op_arg1 = 1.7;
    double binary_op_arg2 = 3.5;

    //testing unary operations Abs, Sin, Cos, Tan
    test_functions = Abs(unary_op_arg);
    if (test_functions != fabs(unary_op_arg)) {
        printf("Abs() not working correctly.\n");
        return -1;
    }

    test_functions = Sin(unary_op_arg);
    //printf("Sin: %.10f\n",test_unary_op);
    //printf("sin: %.10f\n",Sin(unary_op_arg));
    if (test_functions <= sin(unary_op_arg) - 0.0000000005
        && test_functions >= sin(unary_op_arg) + 0.0000000005) {
        printf("Sin() not working correctly.\n");
        return -1;
    }

    test_functions = Cos(unary_op_arg);
    if (test_functions <= cos(unary_op_arg) - 0.0000000005
        && test_functions >= cos(unary_op_arg) + 0.0000000005) {
        printf("Cos() not working correctly.\n");
        return -1;
    }

    test_functions = Tan(unary_op_arg);
    if (test_functions <= tan(unary_op_arg) - 0.0000000005
        && test_functions >= tan(unary_op_arg) + 0.0000000005) {
        printf("Tan() not working correctly.\n");
        return -1;
    }

    //testing operators add, sub, mul, div
    test_functions = operator_add(binary_op_arg1, binary_op_arg2);
    if (test_functions != (binary_op_arg1 + binary_op_arg2)) {
        printf("operator_add() not working correctly.\n");
        return -1;
    }

    test_functions = operator_sub(binary_op_arg1, binary_op_arg2);
    if (test_functions != (binary_op_arg1 - binary_op_arg2)) {
        printf("operator_sub() not working correctly.\n");
        return -1;
    }
    test_functions = operator_mul(binary_op_arg1, binary_op_arg2);
    if (test_functions != (binary_op_arg1 * binary_op_arg2)) {
        printf("operator_mul() not working correctly.\n");
        return -1;
    }
    test_functions = operator_div(binary_op_arg1, binary_op_arg2);
    if (test_functions != (binary_op_arg1 / binary_op_arg2)) {
        printf("operator_div() not working correctly.\n");
        return -1;
    }

    //testing functions that utilize stack: stack_push, stack_peek, stack_pop, stack_clear, apply_binary_operator
    bool stack_func_work = true;
    stack_func_work = stack_push(binary_op_arg1);
    if (!stack_func_work) {
        printf("stack_push() not working correctly.\n");
        return -1;
    }
    stack_func_work = stack_push(binary_op_arg2);
    if (!stack_func_work) {
        printf("stack_push() not working correctly.\n");
        return -1;
    }
    stack_func_work = stack_push(1.4);
    if (!stack_func_work) {
        printf("stack_push() not working correctly.\n");
        return -1;
    }
    if (stack_size != 3) {
        printf("stack_push() not working correctly.\n");
        return -1;
    }

    stack_func_work = stack_pop(&test_functions);
    if (!stack_func_work) {
        printf("stack_pop() not working correctly.\n");
        return -1;
    }
    if (test_functions != 1.4) {
        printf("stack_pop() not working correctly.\n");
        return -1;
    }
    stack_func_work = stack_peek(&test_functions);
    if (!stack_func_work) {
        printf("stack_peek() not working correctly.\n");
        return -1;
    }
    if (test_functions != 3.5) {
        printf("stack_peek() not working correctly.\n");
        return -1;
    }

    stack_func_work = apply_binary_operator(operator_add);
    if (!stack_func_work) {
        printf("apply_binary_operator() not working correctly.\n");
        return -1;
    }
    if (stack_size != 1) {
        printf("apply_binary_operator() not working correctly.\n");
        return -1;
    }
    if (stack[0] != 5.2) {
        printf("apply_binary_operator() not working correctly.\n");
        return -1;
    }
    stack_print();
    stack_clear();
    if (stack_size != 0) {
        printf("stack_clear() not working correctly.\n");
        return -1;
    }

    printf("All functions working correctly!\n");
    return 0;
}
