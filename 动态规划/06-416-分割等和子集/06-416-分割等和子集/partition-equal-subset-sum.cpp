//题解参考：https://leetcode-cn.com/problems/partition-equal-subset-sum/solution/0-1-bei-bao-wen-ti-xiang-jie-zhen-dui-ben-ti-de-yo/

#include <iostream>
#include <vector>
using namespace std;

bool canPartition(vector<int>& nums)
{
	int sum = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		sum += nums[i];
	}

	//数组元素之和可以被2整除才会出现分割子集，否则不存在
	if (sum % 2 == 1)
	{
		return false;
	}

	int target = sum / 2;

	//初始化为false
	vector<vector<bool>> dp(nums.size() + 1, vector<bool>(target + 1, false));

	if (nums[0] <= target)
	{
		dp[0][nums[0]] = true;
	}

	//01背包模板
	for (int i = 1; i < nums.size(); i++)
	{
		for (int j = 0; j <= target; j++)
		{
			dp[i][j] = dp[i - 1][j];
			if (nums[i] == j)
			{
				dp[i][j] = true;
				continue;
			}
			else if (nums[i] < j)
			{
				dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i]];
			}
		}
	}
	return dp[nums.size() - 1][target];
}

int main()
{
	vector<int> nums = { 23,13,11,7,6,5,5 };

	cout << canPartition(nums) << endl;
	system("pause");
	return 0;
}