/*
 * Stack.h
 *
 * Description: Defines a Stack class for implementing a stack data structure.
 *              The stack supports basic operations including push, pop, and top, along with
 *              methods to check if the stack is empty and to get the number of elements.
 * 
 * Author: Cayden Yoo
 * 
 * Last Modified: August 18, 2024
 */

#include "Stack.h"
#include <stdexcept>

// Constructor
Stack::Stack() : topNode(nullptr) {}

// Destructor
Stack::~Stack() {
    while (!isEmpty()) {
        pop();  // Free memory
    }
}

// Description: Push value onto top of stack.
// Time Efficiency: O(1) 
void Stack::push(double value) {
    Node * newNode = new Node();
    newNode->data = value;
    newNode->next = topNode;
    topNode = newNode;
}

// Description: Removes top element of stack.
// Precondition: This stack is not empty.
// Exception: Throws out_of_range exception if stack is empty.
// Time Efficiency: O(1)
void Stack::pop() {
    if (isEmpty()) {
        throw std::out_of_range("Stack underflow");
    }
    Node * temp = topNode;
    topNode = topNode->next;
    delete temp;  // Free memory
}

// Description: Returns top element of stack.
// Precondition: This stack is not empty.
// Postcondition: This stack is unchanged by this operation.
// Exception: Throws out_of_range exception if stack is empty.
// Time Efficiency: O(1)
double Stack::top() {
    if (isEmpty()) {
        throw std::out_of_range("Stack is empty");
    }
    return topNode->data;
}

// Description: Returns true if this Stack is empty, otherwise false.
// Postcondition: This Queue is unchanged by this operation.
// Time Efficiency: O(1)
bool Stack::isEmpty() {
    return topNode == nullptr;
}