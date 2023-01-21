#include <bits/stdc++.h>
using namespace std;

/*

1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
0 1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
No

2 2 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
2 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 2
Yes

0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 2 
2 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
No

4 2 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
0 0 2 4 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
Yes

*/

void test_case(int tc) {
	int n, k;
	cin >> n >> k;
	string a, b;
	cin >> a >> b;
	int have[27], need[26];
	memset(have, 0, sizeof(have));
	memset(need, 0, sizeof(need));
	for (int i = 0; i < n; i++) {
		have[a[i]-'a']++;
		need[b[i]-'a']++;
	}
	// for (int i = 0; i < 26; i++) {
	// 	cout << have[i] << " ";
	// }
	// cout << "\n";
	// for (int i = 0; i < 26; i++) {
	// 	cout << need[i] << " ";
	// }
	// cout << "\n";
	bool bad = false;
	for (int i = 0; i < 26; i++) {
		if ((have[i] < need[i]) || ((have[i] -= need[i]) % k != 0)) {
			bad = true;
		}
		have[i+1] += have[i];
	}
	cout << (bad ? "No" : "Yes") << "\n";
	// cout << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T = 1;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		test_case(tc);
	}
}
