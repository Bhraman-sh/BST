// g++ main.cpp bst.cpp -I./include

// C++ standard libraries

#include "bst.h"
#include <iostream>

int main() {
  BST<int> g1;
  g1.printer();
  g1.insert(10);
  g1.insert(45);
  g1.insert(5);

  g1.printiot();

  return 0;
}
