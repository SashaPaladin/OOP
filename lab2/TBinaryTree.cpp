#include "TBinaryTree.h"

TBinaryTree::TBinaryTree () {
    root = nullptr;
}

TBinaryTreeItem* copy (TBinaryTreeItem* root) {
    if (!root) {
        return nullptr;
    }
    TBinaryTreeItem* root_copy = new TBinaryTreeItem (root->GetTrapezoid());
    root_copy->SetLeft(copy(root->GetLeft()));
    root_copy->SetRight(copy(root->GetRight()));
    return root_copy;
}

TBinaryTree::TBinaryTree (const TBinaryTree &other) {
    root = copy(other.root);
}

void Print (std::ostream& os, TBinaryTreeItem* node){
    if (!node){
        return;
    }
    if(node->GetLeft()){
        os << node->GetTrapezoid().GetArea() << ": [";
        Print (os, node->GetLeft());
        if (node->GetRight()){
            if (node->GetRight()){
                os << ", ";
                Print (os, node->GetRight());
            }
        }
        os << "]";
    } else if (node->GetRight()) {
        os << node->GetTrapezoid().GetArea() << ": [";
        Print (os, node->GetRight());
        if (node->GetLeft()){
            if (node->GetLeft()){
                os << ", ";
                Print (os, node->GetLeft());
            }
        }
        os << "]";
    }
    else {
        os << node->GetTrapezoid().GetArea();
    }
}

std::ostream& operator<< (std::ostream& os, TBinaryTree& tree){
    Print(os, tree.root);
    os << "\n";
    return os;
}

void TBinaryTree::Push (Trapezoid &trapezoid) {
    if (root == nullptr) {
    root = new TBinaryTreeItem(trapezoid);
    }
    else if (root->GetTrapezoid() == trapezoid) {
        root->IncreaseCounter();
    }
    else {
        TBinaryTreeItem* parent = root;
        TBinaryTreeItem* current;
        bool childInLeft = true;
        if (trapezoid.GetArea() < parent->GetTrapezoid().GetArea()) {
            current = root->GetLeft();
        }
        else if (trapezoid.GetArea() > parent->GetTrapezoid().GetArea()) {
            current = root->GetRight();
            childInLeft = false;
        }
        while (current != NULL) {
            if (current->GetTrapezoid() == trapezoid) {
                current->IncreaseCounter();
            }
            else {
                if (trapezoid.GetArea() < current->GetTrapezoid().GetArea()) {
                parent = current;
                current = parent->GetLeft();
                childInLeft = true;
                }
                else if (trapezoid.GetArea() > current->GetTrapezoid().GetArea()) {
                parent = current;
                current = parent->GetRight();
                childInLeft = false;
            }
        }
    }
        current = new TBinaryTreeItem(trapezoid);
        if (childInLeft == true) {
            parent->SetLeft(current);
        }
        else {
            parent->SetRight(current);
        }
    }
}

TBinaryTreeItem* FMRST(TBinaryTreeItem* root) {
    if (root->GetLeft() == nullptr) {
        return root;
    }
    return FMRST(root->GetLeft());
}

TBinaryTreeItem* TBinaryTree:: Pop(TBinaryTreeItem* root, Trapezoid &trapezoid) {
    if (root == NULL) {
        return root;
    }
    else if (trapezoid.GetArea() < root->GetTrapezoid().GetArea()) {
        root->SetLeft(Pop(root->GetLeft(), trapezoid));
    }
    else if (trapezoid.GetArea() > root->GetTrapezoid().GetArea()) {
        root->SetRight(Pop(root->GetRight(), trapezoid));
    }
    else {
        //first case of deleting - we are deleting a list
        if (root->GetLeft() == nullptr && root->GetRight() == nullptr) {
            delete root;
            root = nullptr;
            return root;
        }
        //second case of deleting - we are deleting a verex with only one child
        else if (root->GetLeft() == nullptr && root->GetRight() != nullptr) {
            TBinaryTreeItem* pointer = root;
            root = root->GetRight();
            delete pointer;
            return root;
        }
        else if (root->GetRight() == nullptr && root->GetLeft() != nullptr) {
            TBinaryTreeItem* pointer = root;
            root = root->GetLeft();
            delete pointer;
            return root;
        }
        //third case of deleting 
        else {
            TBinaryTreeItem* pointer = FMRST(root->GetRight());
            root->GetTrapezoid().area = pointer->GetTrapezoid().GetArea();
            root->SetRight(Pop(root->GetRight(), pointer->GetTrapezoid()));
        }
    }
    return root;
}

void RecursiveCount(double minArea, double maxArea, TBinaryTreeItem* current, int& ans) {
    if (current != nullptr) {
        RecursiveCount(minArea, maxArea, current->GetLeft(), ans);
        RecursiveCount(minArea, maxArea, current->GetRight(), ans);
        if (minArea <= current->GetTrapezoid().GetArea() && current->GetTrapezoid().GetArea() < maxArea) {
            ans += current->ReturnCounter();
        }
    }
}

int TBinaryTree::Count(double minArea, double maxArea) {
    int ans = 0;
    RecursiveCount(minArea, maxArea, root, ans);
    return ans;
}

Trapezoid& TBinaryTree::GetItemNotLess(double area, TBinaryTreeItem* root) {
    if (root->GetTrapezoid().GetArea() >= area) {
        return root->GetTrapezoid();
    }
    else {
        return GetItemNotLess(area, root->GetRight());
    }
}

void RecursiveClear(TBinaryTreeItem* current){
    if (current!= nullptr){
        RecursiveClear(current->GetLeft());
        RecursiveClear(current->GetRight());
            delete current;
            current = nullptr;
    }
}

void TBinaryTree::Clear(){
    RecursiveClear(root);
}

bool TBinaryTree::Empty() {
     if (root == nullptr) {
         return true;
     }
     return false;
}

TBinaryTree::~TBinaryTree() {
    Clear();
    std:: cout << "Your tree has been deleted" << std:: endl;
}