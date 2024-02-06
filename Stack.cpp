// Constructor: Initializes a stack with initial capacity of 10
template <typename T>
Stack<T>::Stack(void) {
  data_.resize(10);
  index_ = -1;
}

// Copy Constructor: Creates a copy of an existing stack
template <typename T>
Stack<T>::Stack(const Stack &stack) {
  data_ = stack.data_;
  index_ = stack.index_;
}

// Destructor: Destroys the stack
template <typename T>
Stack<T>::~Stack(void) {
}

// Checks if the stack is empty
template <typename T>
inline bool Stack<T>::is_empty(void) const {
  return index_ == -1;
}

// Returns the size of the stack
template <typename T>
inline size_t Stack<T>::size(void) const {
  return index_ + 1;
}

// Returns the top element of the stack
template <typename T>
inline T Stack<T>::top(void) const {
  // Throws an exception if the stack is empty
  return (index_ == -1) ? throw(empty_exception()) : data_.get(index_);
}

// Pushes an element onto the stack
template <typename T>
void Stack<T>::push(T element) {
  index_++;
  int cur_size = data_.size();
  // If the stack is full, resize the underlying data structure
  if (index_ >= cur_size) {
    data_.resize(cur_size * 2);
  }
  data_.set(index_, element);
}

// Pops the top element from the stack and returns it
template <typename T>
T Stack<T>::pop(void) {
  // Throws an exception if the stack is empty
  if (is_empty()) {
    throw(empty_exception());
  }
  index_--;
  return data_[index_ + 1];
}

// Assignment Operator: Assigns the contents of one stack to another
template <typename T>
const Stack<T> & Stack<T>::operator=(const Stack &rhs) {
  // Avoid self-assignment
  if (&rhs != this) {
    // Copy data from rhs to the current stack
    data_ = rhs.data_;
    index_ = rhs.index_;
  }
  return *this;
}

// Clears the stack by resetting the index
template <typename T>
void Stack<T>::clear(void) {
  index_ = -1;
}
