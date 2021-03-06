#ifndef BINTREE_H
#define BINTREE_H

#include <iostream>
#include <fstream>
#include <string>
#include "eidpliste.h"

using namespace std;

template<typename T>
class BinTree {
private:
    struct Node {
        T data;
        Node *left, *right; // linker und rechter Unterbaum
    };
    
    Node* root; // Wurzel
    
    bool isElement(Node* node, T data) {
        if (node == nullptr)
            return false;
        if (node->data == data)
            return true;
        if (node->data < data)
            return isElement(node->right, data);
        return isElement(node->left, data);
    }
    
    void clear(Node* node) {
        if (node != nullptr) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }
    
    Node* insert(Node *node, T data) {
        if (node == nullptr) {
            node = new Node;
            node->data = data;
            node->left = node->right = nullptr;
            return node;
        }
        if (node->data < data)
            node->right = insert(node->right, data);
        else if (node->data > data)
            node->left = insert(node->left, data);
        return node;
    }
    
    // Aufgabe 1a)
    void preOrder(Node* node) {
    	if(node == nullptr) return;
    	cout << node->data << ' ';
    	preOrder(node->left);
    	preOrder(node->right);
        // hier Code einfuegen
    }
    
    // Aufgabe 1a)
    void inOrder(Node* node) {
    	if(node == nullptr) return;
    	inOrder(node->left);
    	cout << node->data << ' ';
    	inOrder(node->right);
        // hier Code einfuegen
    }
    
    // Aufgabe 1a)
    void postOrder(Node* node) {
    	if(node == nullptr) return;
    	postOrder(node->left);
    	postOrder(node->right);
    	cout << node->data << ' ';
        // hier Code einfuegen
    }
    
    // Aufgabe 1b)
    int height(Node* node) {
    	if(node == nullptr)
    	        return 0;
    	return 1 + max(height(node->left), height(node->right));

    	// hier Code einfuegen
    }
    // Aufgabe 1c)
    int count(Node* node){
    	if(node == nullptr)
    		return 0;
    	else return 1+(count(node->left)+count(node->right));
        // hier Code einfuegen
    }
    
    // Aufgabe 1d)
    void range(Node* node, T min, T max){
    	if(node == nullptr) return;
    	if(node->data > min)
    		range(node->left, min, max);
    	else range(node->right, min, max);
    	if(node->data <= max && node->data >= min)
    		cout << node->data << ' ';
//    	if(node->data < max)
//    		range(node->right, min, max);
//    	else range(node->left, min, max);

        // hier Code einfuegen
    }
    
public:
    BinTree() : root(nullptr) {
    }
    
    ~BinTree() {
        clear(root);
    }
    
    void clear() {
        clear(root);
        root = nullptr;
    }
    
    void insert(T x) {
        root = insert(root, x);
    }
    
    bool isElement(T x) {
        return isElement(root, x);
    }
    
    T rootData(){
        return root->data;
    }
    
    void preOrder() {
        preOrder(root);
        cout << endl;
    }
    
    void inOrder() {
        inOrder(root);
        cout << endl;
    }
    
    void postOrder() {
        postOrder(root);
        cout << endl;
    }
    
    int height() {
        return height(root);
    }
    
    int count() {
        return count(root);
    }
    
    void range(T min, T max){
        range(root, min, max);
    }
    
    // Aufgabe 1e)
    void newRootLeft(){
        // hier Code einfuegen
    }
};



#endif /* BINTREE_H */
