#include <iostream>
#include "TStack.h"
#include "HStackItem.h"
 
template <class T> TStack<T>::TStack() {
  size_of_list = 0;
  std::shared_ptr<HStackItem<T>> front;
  std::shared_ptr<HStackItem<T>> back;
  std::cout << "Trapezoid Stack created" << std::endl;
}
template <class T> TStack<T>::TStack(const std::shared_ptr<TStack> &other){
  front = other->front;
  back = other->back;
}
template <class T> size_t TStack<T>::Length() {
  return size_of_list;
}
template <class T> bool TStack<T>::Empty() {
  return size_of_list;
}
template <class T> std::shared_ptr<Trapezoid>& TStack<T>::GetItem(size_t idx){
  int k = 0;
  std::shared_ptr<HStackItem<T>> obj = front;
  while (k != idx){
    k++;
    obj = obj->next;
  }
  return obj->trapezoid;
}
template <class T> std::shared_ptr<Trapezoid>& TStack<T>::Last() {
  return back->trapezoid;
}
template <class T> void TStack<T>::InsertLast(const std::shared_ptr<Trapezoid> &&trapezoid) {
  std::shared_ptr<HStackItem<T>> obj (new HStackItem<T>(trapezoid));
  if(size_of_list == 0) {
    front = obj;
    back = obj;
    size_of_list++;
    return;
  }
  back->next = obj;
  back = obj;
  obj->next = nullptr;
  size_of_list++;
}
template <class T> void TStack<T>::RemoveLast() {
  if (size_of_list == 0) {
    std::cout << "Trapezoid does not pop_back, because the Trapezoid List is empty" << std:: endl;
  } else {
    std::shared_ptr<HStackItem<T>> prev_del = front;
    while (prev_del->next != back) {
      prev_del = prev_del->next;
    }
    prev_del->next = nullptr;
    back = prev_del;
    size_of_list--;
    } 
}
template <class T> void TStack<T>::Insert(const std::shared_ptr<Trapezoid> &&trapezoid, size_t position) {
  if (position <0) {
    std::cout << "Position < zero" << std::endl;
  } else if (position > size_of_list) {
    std::cout << " Position > size_of_list" << std::endl;
  } else {
    std::shared_ptr<HStackItem<T>> obj (new HStackItem<T>(trapezoid));
    if (position == 0) {
      front = obj;
      back = obj;
    } else {
      int k = 0;
      std::shared_ptr<HStackItem<T>> prev_insert = front;
      std::shared_ptr<HStackItem<T>> next_insert;
      while(k+1 != position) {
        k++;
        prev_insert = prev_insert->next;
      }
      next_insert = prev_insert->next;
      prev_insert->next = obj;
      obj->next = next_insert;
    }
    size_of_list++;
  }
}
template <class T> void TStack<T>::Remove(size_t position) {
  if (position > size_of_list ) {
    std:: cout << "Position " << position << " > " << "size " << size_of_list << " Not correct erase" << std::endl;
  } else if (position < 0) {
    std::cout << "Position < 0" << std::endl;
  } else {
      int k = 0;
      std::shared_ptr<HStackItem<T>> prev_erase = front;
      std::shared_ptr<HStackItem<T>> next_erase;
      std::shared_ptr<HStackItem<T>> del;
      while( k+1 != position) {
        k++;
        prev_erase = prev_erase->next;
      }
      next_erase = prev_erase->next;
      del = prev_erase->next;
      next_erase = del->next;
      prev_erase->next = next_erase;
    size_of_list--;
  }
}
template <class T> void TStack<T>::Clear() {
  std::shared_ptr<HStackItem<T>> del = front;
  std::shared_ptr<HStackItem<T>> prev_del;
  if(size_of_list !=0 ) {
    while(del->next != nullptr) {
      prev_del = del;
      del = del->next;
    }
    size_of_list = 0;
    //   std::cout << "HStackItem deleted" << std::endl;
  } 
  size_of_list = 0;
  std::shared_ptr<HStackItem<T>> front;
  std::shared_ptr<HStackItem<T>> back;
}
template <class T> std::ostream& operator<<(std::ostream& os, TStack<T>& hl) {
  if (hl.size_of_list == 0) {
    os << "The trapezoid stack is empty, so there is nothing to output" << std::endl;
  } else {
    os << "Print Trapezoid Stack" << std::endl;
    std::shared_ptr<HStackItem<T>> obj = hl.front;
    while(obj != nullptr) {
      if (obj->next != nullptr) {
        os << obj->trapezoid << " " << "," << " ";
        obj = obj->next;
      } else {
        os << obj->trapezoid;
        obj = obj->next;
      }
    }
    os << std::endl;
  }
  return os;
}
template <class T> TStack<T>::~TStack() {
  std::shared_ptr<HStackItem<T>> del = front;
  std::shared_ptr<HStackItem<T>> prev_del;
  if(size_of_list !=0 ) {
    while(del->next != nullptr) {
      prev_del = del;
      del = del->next;
    }
    size_of_list = 0;
    std::cout << "Trapezoid Stack deleted" << std::endl;
  } 
}