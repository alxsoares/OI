/*
 * $Date: Mon Oct 31 16:04:55 2011 +0800
 * $Author: csimstu
 * $Source: Codechef COOK15 LAMQUGAM
 * $Method: Bitmask + Binary Index Tree
 */
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long int64;
const int N = 200000;
int D, T;
int diagMask[N];
bool marked[N + 1];
int lose[N + 1];
int W[100010][4];
int ans[100010];

struct Query{
	int x, y, flag, i;
	Query(){}
	Query(int _x, int _y, int _flag, int _i):
		x(_x), y(_y), flag(_flag), i(_i){}
	bool operator< (const Query &t) const{
		return x < t.x;
	}
	void set(int t){
		ans[i] += flag * t; 
	}
} Q[400000];
int nQ;

int bit[200010];

void add(int x, int y){
	for(; x <= N; x += x & -x)
		bit[x] += y;
}

int sum(int x){
	int res = 0;
	for(; x; x -= x & -x)
		res += bit[x];
	return res;
}

int64 gcd(int64 a, int64 b){
	return b ? gcd(b, a % b) : a;
}

int main(){
	scanf("%d", &D);
	for(int x = 1, y0 = 1, dg = 0; x <= N; x ++)
		if(!marked[x]){
			for(; y0 <= N && marked[y0]; y0 ++);
			if(y0 > N)
				break;
			for(; dg < N && diagMask[dg] == (1 << D) - 1; dg ++);
			int y;
			for(y = max(y0, x + dg); y <= N && (marked[y] || (diagMask[y - x] & 1 << (x % D))); y ++);
			if(y <= N){
				lose[x] = y;
				lose[y] = x;
				diagMask[y - x] |= 1 << (x % D);
				marked[y] = true;
			}
			marked[x] = true;
		}
	scanf("%d", &T);
	for(int i = 1; i <= T; i ++){
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		W[i][0] = x1; W[i][1] = y1; W[i][2] = x2; W[i][3] = y2;
		Q[nQ ++] = Query(x2, y2, 1, i);
		Q[nQ ++] = Query(x1 - 1, y2, -1, i);
		Q[nQ ++] = Query(x2, y1 - 1, -1, i);
		Q[nQ ++] = Query(x1 - 1, y1 - 1, 1, i);
	}
	sort(Q, Q + nQ);
	for(int x = 1, i = 0; x <= N; x ++){
		if(lose[x])
			add(lose[x], 1);
		while(i < 4 * T && Q[i].x < x)
			i ++;
		while(i < 4 * T && Q[i].x == x)
			Q[i].set(Q[i].y ? sum(Q[i].y) : 0), i ++;
		if(i == 4 * T)
			break;
	}
	for(int i = 1; i <= T; i ++){
		int64 b = (int64)(W[i][2] - W[i][0] + 1) * (W[i][3] - W[i][1] + 1),
			  a = ans[i];
		int64 g = gcd(a, b);
		printf("%lld/%lld\n", a / g, b / g);
	}
}
