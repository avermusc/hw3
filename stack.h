#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack : private std::vector<T>
{
public:
  Stack() : std::vector<T>() {}
  ~Stack() {}
  bool empty() const{
      return std::vector<T>::empty();
  }
  size_t size() const{
      return std::vector<T>::size();
  }
  void push(const T& item){
      std::vector<T>::push_back(item);
  }
  void pop(){
      if (std::vector<T>::empty()){
          throw std::underflow_error{"No elements to pop, stack is empty."};
      }
      else{
          std::vector<T>::pop_back();
      }
  }  // throws std::underflow_error if empty
  const T& top() const{
      if (std::vector<T>::empty()){
          throw std::underflow_error{"No elements to pop, stack is empty."};
      }
      else{
          return std::vector<T>::back();
      }
  } 
};


#endif