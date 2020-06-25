//https://leetcode-cn.com/problems/coin-lcci/
#include <iostream>
#include <vector>
using namespace std;

//״̬���壺dp[n]:�����ֵΪn�ķ�������
//��ʼֵ��dp[0] = 1;
//״̬ת�Ʒ��̣�dp[i] = dp[i] + dp[i-coin];
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