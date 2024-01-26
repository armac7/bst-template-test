#include <iostream>
#include "../headers/BinarySearchTree.h"
using namespace std;

void PrintMenu();
int GetInput();
void ExecuteOption(int input, BinarySearchTree<int> &tree);

int main()
{
    BinarySearchTree<int> tree;
    int input = 0;
    while (input != 6)
    {
        PrintMenu();
        input = GetInput();
        if (input != 6)
            ExecuteOption(input, tree);
    }

    // Test Calls
    // tree.Insert(7);
    // tree.PrintInOrder();
    // cout << endl;
    // tree.Insert(4);
    // tree.PrintInOrder();
    // cout << endl;
    // tree.Insert(10);
    // tree.PrintInOrder();
    // cout << endl;
    // tree.Insert(2);
    // tree.PrintInOrder();
    // cout << endl;
    // tree.Insert(3);
    // tree.PrintInOrder();
    // cout << endl;
    // tree.Insert(6);
    // tree.PrintInOrder();
    // cout << endl;
    // tree.Insert(12);
    // tree.PrintInOrder();
    // cout << endl;
    // tree.Insert(13);
    // tree.PrintInOrder();
    // cout << endl;
    // tree.Insert(20);
    // tree.PrintInOrder();
    // cout << endl;
    // tree.PrintPreOrder();
    // cout << endl;
    // tree.PrintPostOrder();
    // cout << endl;
    // tree.DeleteTree();
    // tree.PrintInOrder();
    return 0;
}

void PrintMenu()
{
    cout << "***************************************" << endl;
    cout << "1. Insert Into Tree" << endl;
    cout << "2. Print In Order" << endl;
    cout << "3. Print Preorder" << endl;
    cout << "4. Print Postorder" << endl;
    cout << "5. Delete Node" << endl;
    cout << "6. Delete Tree" << endl;
    cout << "7. Quit" << endl;
    cout << "***************************************" << endl;
}
int GetInput()
{
    int input = 0;
    while (input < 1 || input > 7)
    {
        cout << "Enter choice (1-7): ";
        cin >> input;
    }
    return input;
};
void ExecuteOption(int input, BinarySearchTree<int> &tree)
{
    if (input == 1)
    {
        int data = 0;
        cout << "Enter the number you want to put into the tree: ";
        cin >> data;
        tree.Insert(data);
    }
    else if (input == 2)
        tree.PrintInOrder();
    else if (input == 3)
        tree.PrintPreOrder();
    else if (input == 4)
        tree.PrintPostOrder();
    else if (input == 5)
    {
        int data = 0;
        cout << "Enter the number you want to remove: ";
        cin >> data;
        tree.Remove(data);
    }
    else if (input == 6)
        tree.DeleteTree();
    cout << endl;
    cout << endl;
}