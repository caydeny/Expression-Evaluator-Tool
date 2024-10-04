/*
 * Calculator.cpp
 *
 * Description: The application of data structures and time efficiencies 
 *              as studied in CMPT 225 by implementing a basic calculator program. The program
 *              uses stacks to evaluate mathematical expressions based on the BEDMAS rule.
 * 
 * Author: Cayden Yoo
 * 
 * Last Modified: October 3, 2024
 */

#include "Stack.h"  
#include "Evaluate.h"


int main() {

    char option;
    string expression;
    bool loop = true;

    // Interface
    while (loop) {
        cout << "1. Evaluate expression\n2. Learn\n3. Practice\n4. Exit" << endl;
        cin >> option;

        // Evaluate expression
        if (option == '1') {

            // Clear input stream
            cout << endl << "Enter an expression: ";
            cin >> expression;

            try {
                double result = evaluateExpression(expression);
                cout << "Result: " << result << endl << endl;
            } catch (const exception & e) {
                cerr << "Error: " << e.what() << endl;
            }
        }
        // Learn how to BEDMAS
        else if (option == '2') {

            char y_n;


            cout << endl << "Is there a specific expression you would like to learn how to solve? (Y/N): ";
            cin >> y_n;

            if (y_n == 'Y') {


                cout << endl << "Enter an expression: ";
                cin >> expression;

                // Check for brackets
                
                // Check for exponents

                // Check for division

                // Check for multiplication

                // Check for addition

                // Check for subtraction

            }
            else if (y_n == 'N') {



            }
            else {

            }







        }
        // Practice BEDMAS
        else if (option == '3') {








        }
        // Exit program
        else if (option == '4') {
            loop = false;
        }
        // Invalid input
        else {
            cout << "\nInvalid option." << endl;
        }
    }

    return 0;
}

