// Get the current size of the array
template <typename T>
inline size_t Base_Array<T>::size() const
{
    return cur_size_;
}

// Get the maximum size the array can hold
template <typename T>
inline size_t Base_Array<T>::max_size() const
{
    return max_size_;
}
