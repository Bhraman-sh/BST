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

  void insert(T n_data) {  
    insert(n_data, &head);
  }

  void insert(T n_data, Node<T> **ptr) {
    if (*ptr == NULL) {
      (*ptr) = new Node<T>;
      (*ptr)->data = n_data;
      (*ptr)->right = NULL;
      (*ptr)->left = NULL;
      std::cout << n_data << " was inserted " << std::endl;
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

  void printiot() { printiot(head); }

  void printiot(Node<T> *ptr) {
    if (ptr == NULL)
      return;

    printiot(ptr->left);

    std::cout << ptr->data << " ";

    printiot(ptr->right);
  }

private:
  Node<T> *head;
};
