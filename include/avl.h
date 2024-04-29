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

    if (badBalance != NULL) {
      rotateAndBalance(n_data);

      badBalance = NULL;
    }
    // badBalance = NULL;
  }
  // PRIVATE FUNCTION
private:
  void rotateAndBalance(int n_data) {
    if (n_data < (*badBalance)->data) {
      if (n_data < (*badBalance)->left->data)
        LL_rotation();
      else
        LR_rotation();
    } else {
      if (n_data < (*badBalance)->right->data)
        RL_rotation();
      else
        RR_rotation();
    }
  }

  void LR_rotation() {
    Node<T> *&ptr = (*badBalance)->left;
    Node<T> *temp = ptr;
    ptr = ptr->right;
    Node<T> *temp1 = ptr->left;
    ptr->left = temp;
    temp->right = temp1;
    LL_rotation();
  }
  void LL_rotation() {
    Node<T> *temp = *badBalance;
    *badBalance = (*badBalance)->left;
    Node<T> *temp1 = (*badBalance)->right;
    (*badBalance)->right = temp;
    temp->left = temp1;
  }
  void RR_rotation() {
    Node<T> *temp = (*badBalance);
    (*badBalance) = (*badBalance)->right;
    Node<T> *temp1 = (*badBalance)->left;
    (*badBalance)->left = temp;
    temp->right = temp1;
  }
  void RL_rotation() {
    Node<T> *&ptr = (*badBalance)->right;
    Node<T> *temp = ptr;
    ptr = ptr->left;
    Node<T> *temp1 = ptr->right;
    ptr->right = temp;
    temp->left = temp1;
    RR_rotation();
  }
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
