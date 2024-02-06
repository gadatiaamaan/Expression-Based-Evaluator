// Array Class Implementation

// Default constructor
template <typename T>
Array<T>::Array(): Base_Array<T>() {}

// Constructor with specified length
template <typename T>
Array<T>::Array(size_t length): Base_Array<T>(length) {}

// Constructor with specified length and fill value
template <typename T>
Array<T>::Array(size_t length, T fill): Base_Array<T>(length, fill) {}

// Copy constructor
template <typename T>
Array<T>::Array(const Array &arr) {
  this->swap(static_cast<const Base_Array<T> *>(&arr));
}

// Assignment operator
template <typename T>
const Array<T> & Array<T>::operator=(const Array<T> &rhs) {
  if (*this != rhs) {
    this->swap(static_cast<const Base_Array<T> *>(&rhs));
  }
  return *this;
}

// Resize method
template <typename T>
void Array<T>::resize(size_t new_size) {
  if (new_size == this->cur_size_) {
    return;
  }

  T *cp;
  if (new_size > this->max_size_) {
    cp = new T[new_size];
    for (size_t i = 0; i < this->size(); i++) {
      cp[i] = this->data_[i];
    }
    delete[] this->data_;
    this->data_ = cp;
    this->max_size_ = new_size;
  }

  this->cur_size_ = new_size;
}
