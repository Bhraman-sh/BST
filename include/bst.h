#include <iostream>

template <typename T> class Node {
public:
  T data;
  Node<T> *left;
  Node<T> *right;
};

template <typename T> class BST {
public:
  BST() { head = NULL; }

  ~BST() { delete head; }

  void printer() {
    std::cout << "Random check" << std::endl;
    std::cout << "Code management " << std::endl;
  }

  void insert(T n_data) { insert(n_data, &head); }

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

  void printiot() {
    printiot(head);
    std::cout << std::endl;
  }

  void printiot(Node<T> *ptr) {
    if (ptr == NULL)
      return;

    printiot(ptr->left);

    std::cout << ptr->data << " ";

    printiot(ptr->right);
  }

  void printpot() {
    printpot(head);
    std::cout << std::endl;
  }

  void printpot(Node<T> *ptr) {
    if (ptr == NULL)
      return;

    std::cout << ptr->data << " ";

    printpot(ptr->left);

    printpot(ptr->right);
  }

  int findLargest() {
      return findLargest(head);
  }

  int findLargest(Node<T> *ptr) {
      if ( ptr->right == NULL)
          return ptr->data;

      return findLargest(ptr->right);
  }

int findSmallest() {
      return findSmallest(head);
  }

  int findSmallest(Node<T> *ptr) {
      if ( ptr->left == NULL)
          return ptr->data;

      return findSmallest(ptr->left);
  }
  void deleteTree(int d_data) {
    deleteTree(d_data, head);
  }
  
  void deleteTree(int d_data, Node<T> *&ptr) {
    while (ptr->data != d_data) {
    }
  }
private:
  Node<T> *head;
};
