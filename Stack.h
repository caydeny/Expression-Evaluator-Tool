/*
 * Stack.h
 *
 * Description: Defines a Stack class for implementing a stack data structure.
 *              The stack supports basic operations including push, pop, and top, along with
 *              methods to check if the stack is empty and to get the number of elements.
 *
 * Class Invariant: FILO or LIFO order
 * 
 * Author: Cayden Yoo
 * 
 * Last Modified: August 18, 2024
 */

#ifndef STACK_H
#define STACK_H

class Stack {
private:

    struct Node {
        double data;     // Value of the node
        Node* next;      // Pointer to the next node
    };

    Node* topNode;       // Pointer to the top node of the stack

public:

    // Description: Default constructor
    Stack();             

    // Description: Destructor
    ~Stack();

    // Description: Push value onto top of stack.
    // Time Efficiency: O(1)            
    void push(double value);  

    // Description: Removes top element of stack.
    // Exception: Throws out_of_range exception if stack is empty.
    // Time Efficiency: O(1)
    void pop();         

    // Description: Returns true if this Queue is empty, otherwise false.
    // Postcondition: This Queue is unchanged by this operation.
    // Exception: Throws out_of_range exception if stack is empty.
    // Time Efficiency: O(1)
    double top();        

    // Description: Returns true if this Stack is empty, otherwise false.
    // Postcondition: This Queue is unchanged by this operation.
    // Time Efficiency: O(1)
    bool isEmpty();

};

#endif