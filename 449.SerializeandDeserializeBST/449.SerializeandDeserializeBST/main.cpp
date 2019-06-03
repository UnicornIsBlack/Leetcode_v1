#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec
{
	public:
	// Encodes a tree to a single string.
	string serialize(TreeNode* root)
	{
		if ( !root ) return " #";
		string ans = " " + to_string(root->val);
		return ans + serialize(root->left) + serialize(root->right);
	}

	TreeNode* DFS(istringstream &is)
	{
		string str;
		is >> str;
		if ( str == "#" ) return NULL;
		TreeNode* root = new TreeNode(stoi(str));
		root->left = DFS(is), root->right = DFS(is);
		return root;
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data)
	{
		istringstream is(data);
		return DFS(is);
	}

	

};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

int main()
{
	return 0;
}