//01背包
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxValue_1(int n, int c, vector<int> v, vector<int> w)
{
	int *dp = new int[n];

	memset(dp, 0, sizeof(dp));

	for (int i = 1; i < n; i++)
	{
		for (int j = c; j >= w[i]; j--)
		{
				dp[j] = max(v[i] + dp[j - w[i]], dp[j]);
		}
	}
	return dp[c];
}

int main()
{
	int n = 0, capacity = 0;//物品数量、背包容量
	cin >> n >> capacity;

	vector<int> values(n, 0);//物品价值
	vector<int> weights(n, 0);//物品重量

	for (int j = 0; j < n; j++)
		cin >> weights[j];

	for (int i = 0; i < n; i++)
		cin >> values[i];

	cout << maxValue_1(n, capacity, values, weights) << endl;

	system("pause");
	return 0;
}