/*
 * $Date: Sat Oct 29 14:33:48 2011 +0800
 * $Author: csimstu
 * $Source: Codeforces Beta Round 91 Problem D
 * $Method: Two pointers
 */
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long int64;
#ifdef unix
#define INT64_FMT "%lld"
#else
#define INT64_FMT "%I64d"
#endif
const int64 INF = 1000000000000000010LL;

struct Segment{
	int64 l, r;
} seg[100010];
int64 f[1 << 19], g[1 << 19];
int64 lucky[1 << 19];

int64 plus(int64 a, int64 b){
	return min(a + b, INF);
}
int64 mul(int64 a, int64 b){
	double test = (double)a * (double)b;
	if(test > INF)
		return INF;
	return a * b;
}

bool cmp_l(const Segment &a, const Segment &b){
	return a.l < b.l;
}

bool cmp_r(const Segment &a, const Segment &b){
	return a.r < b.r;
}

int main(){
	int N;
	int64 K;

	scanf("%d" INT64_FMT, &N, &K);
	int64 min_len = INF;
	for(int i = 1; i <= N; i ++){
		scanf(INT64_FMT INT64_FMT, &seg[i].l, &seg[i].r);
		min_len = min(min_len, seg[i].r - seg[i].l + 1);
	}
	int lucky_amount = 0;
	for(int len = 1; len <= 18; len ++)
		for(int s = 0, upper_lim = 1 << len; s < upper_lim; s ++){
			int64 x = 0;
			for(int i = len - 1; i >= 0; i --)
				x = x * 10 + ((s & (1 << i)) ? 7 : 4);
			lucky[++ lucky_amount] = x;
		}
	sort(seg + 1, seg + 1 + N, cmp_l);
	int64 acc = 0, cnt = 0;
	for(int i = lucky_amount, p = N; i >= 1; i --){
		acc = plus(acc, mul(cnt, lucky[i + 1] - lucky[i]));
		while(p >= 1 && seg[p].l > lucky[i]){
			acc = plus(acc, seg[p].l - lucky[i]);
			cnt ++;
			p --;
		}
		f[i] = acc;
	}
	sort(seg + 1, seg + 1 + N, cmp_r);
	acc = cnt = 0;
	for(int i = 1, p = 1; i <= lucky_amount; i ++){
		acc = plus(acc, mul(cnt, lucky[i] - lucky[i - 1]));
		while(p <= N && seg[p].r < lucky[i]){
			acc = plus(acc, lucky[i] - seg[p].r);
			cnt ++;
			p ++;
		}
		g[i] = acc;
	}
	int ans = 0;
	for(int i = 1, j = 1; i <= lucky_amount; i ++){
		while(i > j)
			j ++;
		while(j < lucky_amount && plus(f[i], g[j + 1]) <= K && lucky[j + 1] - lucky[i] + 1 <= min_len)
			j ++;
		if(plus(f[i], g[j]) <= K && lucky[j] - lucky[i] + 1 <= min_len)
			ans = max(ans, j - i + 1);
	}
	printf("%d\n", ans);
}
