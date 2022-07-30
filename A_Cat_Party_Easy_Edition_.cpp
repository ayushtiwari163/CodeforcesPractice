#include <bits/stdc++.h>
using namespace std;
 
// TreeNode Class
class TreeNode 
{
public:
   int data, size;
   TreeNode* left;
   TreeNode* right;
};
 
// Add node to the binary tree
TreeNode* push(int data)
{
   TreeNode* Node = new TreeNode();
   Node->data = data;
   Node->left = NULL;
   Node->right = NULL;
 
   // Return newly created node
   return (Node);
}
 
// Function to count the total number of nodes in the left and right subtrees
pair<int, int> sum(TreeNode* root)
{
   // Initialize a pair that stores the pair of number of nodes and depth
   pair<int, int> p = make_pair(1, 0);
 
   // Count of nodes in the left subtree
   if (root->left)
   {
       pair<int, int> ptemp = sum(root -> left);
 
       p.second += ptemp.first + ptemp.second;
       p.first += ptemp.first;
   }
 
   // Count of nodes in the right subtree
   if (root -> right)
   {
 
       pair<int, int> ptemp = sum(root->right);
 
       p.second += ptemp.first + ptemp.second;
       p.first += ptemp.first;
   }
 
   root->size = p.first;
   return p;
}
 
int ans = 0;
 
// Function to find the total distance
void getResult(TreeNode* root, int target, int distancesum, int n)
{
   //  If target node given by user matches with the current node
   if (root->data == target)
   {
       ans= distancesum;
      // return;
   }
 
   // If root->left is not null
   if (root->left)
   {
 
       // Update sum
       int tempsum = distancesum - root -> left -> size + (n - root -> left -> size);
 
       // For the left subtree
       getResult(root -> left, target, tempsum, n);
   }
 
   // If root->right is not null
   if (root->right)
   {
       int tempsum = distancesum - root->right->size + (n - root -> right -> size);
 
       // Recursion for the right subtree
       getResult(root->right, target, tempsum, n);
   }
}
 
// Driver Code
int main()
{
   // Input tree
   TreeNode* root = push(1);
   root->left = push(2);
   root -> right = push(3);
   root -> left -> left = push(4);
   root -> left -> right = push(5);
   root -> right -> left = push(6);
   root -> right -> right = push(7);
   root -> left -> left -> left = push(8);
   root -> left -> left -> right = push(9);
 
   int target = 3;
 
   pair<int, int> p = sum(root);
 
   // Total number of nodes
   int totalnodes = p.first;
 
   getResult(root, target, p.second, totalnodes);
 
   // Print the sum of distances
   cout << "Sum of the distance of all nodes from a given node is:- " <<  ans << endl;
 
   return 0;
}
