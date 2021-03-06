#include <cstdio>
#include <cassert>

bool isprime(int x) {
	if ( x < 2 ) return false;
	for ( int y = 2; y * y <= x; y ++ )
		if ( x % y == 0 ) return false;
	return true;
}
int ans[6010], tmp[4];
int main() {
	freopen("t.in", "r", stdin);
	int n;
	scanf("%d", &n);
	for ( int i = 1; i <= n; i ++ ) ans[i] = 1;
	int sum = n * (n+1) / 2;
	if ( !isprime(sum) ) {
		if ( (sum & 1) && !isprime(sum-2) )
			sum -= 3, ans[3] = 3;
		for ( int x = 2; x <= n; x ++ ) 
			if ( isprime(x) && isprime(sum-x) ) {
				ans[x] = 2;
				break;
			}
	}
	for ( int i = 1; i <= n; i ++ )
		tmp[ans[i]] += i;
	assert(isprime(tmp[1]));
	if ( tmp[2] != 0 )
		assert(isprime(tmp[2]));
	if ( tmp[3] != 0 )
		assert(isprime(tmp[3]));
	for ( int i = 1; i <= n; i ++ )
		printf("%d ", ans[i]);
}
