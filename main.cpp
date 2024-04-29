// g++ main.cpp bst.cpp -I./include

// C++ standard libraries

#include "bst.h"
#include "avl.h"
#include <iostream>

int main() {
  BST<int> g1;
  AVL<int> a1;
  g1.printer();
  g1.insert(40);
  g1.insert(20);
  g1.insert(60);
  g1.insert(10);
  g1.insert(30);
  g1.insert(50);
  g1.insert(70);

  std::cout << g1.findLargest() << std::endl;
  std::cout << g1.findSmallest() << std::endl;
  std::cout << "Tree before deletion: " << std::endl;
  g1.printiot();
  g1.printpot();

  g1.deleteTree(40);
  std::cout << "Tree after deletion: " << std::endl;
  g1.printiot();
  g1.printpot();

  std::cout << "Height of the tree = " << g1.height() << std::endl;

  std::cout << "\nFor Avl Tree" << std::endl;
  a1.printer();

  a1.insert(44);
  a1.insert(55);
  a1.insert(33);

  std::cout << a1.findLargest() << " " << a1.findSmallest() << std::endl;
  a1.printiot();
  a1.printpot();

  return 0;
}
