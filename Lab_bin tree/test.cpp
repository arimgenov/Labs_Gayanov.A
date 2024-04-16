#include <iostream>

enum TraverseType { INORDER, PREORDER, POSTORDER };

struct Node
{
    int key = 0;
    Node* parent = nullptr;
    Node* right = nullptr;
    Node* left = nullptr;
};

void insert_node(Node*& tree, int new_key) {
    Node* n = new Node;
    n->key = new_key;
    Node* cur = tree;
    if (tree == nullptr) tree = n;
    else {
        while (n->parent == nullptr) {
            if (cur->key < new_key) {
                if (cur->right == nullptr) {
                    cur->right = n;
                    n->parent = cur;
                } else cur = cur->right;
            } else {
                if (cur->left == nullptr) {
                    cur->left = n;
                    n->parent = cur;
                } else cur = cur->left;
            }
        }
    }
}

Node* min(Node*& tree) {
    if (tree == nullptr) return tree;
    Node* cur = tree;
    while(cur->left != nullptr) cur = cur->left;
    return cur;
}

Node* max(Node*& tree) {
    if (tree == nullptr) return tree;
    Node* cur = tree;
    while(cur->right != nullptr) cur = cur->right;
    return cur;
}

Node* find(Node*& tree, int key) {
    if (tree == nullptr) return tree;
    Node* cur = tree;
    while(true) {
        if (cur->key == key) return cur;
        if (cur->key < key) {if (cur->right == nullptr) return nullptr; else cur = cur->right;}
        else {if (cur->left == nullptr) return nullptr; else cur = cur->left;}
    }
}

Node* next(Node*& tree, int key) {
    Node* cur = find(tree, key);
    if (cur == nullptr) return nullptr;
    if (cur->right == nullptr) {
        Node* par = cur->parent;
        while (par->parent != nullptr) {
            if (par->left == cur) return par;
            else {cur = par; par = par->parent;}
        }
        if (par->left == cur) return par;
        else return nullptr;
    } else {
        cur = cur->right;
        while (cur->left != nullptr) cur = cur->left;
        return cur;
    }
}

void lol(Node*& tree, const TraverseType type) {
    if (tree != nullptr) {
        if (type == POSTORDER) {
            lol(tree->left, type);
            lol(tree->right, type);
            std::cout << tree->key << " ";
        } else if (type == INORDER) {
            lol(tree->left, type);
            std::cout << tree->key << " ";
            lol(tree->right, type);
        } else {
            std::cout << tree->key << " ";
            lol(tree->left, type);
            lol(tree->right, type);
        }
    }
}

void print(Node*& tree, const TraverseType type) {
    lol(tree, type);
    std::cout << std::endl;
}

void destroy_tree(Node*& tree) {
    if (tree != nullptr) {
        destroy_tree(tree->left);
        destroy_tree(tree->right);
        delete tree;
    }
}