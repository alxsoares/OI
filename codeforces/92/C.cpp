#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long int64;
const int64 INF = 0x3f3f3f3f3f3f3f3fLL;
struct Stuff{
	int idx, fix;
	bool operator< (const Stuff &t) const{
		return fix < t.fix;
	}
} stuff[210];
int N, M;
int64 K;
int64 f[210][210];
char ans[210];

void inc(int64 &a, int64 b){
	if(a >= INF - b)
		a = INF;
	else
		a += b;
}

int64 dp(){
	int n = N + M - 1;
	memset(f, 0, sizeof(f));
	f[0][0] = 1;
	for(int i = 0; i < n; i ++)
		for(int j = 0; j <= n / 2; j ++)
			if(f[i][j]){
				if(!ans[i]){
					inc(f[i + 1][j + 1], f[i][j]);
					if(j)
						inc(f[i + 1][j - 1], f[i][j]);
				}
				else if(ans[i] == '(')
					inc(f[i + 1][j + 1], f[i][j]);
				else if(j)
					inc(f[i + 1][j - 1], f[i][j]);
			}
	return f[n][0];
}

int main(){
	cin >> N >> M >> K;
	for(int i = 0; i < N + M - 1; i ++){
		stuff[i].idx = i;
		stuff[i].fix = N * M + 1;
	}
	for(int i = 0; i < N; i ++)
		for(int j = 0; j < M; j ++){
			int c;
			scanf("%d", &c);
			stuff[i + j].fix = min(stuff[i + j].fix, c - 1);
		}
	sort(stuff, stuff + N + M - 1);
	for(int i = 0; i < N + M - 1; i ++){
		int x = stuff[i].idx;
		ans[x] = '(';
		int64 tmp = dp();
		if(tmp >= K)
			continue;
		else{
			ans[x] = ')';
			K -= tmp;
		}
	}
	for(int i = 0; i < N; i ++, printf("\n"))
		for(int j = 0; j < M; j ++)
			printf("%c", ans[i + j]);
}
