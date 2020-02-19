#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[50000];

int D, n, m;
vector<int> vec;
int maxi = 0;

void minMax(vector<int> vec) {
	int mini = 2e9;

	for (int k = 0; k <= vec.size(); k++) {
		int d = 0;
		if (k == vec.size())d = D - vec[k - 1];
		else if (k == 0)d = vec[k];
		else d = vec[k] - vec[k - 1];
		if (d < mini)mini = d;
	}
	if (mini > maxi) maxi = mini;

	return;
}

void pick(int n, vector<int>& picked, int toPick)
{

	if (toPick == 0)minMax(picked);


	int smallest = picked.empty() ? 0 : picked.back() + 1;

	for (int i = 0;i<n;i++)
	{
		if (arr[i] >= smallest) {
			picked.push_back(arr[i]);
			pick(n, picked, toPick - 1);
			picked.pop_back();

		}
	}
}

int main() {
	cin >> D >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}


	if (n == 0) {
		cout << D << '\n';
		return 0;
	}
	vector<int> v;
	pick(n, v, n-m);

	cout << maxi << '\n';
	return 0;
}