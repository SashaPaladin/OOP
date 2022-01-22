#include <iostream>
#include "HStackItem.h"


template <class T> HStackItem<T>::HStackItem(const std::shared_ptr<Trapezoid> &trapezoid) {
  this->trapezoid = trapezoid;
  this->next = nullptr;
}
template <class A> std::ostream& operator<<(std::ostream& os,HStackItem<A> &obj) {
  os << "[" << obj.trapezoid << "]" << std::endl;
  return os;
}
template <class T> HStackItem<T>::~HStackItem() {
}
