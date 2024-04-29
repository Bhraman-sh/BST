// g++ main.cpp bst.cpp -I./include

// C++ standard libraries

#include "bst.h"
#include <iostream>

int main() {
  BST<int> g1;
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
  g1.printiot();
  g1.printpot();

  g1.deleteTree(40);
  g1.printiot();
  g1.printpot();

  return 0;
}
