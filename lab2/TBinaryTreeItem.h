#ifndef TBINARYTREE_ITEM_H
#define TBINARYTREE_ITEM_H
#include "trapezoid.h"

class TBinaryTreeItem {
public:
TBinaryTreeItem(const Trapezoid& pentagon);
TBinaryTreeItem(const TBinaryTreeItem& other);
Trapezoid& GetTrapezoid();
void SetTrapezoid(Trapezoid& pentagon);
TBinaryTreeItem* GetLeft();
TBinaryTreeItem* GetRight();
void SetLeft(TBinaryTreeItem* item);
void SetRight(TBinaryTreeItem* item);
void SetTrapezoid(const Trapezoid& pentagon);
void IncreaseCounter();
void DecreaseCounter();
int ReturnCounter();
virtual ~TBinaryTreeItem();

private:
Trapezoid trapezoid;
TBinaryTreeItem *left;
TBinaryTreeItem *right;
int counter;
};
#endif