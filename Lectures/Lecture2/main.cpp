/*********************************************
 * BINARY TREE
 *
 * search time is O(log n)
 * look up ABL trees and Red/Black Trees
 **********************************************/

#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node()
    {
        left = right = nullptr;
    }
    Node(int d)
    {
        data = d;
        left = right = nullptr;
    }
};

class BST
{
private:
    Node *root;

    ///////////////////////////////////////
    // Recursive print
    // Base case
    // Shrink the space
    ///////////////////////////////////////
    void Print(Node *root)
    {
        if (!root)
        {
            return;
        }

        // Preorder
        Print(root->left);
        // in order
        cout << root->data << " ";
        Print(root->right);
        // post order
    }

    ////////////////////////////////////////////
    //  Private Insert -- recursive
    //
    //
    //
    ////////////////////////////////////////////
    void Insert(Node*& root, int x)
    {
        if (!root)
        {
            root = new Node(x);
            return;
        }
        if (x < root->data)
        {
            Insert(root->left, x);
        }
        else
        {
            Insert(root->right, x);
        }
    }

    int Find(Node* root, int key){
        static int count = 0;
        
        count++;

        if(!root){
            return count;
        }
        if (root->data == key){
            return count;
        }else if (key < root->data){
            return Find(root->left, key);
        }else{
            return Find(root->right, key);
        }
    }

public:
    BST()
    {
        root = nullptr;
    }

    // Insert
    void Insert(int x)
    {
        Insert(root, x);
    }
    // Find
    int Find(int key)
    {
        return Find(root, key);
        
    }
    // Delete
    void Delete()
    {
    }
    // Print
    void Print()
    {
        Print(root);
    }
};

int main(void)
{
    BST tree;
    for (int i = 0; i < 15; i++){
        tree.Insert(rand() % 100);
    }
    tree.Print();
}