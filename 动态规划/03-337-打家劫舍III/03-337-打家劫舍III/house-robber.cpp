//https://leetcode-cn.com/problems/house-robber-iii/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode 
{
    int val;
	TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : 
		 val(x), 
		 left(NULL), 
		 right(NULL) 
	 {

	 }
 };

pair<int, int> dfs(TreeNode *root)
{
	if (root == nullptr)
	{
		return{ 0, 0 };
	}

	auto left_pair = dfs(root->left);
	auto right_pair = dfs(root->right);
	return{ root->val + left_pair.second + right_pair.second,
		max(left_pair.first, left_pair.second) + max(right_pair.first, right_pair.second) };
}

int rob(TreeNode* root)
{
	auto p = dfs(root);
	return max(p.first, p.second);
}

int main()
{

	system("pause");
	return 0;
}