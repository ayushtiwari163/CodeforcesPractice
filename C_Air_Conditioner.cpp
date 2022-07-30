// C++ program to demonstrate insert operation
// in binary search tree
#include <bits/stdc++.h>
using namespace std;
 
// BST node
class Node {
    public:
        int value;
        Node *left, *right;
        Node(int value){
            this->value = value;
            left = NULL;
            right = NULL;
        }
};
 
// A utility function to insert a new
// Node with given value in BST
Node* insert(Node* root, int value)
{
    // Create a new Node containing
    // the new element
    Node* newnode = new Node(value);
 
    // Pointer to start iterating the array
    // from the root node
    Node* curr = root;
 
    // prev pointer will note the trailing of start pointer
    Node* prev = NULL;
 
    while (curr!= NULL) {
        prev = curr;
        if (value < curr->value)
            curr = curr->left;
        else
            curr = curr->right;
    }
 
    // If the prev is NULL it means that the tree is empty
    // The new node is the root node
    if (prev == NULL)
        prev = newnode;
 
    // if the new value is lesser than the leaf node
    // make the newNode as the left child of leaf node
    else if (value < prev->value)
        prev->left = newnode;
 
    // otherwise make the newNode as right child of leaf node
    else
        prev->right = newnode;
 
    // Returns the prev pointer
    // where we have inserted the newNode
    return prev;
}
 
void InorderTraversal(Node *root){
    // if the root node is NULL
    if(!root)
        return;
    // recursively call for left subtree
    InorderTraversal(root->left);
    // print the current root value
    cout << root->value << " ";
    // recursively call for the right subtree
    InorderTraversal(root->right);
    return;
}
 
// Driver code
int main()
{
    // Let us create the BST given in sample example 1
 
    Node* root = NULL;
    root = insert(root, 50);
    insert(root, 28);
    insert(root, 52);
    insert(root, 26);
    insert(root, 45);
    insert(root, 56);
 
    // Print inorder traversal of the BST
    cout << "Inorder Traversal of BST before inserting the Node ";
    InorderTraversal(root);
    cout << endl;
    // Node to be inserted is 51
    insert(root, 51);
 
    cout << "Inorder Traversal of BST after inserting the Node ";
    InorderTraversal(root);
 
    return 0;
}
