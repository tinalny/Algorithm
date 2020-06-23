#include <iostream>
#include <vector>
using namespace std;

int numOfSubarrays(vector<int>& arr, int k, int threshold) 
{
	if (k > arr.size())
	{
		return 0;
	}

	int count = 0, sum = 0;
	for (int i = 0; i < k; i++)
	{
		sum += arr[i];
	}

	if (sum >= k*threshold)
	{
		count++;
	}

	for (int i = 0; i<arr.size() - k; i++)
	{
		sum += (arr[i + k] - arr[i]);
		if (sum >= k*threshold)
		{
			count++;
		}
	}
	return count;
}

int main()
{
	vector<int> arr = { 2,2,2,2,5,5,5,8};
	cout<<numOfSubarrays(arr, 3, 4) <<endl;
	system("pause");
	return 0;
}