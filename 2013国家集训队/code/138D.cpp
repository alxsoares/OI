#include <cstdio>
#include <vector>
using namespace std;
char bd[2][44][44];
bool done[2][44][44][44][44];
int memo[2][44][44][44][44];
int n, m;
int dp(int t, int x1, int y1, int x2, int y2) {
	if ( x1 > x2 || y1 > y2 || x1 < 0 || y1 < 0 || x2 > n+m-2 || y2 > n+m-2 ) return 0; 
	if ( done[t][x1][y1][x2][y2] ) return memo[t][x1][y1][x2][y2];
	done[t][x1][y1][x2][y2] = true;
	int &ret = memo[t][x1][y1][x2][y2];
	vector<bool> bs(1000);
	for ( int x = x1; x <= x2; x ++ )
		for ( int y = y1; y <= y2; y ++ )
			if ( bd[t][x][y] == 'L' ) 
				bs[dp(t,x1,y1,x-1,y2)^dp(t,x+1,y1,x2,y2)] = 1;
			else if ( bd[t][x][y] == 'R' )
				bs[dp(t,x1,y1,x2,y-1)^dp(t,x1,y+1,x2,y2)] = 1;
			else if ( bd[t][x][y] == 'X' )
				bs[dp(t,x1,y1,x-1,y-1)^dp(t,x1,y+1,x-1,y2)^dp(t,x+1,y1,x2,y-1)^dp(t,x+1,y+1,x2,y2)] = 1;
	for ( int i = 0; ; i++ ) 
		if ( !bs[i] ) { 
			ret = i; 
			break; 
		}
	return ret;
}

int main() {
	freopen("t.in", "r", stdin);
	scanf("%d%d", &n, &m);
	for ( int i = 0; i < n; i ++ ) {
		char str[44];
		scanf("%s", str);
		for ( int j = 0; j < m; j ++ ) 
			bd[(i+j)&1][i+j][i-j+m-1] = str[j];
	}
	if ( dp(0,0,0,n+m-2,n+m-2) ^ dp(1,0,0,n+m-2,n+m-2) )
		puts("WIN");
	else puts("LOSE");
}
