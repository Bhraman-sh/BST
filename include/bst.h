#ifndef BST_H
#define BST_H

#include <iostream>

template <typename T> class Node {
public:
  T data;
  Node<T> *left;
  Node<T> *right;
  int balanceFactor;
};

template <typename T> class BST {
public:
  // CONSTRUCTOR AND DESTRUCTOR
  BST() { head = NULL; }

  ~BST() { destroyTree(head); }

  // TEST FUNCTION
  void printer() {
    std::cout << "Random check" << std::endl;
    std::cout << "Code management " << std::endl;
  }

  // INSERT DATA

  void insert(T n_data) { insert(n_data, &head); }

  // Printing functions
  // Inorder traversal
  void printiot() {
    printiot(head);
    std::cout << std::endl;
  }

  // Printing functions
  // Preorder traversal
  void printpot() {
    printpot(head);
    std::cout << std::endl;
  }

  // SMALLEST AND LARGEST

  int findLargest() { return findLargest(head); }

  int findSmallest() { return findSmallest(head); }

  // Height of the tree
  int height() { return height(head); }

  // DELETION

  void deleteTree(int d_data) { deleteTree(d_data, head); }

protected:
  // DELETE EVERY NODE OF THE TREE
  void destroyTree(Node<T> *ptr) {
    if (ptr) {
      destroyTree(ptr->left);
      destroyTree(ptr->right);
      delete (ptr);
    }
  }

  // Height function
  int height(Node<T> *ptr) {
    if (ptr == NULL)
      return 0;

    int leftHeight = (height(ptr->left)) + 1;
    int rightHeight = (height(ptr->right)) + 1;

    ptr->balanceFactor = leftHeight - rightHeight;

    if (leftHeight > rightHeight)
      return leftHeight;
    else
      return rightHeight;
  }

  // Private methodes

private:
  // Insert function
  void insert(T n_data, Node<T> **ptr) {
    if (*ptr == NULL) {
      (*ptr) = new Node<T>;
      (*ptr)->data = n_data;
      (*ptr)->right = NULL;
      (*ptr)->left = NULL;
      // std::cout << n_data << " was inserted " << std::endl;
      return;
    }
    if (n_data > (*ptr)->data)
      insert(n_data, &(*ptr)->right);
    else if (n_data < (*ptr)->data)
      insert(n_data, &(*ptr)->left);
    else {
      std::cout << n_data << " is a duplicate " << std::endl;
    }
  }

  // Printing contents
  void printpot(Node<T> *ptr) {
    if (ptr == NULL)
      return;

    std::cout << ptr->data << " ";

    printpot(ptr->left);

    printpot(ptr->right);
  }
  void printiot(Node<T> *ptr) {
    if (ptr == NULL)
      return;

    printiot(ptr->left);

    std::cout << ptr->data << " ";

    printiot(ptr->right);
  }

  // Smallest and largest
  int findLargest(Node<T> *ptr) {
    if (ptr->right == NULL)
      return ptr->data;

    return findLargest(ptr->right);
  }
  int findSmallest(Node<T> *ptr) {
   if (ptr->left == NULL)
      return ptr->data;

    return findSmallest(ptr->left);
  }

  // Delete function
  void deleteTree(int d_data, Node<T> *&ptr) {
    if (d_data != ptr->data) {
      if (d_data < ptr->data)
        deleteTree(d_data, (ptr->left));
      else
        deleteTree(d_data, (ptr->right));
    } else {
      if (ptr->right == NULL && ptr->left == NULL) {
        Node<T> *temp = ptr;
        ptr = NULL;
        free(temp);
      } else if (ptr->right == NULL) {
        Node<T> *temp = ptr;
        ptr = ptr->left;
        free(temp);
      } else if (ptr->left == NULL) {
        Node<T> *temp = ptr;
        ptr = ptr->right;
        free(temp);
      } else {
        int p = findSmallest(ptr->right);
        ptr->data = p;
        deleteTree(p, ptr->right);
      }
    }
  }

  // Private data members
protected:
  Node<T> *head;
};

#endif // BST_H
