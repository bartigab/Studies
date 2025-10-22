#include <iostream>
#pragma once
using namespace std;

template <typename T> class Node {
public:
T value;
Node<T>* left;
Node<T>* right;
int balanceFactor;

Node(T val)
    :value(val), left(nullptr), right(nullptr), balanceFactor(0) {}
};


template <typename T> class Tree {
public:
    Node<T> * root;
    int counter;
    Tree() {
        root = nullptr;
        counter = 0;
    };
    
    
    
    
    void add(T val) {
    root = add(root, val);
}

Node<T>* add(Node<T>* node, T val) {
    if (node == nullptr)
        return new Node<T>(val);

    if (val < node->value)
        node->left = add(node->left, val);
    else if (val > node->value)
        node->right = add(node->right, val);

    node->balanceFactor = getHeight(node->right) - getHeight(node->left);
    return balance(node);
}



  void rmv(T val) {
    root = remove(root, val);
}

Node<T>* remove(Node<T>* node, T val) {
    if (node == nullptr)
        return nullptr;

    if (val < node->value) {
        node->left = remove(node->left, val);
    } else if (val > node->value) {
        node->right = remove(node->right, val);
    } else {
        if (node->left == nullptr && node->right == nullptr) {
            delete node;

            return nullptr;
        } else if (node->left == nullptr) {
            Node<T>* temp = node->right;
            delete node;

            return temp;
        } else if (node->right == nullptr) {
            Node<T>* temp = node->left;
            delete node;

            return temp;
        } else {
            Node<T>* minRight = findMin(node->right);

            node->value = minRight->value;
            node->right = remove(node->right, minRight->value);
        }
    }

    node->balanceFactor = getHeight(node->right) - getHeight(node->left);
    return balance(node);
}

   Node<T>* findMin(Node<T>* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    int getHeight(Node<T>* node) {
        if (node == nullptr) {
            return -1;
        }

        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);

        return max(leftHeight, rightHeight) + 1;
    }

    bool searchElement(T val) {
        return search(root, val);
    }

    bool search(Node<T>* node, T val) {
        if (node == nullptr)
            return false;

        if (val == node->value) return true;
        else if (val < node->value)
            return search(node->left, val);
        else
            return search(node->right, val);
    }

    
        Node<T>* balance(Node<T>* node) {
        if (node->balanceFactor < -1) {
            if (node->left->balanceFactor > 0)
                node->left = rotateLeft(node->left);

            return rotateRight(node);
        } else if (node->balanceFactor > 1) {
            if (node->right->balanceFactor < 0)
                node->right = rotateRight(node->right);

            return rotateLeft(node);
        }

        return node;
    }
    
        Node<T>* rotateLeft(Node<T>* node) {
            Node<T>* newRoot = node->right;
    
            node->right = newRoot->left;
            newRoot->left = node;
    
            node->balanceFactor = getHeight(node->right) - getHeight(node->left);
            newRoot->balanceFactor = getHeight(newRoot->right) - getHeight(newRoot->left);
    
            return newRoot;
        }
    
        Node<T>* rotateRight(Node<T>* node) {
            Node<T>* newRoot = node->left;
    
            node->left = newRoot->right;
            newRoot->right = node;
    
            node->balanceFactor = getHeight(node->right) - getHeight(node->left);
            newRoot->balanceFactor = getHeight(newRoot->right) - getHeight(newRoot->left);
    
            return newRoot;
        }
    


void display(int M) {
    if(M == 0) {
        show_pre(*root);
    }
    else if (M == 1) {
        show_in(*root);
    }
    else if (M == 2) {
        show_post(*root);
    }
}

void show_pre(Node<T> ptr) {
    cout << ptr.value << ' ';
    if(ptr.left != nullptr) {
        show_pre(*(ptr.left));
    }
    if(ptr.right != nullptr) {
        show_pre(*(ptr.right));
    }
    return;
};

void show_post(Node<T> ptr) {
    if(ptr.left != nullptr) {
        show_post(*(ptr.left));
    }
    if(ptr.right != nullptr) {
        show_post(*(ptr.right));
    }
    cout << ptr.value << ' ';
    return;
};

void show_in(Node<T> ptr) {
    if(ptr.left != nullptr) {
        show_in(*(ptr.left));
    }
    cout << ptr.value << ' ';
    if(ptr.right != nullptr) {
        show_in(*(ptr.right));
    }
    return;
};
};