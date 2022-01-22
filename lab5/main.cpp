#include <iostream>
#include "trapezoid.h"
#include "TBinaryTree.h"
#include "TBinaryTreeItem.h"
int main () {
    //lab1
    Trapezoid a (std::cin);
    std:: cout << "The area of your figure is : " << a.Area() << std:: endl;

    Trapezoid b (std::cin);
    std:: cout << "The area of your figure is : " << b.Area() << std:: endl;

    Trapezoid c (std::cin);
    std:: cout << "The area of your figure is : " << c.Area() << std:: endl;

    Trapezoid d (std::cin);
    std:: cout << "The area of your figure is : " << d.Area() << std:: endl;

    Trapezoid e (std::cin);
    std:: cout << "The area of your figure is : " << e.Area() << std:: endl;

    //lab2
    TBinaryTree<Trapezoid> tree;
    std:: cout << "Is tree empty? " << tree.Empty() << std:: endl;
    tree.Push(a);
    std:: cout << "And now, is tree empty? " << tree.Empty() << std:: endl;
    tree.Push(b);
    tree.Push(c);
    tree.Push(d);
    tree.Push(e);
    std:: cout << "The number of figures with area in [minArea, maxArea] is: " << tree.Count(0, 100000) << std:: endl;
    std:: cout << "The result of searching the same-figure-counter is: " << tree.root->ReturnCounter() << std:: endl;
    std:: cout << "The result of function named GetItemNotLess is: " << tree.GetItemNotLess(0, tree.root) << std:: endl;

    //lab5
    TIterator<TBinaryTreeItem<Trapezoid>, Trapezoid> iter(tree.root);
    std:: cout << "The figure that you have put in root is: " << *iter << std:: endl;
    iter.GoToLeft();
    std:: cout << "The first result of Left-Iter function is: " << *iter << std:: endl;
    iter.GoToRight();
    std:: cout << "The first result of Right-Iter function is: " << *iter << std:: endl;
    TIterator<TBinaryTreeItem<Trapezoid>, Trapezoid> first(tree.root->GetLeft());
    TIterator<TBinaryTreeItem<Trapezoid>, Trapezoid> second(tree.root->GetLeft());
    if (first == second) {
        std:: cout << "YES, YOUR ITERATORS ARE EQUALS" << std::endl;
    }
    TIterator<TBinaryTreeItem<Trapezoid>, Trapezoid> third(tree.root->GetRight());
    TIterator<TBinaryTreeItem<Trapezoid>, Trapezoid> fourth(tree.root->GetLeft());
    if (third != fourth) {
        std:: cout << "NO, YOUR ITERATORS ARE NOT EQUALS" << std::endl;
    }
    return 0;
}