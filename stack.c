#include "stack.h"

#include "messages.h"

#include <stdio.h>

int stack_size = 0;
double stack[STACK_CAPACITY];

/*push item to top of stack
 * update stack size
 * return true if push was possible
 * false if stack was at capacity
 * IF STACK AT CAPACITY: do NOT modify stack and size
 * */
bool stack_push(double item) {
    //if stack size is at stack capacity
    if (stack_size == STACK_CAPACITY) {
        fprintf(stderr, ERROR_NO_SPACE, item);
        return false;
    }
    //push item to top of stack
    stack[stack_size] = item;
    stack_size += 1;
    (void) item;
    return true;
}

/* without modifying stack, copy the first item of the stack
 * to the address pointed to by item
 * IF STACK IS EMPTY:
 * return false
 * do NOT modify *item
 *
 * otherwise return true
 *
 * pointer argument: stack value
 * return value: success state
 *
 * function user should pass a pointer to a variable
 * that should hold stack value for user to look at
 * so stack_peek can look at contents of that variable
 *
 * FOR EXAMPLE LOOK AT apply_unary_operator
 * */
bool stack_peek(double *item) {
    (void) item;
    if (stack_size == 0) {
        return false;
    }
    double value = stack[stack_size - 1];
    *item = value;
    return true;
}

/*store the first item of stack in location of pointer item
 * IF STACK IS EMPTY: 
 * return false, do not modify item
 * 
 * update stack size
 * return true
 * */
bool stack_pop(double *item) {
    (void) item;
    if (stack_size == 0) {
        return false;
    }
    double value = stack[stack_size - 1];
    *item = value;
    stack_size -= 1;
    return true;
}

/*set size of stack to zero
 * */
void stack_clear(void) {
    stack_size = 0;
}

/*prints every element in stack to stdout (separated by spaces)
 * NO NEWLINE AFTER
 * */
void stack_print(void) {
    //make sure we don't print stack[0] when it is empty
    if (stack_size == 0) {
        return;
    }
    //print first element with 10 decimal places
    printf("%.10f", stack[0]);
    //print remaining elements (if any), with a space before each one
    for (int i = 1; i < stack_size; i++) {
        printf(" %.10f", stack[i]);
    }
    printf("\n");
}
