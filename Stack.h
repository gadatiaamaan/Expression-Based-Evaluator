#ifndef _STACK_H_
#define _STACK_H_

#include <exception>
#include "Array.h"

template <typename T>
class Stack {
public:
    typedef T type; // Type definition of the type.

    class empty_exception : public std::exception { // Exception thrown to indicate the stack is empty.
    public:
        const char* what() const throw() {
            return "Empty stack exception";
        }
    };

    Stack(void); // Default constructor.
    Stack(const Stack & s); // Copy constructor.
    ~Stack(void); // Destructor.

    const Stack & operator=(const Stack & rhs); // Assignment operator.

    void push(T element); // Push a new element onto the stack.
    T pop(void); // Remove the top-most element from the stack.
    T top(void) const; // Get the top-most element on the stack.

    bool is_empty(void) const; // Test if the stack is empty.
    size_t size(void) const; // Number of elements on the stack.
    void clear(void); // Remove all elements from the stack.

private:
    int index_; // Index variable.
    Array<T> data_; // Array to store elements.
};

#include "Stack.cpp"

#endif 
