/*
 * $Date: Mon Oct 31 16:06:36 2011 +0800
 * $Author: csimstu
 * $Source: Codechef COOK15 PERMDIG
 * $Method: State compression + DP
 */
#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>
#include <map>
using namespace std;

typedef long long int64;
typedef pair<int64, int64> doublet_t;
typedef pair<doublet_t, int> triplet_t;

map<triplet_t, int64> memo;
char A[88], B[88], C[88];
int LA, LB, LC;
int BASE;
vector<int> initA, initB;

int64 encode(const vector<int> &s){
	int64 res = 0;
	for(int i = 0; i < BASE; i ++){
		res <<= 6;
		res |= s[i];
	}
	return res;
}

vector<int> decode(int64 s){
	vector<int> res(BASE);
	for(int i = BASE - 1; i >= 0; i --){
		res[i] = s & 63;
		s >>= 6;
	}
	return res;
}

int64 dp(int64 sA, int64 sB, int d){
	triplet_t T = make_pair(make_pair(sA, sB), d);
	if(memo.count(T))
		return memo[T];
	int64 &res = memo[T] = 0;
	vector<int> nA = decode(sA),
		nB = decode(sB);
	int digA = 0;
	for(int i = 0; i < BASE; i ++)
		digA += nA[i];
	int digB = 0;
	for(int i = 0; i < BASE; i ++)
		digB += nB[i];
	int dig = max(digA, digB);
	int z = LC < dig ? 0 : C[LC - dig] - '0';
	for(int t = 0; t < 2; t ++){
			if(dig > LA){
				int y = d * BASE + z - t;
				if(!(0 <= y && y < BASE))
					continue;
				if(nB[y] == 0)
					continue;
				nB[y] --;
				res += dp(encode(nA), encode(nB), t);
				nB[y] ++;
			}
			else
				for(int x = 0; x < BASE; x ++)
					if(nA[x]){
						int y = d * BASE + z - x - t;
						if(!(0 <= y && y < BASE))
							continue;
						if(dig <= LB && nB[y] == 0)
							continue;
						if(dig > LB && y > 0)
							continue;
						int tA = nA[x], tB = nB[y];
						nA[x] --;
						if(LB >= dig)
							nB[y] --;
						res += dp(encode(nA), encode(nB), t);
						nA[x] = tA, nB[y] = tB;
					}
	}
	return res;
}

void work(){
	memo.clear();
	scanf("%d", &BASE);
	scanf("%s %s %s", A, B, C);
	LA = strlen(A);
	LB = strlen(B);
	LC = strlen(C);
	bool carry = 0;
	if(LC > max(LA, LB)){
		if(LC > max(LA, LB) + 1 || C[0] != '1'){
			printf("0\n");
			return;
		}
		carry = 1;
	}
	initA = initB = vector<int>(BASE);
	for(int i = 0; i < LA; i ++)
		initA[A[i] - '0'] ++;
	for(int i = 0; i < LB; i ++)
		initB[B[i] - '0'] ++;
	memo[make_pair(make_pair(0, 0), 0)] = 1;
	printf("%lld\n", dp(encode(initA), encode(initB), carry));
}

int main(){
	int T;
	scanf("%d", &T);
	while(T --)
		work();
}
