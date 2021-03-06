#include <cstdio>
#include <bitset>
using namespace std;
const int kMod = 1000000007;
int ans = 0;
int n, m, t;
int cnt[122];

void dfs(int i, bitset<120> msk, int acc) {
	if ( i > m/2 ) { 
		ans = (ans + acc) % kMod;
		return;
	}
	dfs(i+1, msk, acc);
	if ( cnt[i] && !msk[i] )
		dfs(i+1, msk|msk<<i|msk>>i|msk<<m-i|msk>>m-i, (long long)cnt[i]*acc%kMod);
}

int main() {
	freopen("t.in", "r", stdin);
	scanf("%d%d%d", &n, &m, &t);
	for ( int i = 0; i < t; i ++ ) {
		int x;
		scanf("%d", &x);
		x %= m;
		cnt[min(x, m-x)]++;
	}
	dfs(0, bitset<120>(1), 1);
	printf("%d\n", ans);
}
