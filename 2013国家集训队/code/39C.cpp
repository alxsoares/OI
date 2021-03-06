#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cassert>
#include <vector>
#define pb(x) push_back(x)
#define foreach(I, C) for(__typeof((C).begin()) I = (C).begin(); I != (C).end(); I ++)
using namespace std;
const int kNMax = 2005;
struct Segment {
	int l, r;
	Segment(){}
	Segment(int _l ,int _r):
		l(_l), r(_r){}
} seg[kNMax];
int dis[2*kNMax], nDis, nSeg;
vector<int> pin[2*kNMax];
int f[2*kNMax][2*kNMax], g[2*kNMax][2*kNMax], w[2*kNMax][2*kNMax];
int n;

int dp(int l, int r) {
	assert(l <= r);
	if ( f[l][r] != -1 ) return f[l][r];
	if ( l == r ) return f[l][r] = 0;
	f[l][r] = dp(l, r-1) + w[l][r];
	g[l][r] = -1;
	foreach(it, pin[r]) 
		if ( seg[*it].l >= l && !(seg[*it].l == l && seg[*it].r == r) ) {
			int tmp = dp(l, seg[*it].l) + dp(seg[*it].l, r) + w[l][r];
			if ( tmp > f[l][r] ) {
				f[l][r] = tmp; g[l][r] = *it;
			}
		}
	return f[l][r];
}

void output(int l, int r) {
	assert(l <= r);
	if ( l == r ) return;
	if ( w[l][r] ) 
		foreach(it, pin[r])
			if ( seg[*it].l == l ) printf("%d ", (*it)+1);
	if ( g[l][r] == -1 ) output(l, r-1);
	else {
		output(l, seg[g[l][r]].l);
		output(seg[g[l][r]].l, r);
	}
}	

int main() {
	freopen("t.in", "r", stdin);
	memset(f, -1, sizeof(f));
	scanf("%d", &n);
	for ( int i = 0; i < n; i ++ ) {
		int c, r;
		scanf("%d%d", &c, &r);
		seg[nSeg++] = Segment(c-r, c+r);
		dis[nDis++] = c-r;
		dis[nDis++] = c+r;
	}
	sort(dis, dis + nDis);
	nDis = unique(dis, dis + nDis) - dis;
	for ( int i = 0; i < n; i ++ ) {
		seg[i].l = lower_bound(dis, dis + nDis, seg[i].l) - dis;
		seg[i].r = lower_bound(dis, dis + nDis, seg[i].r) - dis;
		w[seg[i].l][seg[i].r]++;
		pin[seg[i].r].pb(i);
	}
	printf("%d\n", dp(0, nDis-1));
	output(0, nDis-1);
}
