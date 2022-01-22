cmake_minimum_required(VERSION 3.19)
project(lab6)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab6 main.cpp figure.h point.cpp point.h trapezoid.h trapezoid.cpp HStackItem.cpp HStackItem.h TBinaryTree.cpp TBinaryTree.h TBinaryTreeItem.cpp TBinaryTreeItem.h TAllocatorBlock.h TStack.cpp TStack.h)