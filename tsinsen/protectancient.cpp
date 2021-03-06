#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define pb(x) push_back(x)
#define foreach(I, C) for(__typeof((C).begin()) I = (C).begin(); I != (C).end(); I++)
#define mp(x, y) make_pair(x, y)
using namespace std;
const int kInf = 0x3f3f3f3f;
const int kVMax = 111*1024;
struct Point {
	int x, y;
} relic[11], stake[111];

int p, n, m;
int weight[111][111], affect[111][111];
vector<pair<int, int> > adj[111];
int f[111][1024];
bool inQ[111][1024];
pair<int, int> Q[kVMax];
int g[1024], h[1024];
int ans[11];

int countBits(int s) {
	int res = 0;
	while ( s ) {
		res += s & 1;
		s >>= 1;
	}
	return res;
}

int main() {
	freopen("t.in", "r", stdin);
	scanf("%d%d%d", &p, &n, &m);
	for ( int i = 1; i <= p; i ++ )
		scanf("%d%d", &relic[i].x, &relic[i].y);
	memset(weight, 0x3f, sizeof(weight));
	for ( int i = 1; i <= n; i ++ ) {
		scanf("%d%d", &stake[i].x, &stake[i].y);
		weight[i][i] = 0;
	}
	for ( int i = 1; i <= m; i ++ ) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		weight[u][v] = weight[v][u] = w;
		adj[u].pb(mp(v, w));
		adj[v].pb(mp(u, w));
	}

	for ( int i = 1; i <= n; i ++ )
		for ( int j = i+1; j <= n; j ++ ) 
			for ( int k = 1; k <= p; k ++ ) {
				int ll = min(stake[i].x, stake[j].x),
					rr = max(stake[i].x, stake[j].x);
				if ( !(ll <= relic[k].x && relic[k].x < rr) ) continue;
				double t = (double)(stake[j].y-stake[i].y) / (stake[j].x-stake[i].x),
					   b = stake[i].y-t*stake[i].x;
				double yy = t * relic[k].x + b;
				if ( yy > relic[k].y ) {
					affect[i][j] |= 1 << (k-1);
					affect[j][i] |= 1 << (k-1);
				}
			}

	memset(g, 0x3f, sizeof(g));
	int upperlim = 1<<p;
	for ( int i = 1; i <= n; i ++ ) {
		memset(f, 0x3f, sizeof(f));
		memset(inQ, 0, sizeof(inQ));
		int qh = 0, qt = 0;
		Q[qt++] = mp(i, 0);
		inQ[i][0] = true;
		f[i][0] = 0;
		while ( qh != qt ) {
			pair<int, int> u = Q[qh];
			qh = (qh + 1) % kVMax;
			inQ[u.first][u.second] = false;

			foreach(it, adj[u.first]) {
				pair<int, int> v = mp(it->first, u.second ^ affect[u.first][it->first]);
				int tmp = it->second + f[u.first][u.second];
				if ( tmp < f[v.first][v.second] ) {
					f[v.first][v.second] = tmp;
					if ( !inQ[v.first][v.second] ) {
						inQ[v.first][v.second] = true;
						Q[qt] = v;
						qt = (qt + 1) % kVMax;
					}
				}
			}
		}

		for ( int j = 1; j <= n; j ++ )
			for ( int s = 0; s < upperlim; s ++ ) 
				if ( f[j][s] != kInf && weight[i][j] != kInf ) {
					int ss = s ^ affect[i][j];
					g[ss] = min(g[ss], f[j][s] + weight[i][j]);
				}
	}

	memset(h, 0x3f, sizeof(h));
	h[0] = 0;
	for ( int s = 1; s < upperlim; s ++ ) {
		for ( int s2 = s; s2; s2 = s&(s2-1) )
			h[s] = min(h[s], g[s2] + h[s-s2]);
	}

	memset(ans, 0x3f, sizeof(ans));
	for ( int s = 1; s < upperlim; s ++ )
		ans[countBits(s)] = min(ans[countBits(s)], h[s]);
	for ( int i = p-1; i >= 1; i -- )
		ans[i] = min(ans[i], ans[i+1]);
	for ( int i = 1; i <= p; i ++ )
		printf("%d\n", ans[i]);
}
