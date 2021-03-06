#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <cstring>
#define FOREACH(I, C) for(__typeof((C).begin()) I = (C).begin(); I != (C).end(); I++)

using namespace std;
typedef long long ll;

const int MOD = 1000000007;

void upd(int &a, int b) {
	a += b;
	a %= MOD;
}

class DengklekBuildingRoads {
public:
	int f[2][33][33][1<<9];
	int numWays(int N, int M, int K) {
		K = min(K, N);
		memset(f, 0, sizeof(f));
		int upperlim = 1 << (K+1);
		int cur = 1;
		f[cur][0][1][0] = 1;
		for ( int i = 1; i < N; i ++, cur ^= 1 ) {
			memset(f[!cur], 0, sizeof(f[!cur]));
			for ( int j = 0; j <= M; j ++ )
				for ( int k = K; k >= 0; k -- )
					for ( int s = 0; s < upperlim; s ++ ) 
						if ( f[cur][j][k][s] ) {
							if ( !(k==K && (s&(1<<k))) ) {
								if ( k )
									upd(f[cur][j][k-1][s], f[cur][j][k][s]);
								else
									upd(f[!cur][j][min(i+1,K)][(s<<1)&(upperlim-1)], f[cur][j][k][s]);
							}

							if ( k && j+1 <= M )
								upd(f[cur][j+1][k][s^(1<<k)^1], f[cur][j][k][s]);
						}
		}
		return f[cur][M][K][0];
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, int p1, int p2, bool hasAnswer, int p3) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2;
	cout << "]" << endl;
	DengklekBuildingRoads *obj;
	int answer;
	obj = new DengklekBuildingRoads();
	clock_t startTime = clock();
	answer = obj->numWays(p0, p1, p2);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p3 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p3;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;

	int p0;
	int p1;
	int p2;
	int p3;

	/*
	   {
	// ----- test 0 -----
	p0 = 3;
	p1 = 4;
	p2 = 1;
	p3 = 3;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}

	{
	// ----- test 1 -----
	p0 = 4;
	p1 = 3;
	p2 = 3;
	p3 = 4;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}

	{
	// ----- test 2 -----
	p0 = 2;
	p1 = 1;
	p2 = 1;
	p3 = 0;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}

	{
	// ----- test 3 -----
	p0 = 5;
	p1 = 0;
	p2 = 3;
	p3 = 1;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	 */
	{
		// ----- test 4 -----
		p0 = 10;
		p1 = 20;
		p2 = 5;
		p3 = 26964424;
		all_right = KawigiEdit_RunTest(4, p0, p1, p2, true, p3) && all_right;
		// ------------------
	}

	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// END KAWIGIEDIT TESTING

//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
