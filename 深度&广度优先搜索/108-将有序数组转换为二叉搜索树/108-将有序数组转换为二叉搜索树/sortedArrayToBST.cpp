//https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree/

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode 
{
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


TreeNode* dfs(vector<int>& nums, int left, int right)
{
	if (left > right)
	{
		return NULL;
	}

	int mid = (left + right) / 2;
	TreeNode* root = new TreeNode(nums[mid]);
	root->left = dfs(nums, left, mid - 1);
	root->right = dfs(nums, mid + 1, right);

	return root;
}

TreeNode* sortedArrayToBST(vector<int>& nums)
{
	return dfs(nums, 0, nums.size() - 1);
}

int main()
{
	vector<int> nums = { -5,-3 ,0,1,6 };

	system("pause");
	return 0;
}