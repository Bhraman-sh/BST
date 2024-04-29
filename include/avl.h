#ifndef AVL_H
#define AVL_H

#include "bst.h"

template <typename T> class AVL : public BST<T> {
public:
  AVL() {
    // head = NULL;
    badBalance = NULL;
  }
  //~AVL() { BST<T>::destroyTree(head); }

  void insert(int n_data) {
    BST<T>::insert(n_data);

    balanceFactorCalculator();

    imbalancedNodeFinder(BST<T>::head);

    // badBalance = NULL;
  }
  // PRIVATE FUNCTION
private:
  void imbalancedNodeFinder(Node<T> *&ptr) {
    if (ptr == NULL)
      return;
    if (ptr->balanceFactor == 2 || ptr->balanceFactor == -2)
      badBalance = &ptr;

    imbalancedNodeFinder(ptr->left);
    imbalancedNodeFinder(ptr->right);
  }
  void balanceFactorCalculator() { BST<T>::height(BST<T>::head); }

private:
  // Node<T> *head;
  Node<T> **badBalance;
};

#endif // AVL_H
