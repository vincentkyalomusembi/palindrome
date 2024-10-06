// C++ Program to iterative Postorder
// Traversal of N-ary Tree
#include<bits/stdc++.h>
using namespace std; 

// Node class
class Node 
{
	public :
	int val;
	vector<Node*> children ;

	// Default constructor
	Node() {}

	Node(int _val)
	{
		val = _val;
	}

	Node(int _val, vector<Node*> _children)
	{
		val = _val;
		children = _children;
	}
};
	
// Helper class to push node and it's index
// into the st
class Pair 
{
	public:
	Node* node;
	int childrenIndex;
	Pair(Node* _node, int _childrenIndex)
	{
		node = _node;
		childrenIndex = _childrenIndex;
	}
};
	
// We will keep the start index as 0, 
// because first we always
// process the left most children
int currentRootIndex = 0;
stack<Pair*> st;
vector<int> postorderTraversal ;

// Function to perform iterative postorder traversal
vector<int> postorder(Node* root)
{
	while (root != NULL || st.size() > 0) 
	{
		if (root != NULL)
		{
			
			// Push the root and it's index 
			// into the st
			st.push(new Pair(root, currentRootIndex));
			currentRootIndex = 0;

			// If root don't have any children's that 
			// means we are already at the left most
			// node, so we will mark root as NULL
			if (root->children.size() >= 1) 
			{
				root = root->children[0];
			}
			else
			{
				root = NULL;
			}
			continue;
		}

		// We will pop the top of the st and
		// push_back it to our answer
		Pair* temp = st.top();
		st.pop();
		postorderTraversal.push_back(temp->node->val);

		// Repeatedly we will the pop all the 
		// elements from the st till popped 
		// element is last children of top of
		// the st
		while (st.size() > 0 && temp->childrenIndex == 
				st.top()->node->children.size() - 1)
		{
			temp = st.top();
			st.pop();
			
			postorderTraversal.push_back(temp->node->val);
		}

		// If st is not empty, then simply assign 
		// the root to the next children of top
		// of st's node
		if (st.size() > 0) 
		{
			root = st.top()->node->children[temp->childrenIndex + 1];
			currentRootIndex = temp->childrenIndex + 1;
		}
	}
	return postorderTraversal;
}

// Driver Code
int main()
{
	Node* root = new Node(1);

	root->children.push_back(new Node(3));
	root->children.push_back(new Node(2));
	root->children.push_back(new Node(4));

	root->children[0]->children.push_back(new Node(5));
	root->children[0]->children.push_back(new Node(6));
	vector<int> v = postorder(root);
	for(int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
}

// This code is contributed by Arnab Kundu
