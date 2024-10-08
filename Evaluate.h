/*
 * Evaluate.h
 *
 * Description: Defines functions for performing operations. 
 *           
 * Class Invariant: FILO or LIFO order
 * 
 * Author: Cayden Yoo
 * 
 * Last Modified: October, 2024
 */

#ifndef EVALUATE_H
#define EVALUATE_H

#include <iostream>
#include <string>
#include <cctype>
#include <stdexcept>
#include "Stack.h"  

using std::string;
using std::exception;
using std::invalid_argument;
using std::cout;
using std::cin;
using std::cerr;
using std::endl;


int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

double applyOperation(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0) {
                throw invalid_argument("Division by zero.");
            }
            return a / b;
        default: throw invalid_argument("Invalid operator.");
    }
}

double evaluateExpression(const string & expr) {
    
    Stack values;  // Stack to store numbers (operands)
    Stack ops;     // Stack to store operators
    int i = 0;     // Index to traverse the expression

    // Loop through each character in the expression
    while (i < expr.length()) {
        if (isspace(expr[i])) {
            // Skip spaces
            i++;
            continue;
        }

        // Handle numbers (including negative numbers)
        if (isdigit(expr[i]) || (expr[i] == '-' && (i == 0 || expr[i - 1] == '('))) {
            double value = 0;
            bool isNegative = (expr[i] == '-');
            if (isNegative) i++; // Skip the minus sign if it's a negative number

            bool hasDecimalPoint = false;

            // Extract the full number, including decimals
            while (i < expr.length() && (isdigit(expr[i]) || expr[i] == '.')) {
                if (expr[i] == '.') {
                    if (hasDecimalPoint) {
                        // If a second decimal point is found, throw an error
                        throw std::invalid_argument("Invalid number format: multiple decimal points");
                    }
                    hasDecimalPoint = true;
                    i++;
                } else {
                    value = value * 10 + (expr[i] - '0');
                    if (hasDecimalPoint) {
                        static double decimalPlace = 1.0;
                        value += (expr[i] - '0') * decimalPlace;
                        decimalPlace *= 0.1;
                    }
                    i++;
                }
            }
            // Push the extracted number (positive or negative) onto the values stack
            values.push(isNegative ? -value : value);
        } 
        // Handle opening parenthesis
        else if (expr[i] == '(') {
            ops.push(expr[i]);  // Push '(' to ops stack
            i++;
        } 
        // Handle closing parenthesis
        else if (expr[i] == ')') {
            // Evaluate the expression inside the parentheses
            while (!ops.isEmpty() && ops.top() != '(') {
                double b = values.top(); 
                values.pop();
                double a = values.top(); 
                values.pop();
                char op = ops.top(); 
                ops.pop();
                values.push(applyOperation(a, b, op));  // Apply the operator and push the result
            }
            ops.pop();  // Pop the '(' from the ops stack
            i++;
        } 
        // Handle operators (+, -, *, /)
        else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/') {
            // Evaluate the top of the stack if the current operator has lower or equal precedence
            while (!ops.isEmpty() && precedence(ops.top()) >= precedence(expr[i])) {
                double b = values.top(); values.pop();
                double a = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOperation(a, b, op));  // Apply the operator and push the result
            }
            ops.push(expr[i]);  // Push the current operator to ops stack
            i++;
        }
        else {
            // If an unknown character is encountered, throw an error
            throw std::invalid_argument("Invalid character encountered in the expression");
        }
    }

    // Apply the remaining operators in the ops stack
    while (!ops.isEmpty()) {
        double b = values.top(); values.pop();
        double a = values.top(); values.pop();
        char op = ops.top(); ops.pop();
        values.push(applyOperation(a, b, op));  // Apply the operator and push the result
    }

    return values.top();  // The final result is at the top of the values stack
}

#endif 