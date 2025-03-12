#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> heap;
  int m_;
  PComparator pcomp;
  void trickleDown(size_t idx);
  void trickleUp(int loc);
};

// Add implementation of member functions here


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Empty heap, no item on top.");
  }
  else{
    return heap.front();
  }
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()//referenced from CH9 Heap slides
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Empty heap, no items to pop.");
  }
  if (heap.size() == 1){
    heap.pop_back(); //no need to trickle down because we just emptied the heap
  }
  else{
    heap[0] = heap.back();
    heap.pop_back();
    trickleDown(0);
  }
}

template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c) : heap(), m_(m), pcomp(c){}

template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap(){}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item){ //referenced from CH9 Heap slides
  heap.push_back(item);
  trickleUp(heap.size() - 1);
}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const{
  return (heap.size() == 0);
}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const{
  return heap.size();
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::trickleDown(size_t idx){ //referenced from CH9 Heap slides
  if (m_ * idx + 1 >= heap.size()){ //if idx is a leaf node
    return;
  }
  size_t smallerChild = m_ * idx + 1; //start w/ left
  for (size_t i = smallerChild + 1; i <= std::min(heap.size() - 1, m_ * idx + m_); i++){ //parse through all valid children
    if(pcomp(heap[i], heap[smallerChild])){ //if smaller child has a bigger value
      smallerChild = i;
    }
  }
  if (pcomp(heap[smallerChild], heap[idx])) {
    std::swap(heap[idx], heap[smallerChild]);
    trickleDown(smallerChild);
  }
}


template <typename T, typename PComparator>
void Heap<T,PComparator>::trickleUp(int loc){ //referenced from CH9 Heap slides
  int parent = (loc - 1) / m_;
  while (parent >= 0 && pcomp(heap[loc], heap[parent])){
    std::swap(heap[loc], heap[parent]);
    loc = parent;
    parent = (loc - 1) / m_;
  }
}






#endif

