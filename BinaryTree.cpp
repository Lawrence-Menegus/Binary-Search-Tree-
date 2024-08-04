// Name: Lawrence Menegus
// Date: 10/9/23
// Data Structures and Algorithms
// Description: Creates a Binary Search Tree through linked list. Program provides the correct order of nodes, correct number of nodes of the binary tree 
// It also searches for the value in a binary tree and prints out the results of the binary search.  It will state if the value is in the binary tree or if the value 
// is not in the binary tree


#include <iostream>
using namespace std;

// Struct for the Linked List. 
struct TreeNode
{
    int info;
    TreeNode* left;
    TreeNode* right;
};

// Initialize 
void inOrder(TreeNode*);
void insert(TreeNode*&, int);
int countNodes(TreeNode*);
TreeNode* treeSearch(TreeNode*, int);

// Main Function 
int main()
{
    // Declare the root 
    TreeNode* root = nullptr;

    // Assign nodes of the binary tree 
    insert(root, 2);
    insert(root, 7);
    insert(root, 10);
    insert(root, 15);
    insert(root, 18);
    insert(root, 20);
  

    // Print out the In Order 
    cout << "Binary Search Tree Traversal: ";
    inOrder(root);
    cout << endl;

    // Print out the Count of the nodes 
    cout << "Binary Search Tree Node Count: ";
    cout << countNodes(root);
    cout << endl;

    // Changable variables for Binary Search 
    int n = 7; 
    int i = 13; 

    // Print the Results of Binary Search 
    cout << "Binary Search Tree Search for: ";

    // ? is to check if the condition treeSearch is true. It if is It is in the binary tree
    // if if is not it is not in the binary tree
    treeSearch(root, n) ? cout << n <<" is in the binary tree " : cout<< n << " is not in the binary tree ";
    treeSearch(root, i) ? cout << i << " is in the binary tree " : cout << i << " is not in the binary tree ";
    cout << endl;

    return 0;
}

// In Order Function 
void inOrder(TreeNode* root)
{
    // Compares if the root is null 
    if (root == nullptr)
        return;

    // Traverse the left subtree 
    inOrder(root->left);

    // Visit the root 
    cout << root->info << " ";

    // Traverse the right subtree 
    inOrder(root->right);
}

// Insert Function 
void insert(TreeNode*& node, int value)
{
    // Checks if node is a node pointer 
    if (node == nullptr)
    {
        // Create a new Tree node 
        node = new TreeNode();

        // Sets first node to value 
        node->info = value;

        // Set left node to nullptr 
        node->left = nullptr;

        // Sets right node to nullptr
        node->right = nullptr;
    }
    // Checks if the value less than the node
    else if (value < node->info)
        // Inserts value left
        insert(node->left, value);

    else
        // Inserts value right 
        insert(node->right, value);
}

// Count Nodes Function 
int countNodes(TreeNode* node)
{
    // Checks if node is nullptr 
    if (node == nullptr)
        return 0;
    else
        // Calls the function to be counted 
        return(countNodes(node->left) + 1 + countNodes(node->right));
}

// Binary Search Function 
TreeNode* treeSearch(TreeNode* node, int target)
{
    // Checks if node equal nullptr 
    if (node == nullptr) 
        return nullptr;

    // Checks if value equals node
    if (target == node->info)
        return node;

    // Checks if node is less than node calls search to right part of binary tree
    if (target < node->info)
        return treeSearch(node->left, target);
    
    // Calls binary search for right part of tree 
    return treeSearch(node->right, target);
}
