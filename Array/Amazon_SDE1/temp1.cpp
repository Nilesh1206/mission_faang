#include <bits/stdc++.h>
using namespace std;

int countUnique(int arr[], int n)
{

	unordered_set<int> mp;
	for (int i = 0; i < n; i++)
		mp.insert(arr[i]);

	int c = pow(mp.size(), 2);

	return c;
}

int main()
{
    int n;
    cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
	cout << countUnique(arr, n);
	return 0;
}
