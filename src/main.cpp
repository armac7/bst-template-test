#include <iostream>
#include "../headers/BinarySearchTree.h"
using namespace std;

int main()
{
    BinarySearchTree<int> tree;
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
    tree.PrintPostOrder();
    cout << endl;
    return 0;
}