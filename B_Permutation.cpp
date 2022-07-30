#include <bits/stdc++.h>
using namespace std;

struct Node
{
    char data;
    Node *left, *right;
};

Node *newNode(char Data)
{
    Node *new_node = new Node;
    new_node->data = Data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

// Function for converting Ternary Expression to a Binary Tree.
Node *convertExpression(string str, int &i)
{
    // to store current character of expression_string
    Node *root = newNode(str[i]);

    // Base Case
    if (i == str.length() - 1)
        return root;
    i++;
    if (str[i] == '?')
    {
        i++; // to skip the '?'
        // construct the left subtree
        root->left = convertExpression(str, i);
        i++; // skip the ':' character
        // construct the right subtree
        root->right = convertExpression(str, i);
        return root;
    }
    else
        return root;
}

// function print tree
void printTree(Node *root)
{
    if (!root)
        return;
    cout << root->data << " ";
    printTree(root->left);
    printTree(root->right);
}

// Driver program to test above function
int main()
{
    string expression = "a?b?c:d:e";
    int i = 0;
    Node *root = convertExpression(expression, i);
    printTree(root);
    return 0;
}