//https://leetcode-cn.com/problems/delete-and-earn/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int deleteAndEarn(vector<int>& nums)
{
	if (nums.empty())
	{
		return 0;
	}
	if (nums.size() == 1)
	{
		return nums[0];
	}

	vector<int> tmp(20001, 0);
	for (auto n : nums)
	{
		tmp[n] += n;
	}

	vector<int> dp(20001, 0);
	dp[0] = tmp[0];
	dp[1] = max(tmp[0], tmp[1]);
	for (int i = 2; i < 20001; i++)
	{
		dp[i] = max(dp[i - 1], dp[i - 2] + tmp[i]);
	}
	return dp[20000];
}
int main()
{
	vector<int> nums = { 2,2,3,3,3,4 };
	cout<< deleteAndEarn(nums) << endl;
	system("pause");
	return 0;
}