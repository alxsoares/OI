#include <cstdio>
#include <ext/rope>

using namespace std;
using namespace __gnu_cxx;

char str[3000005];
int l[5005], r[5005];
crope rec(int i, int len) {
	if ( i == 0 ) return crope(((string)str).substr(0, len+1).c_str());
	if ( r[i] >= len ) return rec(i-1, len);
	int lb = r[i]+1, rb = min(len, 2*r[i]-l[i]+1),
		sz = rb-lb+1;
	crope pre = rec(i-1, len-sz);
	string tmp;
	for ( int t = l[i]+1; sz&&t <= r[i]; t+=2 ) tmp += pre[t],sz--;
	for ( int t = l[i]; sz&&t <= r[i]; t+=2 ) tmp += pre[t],sz--;
	pre.insert(lb, tmp.c_str());
	return pre;
}

int main() {
	freopen("t.in", "r", stdin);
	int k, n;
	scanf("%s%d%d", str+1, &k, &n);
	str[0] = '?';
	for ( int i = 1; i <= n; i ++ )
		scanf("%d%d", &l[i], &r[i]);
	printf("%s", rec(n, k).c_str()+1);
}
