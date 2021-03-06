#include <cstdio>
#include <cassert>
#ifdef unix
#define LL_FMT "%lld"
#else
#define LL_FMT "%I64d"
#endif
typedef long long ll;
const int kNMax = 250010;
const int kLogMax = 20;
int a[kNMax*2];
int log2[kNMax*2];
int st[kLogMax][kNMax*2];
int f[kLogMax][kNMax*2];
int n;

inline int eval(int i) {
	return i+a[i];
}

int findMax(int l, int r) {
	int k = log2[r-l+1];
	int res1 = st[k][l], res2 = st[k][r-(1<<k)+1];
	if ( eval(res1) < eval(res2) ) return res2;
	return res1;
}

int main() {
	freopen("t.in", "r", stdin);
	scanf("%d", &n);
	for ( int i = 1; i <= n; i ++ ) {
		scanf("%d", &a[n-i+1]);
		a[n+n-i+1] = a[n-i+1];
	}

	for ( int i = 0; (1<<i) <= 2*n; i ++ )
		log2[1<<i] = i;
	for ( int i = 2; i <= 2*n; i ++ )
		if ( !log2[i] ) log2[i] = log2[i-1];
	for ( int i = 1; i <= 2*n; i ++ )
		st[0][i] = i;
	for ( int k = 1; k < kLogMax; k ++ )
		for ( int i = 1; i <= 2*n; i ++ ) {
			st[k][i] = st[k-1][i];
			int p = i+(1<<(k-1));
			if ( p <= 2*n && eval(st[k-1][p]) > eval(st[k][i]) )
				st[k][i] = st[k-1][p];
		}
	for ( int i = 1; i <= 2*n; i ++ )
		f[0][i] = findMax(i, i+a[i]);
	for ( int k = 1; k < kLogMax; k ++ )
		for ( int i = 1; i <= 2*n; i ++ ) {
			assert(f[k-1][i]);
			f[k][i] = f[k-1][f[k-1][i]];
		}

	ll ans = 0;
	for ( int st = 1; st <= n; st ++ ) {
		int cur = st, des = st+n-1;
		if ( eval(cur) >= des ) {
			ans++;
			continue;
		}
		for ( int k = kLogMax-1; k >= 0; k -- )
			if ( eval(f[k][cur]) < des ) {
				cur = f[k][cur];
				ans += 1<<k;
			}
		assert(eval(cur) < des);
		assert(eval(f[0][cur]) >= des);
		ans+=2;
	}
	printf(LL_FMT "\n", ans);
}
