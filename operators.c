#include "operators.h"

#include "messages.h"
#include "stack.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/* takes sum of doubles left hand side (lhs) and right hand side (rhs)
 * and returns the sum
 * */
double operator_add(double lhs, double rhs) {
    double sum = lhs + rhs;
    return sum;
}

/*takes the difference of the doubles
 * left hand side (lhs) and right hand side (rhs)
 * and returns it (lhs - rhs)
 * */
double operator_sub(double lhs, double rhs) {
    double diff = lhs - rhs;
    return diff;
}

/*multiplies doubles left hand side (lhs) and right hand side (rhs)
 * returns double multiple
 * */
double operator_mul(double lhs, double rhs) {
    double mul = lhs * rhs;
    return mul;
}
/*divides the double left hand side (lhs) by right hand side (rhs)
 * returns double division
 * */
double operator_div(double lhs, double rhs) {
    double div = lhs / rhs;
    return div;
}

/*function takes in an operator and accesses the global stack
 * it pops the first 2 elements on the stack
 * calls the op function with those as its arguments
 * 1st element = rhs, 2nd element = lhs
 * pushes result to stack
 * WILL NEVER make the stack too big
 * if 2 elements are not on stack, return false (error handling in calc.c)
 * stack (top to bottom): 1, 4, 2  and + operator
 * 4 + 1 = 5
 * stack (top to bottom): 5, 2
 * */
bool apply_binary_operator(binary_operator_fn op) {
    if (stack_size < 2) {
        fprintf(stderr, ERROR_BINARY_OPERATOR);
        return false;
    }
    double rhs;
    double lhs;
    assert(stack_pop(&rhs));
    //printf("%f\n",rhs);
    //stack_pop(&rhs);
    //printf("%f\n",rhs);
    assert(stack_pop(&lhs));
    double result = op(lhs, rhs);
    assert(stack_push(result));
    return true;
}

// return false if the stack is empty, otherwise pop an item, call op on it, and push the result
bool apply_unary_operator(unary_operator_fn op) {
    //make sure that stack is not empty
    if (stack_size < 1) {
        fprintf(stderr, ERROR_UNARY_OPERATOR);
        return false;
    }
    double x;
    //It should be impossible for stack_pop to fail here,
    //since we have checked above that the stack isn't empty.
    //The assert() function causes the program to exit
    //if the condition passed is false.
    //It is often useful for "sanity checks" like this:
    //if stack_pop fails, either our assumpt that it can't fail was false
    //or the implim. of stack_pop has a bug
    //either way it lets us know immediately
    assert(stack_pop(&x));
    //calculate the value we should push to the stack
    double result = op(x);
    //similar to above: stack_push should never fail here
    //because we just popped an element,
    //so we are not increasing the stack size past the size
    //it was originally.
    assert(stack_push(result));
    return true;
}

// this function should be given to students
bool parse_double(const char *s, double *d) {
    char *endptr;
    double result = strtod(s, &endptr);
    if (endptr != s) {
        *d = result;
        return true;
    } else {
        return false;
    }
}
