#include<iostream>
using namespace std;
#pragma once


template <typename T> class Node {
    public:
        Node<T> * left;
        Node<T> * right;
        T value;
        Node() {
            left = nullptr;
            right = nullptr;
            value = 2;
        };
        Node(T v): value(v) {};
    
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
            counter++;
            Node<T> * wezel;
            wezel = new Node<T>(val);
            if(root == nullptr) {
                root = wezel;
                return;
            }
            else {
                bool flag = 0;
                Node<T> * tmp;
                tmp = root;
                
                while (flag == 0) {
                    if (val >= tmp -> value) {
                        if (tmp -> left == nullptr) {
                            tmp -> left = wezel;
                            flag = 1;
                        }
                        else {
                            tmp = tmp -> left;
                        }
                    }
                    else {
                        if (tmp -> right == nullptr) {
                            tmp -> right = wezel;
                            flag = 1;
                        }
                        else {
                            tmp = tmp -> right;
                        }
                    }
                }
            }
            return;
        };
        
        void rmv(T val) {
            int x = counter;
            for(int i = 0; i < x; i++) {
                
                if (root == nullptr) {
                    return;
                }

                
                Node<T> * current = root;
                Node<T> * parent = nullptr;
                
                while (current != nullptr) {
                    if (val > current -> value) {
                        //left
                        parent = current;
                        current = current -> left;
                    }
                    else if (val < current -> value) {
                        // to right
                        parent = current;
                        current = current -> right;
                    }
                    else {

                        counter--;
                        if ((current -> left == nullptr) && (current -> right == nullptr)) {

                            if (current == root) {
                                root = nullptr;
                            }
                            else if (parent -> left == current) {
                                parent -> left = nullptr;
                            }
                            else {
                                parent -> right = nullptr;
                            }
                            delete current;
                        }
                        else if (current -> left == nullptr) {

                            if (current == root) {
                                root = current -> right;
                            }
                            else if (parent -> left == current) {
                                parent -> left = current -> right;
                            }
                            else {
                                parent -> right = current -> right;
                            }
                            delete current;
                        }
                        else if (current -> right == nullptr) {

                            if (current == root) {
                                root = current -> left;
                            }
                            else if (parent -> left == current) {
                                parent -> left = current -> left;
                            }
                            else {
                                parent -> right = current -> left;
                            }
                            delete current;
                        }
                        else {

                            Node<T> * tmp = current -> right;
                            Node<T> * tmp_parent = current;
                            while (tmp -> left != nullptr) {
                                tmp_parent = tmp;
                                tmp = tmp -> left;
                            }
                            current -> value = tmp -> value;
                            if (tmp_parent -> left == tmp) {
                                tmp_parent -> left = tmp -> right;
                            }
                            else {
                                tmp_parent -> right = tmp -> right;
                            }
                            delete tmp;
                        }
                        break;
                    }
                }
            }
        };
        
        int longestPath(int l, Node<T> ptr, int rekord) {
            if (ptr.left != nullptr) {
                rekord = longestPath(l+1,*(ptr.left), rekord);
            }
            if (ptr.right != nullptr) {
                rekord = longestPath(l+1,*(ptr.right), rekord);
            }
            if ((ptr.left == nullptr) && (ptr.right == nullptr)) {
                if(l > rekord) {
                    return l;
                }
                else {
                    return rekord;
                }
            }
            return rekord;
        };
        
        int shortestPath(int l, Node<T> ptr, int rekord) {
            if (ptr.left != nullptr) {
                rekord = shortestPath(l+1,*(ptr.left), rekord);
            }
            if (ptr.right != nullptr) {
                rekord = shortestPath(l+1,*(ptr.right), rekord);
            }
            if ((ptr.left == nullptr) && (ptr.right == nullptr)) {
                if(l < rekord) {
                    return l;
                }
                else {
                    return rekord;
                }
            }
            return rekord;
        };
        
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
        };
        
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