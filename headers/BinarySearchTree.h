#include <iostream>
using namespace std;

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

template <typename TYPE>
class BinarySearchTree;

template <typename TYPE>
class Node
{
    TYPE key;
    Node<TYPE> *left;
    Node<TYPE> *right;
    Node() : left(nullptr), right(nullptr){};
    Node(TYPE key) : key(key), left(nullptr), right(nullptr){};
    Node(TYPE key, Node *l, Node *r) : key(key), left(nullptr), right(nullptr){};
    friend class BinarySearchTree<TYPE>;
};

template <typename TYPE>
class BinarySearchTree
{
public:
    BinarySearchTree() : root(nullptr){};
    BinarySearchTree(TYPE key) { Insert(key); };
    // ~BinarySearchTree();
    bool Insert(TYPE key) { return Insert(key, root); };
    Node<TYPE> *Search(TYPE key) const { Search(key, root); };
    void PrintInOrder() const
    {
        cout << "< ";
        PrintInOrder(root);
        cout << ">";
    };
    void PrintPreOrder() const
    {
        cout << "< ";
        PrintPreOrder(root);
        cout << ">";
    };
    void PrintPostOrder() const
    {
        cout << "< ";
        PrintPostOrder(root);
        cout << ">";
    };

private:
    Node<TYPE> *root;
    bool Insert(TYPE key, Node<TYPE> *&subroot)
    {
        bool success = true;
        if (subroot == nullptr)
            subroot = new Node(key);
        else if (key < subroot->key)
            Insert(key, subroot->left);
        else if (key > subroot->key)
            Insert(key, subroot->right);
        else if (key == subroot->key)
        {
            success = false;
            cout << "NO DUPLICATES ALLOWED!" << endl;
        }
        return success;
    }
    Node<TYPE> *Search(TYPE key, Node<TYPE> *subroot) const
    {
        Node<TYPE> *found = nullptr;
        if (subroot == nullptr)
            found = nullptr;
        else if (key == subroot->data)
            found = subroot;
        else if (key < subroot->data)
            Search(key, subroot->left);
        else if (key > subroot->data)
            Search(key, subroot->right);
        return found;
    };
    void PrintInOrder(Node<TYPE> *subroot) const
    {
        if (subroot != nullptr)
        {
            PrintInOrder(subroot->left);
            cout << subroot->key << " ";
            PrintInOrder(subroot->right);
        }
    };
    void PrintPreOrder(Node<TYPE> *subroot) const
    {
        if (subroot != nullptr)
        {
            cout << subroot->key << " ";
            PrintPreOrder(subroot->left);
            PrintPreOrder(subroot->right);
        }
    };
    void PrintPostOrder(Node<TYPE> *subroot) const
    {
        if (subroot != nullptr)
        {
            PrintPostOrder(subroot->left);
            PrintPostOrder(subroot->right);
            cout << subroot->key << " ";
        }
    };
};

#endif