#include <bits/stdc++.h>
 
using namespace std;
 
// structure of the binary search tree node
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
Node* leftMost(Node* root)
{
    if (!root)
        return NULL;
    while (root->left)
        root = root->left;
    return root;
}
// A Utility function to delete the nodes in the Binary search tree
Node* deleteNode(Node* root)
{
    // If nodes have only the single child or no child
    if (!root->left) {
        Node* child = root->right;
        root = NULL;
        return child;
    }
    else if (!root->right) {
        Node* child = root->left;
        root = NULL;
        return child;
    }
    Node* next = leftMost(root->right);
 
    // copying the content of inorder successor to this node
    root->value = next->value;
 
    // deleting the inorder successor
    root->right = deleteNode(root->right);
 
    return root;
}
 
// A utility function to remove BST nodes having a value in the given range 
Node* BSTremoveRange(Node* root, int min, int max)
{
 
    // Base case
    if (!root)
        return NULL;
 
    // traversing in the preorder fashion by fixing the left and right subtrees
    root->left = BSTremoveRange(root->left, min, max);
    root->right = BSTremoveRange(root->right, min, max);
 
    // if given root value is in Range then call deleteNode function
    if (root->value >= min && root->value <= max)
	// delete the nodes in the binary search tree
        return deleteNode(root);
 
    // if root value is not in range
    return root;
}
 
 
// A utility function to insert a new
// Node with given value in BST
Node* insert(Node* root, int value)
{
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
 
void Inorder(Node *root){
    // if the root node is NULL
    if(!root)
        return;
    Inorder(root->left);
    // printing the root value
    cout << root->value << " ";
    Inorder(root->right);
    return;
}
 
// Driver Program to test above functions
int main()
{
    Node *root = NULL;
    root = insert(root, 41);
    int nodesValues[] = {20,65,11,29,50,91,32,72,99};
    for(int i=0;i<9;i++){
        insert(root,nodesValues[i]);
    }
 
    cout << "Inorder Traversal before Deletion : ";
    Inorder(root);
 
    root = BSTremoveRange(root, 20, 40);
 
    cout << endl << "Inorder Traversal before Deletion: ";
    Inorder(root);
 
    cout << endl;
    return 0;
}
