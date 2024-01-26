#include <iostream>
using namespace std;

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

template <typename TYPE>
class BinarySearchTree;

//*************************************************
// Node Declaration of Definition
//*************************************************
template <typename TYPE>
class Node
{
    TYPE key;
    Node<TYPE> *left;
    Node<TYPE> *right;
    Node() : left(nullptr), right(nullptr){};
    Node(TYPE key) : key(key), left(nullptr), right(nullptr){};
    Node(TYPE key, Node *l, Node *r) : key(key), left(nullptr), right(nullptr){};
    Node<TYPE> *operator=(Node<TYPE> *node)
    {
        key = node->key;
        left = node->left;
        right = node->right;
    };
    friend class BinarySearchTree<TYPE>;
};

//*************************************************
// Binary Search Tree Declaration and Definition
//*************************************************
template <typename TYPE>
class BinarySearchTree
{
public:
    BinarySearchTree() : root(nullptr){};
    BinarySearchTree(TYPE key) { Insert(key); };
    ~BinarySearchTree() { DeleteTree(); };
    void DeleteTree()
    {
        DeleteTree(root);
        root = nullptr;
    }
    bool Insert(TYPE key) { return Insert(key, root); };
    bool Remove(TYPE key) { return Remove(key, root); };
    Node<TYPE> *Search(TYPE key) const { Search(key, root); };
    void PrintInOrder() const
    {
        if (root == nullptr)
            Empty();
        else
        {
            cout << "< ";
            PrintInOrder(root);
            cout << ">";
        }
    };
    void PrintPreOrder() const
    {
        if (root == nullptr)
            Empty();
        else
        {
            cout << "< ";
            PrintPreOrder(root);
            cout << ">";
        }
    };
    void PrintPostOrder() const
    {
        if (root == nullptr)
            Empty();
        else
        {
            cout << "< ";
            PrintPostOrder(root);
            cout << ">";
        }
    };

private:
    Node<TYPE> *root;
    //*************************************************
    // Helper Functions
    //*************************************************
    void DeleteTree(Node<TYPE> *&subroot) // Recursive delete function
    {
        if (subroot != nullptr)
        {
            // cout << subroot->key << " "; // debug
            DeleteTree(subroot->left);
            DeleteTree(subroot->right);
            delete subroot;
        }
    }
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
    bool Remove(TYPE key, Node<TYPE> *&subroot)
    {
        bool succeed = true;
        if (subroot == nullptr) // if key doesnt exist in bst or bst doesn't exist
            succeed = false;
        else
        {
            if (key < subroot->key) // continue searching to the left
                Remove(key, subroot->left);
            else if (key > subroot->key) // continue searching to the right
                Remove(key, subroot->right);
            else
            {
                if (subroot->left == nullptr) // if no left, shift right up to current subroot.
                    subroot = subroot->right;
                else if (subroot->right == nullptr) // if no right, shift left up to current subroot.
                    subroot = subroot->left;
                else // else if both subroots exist, find predecessor on the right, move up, and delete leaf
                {
                    Node<TYPE> *temp = findMin(subroot->right);
                    subroot->key = temp->key;
                    Remove(temp->key, subroot->right); // recursively delete leaf
                }
            }
        }
        return succeed;
    }
    Node<TYPE> *findMin(Node<TYPE> *subroot)
    {
        if (subroot->left == nullptr)
            return subroot;
        else
            findMin(subroot->left);
        return subroot;
    }
    Node<TYPE> *findMax(Node<TYPE> *subroot)
    {
        if (subroot->right == nullptr)
            return subroot;
        else
            findMin(subroot->right);
        return subroot;
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
    void Empty() const { cout << "Tree is empty." << endl; }
};

#endif