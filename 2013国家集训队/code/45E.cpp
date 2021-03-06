#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int cnt1[26], cnt2[26];
string str1[111], str2[111];

int getlim(char ch) {
	return min(cnt1[ch-'A'], cnt2[ch-'A']);
}

bool isfine(int i, int j) {
	if ( str1[i][0] == str2[j][0] ) return true;
	return getlim(str1[i][0]) != cnt1[str1[i][0]-'A']
		&& getlim(str2[j][0]) != cnt2[str2[j][0]-'A'];
}
int n;
bool done[111];
vector<string> ans;
int main() {
	freopen("t.in", "r", stdin);
	cin >> n;
	for ( int i = 0; i < n; i ++ ) {
		cin >> str1[i];
		cnt1[str1[i][0]-'A']++;
	}
	for ( int i = 0; i < n; i ++ ) {
		cin >> str2[i];
		cnt2[str2[i][0]-'A']++;
	}
	sort(str1, str1 + n);
	sort(str2, str2 + n);
	for ( int i = 0; i < n; i ++ ) {
		for ( int j = 0; j < n; j ++ )
			if ( !done[j] && isfine(i, j) ) {
				done[j] = true;
				cnt1[str1[i][0]-'A']--; cnt2[str2[j][0]-'A']--;
				ans.push_back(str1[i] + " " + str2[j]);
				break;
			}
	}
	int sz = ans.size();
	for ( int i = 0; i < sz-1; i ++ )
		cout << ans[i] << ", ";
	cout << ans[sz-1];
}
