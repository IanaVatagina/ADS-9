// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <iostream>

template<typename T>
class BST {
 private:
    struct Node {
        T value;
        int count;
        Node* left;
        Node* right;
    };
    Node* root;
    Node* addNode(Node*, T);
    int searchTree(Node*, T);
    void printTree(Node*);
    int depthTree(Node*);
    void delTree(Node*);

 public:
    BST();
    ~BST();
    void add(T);
    int search(T);
    void remove(T);
    void print();
    int depth();
};

template<typename T>
BST<T>::BST() {
    root = nullptr;
}

template<typename T>
BST<T>::~BST() {
    if (root)
      delTree(root);
}

template<typename T>
BST<T>::Node* BST<T>::addNode(Node* root, T value) {
  if (root == nullptr) {
    root = new Node;
    root->value = value;
    root->count = 1;
    root->left = root->right = nullptr;
  } else if (root->value > value)
    root->left = addNode(root->left, value);
  else if (root->value < value)
    root->right = addNode(root->right, value);
  else
    root->count++;
  return root;
}

template<typename T>
void BST<T>::add(T value) {
  root = addNode(root, value);
}

template<typename T>
int BST<T>::searchTree(node* root, T value) {
  if (root == nullptr)
    return 0;
  else if (root->value > value)
    return searchTree(root->left, value);
  else if (root->value < value)
    return searchTree(root->right, value);
  else
    return root->count;
}

template<typename T>
int BST<T>::search(T value) {
  return searchTree(root, value);
}

template<typename T>
int BST<T>::depthTree(Node* root) {
  if (root == nullptr)
    return 0;
  int hL = depthTree(root->left);
  int hR = depthTree(root->right);
  if (hR < hL)
    return hL+1;
  else
    return hR+1;
}

template<typename T>
void BST<T>::printTree(Node* root) {
  if (root == nullptr)
    return;
  printTree(root->left);
  for (int i = 0; i < root->count; i++)
    std::cout<<root->value;
  printTree(root->right);
}

template<typename T>
void BST<T>::delTree(Node* root) {
  if (root == nullptr)
    return;
  delTree(root->left);
  delTree(root->right);
  delete root;
  root = nullptr;
}

template<typename T>
void BST<T>::add(T value) {
  root = addNode(root, value);
}

template<typename T>
int BST<T>::search(T value) {
  return searchTree(root, value);
}

template<typename T>
int BST<T>::depth() {
  int d = depthTree(root) - 1;
  return d;
}

template<typename T>
void BST<T>::print() {
  printTree(root);
}

#endif  // INCLUDE_BST_H_
