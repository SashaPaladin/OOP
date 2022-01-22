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

    //lab4
    TBinaryTree<Trapezoid> tree;
    std:: cout << "Is tree empty? " << tree.Empty() << std:: endl;
    std:: cout << "And now, is tree empty? " << tree.Empty() << std:: endl;
    tree.Push(a);
    tree.Push(b);
    tree.Push(c);
    std:: cout << "The number of figures with area in [minArea, maxArea] is: " << tree.Count(0, 100000) << std:: endl;
    std:: cout << "The result of searching the same-figure-counter is: " << tree.root->ReturnCounter() << std:: endl;
    std:: cout << "The result of function named GetItemNotLess is: " << tree.GetItemNotLess(0, tree.root) << std:: endl;
    std:: cout << tree << std:: endl;
    tree.root = tree.Pop(tree.root, a);
    std:: cout << tree << std:: endl;
    return 0;
}