//01背包
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxValue(int n, int c, vector<int> v, vector<int> w)
{
	int **dp = new int*[n];

	//初始化
	for (int i = 0; i < n; i++)
	{
		dp[i] = new int[c + 1];
		for (int j = 0; j <= c; j++)
		{
			dp[i][j] = 0;
		}
	}

	//处理第一行
	for (int j = 0; j <= c; j++)
	{
		dp[0][j] += (j >= w[0]) ? v[0] : 0;
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j <= c; j++)
		{
			if (j < w[i])
			{
				dp[i][j] = dp[i - 1][j];
			}
			else
			{
				dp[i][j] = max(v[i] + dp[i - 1][j - w[i]], dp[i - 1][j]);
			}
		}
	}
	return dp[n - 1][c];
}

int main1()
{
	int n = 0, capacity = 0;//物品数量、背包容量
	cin >> n >> capacity;

	vector<int> values(n, 0);//物品价值
	vector<int> weights(n, 0);//物品重量

	for (int j = 0; j < n; j++)
		cin >> weights[j];

	for (int i = 0; i < n; i++)
		cin >> values[i];

	cout << maxValue(n, capacity, values, weights) << endl;

	system("pause");
	return 0;
}