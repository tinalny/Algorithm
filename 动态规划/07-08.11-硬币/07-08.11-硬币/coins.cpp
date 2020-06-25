//https://leetcode-cn.com/problems/coin-lcci/
#include <iostream>
#include <vector>
using namespace std;

//状态定义：dp[n]:组成面值为n的方案个数
//初始值：dp[0] = 1;
//状态转移方程：dp[i] = dp[i] + dp[i-coin];
int waysToChange(int n)
{
	vector<int> coins = { 1,5,10,25 };
	vector<int> dp(n + 1);

	dp[0] = 1;
	for (int coin : coins)
	{
		for (int i = coin; i <= n; i++)
		{
			dp[i] = (dp[i] + dp[i - coin]) % 1000000007;
		}
	}
	return dp[n];
}

int main()
{
	int n;
	cin >> n;
	cout << waysToChange(n) << endl;;
	system("pause");
	return 0;
}