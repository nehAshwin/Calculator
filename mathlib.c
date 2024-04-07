#include "mathlib.h"

#include <math.h>
#include <stdio.h>

double Abs(double x) {
    if (x < 0) {
        return x * (-1);
    } else {
        return x;
    }
}

double Sqrt(double x) {
    //check domain
    if (x < 0) {
        return nan("nan");
    }
    double old = 0.0;
    double new = 1.0;

    while (Abs(old - new) > EPSILON) {
        //Specifically this is the Babylonian method -- a simplification of Newton's method possibly only for Sqrt(x)
        old = new;
        new = 0.5 * (old + (x / old));
    }
    return new;
}

double Sin(double x) {
    double sum = 0.0;
    int k = 1;
    double numer = 1.0;
    double denom = 1.0;
    double x_value = x;
    double term = 0.0;
    while (1) {
        if (k != 1) {
            denom *= (k - 1) * k;
            x_value *= x * x;
            numer *= -1;
        }
        term = (numer / denom) * x_value;
        if (Abs(term) < EPSILON)
            break;
        sum += term;
        k += 2;
    }
    return sum;
}
double Cos(double x) {
    double sum = 1.0;
    int k = 2;
    double numer = 1.0;
    double denom = 1.0;
    double x_value = 1.0;
    double term = 1.0;
    while (1) {
        denom *= (k - 1) * k;
        x_value *= x * x;
        numer *= -1;
        term = (numer / denom) * x_value;
        if (Abs(term) < EPSILON)
            break;
        sum += term;
        k += 2;
    }
    return sum;
}
double Tan(double x) {
    double sin = Sin(x);
    double cos = Cos(x);
    double tan = sin / cos;
    return tan;
}
