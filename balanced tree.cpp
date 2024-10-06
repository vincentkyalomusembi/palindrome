#include<bits/stdc++.h> 
using namespace std;

class Node {
public:
    int data;//data
    Node* left;//pointer to left child
    Node* right; //pointer to right child
    Node(int d) 
	{
        int data = d;
        left = right = NULL;
    }
   
};


int height(Node* node)// Function to calculate the height of a tree
{
    
    if (node == NULL)//if tree is empty
	{
	return 0;	
	}
        else// If tree is not empty then

    
    // height = 1 + max of left height
    // and right heights
    {
		
	
    return 1 + max(height(node->left), height(node->right));
	}
}



bool isBalanced(Node* root)// Returns true if binary tree is balanced
{
   
    int lh; //  height of left subtree 
    int rh;//  height of right subtree

   
    if (root == NULL) // If tree is empty then return true
        return 1;

    // Get the height of left and right sub trees
    lh = height(root->left);
    rh = height(root->right);

    if (abs(lh - rh) <= 1 && isBalanced(root->left)&& isBalanced(root->right))
	{
	 return 1;	
	}
     else
	 {
	 // If we reach here then tree is not height-balanced
    return 0;	 
	 }  

   
}

//calling code
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->left->left = new Node(8);
    root->right->right = new Node(9);
    

    if (isBalanced(root))
        cout << "Tree is balanced";
    else
        cout << "Tree is not balanced";
    return 0;
}