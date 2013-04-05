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

const int kMemoCond = 9;
const int kDx[5] = {0, 0, -1, 1, 0};
const int kDy[5] = {1, -1, 0, 0, 0};
const int kModX[4] = {0, 0, 1, 1};
const int kModY[4] = {0, 1, 0, 1};

class XorLife {
public:
	map<pair<vector<string>, int>, ll> memo;
	long long countAliveCells(vector <string> field, int K) {
		int n = field.size(), m = field[0].size();
		ll res = 0;
		if ( n * m <= kMemoCond ) {
			pair<vector<string>, int> key = make_pair(field, K);
			if ( memo.count(key) )
				return memo[key];
		}
		if ( K == 0 && n == 1 && m == 1 ) {
			res = field[0][0] == 'o';
		} else if ( K % 2 == 1 ) {
			vector<string> newfield(n + 2, string(m + 2, '.'));
			for ( int x = 0; x < n + 2; x ++ )
				for ( int y = 0; y < m + 2; y ++ ) {
					int cnt = 0;
					for ( int dir = 0; dir < 5; dir ++ ) {
						int nx = x + kDx[dir] - 1, ny = y + kDy[dir] - 1;
						if ( 0 <= nx && nx < n && 0 <= ny && ny < m )
							cnt ^= field[nx][ny] == 'o';
					}
					if ( cnt == 1 ) newfield[x][y] = 'o';
				}
			res = countAliveCells(newfield, K - 1);
		} else if ( n % 2 == 1 ) {
			vector<string> newfield(field);
			newfield.push_back(string(m, '.'));
			res = countAliveCells(newfield, K);
		} else if ( m % 2 == 1 ) {
			vector<string> newfield(field);
			for ( int i = 0; i < n; i ++ )
				newfield[i] += '.';
			res = countAliveCells(newfield, K);
		} else {
			for ( int t = 0; t < 4; t ++ ) {
				vector<string> newfield(n / 2, string(m / 2, '.'));
				for ( int i = 0; i < n / 2; i ++ )
					for ( int j = 0; j < m / 2; j ++ ) 
						newfield[i][j] = field[i * 2 + kModX[t]][j * 2 + kModY[t]];
				res += countAliveCells(newfield, K / 2);
			}
		}

		if ( n * m <= kMemoCond )
			memo[make_pair(field, K)] = res;
		return res;
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <string> p0, int p1, bool hasAnswer, long long p2) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}" << "," << p1;
	cout << "]" << endl;
	XorLife *obj;
	long long answer;
	obj = new XorLife();
	clock_t startTime = clock();
	answer = obj->countAliveCells(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p2 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p2;
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
	
	vector <string> p0;
	int p1;
	long long p2;
	
	{
	// ----- test 0 -----
	string t0[] = {"oo","o."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 3;
	p2 = 23ll;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	{
	// ----- test 1 -----
	string t0[] = {"..",".."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 23;
	p2 = 0ll;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"o"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 1234567;
	p2 = 11018125ll;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"o.oo.ooo","o.o.o.oo","ooo.oooo","o.o..o.o","o.o..o.o","o..oooo.","..o.o.oo","oo.ooo.o"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 987654321;
	p2 = 447104494375ll;
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
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