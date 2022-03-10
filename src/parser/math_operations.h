/**
 * @file math_operations.h
 * @author Eduardo Luis
 *
 * @brief Definitions for callbacks that implement the operations of a math
 * expression, for example the addition and subtraction of two numbers.
 * 
 * @version 0.1
 * @date 2022-03-09
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef MATH_OPERATIONS_H
#define MATH_OPERATIONS_H

#include <math.h> /* for pow() declaration. */

double add (double a, double b);
double sub (double a, double b);
double mul (double a, double b);
double divide (double a, double b);
double negate (double a);

#endif /* MATH_OPERATIONS_H */
