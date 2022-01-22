#ifndef HLISTITEM_H
#define HLISTITEM_H
#include <iostream>
#include "trapezoid.h"
#include <memory>

template <class T> class HStackItem {
public:
  HStackItem(const std::shared_ptr<Trapezoid> &trapezoid);
  template <class A> friend std::ostream& operator<<(std::ostream& os, HStackItem<A> &obj);
  ~HStackItem();
  std::shared_ptr<T> trapezoid;
  std::shared_ptr<HStackItem<T>> next;
};
#endif
