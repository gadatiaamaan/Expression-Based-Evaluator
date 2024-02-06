// Default constructor
template <typename T>
Base_Array<T>::Base_Array() {
  this->data_ = new T[0];
  this->max_size_ = 0;
  this->cur_size_ = 0;
}

// Initializing constructor with length
template <typename T>
Base_Array<T>::Base_Array(size_t length) {
  this->data_ = new T[length];
  this->max_size_ = length;
  this->cur_size_ = length;
}

// Initializing constructor with length and fill value
template <typename T>
Base_Array<T>::Base_Array(size_t length, T fill) {
  this->data_ = new T[length];
  for (int i = 0; i < length; i++) {
    this->data_[i] = fill;
  }
  this->max_size_ = length;
  this->cur_size_ = length;
}

// Copy constructor
template <typename T>
Base_Array<T>::Base_Array(const Base_Array & arr) {
  this->swap(*arr);
}

// Assignment operator
template <typename T>
const Base_Array<T> & Base_Array<T>::operator=(const Base_Array<T> & rhs) {
  if (this != rhs) {
    swap(*rhs);
  }
  return *this;
}

// Destructor
template <typename T>
Base_Array<T>::~Base_Array() {
  delete[] data_;
}

// Subscript operator for non-const objects
template <typename T>
T & Base_Array<T>::operator[](size_t index) {
  if (index >= size()) {
    throw std::out_of_range("Index out of bounds.");
  }
  return data_[index];
}

// Subscript operator for const objects
template <typename T>
const T & Base_Array<T>::operator[](size_t index) const {
  if (index >= size()) {
    throw std::out_of_range("Index out of bounds.");
  }
  return data_[index];
}

// Set method to set value at a specific index
template <typename T>
void Base_Array<T>::set(size_t index, T value) {
  if (index >= size()) {
    throw std::out_of_range("Index out of bounds.");
  }
  data_[index] = value;
}

// Get method to retrieve value at a specific index
template <typename T>
T Base_Array<T>::get(size_t index) const {
  if (index >= size()) {
    throw std::out_of_range("Index out of bounds.");
  }
  return data_[index];
}

// Find method to find the index of an element
template <typename T>
int Base_Array<T>::find(T element) const {
  for (int i = 0; i < size(); i++) {
    if (element == data_[i]) {
      return i;
    }
  }
  return -1;
}

// Find function to search for an element starting from a specified index
template <typename T>
int Base_Array<T>::find(T element, size_t start) const {
  if (start >= size()) {
    throw std::out_of_range("Index out of bounds.");
  }
  // Iterate over the array starting from the specified index
  for (size_t i = start; i < size(); i++) {
    // If the element is found, return its index
    if (element == data_[i]) {
      return i;
    }
  }
  // If the element is not found, return -1
  return -1;
}

// Fill function to set all elements of the array to a specified value
template <typename T>
void Base_Array<T>::fill(T val) {
  // Iterate over the array and set each element to the specified value
  for (size_t i = 0; i < size(); i++) {
    data_[i] = val;
  }
}

// Swap function to swap the contents of the array with another array
template <typename T>
void Base_Array<T>::swap(Base_Array<T> * arr) {
  int n = arr->size();
  // Delete the existing data and allocate new memory for the array
  delete[] data_;
  data_ = new T[n];
  // Copy the contents of the other array into the current array
  for (int i = 0; i < n; i++) {
    data_[i] = arr[i];
  }
  // Update the current and maximum size of the array
  cur_size_ = n;
  max_size_ = n;
}

// Swap function to swap the contents of the array with another array using get method
template <typename T>
void Base_Array<T>::swap(const Base_Array<T> * arr) {
  int n = arr->size();
  // Delete the existing data and allocate new memory for the array
  delete[] data_;
  data_ = new T[n];
  // Copy the contents of the other array into the current array using get method
  for (int i = 0; i < n; i++) {
    data_[i] = arr->get(i);
  }
  // Update the current and maximum size of the array
  cur_size_ = n;
  max_size_ = n;
}

// Equality operator to check if two arrays are equal
template <typename T>
bool Base_Array<T>::operator==(const Base_Array<T> & rhs) const {
  // If the sizes of the arrays are different, they are not equal
  if (this->size() != rhs.size()) {
    return false;
  }
  // Iterate over the arrays and compare each element
  for (size_t i = 0; i < this->size(); i++) {
    // If any element is different, the arrays are not equal
    if (this->data_[i] != rhs[i]) {
      return false;
    }
  }
  // If all elements are equal, the arrays are equal
  return true;
}

// Inequality operator to check if two arrays are not equal
template <typename T>
bool Base_Array<T>::operator!=(const Base_Array<T> & rhs) const {
  // Use the equality operator and negate the result
  return !(*this == rhs);
}
