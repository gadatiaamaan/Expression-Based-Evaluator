#ifndef _BASE_ARRAY_H_
#define _BASE_ARRAY_H_

#include <cstring>
#include <stdexcept>
#include <iostream>

template <typename T>
class Base_Array
{
public:
    typedef T type;

    // Default constructor
    Base_Array (void);

    // Initializing constructor
    Base_Array (size_t length);

    // Initializing constructor
    Base_Array (size_t length, T fill);

    // Copy constructor
    Base_Array (const Base_Array & arr);

    // Assignment operation
    const Base_Array & operator = (const Base_Array<T> & rhs);

    // Destructor
    ~Base_Array (void);

    // Retrieve the current size of the array
    size_t size (void) const;

    // Retrieve the maximum size of the array
    size_t max_size (void) const;

    // Get the element at the specified index
    T & operator [] (size_t index);

    // Get the element at the specified index (const version)
    const T & operator [] (size_t index) const;

    // Get the element at the specified index
    T get (size_t index) const;

    // Set the element at the specified index
    void set (size_t index, T value);

    // Locate the specified element in the array
    int find (T element) const;

    // Locate the specified element in the array starting from a given index
    int find (T element, size_t start) const;

    // Fill the contents of the array with the specified element
    void fill (T element);

    // Test the array for equality
    bool operator == (const Base_Array & rhs) const;

    // Test the array for inequality
    bool operator != (const Base_Array & rhs) const;

protected:
    T * data_; // Pointer to the actual data
    size_t cur_size_; // Current size of the array
    size_t max_size_; // Maximum size of the array

    // Set the current array to an exact copy of the given array
    void swap(Base_Array<T> * arr);

    void swap(const Base_Array<T> * arr);
};

#include "Base_Array.cpp"
#include "Base_Array.inl"

#endif
