#include <iostream>
using namespace std;

int countDigitOne(int n)
{
	long k = 1;
	int count = 0;
	while (n / k != 0)
	{
		long high = n / (k * 10);
		long cur = (n / k) % 10;
		long low = n - (n / k)*k;

		if (cur == 0)
		{
			count += high*k;
		}
		else if (cur == 1)
		{
			count += high*k + low + 1;
		}
		else
		{
			count += high*k + k;
		}
		k *= 10;
	}
	return count;
}

int main()
{
	int n = 2014;
	cout << countDigitOne(n) << endl;
	system("pause");
	return 0;
}