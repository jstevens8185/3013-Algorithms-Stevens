/*******
 * This lecture is about different ways to traverse binary trees
 * 
 * 
*/


#include <iostream>
#include <queue>

using namespace std;

////////////////////////////////////
//  Struct:     Node
//  Purpose:    Hold data in binary
//              tree
//  Params:     Int d
////////////////////////////////////
struct Node{
    Node* right;
    Node* left;
    int data;
    Node(){
        right = left = nullptr;
        data = -1;
    }
    Node(int d){
        right = left = nullptr;
        data = d;
    }
};

/***************************************************************
 * Function:        inOrderTraversal
 * Purpose:         
 * Params:
*****************************************************************/


void inOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }

    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

/***************************************************************
 * Function:        preOrderTraversal
 * Purpose:         
 * Params:
*****************************************************************/

void preOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }

    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

/***************************************************************
 * Function:        postOrderTraversal
 * Purpose:         
 * Params:
*****************************************************************/

void postOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

/***************************************************************
 * Function:        breadthFirstTraversal
 * Purpose:         
 * Params:
*****************************************************************/

void breadthFirstTraversal(Node* root) {
    if (root == NULL) {
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        cout << current->data << " ";
        q.pop();

        if (current->left != NULL) {
            q.push(current->left);
        }
        if (current->right != NULL) {
            q.push(current->right);
        }
    }
}
