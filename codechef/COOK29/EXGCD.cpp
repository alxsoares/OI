#include <cstdio>
#include <cassert>
typedef long long ll;

const int kValMax = 200000;
const int kMod = 1000000007;

int mul(int a, int b) {
	return (ll)a * b % kMod;
}

void add(int &a, int b) {
	a += b;
	a %= kMod;
}

int powMod(int a, int n) {
	int res = n & 1 ? a : 1;
	for ( n >>= 1; n; n >>= 1 ) {
		a = (ll)a * a % kMod;
		if ( n & 1 )
			res = (ll)res * a % kMod;
	}
	return res;
}

int prime[kValMax+1], phi[kValMax+1],
	minfact[kValMax+1], factcnt[kValMax], factacc[kValMax];
bool notprime[kValMax+1];
int nPrime = 0;

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

void prework() {
	phi[1] = 1;
	for ( int x = 2; x <= kValMax; x ++ ) {
		if ( !notprime[x] ) {
			prime[nPrime++] = x;
			phi[x] = x-1;
			minfact[x] = x;
			factcnt[x] = 1;
			factacc[x] = x;
		}

		for ( int i = 0; i < nPrime && prime[i] <= minfact[x]; i ++ ) {
			int y = x * prime[i];
			if ( y > kValMax ) break;
			notprime[y] = true;
			minfact[y] = prime[i];
			factcnt[y] = minfact[y] == minfact[x] ? factcnt[x] + 1 : 1;
			factacc[y] = minfact[y] == minfact[x] ? factacc[x] * minfact[x] : prime[i];
			if ( y != factacc[y] )
				phi[y] = phi[y / factacc[y]] * phi[factacc[y]];
			else
				phi[y] = y - y/minfact[y];
		}
	}
}

void check() {
	for ( int i = 1; i <= 2000; i ++ ) {
		int cnt = 0;
		for ( int x = 1; x <= i; x ++ )
			if ( gcd(i,x) == 1 )
				cnt++;
		assert(cnt == phi[i]);
	}
}
int A[5], B[5], K;
int main() {
	freopen("t.in", "r", stdin);
	prework();
//	check();
	int TST;
	scanf("%d", &TST);
	while ( TST -- ) {
		scanf("%d", &K);
		for ( int i = 0; i < K; i ++ ) {
			scanf("%d%d", &A[i], &B[i]);
		}
		int ans = 0;
		for ( int d = 1; d <= B[0]; d ++ ) {
			int acc = phi[d];
			for ( int i = 0; i < K; i ++ )
				acc = mul(acc, B[i]/d-(A[i]-1)/d);
			add(ans, acc);
		}
		for ( int i = 0; i < K; i ++ )
			ans = mul(ans, powMod(B[i]-A[i]+1, kMod-2));
		ans = (-ans + kMod) % kMod;
		printf("%d\n", ans);
	}
}
