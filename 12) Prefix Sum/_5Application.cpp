// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;

int find(int m, vector<pair<int, int> > q)
{
	int mx = 0;
	vector<int> pre(5, 0);

	for (int i = 0; i < m; i++) {
		// take input a and b
		int a = q[i].first, b = q[i].second;

		// add 100 at first index and
		// subtract 100 from last index

		// pre[1] becomes 100
		pre[a - 1] += 100;

		// pre[4] becomes -100 and this
		pre[b] -= 100;
		// continues m times as we input diff. values of a
		// and b
	}
	for (int i = 1; i < 5; i++) {
		// add all values in a cumulative way
		pre[i] += pre[i - 1];

		// keep track of max value
		mx = max(mx, pre[i]);
	}

	return mx;
}

// Driver Code
int main()
{

	int m = 3;
	vector<pair<int, int> > q
		= { { 2, 4 }, { 1, 3 }, { 1, 2 } };

	// Function call
	cout << find(m, q);
	return 0;
}
