#include <cstdio>
#include <algorithm>
using namespace std;
int n, m;
double f[3001][301], p[3001][301], g[3001];
int main() {
	freopen("t.in", "r", stdin);
	scanf("%d%d", &n, &m);
	for ( int i = 1; i <= n; i ++ )
		for ( int j = 1; j <= m; j ++ ) {
			int x;
			scanf("%d", &x);
			p[i][j] = x / 1000.;
		}
	for ( int i = 1; i <= n; i ++ ) 
		for ( int j = 1; j <= m; j ++ )
			if ( i == 1 ) f[i][j] = p[i][j];
			else f[i][j] = p[i][j]+f[i-1][j]*(1-p[i][j]);
	double ans = 0;
	for ( int rep = 0; rep < n; rep ++ ) {
		int k = max_element(f[n]+1, f[n]+1+m)-f[n];
		ans += f[n][k];
		for ( int i = 1; i <= n; i ++ )
			g[i] = p[i][k]*f[i-1][k]+(1-p[i][k])*g[i-1];
		for ( int i = 1; i <= n; i ++ )
			f[i][k] = g[i];
	}
	printf("%.10lf\n", ans);
}
