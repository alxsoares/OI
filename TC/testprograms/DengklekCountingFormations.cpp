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
#define plus plus123

using namespace std;
typedef long long ll;

int graphCnt[11][46];
int smallinv[51];
int bino[101][101];

const int MOD = 1000000007;

void add(int &a, int b) {
	a += b;
	a %= MOD;
	if ( a < 0 ) a += MOD;
}

int plus(int a, int b) {
	add(a, b);
	return a;
}

void substract(int &a, int b) {
	add(a, -b);
}

int mul(int a, int b) {
	return (int)((ll)a * b % MOD);
}

int mul(int a, int b, int c) {
	return mul(a, mul(b, c));
}

int powMod(int a, int n) {
	int ret = n & 1 ? a : 1;
	for ( n >>= 1; n; n >>= 1 ) {
		a = mul(a, a);
		if ( n & 1 ) 
			ret = mul(ret, a);
	}
	return ret;
}

int getInv(int x) {
	return powMod(x, MOD - 2);
}

int bruteBino(int n, int k) {
	assert(k <= 10);
	int ret = 1;
	for ( int i = 1; i <= k; i ++ )
		ret = mul(ret, n - i + 1, smallinv[i]);
	return ret;
}
 
void countGraph() {
	static int f[11][46];

	memset(f, 0, sizeof(f));
	f[1][0] = 1;

	for ( int i = 2; i <= 10; i ++ )
		for ( int j = i-1; j <= i*(i-1)/2; j ++ ) {
			f[i][j] = bino[i*(i-1)/2][j];
			for ( int k = 1; k < i; k ++ )
				for ( int l = k-1; l <= j; l ++ )
					substract(f[i][j], mul(f[k][l], bino[i-1][k-1], bino[(i-k)*(i-k-1)/2][j-l]));
		}

	memcpy(graphCnt, f, sizeof(f));
}

vector<vector<int> > decompose(int n, int low) {
	vector<vector<int> > ret;
	if ( n == 0 ) return ret;
	for ( int x = low; x <= n; x ++ ) {
		if ( x == n ) {
			ret.push_back(vector<int>(1, x));
			continue;
		}
		if ( n-x < x ) continue;
		vector<vector<int> > tmp = decompose(n-x, x);
		int sz = tmp.size();
		for ( int k = 0; k < sz; k ++ ) {
			vector<int> cur = tmp[k];
			cur.push_back(x);
			ret.push_back(cur);
		}
	}
	return ret;
}

pair<int, int> rowsVal[500010];
int rowsMore[500010];
int nRowsVal;
int fact[51], invfact[51];
int rowsWays[11];
int duckKind;

void preworkRows(int n, int low, int val, int cnt, int acc, int more) {
	if ( n == 0 ) {
		rowsVal[nRowsVal++] = make_pair(val, cnt);
		rowsMore[nRowsVal-1] = mul(more, invfact[acc]);
		return;
	}
	for ( int x = low; x <= n; x ++ ) {
		if ( x == low )
			preworkRows(n-x, x, mul(val, invfact[x]), cnt + 1, acc + 1, more);
		else
			preworkRows(n-x, x, mul(val, invfact[x]), cnt + 1, 1, mul(more, invfact[acc]));
	}
}
void initBino() {
	bino[0][0] = 1;
	for ( int i = 1; i <= 100; i ++ ) {
		bino[i][0] = 1;
		for ( int j = 1; j <= i; j ++ )
			bino[i][j] = plus(bino[i-1][j-1], bino[i-1][j]);
	}
}

class DengklekCountingFormations {
	public:
		int g[2][46];
		int numFormations(int N, int M, int K) {
			duckKind = K;
			initBino();
			countGraph();
			memset(rowsWays, 0, sizeof(rowsWays));
			nRowsVal = 0;
			fact[0] = 1;
			for ( int i = 1; i <= 50; i ++ ) fact[i] = mul(fact[i-1], i);
			for ( int i = 0; i <= 50; i ++ ) invfact[i] = getInv(fact[i]);
			for ( int i = 1; i <= 50; i ++ ) smallinv[i] = getInv(i);
			preworkRows(M, 1, fact[M], 0, 0, 1);
			for ( int i = 1; i <= N; i ++ )
				for ( int j = 0; j < nRowsVal; j ++ )
					add(rowsWays[i], mul(bino[K][rowsVal[j].second], mul(fact[rowsVal[j].second], rowsMore[j]), powMod(rowsVal[j].first, i)));

			vector<vector<int> > blocks = decompose(N, 1);
			int ans = 0;
			FOREACH(it, blocks) {
				int sz = it->size();
				memset(g, 0, sizeof(g));
				int cur = 0;
				g[cur][0] = fact[N];
				FOREACH(iit, (*it))
					g[cur][0] = mul(g[cur][0], invfact[*iit]);
				FOREACH(iit, (*it))
					g[cur][0] = mul(g[cur][0], rowsWays[*iit]);
				for ( int i = 0; i < sz; i ++ ) {
					int st = i;
					while ( i+1 < sz && (*it)[i] == (*it)[i+1] ) i ++;
					int en = i;
					g[cur][0] = mul(g[cur][0], invfact[en-st+1]);
				}
				for ( int i = 0; i < sz; i ++, cur ^= 1 ) {
					memset(g[!cur], 0, sizeof(g[!cur]));
					for ( int j = 0; j <= N*(N-1)/2; j ++ )
						if ( g[cur][j] ) {
							for ( int k = 0; j+k <= N*(N-1)/2; k++ )
								add(g[!cur][j+k], mul(g[cur][j], graphCnt[(*it)[i]][k]));
						}
				}
				for ( int j = 0; j <= N*(N-1)/2; j ++ )
					add(ans, (j&1?-1:1)*g[cur][j]);
			}
			return ans;
		}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, int p1, int p2, bool hasAnswer, int p3) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2;
	cout << "]" << endl;
	DengklekCountingFormations *obj;
	int answer;
	obj = new DengklekCountingFormations();
	clock_t startTime = clock();
	answer = obj->numFormations(p0, p1, p2);
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
	{
		// ----- test 0 -----
		p0 = 2;
		p1 = 2;
		p2 = 2;
		p3 = 10;
		all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
		// ------------------
	}


	{
		// ----- test 1 -----
		p0 = 1;
		p1 = 1;
		p2 = 58;
		p3 = 58;
		all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
		// ------------------
	}

	{
		// ----- test 2 -----
		p0 = 5;
		p1 = 3;
		p2 = 2;
		p3 = 0;
		all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
		// ------------------
	}
	
	{
		// ----- test 3 -----
		p0 = 3;
		p1 = 5;
		p2 = 7;
		p3 = 894953467;
		all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
		// ------------------
	}


	{
		// ----- test 4 -----
		p0 = 7;
		p1 = 47;
		p2 = 74;
		p3 = 778075142;
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
