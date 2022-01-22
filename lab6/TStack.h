#ifndef HLIST_H
#define HLIST_H
#include <iostream>
#include "HStackItem.h"
#include "trapezoid.h"
#include <memory>

template <class T> class TStack {
public:
  TStack();
  int size_of_list;
  size_t Length();
  std::shared_ptr<Trapezoid>& Last();
  std::shared_ptr<Trapezoid>& GetItem(size_t idx);
  bool Empty();
  TStack(const std::shared_ptr<TStack> &other);
  void InsertLast(const std::shared_ptr<Trapezoid> &&trapezoid);
  void RemoveLast();
  void Insert(const std::shared_ptr<Trapezoid> &&trapezoid, size_t position);
  void Remove(size_t position);
  void Clear();
  template <class A> friend std::ostream& operator<<(std::ostream& os, TStack<A>& list);
  ~TStack();
private:
  std::shared_ptr<HStackItem<T>> front;
  std::shared_ptr<HStackItem<T>> back;
};
#endif 

