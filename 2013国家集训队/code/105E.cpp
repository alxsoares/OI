#include <cstdio>
#include <vector>
#include <cassert>
#include <algorithm>
#include <set>
using namespace std;
typedef long long state_t;
int ans = 0;
vector<int> mran(3), tran(3), pos(3), hold(3), s(3);
set<state_t> S;

void solve() {
	state_t cur = 1;
	for ( int i = 0; i < 3; i ++ )
		cur = (cur<<7) + pos[i];
	for ( int i = 0; i < 3; i ++ )
		cur = (cur<<7) + (hold[i]==-1?3:hold[i]);
	for ( int i = 0; i < 3; i ++ )
		cur = (cur<<7) + s[i];
	if ( S.find(cur) != S.end() ) return;
	S.insert(cur);
	{
		for ( int i = 0; i < 3; i ++ ) {
			ans = max(ans, pos[i]);
		}
	}

	for ( int i = 0; i < 3; i ++ ) 
		if ( pos[i] != -1 ) {
			if ( hold[i] == -1 && (s[i]&1) ) {
				//move
				for ( int d = -mran[i]; d <= mran[i]; d++ )
					if ( pos[i]+d >= 1 ) {
						bool unoccupied = true;
						for ( int j = 0; j < 3; j ++ )
							if ( pos[j] != -1 && i != j && pos[j] == pos[i]+d )
								unoccupied = false;
						if ( !unoccupied ) continue;

						pos[i] += d;
						s[i] ^= 1;
						solve();
						s[i] ^= 1;
						pos[i] -= d;
					}
			}
			if ( hold[i] == -1 && (s[i]&2) ) {
				//grab
				for ( int j = 0; j < 3; j ++ )
					if ( pos[j] != -1 && abs(pos[i]-pos[j]) == 1 ) {
						int prepos = pos[j];
						pos[j] = -1;
						hold[i] = j;
						s[i] ^= 2;
						solve();
						pos[j] = prepos;
						hold[i] = -1;
						s[i] ^= 2;
					}
			}
			if ( hold[i] != -1 && (s[i]&4) ) {
				//throw
				int j = hold[i];
				assert(pos[j] == -1);
				for ( int d = -tran[i]; d <= tran[i]; d++ )
					if ( pos[i]+d >= 1 ) {

						bool unoccupied = true;
						for ( int k = 0; k < 3; k ++ )
							if ( pos[k] != -1 && pos[k] == pos[i]+d )
								unoccupied = false;
						if ( !unoccupied ) continue;

						pos[j] = pos[i] + d;
						hold[i] = -1;
						s[i] ^= 4;
						solve();
						pos[j] = -1;
						hold[i] = j;
						s[i] ^= 4;
					}
			}
		}
}

int main() {
	freopen("t.in", "r", stdin);
	for ( int i = 0; i < 3; i ++ ) {
		scanf("%d%d%d", &pos[i], &mran[i], &tran[i]);
		hold[i] = -1;
		s[i] = 7;
	}
	solve();
	printf("%d\n", ans);
}
