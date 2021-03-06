#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cassert>
typedef long long ll;
using namespace std;
#ifdef unix
#define LL_FMT "%lld"
#else
#define LL_FMT "%I64d"
#endif
int N, M, K;
struct P{
	ll a, b;
	int c, idx;
	bool operator< (const P &t) const{
		return c < t.c;
	}
} p[55];
ll f[55][110][55], g[55][110][55][2];
ll ans[55][2];
int main(){
	scanf("%d%d%d", &N, &M, &K);
	for(int i = 1; i <= M; i ++){
		scanf(LL_FMT LL_FMT "%d", &p[i].a, &p[i].b, &p[i].c);
		p[i].idx = i;
	}
	sort(p + 1, p + 1 + M);
	memset(f, -0x3f, sizeof(f));
	for(int i = 1; i <= M; i ++)
		for(int j = 0; j <= p[i].b - p[i].a; j ++)
			for(int k = 1; k <= N; k ++){
				ll tmp = j + p[i].a;
				if(k == 1){
					f[i][j][k] = tmp;
					g[i][j][k][0] = g[i][j][k][1] = 0;
					continue;
				}
				for(int l = 1; l < i; l ++)
					if(p[l].c < p[i].c){
						if(p[l].a <= tmp - K && tmp - K <= p[l].b)
							if(f[l][tmp - K - p[l].a][k - 1] + tmp > f[i][j][k]){
								f[i][j][k] = f[l][tmp - K - p[l].a][k - 1] + tmp;
								g[i][j][k][0] = l;
								g[i][j][k][1] = tmp - K - p[l].a;

							}
						if(tmp % K == 0){
							ll z = tmp / K;
							if(p[l].a <= z && z <= p[l].b)
								if(f[l][z - p[l].a][k - 1] + tmp > f[i][j][k]){
									f[i][j][k] = f[l][z - p[l].a][k - 1] + tmp;
									g[i][j][k][0] = l;
									g[i][j][k][1] = z - p[l].a;
								}
						}
					}
			}
	ll res = 0;
	ll bestI = -1, bestJ = -1;
	for(int i = 1; i <= M; i ++)
		for(int j = 0; j <= p[i].b - p[i].a; j ++)
			if(f[i][j][N] > res){
				bestI = i, bestJ = j;
				res = f[i][j][N];
			}
	if(bestI == -1)
		printf("NO\n");
	else{
		printf("YES\n");
		ll ti = bestI, tj = bestJ, tk = N;
		ans[N][0] = ti, ans[N][1] = tj + p[ti].a;
		while(1){
			ll tmp = ti;
			ti = g[ti][tj][tk][0];
			tj = g[tmp][tj][tk][1];
			tk --;
			if(ti == 0)
				break;
			ans[tk][0] = ti;
			ans[tk][1] = tj + p[ti].a;
		}
		for(int i = 1; i <= N; i ++)
			printf("%d " LL_FMT "\n", p[(int)ans[i][0]].idx, ans[i][1]);
	}
}
