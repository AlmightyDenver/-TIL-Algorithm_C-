#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
	int n;
	cin >> n; cin.ignore();
	int max = 0, min = 0, loss = 0;
	for (int i = 0; i < n; i++) {
		int v;
		cin >> v; cin.ignore();
		if (min == 0 && max == 0) { //At Frist
			max = v;
			min = v;
		}
		else {
			if (v > max) max = v;
			else if (v < min || (v < max - loss)) {
				min = v;
				loss = max - min;
			}
		}
	}

	// Write an action using cout. DON'T FORGET THE "<< endl"
	// To debug: cerr << "Debug messages..." << endl;
	if (loss > 0) cout << "-" << loss << endl;
	else cout << loss << endl;
}