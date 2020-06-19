//https://leetcode-cn.com/problems/house-robber/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int rob(vector<int>& nums)
{
	if (nums.empty())
	{
		return 0;
	}
	if (nums.size() == 1)
	{
		return nums[0];
	}
	vector<int>dp(nums.size(), 0);
	dp[0] = nums[0];
	dp[1] = max(nums[0], nums[1]);
	for (int i = 2; i < nums.size(); i++)
	{
		dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
	}
	return dp[nums.size() - 1];
}

int main()
{
	vector<int> nums = {0};
	cout << rob(nums) << endl;
	system("pause");
	return 0;
}