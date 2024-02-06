#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <cstring>          // for size_t definition
#include <stdexcept>
#include <iostream>
#include "Base_Array.h"

/**
 * @class Array
 * Basic implementation of a standard array class for elements of type T.
 */
template <typename T>
class Array: public Base_Array<T>
{
public:
    // Type definition of the element type
    typedef T type;

    // Default constructor
    Array(void);

    /**
     * Initializing constructor.
     *
     * @param[in]  length  Initial size
     */
    Array(size_t length);

    /**
     * Initializing constructor.
     *
     * @param[in]  length  Initial size
     * @param[in]  fill    Initial value for each element
     */
    Array(size_t length, T fill);

    /**
     * Copy constructor
     *
     * @param[in]  arr  The source array.
     */
    Array(const Array & arr);

    /**
     * Assignment operation
     *
     * @param[in]  rhs  Right-hand side of equal sign
     * @return     Reference to self
     */
    const Array & operator=(const Array<T> & rhs);

    /**
     * Set a new size for the array. If \a new_size is less than the current
     * size, then the array is truncated. If \a new_size if greater then the
     * current size, then the array is made larger and the new elements are
     * not initialized to anything. If \a new_size is the same as the current
     * size, then nothing happens.
     * 
     * The array's original contents are preserved regardless of whether the
     * array's size is either increased or decreased.
     *
     * @param[in]  new_size  New size of the array
     */
    void resize(size_t new_size);
};

#include "Array.cpp"

#endif   // !defined _ARRAY_H_
