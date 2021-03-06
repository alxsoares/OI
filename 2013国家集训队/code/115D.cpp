#include <cstdio>
#include <cstring>
#include <cctype>
#include <cassert>
typedef long long ll;
const int kMod = 1000003;
char str[2222], ns[2222];
int f[2222][2222];
void add(int &a, int b) {
	a = (a + b) % kMod;
}

int main() {
	freopen("t.in", "r", stdin);
	scanf("%s", str+1);
	int len = strlen(str+1), n = 0;
	for ( int i = 1; i <= len; i ++ ) {
		if ( str[i] == '+' || str[i] == '-' )
			ns[++n] = '+';
		else if ( str[i] == '*' || str[i] == '/' )
			ns[++n] = '*';
		else {
			ns[++n] = 'a';
			while ( i+1 <= len && isdigit(str[i+1]) )
				i++;
		}
	}
	f[n-1][1] = ns[n] == 'a';
	for ( int i = n-1; i >= 1; i -- ) {
		for ( int j = 1; j <= n; j ++ )
			if ( f[i][j] ) {
				assert(ns[i]!='a');
				if ( i>1&&ns[i-1]=='a' ) {
					for ( int k = j+1; k >= 1; k-- )
						add(f[i-2][k], f[i][j]);
				} else if ( ns[i]=='+' ) {
					for ( int k = j; k >= 1; k -- )
						add(f[i-1][k], f[i][j]);
				}
			}
	}
	printf("%d\n", f[0][1]);
}
