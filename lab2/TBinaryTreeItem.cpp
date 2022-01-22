#include "TBinaryTreeItem.h"


TBinaryTreeItem::TBinaryTreeItem(const Trapezoid &trapezoid) {
    this->trapezoid = trapezoid;
    this->left = this->right = nullptr;
    this->counter = 1;
}

TBinaryTreeItem::TBinaryTreeItem(const TBinaryTreeItem &other) {
    this->trapezoid = other.trapezoid;
    this->left = other.left;
    this->right = other.right;
    this->counter = other.counter;
}

Trapezoid& TBinaryTreeItem::GetTrapezoid() {
    return this->trapezoid;
}

void TBinaryTreeItem::SetTrapezoid(const Trapezoid& trapezoid){
    this->trapezoid = trapezoid;
}
TBinaryTreeItem* TBinaryTreeItem::GetLeft(){
    return this->left;
}
TBinaryTreeItem* TBinaryTreeItem::GetRight(){
    return this->right;
}


void TBinaryTreeItem::SetLeft(TBinaryTreeItem* item) {
    if (this != nullptr){
        this->left = item;
    }
}

void TBinaryTreeItem::SetRight(TBinaryTreeItem* item) {
    if (this != nullptr){
        this->right = item;
    }
}

void TBinaryTreeItem::IncreaseCounter() {
    if (this != nullptr){
        counter++;
    }
}
void TBinaryTreeItem::DecreaseCounter() {
    if (this != nullptr){
        counter--;
    }
}

int TBinaryTreeItem::ReturnCounter() {
    return this->counter;
}

TBinaryTreeItem::~TBinaryTreeItem() {
}


