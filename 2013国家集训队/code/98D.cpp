#include <cstdio>
#include <algorithm>
using namespace std;
int n, d[22];
int f[22], g[22], L[22], memF[22];

void moveG(int n, int a, int b, int c) {
	if ( n == 0 ) return;
	moveG(n-L[n], a, c, b);
	for ( int i = 0; i < L[n]; i ++ )
		printf("%d %d\n", a, c);
	moveG(n-L[n], b, a, c);
}

void moveF(int n, int a, int b, int c) {
	if ( n == 0 ) return;
	if ( memF[n] == 0 ) {
		moveG(n-1, a, c, b);
		printf("%d %d\n", a, c);
		moveG(n-1, b, a, c);
	} else {
		int k = memF[n];
		moveG(n-k, a, b, c);
		for ( int i = 0; i < k; i ++ )
			printf("%d %d\n", a, b);
		moveG(n-k, c, b, a);
		for ( int i = 0; i < k; i ++ )
			printf("%d %d\n", b, c);
		moveF(n-k, a, b, c);
	}
}

int main() {
	freopen("t.in", "r", stdin);
	scanf("%d", &n);
	for ( int i = 1; i <= n; i ++ ) 
		scanf("%d", &d[i]);
	reverse(d+1, d+1+n);
	for ( int i = 1; i <= n; i ++ ) {
		L[i] = 1;
		while ( i-L[i] >= 1 && d[i-L[i]] == d[i] ) L[i]++;
	}

	for ( int i = 1; i <= n; i ++ ) {
		f[i] = 2*g[i-1]+1;
		memF[i] = 0;
		for ( int k = 1; k <= L[i]; k ++ ) {
			int tmp = 2*g[i-k]+f[i-k]+2*k;
			if ( tmp < f[i] )
				f[i] = tmp, memF[i] = k;
		}
		g[i] = 2*g[i-L[i]]+L[i];
	}
	printf("%d\n", f[n]);
	moveF(n, 1, 2, 3);
}
