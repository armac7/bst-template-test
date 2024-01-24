#include <iostream>
using namespace std;

class BNode
{
    int data;
    BNode *left;
    BNode *right;
    BNode();
    BNode(int e);
    BNode(int e, BNode *l, BNode *r);
    friend class BST;
};

BNode::BNode() : left(nullptr), right(nullptr){};
BNode::BNode(int e) : data(e), left(nullptr), right(nullptr){};
BNode::BNode(int e, BNode *l, BNode *r) : data(e), left(l), right(r){};

class BST
{
    BNode *root;
    bool Insert(int e, BNode *&subroot);
    void PrintInOrder(BNode *subroot) const;
    void PrintPostOrder(BNode *subroot) const;
    void PrintPreOrder(BNode *subroot) const;
    BNode *Search(int e, BNode *subroot) const;

public:
    BST();
    bool Insert(int e);
    void PrintInOrder() const;
    void PrintPostOrder() const;
    void PrintPreOrder() const;
    BNode *Search(int e) const;
};

BST::BST() : root(nullptr){};
bool BST::Insert(int e)
{
    return Insert(e, root);
};
bool BST::Insert(int e, BNode *&subroot)
{
    bool success = true;
    if (subroot == nullptr)
        subroot = new BNode(e);
    else if (e == subroot->data)
    {
        success = false;
        cout << "NO DUPLICATES ALLOWED!" << endl;
    }
    else if (e < subroot->data)
        success = Insert(e, subroot->left);
    else if (e > subroot->data)
        success = Insert(e, subroot->right);
    return success;
};
void BST::PrintInOrder() const
{
    cout << "< ";
    PrintInOrder(root);
    cout << ">";
}
void BST::PrintInOrder(BNode *subroot) const
{
    if (subroot != nullptr)
    {
        PrintInOrder(subroot->left);
        cout << subroot->data << " ";
        PrintInOrder(subroot->right);
    }
};
void BST::PrintPostOrder() const
{
    cout << "< ";
    PrintPostOrder(root);

    cout << ">";
};
void BST::PrintPostOrder(BNode *subroot) const
{
    if (subroot != nullptr)
    {
        PrintPostOrder(subroot->left);
        PrintPostOrder(subroot->right);
        cout << subroot->data << " ";
    }
};
void BST::PrintPreOrder() const
{
    cout << "< ";
    PrintPreOrder(root);
    cout << ">";
};
void BST::PrintPreOrder(BNode *subroot) const
{
    if (subroot != nullptr)
    {
        cout << subroot->data << " ";
        PrintPreOrder(subroot->left);
        PrintPreOrder(subroot->right);
    }
};
BNode *BST::Search(int e) const
{
    return Search(e, root);
};
BNode *BST::Search(int e, BNode *subroot) const
{
    BNode *result = nullptr;
    if (subroot == nullptr) // if not found
        result = nullptr;
    else if (e == subroot->data) // if found
        result = subroot;
    else if (e < subroot->data)
        result = Search(e, subroot->left);
    else if (e > subroot->data)
        result = Search(e, subroot->right);
    return result;
};

int main()
{
    BST tree;
    tree.Insert(7);
    tree.PrintInOrder();
    cout << endl;
    tree.Insert(4);
    tree.PrintInOrder();
    cout << endl;
    tree.Insert(10);
    tree.PrintInOrder();
    cout << endl;
    tree.Insert(2);
    tree.PrintInOrder();
    cout << endl;
    tree.Insert(3);
    tree.PrintInOrder();
    cout << endl;
    tree.Insert(6);
    tree.PrintInOrder();
    cout << endl;
    tree.Insert(12);
    tree.PrintInOrder();
    cout << endl;
    tree.Insert(13);
    tree.PrintInOrder();
    cout << endl;
    tree.Insert(20);
    tree.PrintInOrder();
    cout << endl;
    tree.PrintPreOrder();
    cout << endl;
    return 0;
}