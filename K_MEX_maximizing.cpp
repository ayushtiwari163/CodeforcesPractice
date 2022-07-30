// C++ implementation to print all pairs from two BSTs whose sum is greater than the given value
#include <bits/stdc++.h>
using namespace std;

// structure of each node of BST
struct node
{
    int key;
    struct node *left, *right;
};

// function to create a new BST node
node *TreeNode(int data)
{
    node *temp = new node();
    temp->key = data;
    temp->left = temp->right = NULL;
    return temp;
}

// function to insert node in bst
struct node *insert(struct node *node, int key)
{
    // if the tree is empty, then return a new node
    if (node == NULL)
        return TreeNode(key);

    // otherwise, recur down the tree
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    // return the (unchanged) node pointer
    return node;
}

// to get the size of the tree
int sizeOfTree(node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    // recursive call to store the left side size of the bst
    int left = sizeOfTree(root->left);

    // recusive call to store the right side size of the bst
    int right = sizeOfTree(root->right);

    // recursive call to store the total size
    return (left + right + 1);
}

// function to store the inorder of the bst
void storeInorder(node *root, int inOrder[], int &index)
{
    // Base condition
    if (root == NULL)
    {
        return;
    }

    // left recursive call
    storeInorder(root->left, inOrder, index);

    // to store the elements in the array
    inOrder[index++] = root->key;

    // right recursive call
    storeInorder(root->right, inOrder, index);
}

// function to print the pairs
void print(int inOrder[], int i, int index, int value)
{
    while (i < index)
    {
        cout << "{" << inOrder[i] << ", " << value << "}" << endl;
        i++;
    }
}

// to check a valid pair and to print it
void printPairs(int inOrderBst1[], int inOrderBst2[], int index, int j, int x)
{
    int i = 0;

    while (i < index && j >= 0)
    {

        if (inOrderBst1[i] + inOrderBst2[j] > x)
        {
            print(inOrderBst1, i, index, inOrderBst2[j]);
            j--;
        }
        else
        {
            i++;
        }
    }
}

// function to generate all the pairs and to print valid pairs
void checkPairs(node *root1, node *root2, int k)
{
    // storing the size of first bst
    int sizeOfBst = sizeOfTree(root1);

    // to store the inorder of first bst
    int inOrderBst1[sizeOfBst + 1];
    int index1 = 0;

    // storing the size of second bst
    sizeOfBst = sizeOfTree(root2);

    // to store the inorder of second bst
    int inOrderBst2[sizeOfBst + 1];
    int index2 = 0;

    // to store the inorder the first bst
    storeInorder(root1, inOrderBst1, index1);

    // to store the inorder the second bst
    storeInorder(root2, inOrderBst2, index2);

    // to print the pair
    printPairs(inOrderBst1, inOrderBst2, index1, index2 - 1, k);
}
int main()
{

    /* Formation of BST 1
             5
            / \
           3   7
          /\   /\
         2  4 6  8
    */

    struct node *root1 = NULL;
    root1 = insert(root1, 5);
    insert(root1, 3);
    insert(root1, 2);
    insert(root1, 4);
    insert(root1, 7);
    insert(root1, 6);
    insert(root1, 8);

    /* Formation of BST 2
             10
            /  \
           8   12
          /\   /\
         6  9 11 13
    */

    struct node *root2 = NULL;
    root2 = insert(root2, 10);
    insert(root2, 8);
    insert(root2, 6);
    insert(root2, 9);
    insert(root2, 12);
    insert(root2, 11);
    insert(root2, 13);

    int x = 18;

    // print pairs
    checkPairs(root1, root2, x);

    return 0;
}